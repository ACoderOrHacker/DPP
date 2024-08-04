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

#include "DXXParser.h"
#ifndef _COMPILER_H
#include <string>
#include <fstream>
#include <any>
#include <unordered_map>
#include <stack>
#include <initializer_list>
#include <fmt/core.h>
#include <fmt/color.h>

#include "DXXParserBaseVisitor.h"
#include "acdpp.h"
#include "vm.hpp"
#include "builtin.hpp"
#include "metadata.h"

#define OBJECT_TYPE 0

#define THROW(msg) {                                                          \
    fmt::print(fmt::fg(fmt::color::red), "\nerror: {}\n", msg);               \
    exit(1);                                                                  \
}

struct INFOS {
public:
    unsigned is_compiletime: 1 = false;
    unsigned is_final: 1 = false;
    unsigned is_override: 1 = false;
    unsigned is_inline: 1 = false;
    unsigned is_static: 1 = false;
    unsigned is_public: 1 = false;
    unsigned is_protected: 1 = false;
    unsigned is_private: 1 = false;
    unsigned is_constructor: 1 = false;
    unsigned is_destructor: 1 = false;
    const char *native_library = nullptr;
    const char *native_function = nullptr;
public:
    bool operator ==(const INFOS &infos) const {
        return is_compiletime == infos.is_compiletime &&
               is_final == infos.is_final &&
               is_override == infos.is_override &&
               is_inline == infos.is_inline &&
               is_static == infos.is_static &&
               is_public == infos.is_public &&
               is_protected == infos.is_protected &&
               is_private == infos.is_private &&
               is_constructor == infos.is_constructor &&
               is_destructor == infos.is_destructor &&
               native_library == infos.native_library &&
               native_function == infos.native_function;
    }

    struct INFOS &operator =(const INFOS &infos) {
        if(this == &infos) {
            return *this;
        }

        is_compiletime = infos.is_compiletime;
        is_final = infos.is_final;
        is_override = infos.is_override;
        is_inline = infos.is_inline;
        is_static = infos.is_static;
        is_public = infos.is_public;
        is_protected = infos.is_protected;
        is_private = infos.is_private;
        is_constructor = infos.is_constructor;
        is_destructor = infos.is_destructor;
        native_library = infos.native_library;
        native_function = infos.native_function;

        return *this;
    }

    struct INFOS &operator |=(const INFOS &infos) {
        if(this == &infos) {
            return *this;
        }

        is_compiletime |= infos.is_compiletime;
        is_final |= infos.is_final;
        is_override |= infos.is_override;
        is_inline |= infos.is_inline;
        is_static |= infos.is_static;
        is_public |= infos.is_public;
        is_protected |= infos.is_protected;
        is_private |= infos.is_private;
        is_constructor |= infos.is_constructor;
        is_destructor |= infos.is_destructor;
        native_library = infos.native_library;
        native_function = infos.native_function;

        return *this;
    }
};

DXX_API FObject *fObj = new FObject;

DXX_API FObject *_compile(antlr4::ANTLRInputStream stream);
DXX_API FObject *compile(std::string &code);
DXX_API FObject *compile(std::ifstream &ifs);

struct _Dpp_CObject;

typedef std::unordered_map<std::string, struct _Dpp_CObject *> Throwtable;

