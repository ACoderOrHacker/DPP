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
#include "DXXParser.h"
#include "DXXParserBaseVisitor.h"

#include <cstdint>
#include <string>
#include <fstream>
#include <any>
#include <unordered_map>
#include <stack>
#include <initializer_list>
#include <fmt/core.h>
#include <fmt/color.h>

#include "enum.hpp"
#include "acdpp.h"
#include "vm.hpp"
#include "builtin.hpp"
#include "metadata.h"

#define VOID_TYPE UINT_MAX
#define OBJECT_TYPE (UINT_MAX - 1)
#define TYPE_TYPE (UINT_MAX - 2)

#define THROW(msg) {                                                          \
    fmt::print(fmt::fg(fmt::color::red), "\nerror: {}\n", msg);               \
    exit(1);                                                                  \
}

#define WARNING(msg) {                                                          \
    fmt::print(fmt::fg(fmt::color::yellow), "\nwarning: {}\n", msg);            \
}

#define MESSAGE(msg) {                                                          \
    fmt::print("\nmessage: {}\n", msg);            \
}

DXX_API FObject *fObj = new FObject;

DXX_API FObject *_compile(antlr4::ANTLRInputStream stream);
DXX_API FObject *compile(std::string &code);
DXX_API FObject *compile(std::ifstream &ifs);
DXX_API FObject *compile(std::fstream &ifs);

struct _Dpp_CObject;
class RetTypeNeqError : std::exception {};
bool throw_when_neq = false;

typedef std::unordered_map<std::string, struct _Dpp_CObject *> Throwtable;

