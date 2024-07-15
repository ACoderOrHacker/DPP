/*
  MIT License

  Copyright (c) 2023 ACoderOrHacker

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#ifndef _COMPILER_H
#include <string>
#include <fstream>
#include <any>
#include <stack>
#include <cstdarg>

#include "DXXLexer.h"
#include "DXXParserBaseVisitor.h"
#include "acdpp.h"
#include "vm.hpp"
#include "builtin.hpp"
#include "metadata.h"

DXX_API FObject *fObj = new FObject;

DXX_API FObject *_compile(antlr4::ANTLRInputStream stream);
DXX_API FObject *compile(std::string &code);
DXX_API FObject *compile(std::ifstream &ifs);

typedef struct _Dpp_CObject {
	Object object;
    std::string id;
    uint32_t infos = 0;
    Array<_Dpp_CObject *> subs;
    void *metadata[8];
} Dpp_CObject;

class Namespace {
public:
    Array<Dpp_CObject *> objects;
	Array<Namespace *> namespaces;
    Array<Namespace *> parents;

public:
    Namespace *NewNamespace() {
        Namespace *ns = new Namespace;

        ns->parents.write(this);
        namespaces.write(ns);

        return ns;
    }
};

class IDIterator {
public:
    IDIterator() {
        global = BUILTIN_END;
        idIt.push(global);
    }
    ~IDIterator() {}

    void IncIterator() noexcept {
        ++idIt.top();
    }

    void IncGlobalIterator() noexcept {
        ++global;
    }

    void DecIterator() noexcept {
        --idIt.top();
    }

    void DecGlobalIterator() noexcept {
        --global;
    }

    void PushIterator() noexcept {
        idIt.push(0);
    }

    void PopIterator() noexcept {
        idIt.pop();
    }

    uint32_t GetTopIterator() noexcept {
        return idIt.top();
    }

    uint32_t GetGlobalIterator() noexcept {
        return global;
    }
private:
    std::stack<uint32_t> idIt;
    uint32_t global;

};

void writeInfos(Dpp_Object *o, std::vector<DXXParser::InfoContext *> *infos) {

}

DXX_API OpCode MakeOpCode(rt_opcode op,
    char flags = NO_FLAG,
    int count = 0,
    ...) {
    OpCode _op;
    _op.opcode = op;
    _op.flag = flags;
    va_list l;
    va_start(l, count);
    for(int i = 0; i<count; ++i) {
        _op.params.PushData(va_arg(l, Object));
    }
    va_end(l);

    return _op;
}

DXX_API OpCode MakeOpCode(rt_opcode op,
    char flags,
    Heap<Object> &params) {
    OpCode _op;
    _op.opcode = op;
    _op.flag = flags;
    _op.params = params;

    return _op;
}

class DXXVisitor : public DXXParserBaseVisitor {
public:
    DXXVisitor(FObject *_fObj = nullptr) {
        if (_fObj != nullptr) fObj = _fObj;
        else fObj = new FObject, RegInit(fObj);

        block_end = 0;
    }

    std::any visit(antlr4::tree::ParseTree *tree) {
        visitChildren(tree);

        return fObj;
    }

    /*
     * @return: NONE
     * Create a block at fObj->state
     */
    std::any visitBlock(DXXParser::BlockContext *ctx) override {
        namespaces.push(thisNamespace);
        thisNamespace = thisNamespace->NewNamespace();

        for (auto it : ctx->expressions()) {
            visitChildren(it);
        }

        block_end = fObj->state.vmopcodes.size();
        thisNamespace = namespaces.top();
        namespaces.pop();
        return NONE;
    }

    /*
     * @return: NONE
     * Create 'import' opcodes
     */
    std::any visitImportLib(DXXParser::ImportLibContext *ctx) override {
        Heap<Object> params;

        for (auto it : ctx->idEx()->ID()) {
            Dpp_CObject *mod = MakeString(it->toString());
            params.PushData(mod->object);
        }

        LoadOpcode(OPCODE_IMPORT, NO_FLAG, params);
        return NONE;
    }

    /*
     * @return: Dpp_CObject *
     * Create a 'Compile-time Object' of function
     */
    std::any visitFunctionHead(DXXParser::FunctionHeadContext *ctx) override {
        std::vector<DXXParser::InfoContext *> _infos = ctx->info();
        std::string id = ctx->ID()->toString();
        DXXParser::ParamListContext *_params = ctx->paramList();
        DXXParser::TheTypeContext *retType = ctx->theType();
        DXXParser::ThrowtableContext *throwTable = ctx->throwtable();

        /*
          TODO: visitParamList returns Heap<Dpp_Object *> *, visitThrowtable returns Heap<Dpp_Object *> *
        */
        uint32_t infos = GetInfos(&_infos);
        Heap<Dpp_Object *> *params = anycast(Heap<Dpp_Object *> *, visitParamList(_params));
        Dpp_Object *ret = anycast(Dpp_Object *, visitTheType(retType));
        Heap<Dpp_Object *> *throws = anycast(Heap<Dpp_Object *> *, visitThrowtable(throwTable));

        Dpp_Object *func = MakeFunctionObject(id);
        Dpp_CObject *co = MakeFunction(func, infos, params, ret, throws);

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Create a full function object - has head and body
     */
    std::any visitFunction(DXXParser::FunctionContext *ctx) override {
        Dpp_CObject *co = anycast(Dpp_CObject *, visitFunctionHead(ctx->functionHead()));
        DXXParser::BlockContext *block = ctx->block();
        Dpp_Object *func = GetConstFromCObject(co);

        idIt.PushIterator();
        struct VMState state;
        fObj->callstack.push(fObj->state);
        fObj->state = state;

        visitBlock(block);

        ((FunctionObject *)func)->state = fObj->state;

        fObj->state = fObj->callstack.top();
        fObj->callstack.pop();
        idIt.PopIterator();

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Create a 'Compile-time Object' of function
     */
    std::any visitFunctionDefine(DXXParser::FunctionDefineContext *ctx) override {
        return visitFunctionHead(ctx->functionHead());
    }

    /*
     * @return: NONE
     * Define a variable
     */
	std::any visitVarDefine(DXXParser::VarDefineContext *ctx) override {
		DXXParser::TheTypeContext *_type = ctx->theType();
		std::vector<DXXParser::InfoContext *> infos = ctx->info();
		DXXParser::DataContext *_data = ctx->data();

		std::string id = ctx->ID()->toString();
		Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(_type));
		Dpp_CObject *data;
        Object to = allocMapping();

        LoadOpcode(OPCODE_NEW, NO_FLAG, 2, type->object, to);
        if (_data != nullptr) {
            data = anycast(Dpp_CObject *, visitChildren(_data));
            LoadOpcode(OPCODE_MOV, NO_FLAG, 2, data->object, to);
        }

		return NONE;
	}

    /*
     * @return: NONE
     * Move the value to the variable
     */
	std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
		Dpp_CObject *o = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
		Dpp_CObject *val = anycast(Dpp_CObject *, visitChildren(ctx->data()));

		LoadOpcode(OPCODE_MOV, NO_FLAG, 2, val->object, o->object);

		return NONE;
	}
	/*
	std::any visitTypedef(DXXParser::TypedefContext *ctx) override {
		std::string id = ctx->ID()->toString();
		DXXParser::TheTypeContext *type = ctx->theType();

		Object type = anycast(Object, visitTheType(type));


	}*/

    /*
     * @return: NONE
     * Linking the constant to the enum variable
     */
    std::any visitEnum(DXXParser::EnumContext *ctx) override {
        Dpp_CObject *enum_object = MakeObject(ctx->ID()->toString());

        for(auto it: ctx->enumSub()) {
            std::string id = it->ID()->toString();
            Dpp_CObject *idata = MakeInteger(std::stoll(it->IntegerData()->toString()));

            Dpp_CObject *sub = LinkObject(id, idata);
            enum_object->subs.write(sub);
        }


        return NONE;
    }

    /*
     * @return: NONE
     * The if statement opcodes
     */
    std::any visitWithIf(DXXParser::WithIfContext *ctx) override {
        char flag = NO_FLAG;
        SetBit1(flag, JMP_FALSE);
        uint32_t jmp_pos = fObj->state.vmopcodes.size();
        Dpp_CObject *data = anycast(Dpp_CObject *, visitChildren(ctx->data()));

        Object jmp_to = {true, block_end};
        visitBlock(ctx->block());
        LoadAndInsertOpcode(jmp_pos, OPCODE_JMP, flag, 2, jmp_to, data->object);

        return NONE;
    }

    /*
     * @return: NONE
     * The if statement opcodes
     */
    std::any visitWithIfExtends(DXXParser::WithIfExtendsContext *ctx) override {
        char flag = NO_FLAG;
        SetBit1(flag, JMP_FALSE);
        Heap<uint32_t> block_ends;
        Heap<uint32_t> jmp_poses;
        Heap<Dpp_CObject *> datas;

        for(auto it: ctx->withIfExtendsSub()) {
            datas.PushData(anycast(Dpp_CObject *, visitChildren(it->data())));
            LoadOpcode(OPCODE_JMP, flag, 2, placeholder, placeholder);
            jmp_poses.PushData(fObj->state.vmopcodes.size() - 1);
        }

        for(auto it: ctx->withIfExtendsSub()) {
            visitBlock(it->block());
            block_ends.PushData(block_end);
        }

        Object end = {true, (uint32_t)(fObj->state.vmopcodes.size() + block_ends.size())};
        for(auto jmp_pos: jmp_poses) {
            ResetOpcode(jmp_pos, OPCODE_JMP, flag, 2, datas.PopData(), end);
        }

        for(auto block_end: block_ends) {
            LoadAndInsertOpcode(block_end, OPCODE_JMP, NO_FLAG, 1, end);
        }

        return NONE;
    }

    /*
     * @return: NONE
     * Make 'switch' opcode
     */
    std::any visitWithSwitchStatement(DXXParser::WithSwitchStatementContext *ctx) override {
        // TODO: Not success
        return NONE;
    }

    /*
     * @return: NONE
     * Make the 'goto' opcode
     */
    std::any visitGoto(DXXParser::GotoContext *ctx) override {
        std::string id = ctx->ID()->toString();
        Dpp_CObject *label = FindObject(id, true);

        LoadOpcode(OPCODE_JMP, NO_FLAG, 1, label->object);

        return NONE;
    }

    /*
     * @return: Dpp_CObject *
     * Define a label of runtime opcode id
     */
    std::any visitGotoLabelDefine(DXXParser::GotoLabelDefineContext *ctx) override {
        return MakeLabel(ctx->ID()->toString(), fObj->state.vmopcodes.size());
    }

    /*
     * @return: Object
     * make 'new' opcode and returns the value of object
     */
	std::any visitNew(DXXParser::NewContext *ctx) override {
		Object type = anycast(Object, visitTheType(ctx->theType()));
        Object to = allocMapping();

        LoadOpcode(OPCODE_NEW, NO_FLAG, 2, type, to);
		return to;
	}

    /*
     * @return: NONE
     * Make 'delete' opcode
     */
	std::any visitDelete(DXXParser::DeleteContext *ctx) override {
		Dpp_CObject *data = anycast(Dpp_CObject *, visitChildren(ctx->data()));

        LoadOpcode(OPCODE_DEL, NO_FLAG, 1, data->object);

		return NONE;
	}