typedef struct _Dpp_CObject {
public:
	Object object;
    std::string id;
    struct INFOS infos;
    METHOD_DEF_WITH_VAL(uint32_t, type, OBJECT_TYPE)
    Array<_Dpp_CObject *> subs;
    void *metadata[8] = {};
public:
    bool operator ==(_Dpp_CObject *co) const {
        if(co->id != id || co->type != type || co->infos != infos) {
            return false;
        }

#define METADATA_EQ(pos, type) (*_cast(type *, co->metadata[(pos)]) == *_cast(type *, metadata[(pos)]))
        switch(type) {
            case FUNCTION_TYPE:
            if (METADATA_EQ(function::FUNCTION_METADATA::PARAMS, Heap<_Dpp_CObject *>)      &&
                METADATA_EQ(function::FUNCTION_METADATA::THROW_TABLE, Throwtable)           &&
                _cast(_Dpp_CObject *, metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object == _cast(_Dpp_CObject *, co->metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object) {
                return true;
            }

            default:
            return true;
        }
#undef METADATA_EQ

        return false;
    }
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

    void RemoveObject(Dpp_CObject *co,
        bool(*checker)(Dpp_CObject *, Dpp_CObject *) = [](Dpp_CObject *v1, Dpp_CObject *v2) {
            return *v1 == v2;
        }) {

        for (auto it : objects) {
            if (checker(it, co)) {
                acassert(it == nullptr);
                std::cout << "there";
                objects.remove(it);
            }
        }
    }
};

class IDIterator {
public:
    IDIterator() {
        global = BUILTIN_END;
        idIt.push(global);
    }
    ~IDIterator() = default;

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

    [[nodiscard]] uint32_t GetGlobalIterator() const noexcept {
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
    std::initializer_list<Object> l = {}) {
    OpCode _op;
    _op.params = *new Heap<Object>;
    _op.opcode = op;
    _op.flag = flags;

    for (auto it : l) {
        _op.params.PushData(it);
    }

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
    explicit DXXVisitor(FObject *_fObj = nullptr) {
        if (_fObj != nullptr) fObj = _fObj;
        else fObj = new FObject, RegInit(fObj);

        block_end = 0;

        // init the globalNamespace
        uint32_t builtin_it = 0;
        for (; builtin_it < BUILTIN_END; ++builtin_it) {
            Object o{true, builtin_it};
            Dpp_Object *obj = fObj->obj_map.get(o);
            Dpp_CObject *co = new Dpp_CObject;

            co->id = obj->name;
            co->object = o;
            globalNamespace->objects.write(co);

        }
    }

    std::any visit(antlr4::tree::ParseTree *tree) override {
        visitChildren(tree);

        return fObj;
    }

    /*
     * @return: NONE
     * Create a block at fObj->state
     */
    std::any visitBlock(DXXParser::BlockContext *ctx) override {
        if(blockNoNamespace) {
            namespaces.push(thisNamespace);
            thisNamespace = thisNamespace->NewNamespace();
        }

        for (auto it : ctx->expressions()) {
            visitChildren(it);
        }

        block_end = fObj->state.vmopcodes.size();

        if(blockNoNamespace) {
            thisNamespace = namespaces.top();
            namespaces.pop();
        }

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
     * Create a full function object - has head and body
     */
    std::any visitFunction(DXXParser::FunctionContext *ctx) override {
        DXXParser::FunctionHeadContext *_ctx = ctx->functionHead();
        std::vector<DXXParser::InfoContext *> _infos = _ctx->info();
        std::string id = _ctx->ID()->toString();
        DXXParser::ParamListContext *_params = _ctx->paramList();
        DXXParser::TheTypeContext *retType = _ctx->theType();
        DXXParser::ThrowtableContext *throwTable = _ctx->throwtable();
        DXXParser::BlockContext *block = ctx->block();

        Dpp_Object *func = MakeFunctionObject(id);

        struct INFOS infos = GetInfos(&_infos);

        blockNoNamespace = true;
        namespaces.push(thisNamespace);
        thisNamespace = thisNamespace->NewNamespace();
        idIt.PushIterator();
        struct VMState state;
        fObj->callstack.push(fObj->state);
        fObj->state = state;

        Heap<Dpp_CObject *> *params = anycast(Heap<Dpp_CObject *> *, visitParamList(_params));
        visitBlock(block);

        ((FunctionObject *)func)->state = fObj->state;

        fObj->state = fObj->callstack.top();
        fObj->callstack.pop();
        idIt.PopIterator();
        thisNamespace = namespaces.top();
        namespaces.pop();
        blockNoNamespace = false;

        Dpp_CObject *ret = anycast(Dpp_CObject *, visitTheType(retType));
        Heap<Dpp_CObject *> *throws = anycast(Heap<Dpp_CObject *> *, visitThrowtable(throwTable));

        Dpp_CObject *co = MakeFunction(func, infos, params, ret, throws);

        return co;
    }

    /*
     * @return: Throwtable *
     * Just a helper function of 'functionHead'
     */
    std::any visitThrowtable(DXXParser::ThrowtableContext *ctx) override {
        Throwtable *throw_table = new Throwtable;
        if (ctx == nullptr) return throw_table;

        for (auto it : ctx->idEx()) {
            Dpp_CObject *co = anycast(Dpp_CObject *, visitIdEx(it));
            (*throw_table)[co->id] = co;
        }

        return throw_table;
    }

    /*
     * @return: Heap<Dpp_Object *> *
     * Just a helper function of 'functionHead'
     */
    std::any visitParamList(DXXParser::ParamListContext *ctx) override {
        Heap<Dpp_CObject *> *param_list = new Heap<Dpp_CObject *>;
        if (ctx == nullptr) return param_list;

        for (auto it : ctx->varDefine()) {
            // TODO: Function may need a local variable of function, but there may not
            param_list->PushData(anycast(Dpp_CObject *, visitVarDefine(it)));

        }

        return param_list;
    }

    /*
     * @return: Dpp_CObject *
     * return the type
     */
    std::any visitTheType(DXXParser::TheTypeContext *ctx) override {
        Dpp_CObject *co;

        for (auto it : ctx->theTypeSub()->children) {
            if (it != nullptr) {
                std::string id = it->toString();
                std::vector<DXXParser::InfoContext *> infos = ctx->info();

                // type is always in global namespace
                co = FindObject(id, true);
                if (co == nullptr) {
                    THROW(fmt::format("no type named '{}'", id));
                }

                co->infos |= GetInfos(&infos);
            }
        }

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Define a variable
     */
	std::any visitVarDefine(DXXParser::VarDefineContext *ctx) override {
		DXXParser::TheTypeContext *_type = ctx->theType();
		std::vector<DXXParser::InfoContext *> infos = ctx->info();
		DXXParser::DataContext *_data = ctx->data();

		std::string id = ctx->ID()->toString();
		Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(_type));
		Dpp_CObject *data;
        Dpp_CObject *to = MakeObject(id);
        to->_type(type->object.id);

        LoadOpcode(OPCODE_NEW, NO_FLAG, { type->object, to->object });
        if (_data != nullptr) {
            data = anycast(Dpp_CObject *, visitChildren(_data));
            LoadOpcode(OPCODE_MOV, NO_FLAG, { data->object, to->object });
        }

		return to;
	}

    /*
     * @return: NONE
     * Move the value to the variable
     */
	std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
		Dpp_CObject *o = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
		Dpp_CObject *val = anycast(Dpp_CObject *, visitChildren(ctx->data()));

		LoadOpcode(OPCODE_MOV, NO_FLAG, { val->object, o->object });

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
        enum_object->_type(CLASS_TYPE);

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
        LoadAndInsertOpcode(jmp_pos, OPCODE_JMP, flag, { jmp_to, data->object });

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
            LoadOpcode(OPCODE_JMP, flag, { placeholder, placeholder });
            jmp_poses.PushData(fObj->state.vmopcodes.size() - 1);
        }

        for(auto it: ctx->withIfExtendsSub()) {
            visitBlock(it->block());
            block_ends.PushData(block_end);
        }

        Object end = {true, (uint32_t)(fObj->state.vmopcodes.size() + block_ends.size())};
        for(auto jmp_pos: jmp_poses) {
            ResetOpcode(jmp_pos, OPCODE_JMP, flag, { datas.PopData()->object, end });
        }

        for(auto block_end: block_ends) {
            LoadAndInsertOpcode(block_end, OPCODE_JMP, NO_FLAG, { end });
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

        LoadOpcode(OPCODE_JMP, NO_FLAG, { label->object });

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

        LoadOpcode(OPCODE_NEW, NO_FLAG, { type, to });
		return to;
	}

    /*
     * @return: NONE
     * Make 'delete' opcode
     */
	std::any visitDelete(DXXParser::DeleteContext *ctx) override {
		Dpp_CObject *data = anycast(Dpp_CObject *, visitChildren(ctx->data()));

        LoadOpcode(OPCODE_DEL, NO_FLAG, { data->object });

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
    static void LoadOpcode(rt_opcode op,
                    char flags = NO_FLAG,
                    std::initializer_list<Object> l = {}) {
        fObj->state.vmopcodes.PushData(MakeOpCode(op, flags, l));
    }

    static void LoadOpcode(rt_opcode op,
        char flags,
        Heap<Object> &params) {
        fObj->state.vmopcodes.PushData(MakeOpCode(op, flags, params));
    }

    /*
     * @return: void
     * Create a opcode and push it to main state(fObj->state)
     */
    static void LoadAndInsertOpcode(uint32_t pos,
                    rt_opcode op,
                    char flags = NO_FLAG,
                    std::initializer_list<Object> l = {}) {
        fObj->state.vmopcodes.SetData(pos, MakeOpCode(op, flags, l));
    }

    /*
     * @return: void
     * Reset the opcode in the state
     */
    static void ResetOpcode(uint32_t pos,
                     rt_opcode op,
                     char flags = NO_FLAG,
                     std::initializer_list<Object> l = {}) {
        fObj->state.vmopcodes.ResetData(pos, MakeOpCode(op, flags, l));
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

        if (!obj->name.empty()) {
            globalNamespace->RemoveObject(_co);
        }
        globalNamespace->objects.write(_co);

        return _co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of StringObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeString(const std::string &s) {
        String wstr = stringToWstring(s);
        Object o = allocMapping(true);
        Dpp_Object *obj = mkConst<StringObject, String>(wstr);
        obj->name = s;

        return MakeConst(o, obj)->_type(STRING_TYPE);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of IntegerObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeInteger(Interger idata) {
        Object o = allocMapping(true);
        Dpp_Object *obj = mkConst<IntObject, Interger>(idata);
        obj->name = std::to_string(idata);

        return MakeConst(o, obj)->_type(INT_TYPE);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of FunctionObject
     * And Push the function object to the object pool
     */
    Dpp_CObject *MakeFunction(Dpp_Object *func,
                              struct INFOS &infos,
                              Heap<Dpp_CObject *> *params,
                              Dpp_CObject *ret,
                              Heap<Dpp_CObject *> *throws) {
        Object o = allocMapping(true);
        Dpp_CObject *co = MakeConst(o, func);
        co->id = func->name;
        co->infos = infos;
        co->metadata[function::PARAMS] = params;
        co->metadata[function::RETURN_TYPE] = ret;
        co->metadata[function::THROW_TABLE] = throws;

        return co->_type(FUNCTION_TYPE);
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of label
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeLabel(const std::string &_label,
                                 uint32_t pos) {
        Dpp_CObject *co = MakeInteger(pos);
        Dpp_CObject *label = LinkObject(_label, co);

        return label;
    }

    /*
     * @return: Dpp_Object *
     * Make a function object(run-time)
     */
    static Dpp_Object *MakeFunctionObject(const std::string &id) {
        return mkFunction(id);
    }

    /*
     * @return: Dpp_CObject *
     * Make a normal object
     */
    Dpp_CObject *MakeObject(const std::string &id) {
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
    Dpp_CObject *LinkObject(const std::string &id,
                            Dpp_CObject *src) {
        Dpp_CObject *co = MakeObject(id);
        co->object = src->object;

        return co;
    }

    /*
     * @return: Dpp_Object *
     * Get a run-time object(constant) from compile-time object
     */
    static Dpp_Object *GetConstFromCObject(Dpp_CObject *co) {
        if(!co->object.isInGlobal) return nullptr;

        return fObj->obj_map.get(co->object);
    }

    /*
     * @return: Dpp_CObject *
     * Find a compile-time object from namespaces
     */
    Dpp_CObject *FindObject(const std::string &id, bool onlyGlobal = false) {
        Dpp_CObject *co = FindObject(globalNamespace, id);

        if(onlyGlobal || co != nullptr) {
            return co;
        }

        return FindObject(thisNamespace, id);
    }

    static Dpp_CObject *FindObject(Namespace *ns, const std::string &id) {

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

	static struct INFOS GetInfos(std::vector<DXXParser::InfoContext *> *_infos) {
		struct INFOS infos;

        for (auto it : *_infos) {
            for (auto info : it->children) {
                if (info != nullptr) {
                    std::string native_lib, native_func;
                    if(info->children.size() > 1) {
                        native_lib = info->children[1]->toString();
                        native_func = info->children[2]->toString();
                    }
                    infos |= GetInfoFromID(info->toString(), native_lib, native_func);
                }
            }
        }

        return infos;
	}

    static struct INFOS GetInfoFromID(const std::string &id,
                                      const std::string &native_lib,
                                      const std::string &native_func) {
        struct INFOS infos;

        if(id == "compiletime") {
            infos.is_compiletime = true;
        } else if(id == "inline") {
            infos.is_inline = true;
        } else if(id == "static") {
            infos.is_static = true;
        } else if(id == "final") {
            infos.is_final = true;
        } else if(id == "native") {
            infos.native_function = native_func.c_str();
            infos.native_library = native_lib.c_str();
        } else if(id == "constructor") {
            infos.is_constructor = true;
        } else if(id == "destructor") {
            infos.is_destructor = true;
        } else if(id == "override") {
            infos.is_override = true;
        } else if(id == "private") {
            infos.is_private = true;
        } else if(id == "protected") {
            infos.is_protected = true;
        } else if(id == "public") {
            infos.is_public = true;
        }

        return infos;
    }
private:
    Namespace *globalNamespace = new Namespace;
    Namespace *thisNamespace = globalNamespace;
    std::stack<Namespace *> namespaces;

    /*
     * See doc/compiler/idIt.md
     */
    IDIterator idIt;

    uint32_t block_end; // for jump statements

    bool blockNoNamespace = false;

    Object placeholder = {true, UINT_MAX};
};

#endif // !_COMPILER_H