struct INFOS {
public:
    unsigned is_compiletime : 1 = false;
    unsigned is_final : 1 = false;
    unsigned is_override : 1 = false;
    unsigned is_inline : 1 = false;
    unsigned is_static : 1 = false;
    unsigned is_public : 1 = false;
    unsigned is_protected : 1 = false;
    unsigned is_private : 1 = false;
    unsigned is_constructor : 1 = false;
    unsigned is_destructor : 1 = false;
    std::string native_library;
    std::string native_function;
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
        if (this == &infos) {
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
        if (this == &infos) {
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

typedef struct _Dpp_CObject {
public:
	Object object;
    std::string id;
    struct INFOS infos;
    bool isNone = false;
    uint32_t type = OBJECT_TYPE;
    Array<_Dpp_CObject *> subs;
    void *metadata[8] = {};
public:
    bool operator ==(_Dpp_CObject *co) const {
        if(co->id != id || co->type != type) {
            return false;
        }

#define METADATA_EQ(pos, type) (*_cast(type *, co->metadata[(pos)]) == *_cast(type *, metadata[(pos)]))
        switch(type) {
            case FUNCTION_TYPE:
            if (co->infos != infos) return false;

            if (METADATA_EQ(function::FUNCTION_METADATA::PARAMS, Heap<_Dpp_CObject *>)      &&
                METADATA_EQ(function::FUNCTION_METADATA::AUTOVALUES, Heap<_Dpp_CObject *>) &&
                METADATA_EQ(function::FUNCTION_METADATA::THROW_TABLE, Throwtable)) {
                if (_cast(_Dpp_CObject *, metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object != _cast(_Dpp_CObject *, co->metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object) {
                    if(throw_when_neq) throw RetTypeNeqError();

                    return false;
                }
                return true;
            }

            default:
            return true;
        }
#undef METADATA_EQ
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
            if(it == nullptr) continue;

            if (checker(it, co)) {
                acassert(it == nullptr);
                objects.remove(it);
            }
        }
    }
};

class IDIterator {
public:
    IDIterator() {
        global = BUILTIN_END;
    }
    ~IDIterator() = default;

    void IncIterator() noexcept {
        if (idIt.empty()) ++global;
        else ++idIt.top();
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
        if (idIt.empty()) return global;
        else return idIt.top();
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

    uint32_t i = 0;
    for (auto it : l) {
        _op.params.SetData(i, it);
        ++i;
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
        else fObj = MakeVM();

        loop_end = 0;
        block_end = 0;

        // init the globalNamespace
        uint32_t builtin_it = 0;
        for (; builtin_it < BUILTIN_END; ++builtin_it) {
            if (builtin_it != BUILTIN::BUILTIN_OUT) {
                Object o{ true, builtin_it };
                Dpp_Object *obj = fObj->obj_map.get(o);
                Dpp_CObject *co = new Dpp_CObject;

                co->id = obj->name;
                co->object = o;
                globalNamespace->objects.write(co);
            }


        }

        auto make_type = [=, this](const std::string &id, uint32_t type_id) {
            Dpp_CObject *type = new Dpp_CObject;
            type->id = id;
            type->object = { true, type_id};
            type->type = TYPE_TYPE;
            globalNamespace->objects.write(type);
        };

        make_type("void", VOID_TYPE);
        make_type("object", OBJECT_TYPE);
        make_type("type", TYPE_TYPE);
        make_type("bool", INT_TYPE);
    }

    std::any visit(antlr4::tree::ParseTree *tree) override {
        visitChildren(tree);

        Dpp_CObject *main = FindObject("main", true);
        if (main == nullptr) {
            WARNING("no main function in program");
            goto RETURN;
        }
        if (main->type != FUNCTION_TYPE) {
            THROW("main is not a function");
        }
        if (_cast(Heap<Dpp_CObject *> *, main->metadata[function::FUNCTION_METADATA::PARAMS])->size() > 0) {
            THROW(fmt::format("main function has much than 0 paramter"));
        }
        LoadOpcode(OPCODE_CALL, NO_FLAG, {main->object});

        RETURN:
        return fObj;
    }

    forceinline static std::string SpiltQuote(const std::string &s) {
        if (s.empty()) {
            return "";
        }

        return s.substr(1, s.size() - 2);
    }

    /*
     * @return: NONE
     * Create a block at fObj->state
     */
    std::any visitBlock(DXXParser::BlockContext *ctx) override {
        if(!blockNoNamespace) {
            namespaces.push(thisNamespace);
            thisNamespace = thisNamespace->NewNamespace();
        }

        visitChildren(ctx);

        block_end = fObj->state.vmopcodes.size();

        for(auto &it : gotos) {
            const std::string &id = it.first;
            Dpp_CObject *label = FindObject(id, true);
            if (label == nullptr) {
                THROW(fmt::format("cannot find '{}' label", id));
            }

            uint32_t pos = *_cast(uint32_t *, label->metadata[label::LABEL_METADATA::POS]);
            ResetOpcode(it.second, OPCODE_JMP, NO_FLAG, { {true, pos} });
        }
        gotos.clear();

        if(!blockNoNamespace) {
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

        bool isNone = true;
        Dpp_Object *func = MakeFunctionObject(id);

        struct INFOS infos = GetInfos(&_infos);

        blockNoNamespace = true;
        namespaces.push(thisNamespace);
        thisNamespace = thisNamespace->NewNamespace();
        idIt.PushIterator();
        struct VMState state;
        fObj->callstack.push(fObj->state);
        fObj->state = state;
        Dpp_CObject *ret = anycast(Dpp_CObject *, visitTheType(retType));
        Throwtable *throws = anycast(Throwtable *, visitThrowtable(throwTable));

        return_value = ret;
        noLoadVarOp = true;
        Heap<Dpp_CObject *> *params = anycast(Heap<Dpp_CObject *> *, visitParamList(_params));
        noLoadVarOp = false;
        if(block != nullptr) {
            visitBlock(block);
            isNone = false;
        }
        return_value = nullptr;

        ((FunctionObject *)func)->state = fObj->state;

        fObj->state = fObj->callstack.top();
        fObj->callstack.pop();
        idIt.PopIterator();
        thisNamespace = namespaces.top();
        namespaces.pop();
        blockNoNamespace = false;

        Dpp_CObject *co = MakeFunction(func, infos, params, func_autovalues, ret, throws, isNone);
        func_autovalues = nullptr;

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
        Heap<Dpp_CObject *> *autovalues = new Heap<Dpp_CObject *>;
        if (ctx == nullptr) return param_list;

        bool beginAutovalue = false;
        varDefineAutovalue = true;
        for (auto it : ctx->varDefine()) {
            param_list->PushEnd(anycast(Dpp_CObject *, visitVarDefine(it)));

            if (beginAutovalue && func_param_autovalue == nullptr) {
                THROW("the paramters are invalid");
            }
            if (func_param_autovalue != nullptr) beginAutovalue = true;
            autovalues->PushEnd(func_param_autovalue);
        }
        varDefineAutovalue = false;

        func_autovalues = autovalues;
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
        Dpp_CObject *to = MakeObject(id, true);
        to->type = type->object.id;
        Dpp_CObject *result = FindObject(to);
        if (result != nullptr) {
            THROW(fmt::format("{} was defined", id));
        }
        thisNamespace->objects.write(to);

        if (!noLoadVarOp) {
            LoadOpcode(OPCODE_NEW, NO_FLAG, { type->object, to->object });
            if (_data != nullptr) {
                data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
                LoadOpcode(OPCODE_MOV, NO_FLAG, { data->object, to->object });
            }
        }

        if (varDefineAutovalue) {
            if (_data != nullptr) {
                func_param_autovalue = anycast(Dpp_CObject *, (_data));
            }
        }

		return to;
	}

    /*
     * @return: NONE
     * Move the value to the variable
     */
	std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
		Dpp_CObject *o = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
		Dpp_CObject *val = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));

		LoadOpcode(OPCODE_MOV, NO_FLAG, { val->object, o->object });

		return NONE;
	}

    /*
     * @return Dpp_CObject *
     * Find a object in container
     */
    std::any visitIdEx(DXXParser::IdExContext *ctx) override {
        const auto &idex = ctx->ID();
        const std::string &_container = (*idex.begin())->toString();
        Dpp_CObject *container = FindObject(_container);
        if (container == nullptr) {
            THROW(fmt::format("cannot find object {}", _container));
        }
        Dpp_CObject *co = container;
        Object o = container->object;
        if (container == nullptr) {
            THROW(fmt::format("cannot find object {}", _container));
        }
        if (idex.size() == 1) goto END;
        if (container->type != FUNCTION_TYPE) {
            THROW(fmt::format("object {} was not a container", _container));
        }

        for (auto it = idex.begin() + 1; it != idex.end(); ++it) {
            const std::string &_method = (*it)->toString();
            Dpp_CObject *method = MakeString(_method);
            Dpp_CObject *sub = FindSubObject(container, _method);
            if (sub == nullptr) {
                THROW(fmt::format("the '{}' did not have '{}' method", co->id, _method));
            }
            Object tmp = allocMapping();

            LoadOpcode(OPCODE_METHOD, NO_FLAG, {container->object, method->object, tmp});
            o = tmp;
            container = method;
        }
    END:
        return co;
    }

    /*
     * @return: NONE
     * Create a object linked type
     */
    std::any visitTypedef(DXXParser::TypedefContext *ctx) override {
        std::string id = ctx->ID()->toString();
        Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(ctx->theType()));

        LinkObject(id, type);
        return NONE;
    }

    /*
     * @return: NONE
     * Linking the constant to the enum variable
     */
    std::any visitEnum(DXXParser::EnumContext *ctx) override {
        Dpp_CObject *enum_object = MakeObject(ctx->ID()->toString(), false, true);
        enum_object->type = CLASS_TYPE;
        Interger _idata_it = 0;

        for(auto it: ctx->enumSub()) {
            std::string id = it->ID()->toString();
            Interger _idata = _idata_it;
            antlr4::tree::TerminalNode* node = it->IntegerData();
            if (node != nullptr) {
                _idata = std::stoll(node->toString());
                _idata_it = _idata;
            }
            Dpp_CObject *idata = MakeInteger(_idata);

            Dpp_CObject *sub = LinkObject(id, idata);
            enum_object->subs.write(sub);

            ++_idata_it;
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
        Dpp_CObject *is_jmp = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));
        uint32_t jmp_pos = fObj->state.vmopcodes.size();

        LoadOpcode(OPCODE_JMP, flag, {placeholder, placeholder});// just a placeholder
        visitBlock(ctx->block());
        Object jmp_to = {true, block_end - 1};
        ResetOpcode(jmp_pos, OPCODE_JMP, flag, { jmp_to, is_jmp->object });

        return NONE;
    }

    /*
     * @return: NONE
     * The if statement opcodes
     */
    std::any visitWithIfExtends(DXXParser::WithIfExtendsContext *ctx) override {
        Heap<uint32_t> placeholders;
        char flag = NO_FLAG;
        SetBit1(flag, JMP_FALSE);

        for (auto it : ctx->withIfExtendsSub()) {
            Dpp_CObject *is_jmp = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(it->data()));

            uint32_t jmp1 = fObj->state.vmopcodes.size();

            LoadOpcode(OPCODE_JMP, flag, { placeholder, placeholder });
            visitBlock(it->block());
            Object next_block_begin = { true, (uint32_t)(fObj->state.vmopcodes.size())};
            ResetOpcode(jmp1, OPCODE_JMP, flag, {next_block_begin, is_jmp->object});
            LoadOpcode(OPCODE_JMP, flag, {placeholder, placeholder});// just a placeholder
            placeholders.PushData(fObj->state.vmopcodes.size() - 1);
        }

        for (uint32_t _placeholder : placeholders) {
            ResetOpcode(_placeholder, OPCODE_JMP, NO_FLAG, { {true, (uint32_t)fObj->state.vmopcodes.size() - 1} });
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
     */
    std::any visitWhileLoop(DXXParser::WhileLoopContext *ctx) override {
        DXXParser::BlockContext *_block = ctx->block();
        DXXParser::DataContext *_data = ctx->data();
        uint32_t state_end = fObj->state.vmopcodes.size() - 1;
        char flag = NO_FLAG;
        SetBit1(flag, JMP_FALSE);

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        if (data->type == VOID_TYPE) {
            THROW("the data type of 'while' loop must be integer");
        }

        uint32_t jmp1 = fObj->state.vmopcodes.size();
        LoadOpcode(OPCODE_JMP, flag, { placeholder, placeholder });

        in_loop = true;
        visitChildren(_block);
        // visitBlock(_block);
        in_loop = false;

        ResetOpcode(jmp1, OPCODE_JMP, flag, { {true, (uint32_t)(fObj->state.vmopcodes.size())}, data->object });
        LoadOpcode(OPCODE_JMP, NO_FLAG, { {true, state_end}});
        loop_end = fObj->state.vmopcodes.size() - 1;

        for (auto it : breaks) {
            ResetOpcode(it, OPCODE_JMP, NO_FLAG, { {true, loop_end} });
        }
        for (auto it : continues) {
            ResetOpcode(it, OPCODE_JMP, NO_FLAG, { {true, loop_end - 1} });
        }
        breaks.clear();
        continues.clear();
        loop_end = 0;

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitDoWhileLoop(DXXParser::DoWhileLoopContext *ctx) override {
        DXXParser::BlockContext *_block = ctx->block();
        DXXParser::DataContext *_data = ctx->data();
        uint32_t state_end = fObj->state.vmopcodes.size() - 1;
        char flag = NO_FLAG;
        SetBit1(flag, JMP_TRUE);

        in_loop = true;
        visitChildren(_block);
        // visitBlock(_block);
        in_loop = false;
        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));

        if (data->type == VOID_TYPE) {
            THROW("the data type of 'while' loop must be integer");
        }

        LoadOpcode(OPCODE_JMP, flag, { {true, state_end}, data->object });
        loop_end = fObj->state.vmopcodes.size() - 1;

        for (auto it : breaks) {
            ResetOpcode(it, OPCODE_JMP, NO_FLAG, { {true, loop_end} });
        }
        for (auto it : continues) {
            ResetOpcode(it, OPCODE_JMP, NO_FLAG, { {true, loop_end - 1} });
        }
        breaks.clear();
        continues.clear();
        loop_end = 0;

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitBreakExpr(DXXParser::BreakExprContext *) override {
        if (!in_loop) {
            THROW("break is not in loop");
        }

        breaks.PushData(fObj->state.vmopcodes.size());
        LoadOpcode(OPCODE_JMP, NO_FLAG, { placeholder });

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitContinueExpr(DXXParser::ContinueExprContext *) override {
        if (!in_loop) {
            THROW("continue is not in loop");
        }

        continues.PushData(fObj->state.vmopcodes.size());
        LoadOpcode(OPCODE_JMP, NO_FLAG, { placeholder });

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitReturn(DXXParser::ReturnContext *ctx) override {
        if (return_value == nullptr) {
            THROW("return must in function");
        }

        DXXParser::DataContext *_data = ctx->data();

        if (_data == nullptr) {
            if (return_value->type != VOID_TYPE) {
                THROW("no return paramter");
            }

            LoadOpcode(OPCODE_RET, NO_FLAG);
        }

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        if (data->type == VOID_TYPE) {
            THROW("return paramter cannot be void");
        }
        if (return_value->type != data->type && return_value->type != OBJECT_TYPE) {
            THROW("return paramter type is not match");
        }

        LoadOpcode(OPCODE_RET, NO_FLAG, { data->object });

        return NONE; // TODO: _ret not success
    }

    /*
     * @return: Dpp_CObject *
     * Make 'call function' opcode
     */
    std::any visitFunctionCall(DXXParser::FunctionCallContext *ctx) override {
        Dpp_CObject *func = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
        Dpp_CObject *co = MakeObject("");
        Heap<Object> params;
        Heap<Dpp_CObject *> param_list;


        if(func->type != FUNCTION_TYPE && func->infos.native_function.empty()) {
            THROW(fmt::format("cannot call '{}' because it is not a function", func->id));
        }

        if(func->isNone && func->infos.native_function.empty()) {
            THROW(fmt::format("function {} was not defined", func->id));
        }

        // TODO: the autovalue cannot be a function paramter, the code not write it
        // TODO: cannot compile no-paramter function call
        for(auto *it : ctx->callParamList()->data()) {
            Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(it));
            params.PushData(data->object);
            param_list.PushData(data);
        }

        /******************** Check the paramters ********************/
        if (!__check_call_params(func,
            _cast(Heap<Dpp_CObject *> *, func->metadata[function::FUNCTION_METADATA::PARAMS]),
            &param_list,
            _cast(Heap<Dpp_CObject *> *, func->metadata[function::FUNCTION_METADATA::AUTOVALUES]))) {
            THROW(fmt::format("'{}' has different paramters", func->id));
        }


        if(!func->infos.native_function.empty()) {
            // native function
            params.PushData(MakeString(func->id)->object);

            uint32_t i = 0;
            bool isFound = false;
            for (auto &it : fObj->modules) {
                if (it == func->infos.native_library) {
                    params.PushData({true, i});
                    isFound = true;
                    break;
                }
                ++i;
            }

            if (!isFound) {
                THROW(fmt::format("cannot find '{}' library", func->infos.native_library));
            }

            LoadOpcode(OPCODE_CALLN, NO_FLAG, params);
            return co;
        }

        params.PushData(func->object);
        LoadOpcode(OPCODE_CALL, NO_FLAG, params);
        LoadOpcode(OPCODE_GETRET, NO_FLAG, { co->object });

        return co;
    }

    forceinline bool __check_call_params(Dpp_CObject *func,
        Heap<Dpp_CObject *> *params,
        Heap<Dpp_CObject *> *call_params,
        Heap<Dpp_CObject *> *autovalues) {
        if (params->size() < call_params->size()) {
            THROW(fmt::format("too many parameters to provide in '{}'", func->id));
        }

        for (uint32_t i = 0; i < params->size(); ++i) {
            Dpp_CObject *call_arg = nullptr;
            if (call_params->size() <= i) {
                Dpp_CObject *autovalue = autovalues->GetData(i);
                if (autovalue == nullptr) {
                    THROW(fmt::format("too few parameters to provide in '{}'", func->id));
                }
                call_arg = autovalue;
            }
            else {
                call_arg = call_params->GetData(i);
            }

            Dpp_CObject *arg = params->GetData(i);
            if (call_arg->type == VOID_TYPE) {
                THROW("argument is void");
            }
            if (call_arg->type == OBJECT_TYPE && arg->type != OBJECT_TYPE) {
                MESSAGE(fmt::format("object value to not object type value maybe error"));
            }
            if (call_arg->type != arg->type && arg->type != OBJECT_TYPE) {
                // TODO: there need two types
                THROW(fmt::format("cannot convert from type to other type"));
            }
        }

        return true;
    }

    /*
     * @return: NONE
     * Make the 'goto' opcode
     */
    std::any visitGoto(DXXParser::GotoContext *ctx) override {
        const std::string &id = ctx->ID()->toString();

        gotos.insert({ id, fObj->state.vmopcodes.size() });
        LoadOpcode(OPCODE_JMP, NO_FLAG, { placeholder });

        return NONE;
    }

    /*
     * @return: Dpp_CObject *
     * Define a label of runtime opcode id
     */
    std::any visitGotoLabelDefine(DXXParser::GotoLabelDefineContext *ctx) override {
        return MakeLabel(ctx->ID()->toString(), fObj->state.vmopcodes.size() - 1);
    }

    /*
     * @return: Dpp_CObject *
     * make 'new' opcode and returns the value of object
     */
	std::any visitNew(DXXParser::NewContext *ctx) override {
		Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(ctx->theType()));
        Dpp_CObject *co = MakeObject("");

        LoadOpcode(OPCODE_NEW, NO_FLAG, { type->object, co->object });
		return co;
	}

    /*
     * @return: NONE
     * Make 'delete' opcode
     */
	std::any visitDelete(DXXParser::DeleteContext *ctx) override {
		Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));

        LoadOpcode(OPCODE_DEL, NO_FLAG, { data->object });

		return NONE;
	}