private:
    /*
     * @return: bool
     */
    inline bool isInGlobal() { return globalNamespace == thisNamespace; }

    /*
     * @return: Object
     * Create a Object structure from the iterator
     */
    Object allocMapping(bool isConst = false) {
        if (isConst) {
            uint32_t it = idIt.GetGlobalIterator();
            idIt.IncGlobalIterator();

            return {true, it};
        } else {
            uint32_t it = idIt.GetTopIterator();
            idIt.IncIterator();

            return {isInGlobal(), it};
        }

    }

    /*
     * @return: void
     * Create a opcode and push it to main state(fObj->state)
     */
    void LoadOpcode(rt_opcode op,
                    char flags = NO_FLAG,
                    int count = 0,
                    ...) {
        va_list l;

        va_start(l, count);
        fObj->state.vmopcodes.PushData(MakeOpCode(op, flags, count, l));
        va_end(l);
    }

    void LoadOpcode(rt_opcode op,
        char flags,
        Heap<Object> &params) {
        fObj->state.vmopcodes.PushData(MakeOpCode(op, flags, params));
    }

    /*
     * @return: void
     * Create a opcode and push it to main state(fObj->state)
     */
    void LoadAndInsertOpcode(uint32_t pos,
                    rt_opcode op,
                    char flags = NO_FLAG,
                    int count = 0,
                    ...) {
        va_list l;

        va_start(l, count);
        fObj->state.vmopcodes.SetData(pos, MakeOpCode(op, flags, count, l));
        va_end(l);
    }

    /*
     * @return: void
     * Reset the opcode in the state
     */
    void ResetOpcode(uint32_t pos,
                     rt_opcode op,
                     char flags = NO_FLAG,
                     int count = 0,
                     ...) {
        va_list l;

        va_start(l, count);
        fObj->state.vmopcodes.ResetData(pos, MakeOpCode(op, flags, count, l));
        va_end(l);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md)
     * And Push the constant to the object pool
     */
    Dpp_CObject *MakeConst(Object o, Dpp_Object *obj) {
        Dpp_CObject *_co = new Dpp_CObject;
        _co->object = o;

        fObj->obj_map.write(o, obj);
        // TODO: Write to the constant pool, it was not success

        return _co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of StringObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeString(std::string s) {
        String wstr = stringToWstring(s);
        Object o = allocMapping(true);
        Dpp_Object *obj = mkConst<StringObject, String>(wstr);

        return MakeConst(o, obj);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of IntegerObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeInteger(Interger idata) {
        Object o = allocMapping(true);
        Dpp_Object *obj = mkConst<IntObject, Interger>(idata);

        return MakeConst(o, obj);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of FunctionObject
     * And Push the function object to the object pool
     */
    Dpp_CObject *MakeFunction(Dpp_Object *func,
                              uint32_t infos,
                              Heap<Dpp_Object *> *params,
                              Dpp_Object *ret,
                              Heap<Dpp_Object *> *throws) {
        Object o = allocMapping(true);
        Dpp_CObject *co = MakeConst(o, func);
        co->infos = infos;
        co->metadata[function::PARAMS] = params;
        co->metadata[function::RETURN_TYPE] = ret;
        co->metadata[function::THROW_TABLE] = throws;

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of label
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeLabel(std::string _label,
                                 uint32_t pos) {
        Dpp_CObject *co = MakeInteger(pos);
        Dpp_CObject *label = LinkObject(_label, co);

        return label;
    }

    /*
     * @return: Dpp_Object *
     * Make a function object(run-time)
     */
    Dpp_Object *MakeFunctionObject(std::string id) {
        return mkFunction(id);
    }

    /*
     * @return: Dpp_CObject *
     * Make a normal object
     */
    Dpp_CObject *MakeObject(std::string id) {
        Dpp_CObject *co = new Dpp_CObject;
        co->id = id;
        co->object = allocMapping();
        thisNamespace->objects.write(co);

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * link the source object and a object
     */
    Dpp_CObject *LinkObject(std::string id,
                            Dpp_CObject *src) {
        Dpp_CObject *co = MakeObject(id);
        co->object = src->object;

        return co;
    }

    /*
     * @return: Dpp_Object *
     * Get a run-time object(constant) from compile-time object
     */
    Dpp_Object *GetConstFromCObject(Dpp_CObject *co) {
        if(!co->object.isInGlobal) return nullptr;

        return fObj->obj_map.get(co->object);
    }

    /*
     * @return: Dpp_CObject *
     * Find a compile-time object from namespaces
     */
    Dpp_CObject *FindObject(std::string id, bool onlyGlobal = false) {
        Dpp_CObject *co = FindObject(globalNamespace, id);

        if(onlyGlobal || co != nullptr) {
            return co;
        }

        return FindObject(thisNamespace, id);
    }

    Dpp_CObject *FindObject(Namespace *ns, std::string id) {

        for(auto it: ns->objects) {
            if(it->id == id) {
                return it;
            }
        }

        for(auto it: ns->parents) {
            for(auto it: ns->objects) {
                if(it->id == id) {
                    return it;
                }
            }
        }

        return nullptr;
    }

	uint32_t GetInfos(std::vector<DXXParser::InfoContext *> *_infos) {
		uint32_t infos = 0;

		for (auto it : *_infos) {
			infos |= anycast(uint32_t, visitInfo(it));
		}

        return infos;
	}
private:
	//FObject *fObj;
    Namespace *globalNamespace = new Namespace;
    Namespace *thisNamespace = globalNamespace;
    std::stack<Namespace *> namespaces;

    /*
     * See doc/compiler/idIt.md
     */
    IDIterator idIt;

    uint32_t block_end; // for jump statements

    Object placeholder = {true, UINT_MAX};
};

#endif // !_COMPILER_H