    /*
     * @return: Dpp_CObject *
     * return integer data
     */
    std::any visitIntegerExpr(DXXParser::IntegerExprContext *ctx) override {
        return MakeInteger(std::stoll(ctx->IntegerData()->toString()));
    }

    /*
     * @return: Dpp_CObject *
     * return floating number data
     */
    std::any visitFloatingExpr(DXXParser::FloatingExprContext* ctx) override {
        return MakeFloating(std::stod(ctx->FloatingNumberData()->toString()));
    }

    /*
     * @return: Dpp_CObject *
     * return string data
     */
    std::any visitStringExpr(DXXParser::StringExprContext *ctx) override {
        return MakeString(StringParse(ctx->StringData()->toString()));
    }

    /*
     * @return: Dpp_CObject *
     * return integer data of true or false
     */
    std::any visitBoolean(DXXParser::BooleanContext *ctx) override {
        return MakeInteger(ctx->True() != nullptr ? 1 : 0);
    }

    /*
     * @return: Dpp_CObject *
     * return null object
     */
    std::any visitNullExpr(DXXParser::NullExprContext *ctx) override {
        Dpp_CObject *null = nullptr;

        if ((null = FindObject("null")) == nullptr) {
            THROW("null object cannot find");
        }

        return null;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitIncDecExpr(DXXParser::IncDecExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        DXXParser::DataContext *_data = ctx->data();

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        Dpp_CObject *co = MakeObject("");

        if (data->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->PlusPlus() != nullptr) {
            op = OPCODE_ADD;
        } else if (ctx->MinusMinus() != nullptr) {
            op = OPCODE_SUB;
        }

        Dpp_CObject *int1 = MakeInteger(1);
        LoadOpcode(op, NO_FLAG, { data->object, int1->object, co->object });
        LoadOpcode(OPCODE_MOV, NO_FLAG, { co->object, data->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitNotClassExpr(DXXParser::NotClassExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));
        Dpp_CObject *co = MakeObject("");
        if(data->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->Not() != nullptr) {
            op = OPCODE_NOT;
        } else if (ctx->Tilde() != nullptr) {
            op = OPCODE_BNEG;
        }

        LoadOpcode(op, NO_FLAG, { data->object, co->object });
        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitAndandExpr(DXXParser::AndandExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }
        LoadOpcode(OPCODE_AND, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitOrorExpr(DXXParser::OrorExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }
        LoadOpcode(OPCODE_OR, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }
        LoadOpcode(OPCODE_EQ, NO_FLAG, { ldata->object, rdata->object, co->object });
        if (ctx->NotEqual() != nullptr) {
            Dpp_CObject *co2 = MakeObject("");
            LoadOpcode(OPCODE_NOT, NO_FLAG, { co->object, co2->object });
            return co2;
        }

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitStarClassExpr(DXXParser::StarClassExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->Star() != nullptr) {
            op = OPCODE_MUL;
        } else if (ctx->Div()!= nullptr) {
            op = OPCODE_DIV;
        } else if (ctx->Mod()!= nullptr) {
            op = OPCODE_MOD;
        }
        LoadOpcode(op, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitPlusClassExpr(DXXParser::PlusClassExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->Plus() != nullptr) {
            op = OPCODE_ADD;
        } else if (ctx->Minus()!= nullptr) {
            op = OPCODE_SUB;
        }
        LoadOpcode(op, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->LeftShift() != nullptr) {
            op = OPCODE_SHL;
        } else if (ctx->RightShift() != nullptr) {
            op = OPCODE_SHR;
        }
        LoadOpcode(op, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitLessClassExpr(DXXParser::LessClassExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        if (ctx->Less() != nullptr) {
            op = OPCODE_SMALLER;
            LoadOpcode(op, NO_FLAG, { ldata->object, rdata->object, co->object });
        } else if (ctx->Greater()!= nullptr) {
            op = OPCODE_BIGGER;
            LoadOpcode(op, NO_FLAG, { ldata->object, rdata->object, co->object });
        } else if (ctx->LessEqual() != nullptr) {
            Dpp_CObject *less_tmp = MakeObject("");
            Dpp_CObject *equal_tmp = MakeObject("");

            LoadOpcode(OPCODE_SMALLER, NO_FLAG, { ldata->object, rdata->object, less_tmp->object });
            LoadOpcode(OPCODE_EQ, NO_FLAG, { ldata->object, rdata->object, equal_tmp->object });
            LoadOpcode(OPCODE_OR, NO_FLAG, { less_tmp->object, equal_tmp->object, co->object });
        } else if (ctx->GreaterEqual() != nullptr) {
            Dpp_CObject *greater_tmp = MakeObject("");
            Dpp_CObject *equal_tmp = MakeObject("");

            LoadOpcode(OPCODE_BIGGER, NO_FLAG, { ldata->object, rdata->object, greater_tmp->object });
            LoadOpcode(OPCODE_EQ, NO_FLAG, { ldata->object, rdata->object, equal_tmp->object });
            LoadOpcode(OPCODE_OR, NO_FLAG, { greater_tmp->object, equal_tmp->object, co->object });
        }
        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitAndExpr(DXXParser::AndExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        LoadOpcode(OPCODE_BAND, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitCaretExpr(DXXParser::CaretExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        LoadOpcode(OPCODE_BXOR, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitOrExpr(DXXParser::OrExprContext *ctx) override {
        DXXParser::DataContext *_ldata = ctx->data(0);
        DXXParser::DataContext *_rdata = ctx->data(1);

        Dpp_CObject *ldata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_ldata));
        Dpp_CObject *rdata = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_rdata));
        Dpp_CObject *co = MakeObject("");

        if (ldata->type == VOID_TYPE || rdata->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        LoadOpcode(OPCODE_BOR, NO_FLAG, { ldata->object, rdata->object, co->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitNegative(DXXParser::NegativeContext *ctx) override {
        DXXParser::DataContext *_data = ctx->data();

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        Dpp_CObject *co = MakeObject("");
        Dpp_CObject *int_1 = MakeInteger(-1);

        if (data->type == VOID_TYPE) {
            THROW("cannot use operator on void type");
        }

        LoadOpcode(OPCODE_MUL, NO_FLAG, { data->object, int_1->object, co->object });

        return co;
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
        fObj->state.vmopcodes.PushEnd(MakeOpCode(op, flags, l));
    }

    static void LoadOpcode(rt_opcode op,
        char flags,
        Heap<Object> &params) {
        fObj->state.vmopcodes.PushEnd(MakeOpCode(op, flags, params));
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
    Dpp_CObject *MakeConst(Object o, Dpp_Object *obj,
                            bool isCheck = true, bool noWrite = false) {
        Dpp_CObject *_co = new Dpp_CObject;
        _co->object = o;
        _co->id = obj->name;
        _co->type = obj->reg->type;

        if (!obj->name.empty()) {
            globalNamespace->RemoveObject(_co);
        }

        Dpp_CObject *result = FindObject(_co);
        if(result != nullptr) {
            delete _co;
            _co = nullptr;
            idIt.DecGlobalIterator(); // Restore
            return result;
        }

        if (!noWrite) {
            fObj->obj_map.write(o, obj);
            globalNamespace->objects.write(_co);
        }
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
        obj->reg->type = STRING_TYPE;
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
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
        obj->reg->type = INT_TYPE;
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of IntegerObject
     * And Push the string constant to the object pool
     */
    Dpp_CObject* MakeFloating(FloatNum idata) {
        Object o = allocMapping(true);
        Dpp_Object* obj = mkConst<FloatObject, FloatNum>(idata);
        obj->name = std::to_string(idata);
        obj->reg->type = FLOAT_TYPE;
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of FunctionObject
     * And Push the function object to the object pool
     */
    Dpp_CObject *MakeFunction(Dpp_Object *func,
            const struct INFOS &infos,
            Heap<Dpp_CObject *> *params,
            Heap<Dpp_CObject *> *autovalues,
            Dpp_CObject *ret,
            Throwtable *throws,
            bool isNone) {
        Object o = allocMapping(true);
        Dpp_CObject *co = MakeConst(o, func, false, true);
        co->id = func->name;
        co->infos = infos;
        co->metadata[function::PARAMS] = params;
        co->metadata[function::RETURN_TYPE] = ret;
        co->metadata[function::THROW_TABLE] = throws;
        co->metadata[function::FUNCTION_METADATA::AUTOVALUES] = autovalues;
        co->type = FUNCTION_TYPE;
        co->isNone = isNone;

        Dpp_CObject *result = nullptr;

        try {
            result = FindObject(co);
        }
        catch (RetTypeNeqError &) {
            THROW(fmt::format("{} was defined", result->id));
        }

        if(result != nullptr) {
            if (!result->isNone || co->isNone) {
                THROW(fmt::format("{} was defined", result->id));
            }

            //*result = *co;
            thisNamespace->RemoveObject(result);
            thisNamespace->objects.write(co);
            co->object = result->object;
            fObj->obj_map.write(co->object, func, true);
            co->isNone = false;
            delete result;
            result = nullptr;
            return co;
        }

        if(!co->infos.native_library.empty()) fObj->modules.write(co->infos.native_library);
        fObj->obj_map.write(o, func);
        globalNamespace->objects.write(co);
        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time Object'(See at doc/compiler/compile-time-object.md) of label
     * And Push the string constant to the object pool
     */
    Dpp_CObject *MakeLabel(const std::string &_label,
            uint32_t pos) {
        uint32_t *_pos = new uint32_t;
        *_pos = pos;
        Dpp_CObject *co = MakeInteger(pos);
        Dpp_CObject *label = LinkObject(_label, co, true);
        label->metadata[label::LABEL_METADATA::POS] = _pos;

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
    Dpp_CObject *MakeObject(const std::string &id, bool noWrite = false, bool noMapping = false, bool alwaysConst = false) {
        Dpp_CObject *co = new Dpp_CObject;
        co->id = id;
        if (!noMapping) {
            co->object = allocMapping();
        }
        if(!noWrite) {
            if (alwaysConst) globalNamespace->objects.write(co);
            else thisNamespace->objects.write(co);
        }

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * link the source object and a object
     */
    Dpp_CObject *LinkObject(const std::string &id,
                            Dpp_CObject *src,
                            bool alwaysConst = false) {
        Dpp_CObject *co = MakeObject(id, false, true, alwaysConst);
        co->object = src->object;

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * link the source object and a object
     */
    Dpp_CObject *LinkConst(const std::string &id,
                            Dpp_CObject *src) {
        Dpp_CObject *co = MakeObject(id, false, true);
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
     * Find object from co->subs
     */
    static Dpp_CObject *FindSubObject(Dpp_CObject *co, const std::string &sub) {
        for (auto it : co->subs) {
            if (it->id == sub) {
                return it;
            }
        }

        return nullptr;
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
            if(it == nullptr) continue;

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

    /*
     * @return: Dpp_CObject *
     * Find a compile-time object from namespaces
     */
    Dpp_CObject *FindObject(Dpp_CObject *_co, bool onlyGlobal = false) {
        Dpp_CObject *co = FindObject(globalNamespace, _co);

        if(onlyGlobal || co != nullptr) {
            return co;
        }

        return FindObject(thisNamespace, _co);
    }

    static Dpp_CObject *FindObject(Namespace *ns, Dpp_CObject *co) {

        for(auto it: ns->objects) {
            if (it == nullptr) continue;

            if(*it == co) {
                return it;
            }
        }

        for(auto it: ns->parents) {
            for(auto _it: ns->objects) {
                if(_it == nullptr) continue;

                if(*_it == co) {
                    return _it;
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
                    std::string info_str = info->toString(), native_lib, native_func;
                    if(info->children.size() > 1) {
                        DXXParser::NativeContext *native_ctx = _cast(DXXParser::NativeContext *, info);
                        info_str = native_ctx->Native()->toString();

                        native_lib = SpiltQuote(native_ctx->StringData(0)->toString());
                        native_func = SpiltQuote(native_ctx->StringData(1)->toString());
                    }
                    infos |= GetInfoFromID(info_str, native_lib, native_func);
                }
            }
        }

        return infos;
	}

    static struct INFOS GetInfoFromID(const std::string &id,
                                      const std::string &native_lib,
                                      std::string native_func) {
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
            infos.native_function = std::move(native_func);
            infos.native_library = std::string(LIB_PREFIX) + native_lib;
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

    static std::string subreplace(const std::string &resource_str, const std::string &sub_str, const std::string &new_str) {
        std::string dst_str = resource_str;
        std::string::size_type pos = 0;
        while ((pos = dst_str.find(sub_str)) != std::string::npos) {
            dst_str.replace(pos, sub_str.length(), new_str);
        }
        return dst_str;
    }

    static std::string StringParse(const std::string &s) {
        std::string tmp(SpiltQuote(s));
        tmp = subreplace(tmp, "\\\"", "\"");
        tmp = subreplace(tmp, "\\\'", "\'");
        tmp = subreplace(tmp, "\\n", "\n");
        tmp = subreplace(tmp, "\\a", "\a");
        tmp = subreplace(tmp, "\\b", "\b");
        tmp = subreplace(tmp, "\\f", "\f");
        tmp = subreplace(tmp, "\\r", "\r");
        tmp = subreplace(tmp, "\\t", "\t");

        return tmp;
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
    uint32_t loop_end; // for break and continue
    bool in_loop = false;
    Heap<uint32_t> breaks;
    Heap<uint32_t> continues;

    std::map<std::string, uint32_t> gotos;

    Dpp_CObject *return_value = nullptr;
    bool blockNoNamespace = false;
    bool noLoadVarOp = false;
    bool varDefineAutovalue = false;

    Dpp_CObject *func_param_autovalue = nullptr;
    Heap<Dpp_CObject *> *func_autovalues = nullptr;

    Object placeholder = {true, UINT_MAX};
};

#endif // !_COMPILER_H
