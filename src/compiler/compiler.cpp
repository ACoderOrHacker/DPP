#include "DXXLexer.h"
#include "DXXParser.h"
#include "DXXParserBaseVisitor.h"
#include "ParserRuleContext.h"
#include "acdpp.h"
#include "builtin.hpp"
#include "dpp/api.h"
#include "macros.hpp"
#include "errors.hpp"
#include "metadata.h"
#include "objects.hpp"
#include "struct.hpp"
#include "vm.hpp"
#include "compiler.hpp"
#include "compileinfos.h"
#include <fstream>
#include <memory>

using namespace errors;

/**
 * @brief genrated vm by compiler
 *
 */
DXX_API dpp::vm fObj = new FObject;

#define GET_LINE(ctx) ((ctx)->getStart()->getLine())
#define GET_POS(ctx) ((ctx)->getStart()->getCharPositionInLine())

/**
 * @brief report an error or warning for the given context (ctx)
 *
 */
#define REPORT(id, ...) id(GET_LINE(ctx), GET_POS(ctx), __VA_ARGS__);

/**
 * @brief report an error or warning for the given context (ctx) without arguments
 *
 */
#define REPORT_NPARAM(id) id(GET_LINE(ctx), GET_POS(ctx));

/**
 * @brief report an error or warning for the given context (ctx)
 *
 */
#define REPORT_CTX(ctx, id, ...) REPORT(id, __VA_ARGS__)

#define REPORT_CTX_NPARAM(ctx, id) REPORT_NPARAM(id)

inline std::string get_ctypeid(Dpp_CObject *co) {
    return co->type == Dpp_ObjectType ? "object" : co->type->get_typeid();
}

#include "import.h"
class DXXVisitor : public DXXParserBaseVisitor {
public:
    explicit DXXVisitor(const std::string &file, FObject *_fObj = nullptr, bool _is_output = true) {
        is_output = _is_output;
        if (!is_output) {
            dpp::switch_ostream(opts.rdbuf());
        }

        if (_fObj != nullptr) fObj = _fObj;
        else fObj = dpp::create_vm();

        loop_end = 0;
        block_end = 0;

        // init the globalNamespace
        int32_t builtin_it = 0;
        for (; builtin_it < BUILTIN_END; ++builtin_it) {
            dpp::mapid o({ true, builtin_it });
            Dpp_Object *obj = fObj->obj_map.get(o);
            Dpp_CObject *co = new Dpp_CObject;

            co->id = obj->name;
            co->object = o;
            globalNamespace->objects.write(co);
        }

        auto make_type = [&, this](const std::string &id, int32_t type_id) {
            Dpp_CObject *type = new Dpp_CObject;
            type->id = id;
            type->object = { true, type_id};
            type->type = Dpp_TypeType;
            globalNamespace->objects.write(type);
        };

        make_type("void", VOID_TYPE);
        make_type("object", OBJECT_TYPE);
        make_type("type", TYPE_TYPE);
        make_type("bool", INT_TYPE);

        fObj->files.push(file);
        fObj->obj_map.set_currentfile(file);
    }

    /**
     * @brief visit the root tree
     *
     * @param tree the AST
     * @return std::any the virtual machine
     */
    std::any visit(antlr4::tree::ParseTree *tree) override {
        reset_count();

        visitChildren(tree);

        Dpp_CObject *main = FindObject("main", true);
        if (main == nullptr) {
            W0002();
            goto RETURN;
        }
        if (main->type != Dpp_FunctionType) {
            E0006();
        }
        if (_cast(Heap<Dpp_CObject *> *, main->metadata[function::FUNCTION_METADATA::PARAMS])->size() > 0) {
            E0007();
        }
        LoadOpcode(main_context, OPCODE_CALL, {main->object});

        dpp::fmt::print(error_count, " errors found, ", warning_count, " warnings found.\n");
        if (error_count != 0) {
            exit(EXIT_FAILURE);
        }

        RETURN:
        reset_count();
        if (!is_output) {
            dpp::switch_ostream();
        }
        return fObj;
    }

    /**
     * @brief get compile-information
     *
     * @return dpp::compile_infos the compile-information
     */
    dpp::compile_infos get_compile_infos() {
        dpp::compile_infos infos {globalNamespace, idIt};
        return infos;
    }

    /**
     * @brief split the quotes
     *
     * @param s the string
     * @return std::string the splited string
     */
    forceinline static std::string SpiltQuote(const std::string &s) {
        if (s.empty()) {
            return "";
        }

        return s.substr(1, s.size() - 2);
    }

    /*
     * @brief Create a block at fObj->state
     *
     * @return std::any always NONE
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
                REPORT(E0009, id);
            }

            int32_t pos = *_cast(uint32_t *, label->metadata[label::LABEL_METADATA::POS]);
            ResetOpcode(ctx, it.second, OPCODE_JMP, { {true, pos} });
        }
        gotos.clear();

        if(!blockNoNamespace) {
            thisNamespace = namespaces.top();
            namespaces.pop();
        }

        return NONE;
    }

    std::any visitParens(DXXParser::ParensContext *ctx) override {
        return DXXParserBaseVisitor::visit(ctx->data());
    }

    /*
     * @brief create import opcodes
     *
     * @return std::any always NONE
     */
    std::any visitImportLib(DXXParser::ImportLibContext *ctx) override {
        Heap<dpp::mapid> params;

        for (auto it : ctx->idEx()->ID()) {
            Dpp_CObject *mod = MakeString(it->toString());
            params.PushData(mod->object);
        }

        LoadOpcode(ctx, OPCODE_IMPORT, params);
        return NONE;
    }

    /*
     * @brief create a full function object - has head and body
     *
     * @return std::any the function compile-time object
     */
    std::any visitFunction(DXXParser::FunctionContext *ctx) override {
        DXXParser::FunctionHeadContext *_ctx = ctx->functionHead();
        std::vector<DXXParser::InfoContext *> _infos = _ctx->info();
        std::string id = _ctx->ID()->toString();
        DXXParser::ParamListContext *_params = _ctx->paramList();
        DXXParser::TheTypeContext *retType = _ctx->theType();
        DXXParser::ThrowtableContext *throwTable = _ctx->throwtable();
        DXXParser::BlockContext *block = ctx->block();

        if (id == "main") main_context = ctx;

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

        Dpp_CObject *co = MakeFunction(ctx, func, infos, params, func_autovalues, ret, throws, isNone);
        func_autovalues = nullptr;

        return co;
    }

    std::any visitThrowtable(DXXParser::ThrowtableContext *ctx) override {
        Throwtable *throw_table = new Throwtable;
        if (ctx == nullptr) return throw_table;

        for (auto it : ctx->idEx()) {
            Dpp_CObject *co = anycast(Dpp_CObject *, visitIdEx(it));
            (*throw_table)[co->id] = co;
        }

        return throw_table;
    }

    std::any visitParamList(DXXParser::ParamListContext *ctx) override {
        Heap<Dpp_CObject *> *param_list = new Heap<Dpp_CObject *>;
        Heap<Dpp_CObject *> *autovalues = new Heap<Dpp_CObject *>;
        if (ctx == nullptr) return param_list;

        bool beginAutovalue = false;
        varDefineAutovalue = true;
        for (auto it : ctx->varDefine()) {
            param_list->PushEnd(anycast(Dpp_CObject *, visitVarDefine(it)));

            if (beginAutovalue && func_param_autovalue == nullptr) {
                REPORT_NPARAM(E0008);
            }
            if (func_param_autovalue != nullptr) beginAutovalue = true;
            autovalues->PushEnd(func_param_autovalue);
        }
        varDefineAutovalue = false;

        func_autovalues = autovalues;
        return param_list;
    }

    /*
     * @brief get the type from context
     *
     * @return std::any the type compile-time object
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

                }

                co->infos |= GetInfos(&infos);
            }
        }

        return co;
    }

	std::any visitVarDefine(DXXParser::VarDefineContext *ctx) override {
		DXXParser::TheTypeContext *_type = ctx->theType();
		std::vector<DXXParser::InfoContext *> infos = ctx->info();
		DXXParser::DataContext *_data = ctx->data();

		std::string id = ctx->ID()->toString();
		Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(_type));
		Dpp_CObject *data;
        Dpp_CObject *to = MakeObject(id, true);
        to->type = type->object == dpp::mapid({true, OBJECT_TYPE}) ? Dpp_ObjectType : fObj->obj_map.get(type->object); // TODO: may be have bug
        Dpp_CObject *result = FindObject(to);
        if (result != nullptr) {
            REPORT(E0002, id);
        }
        thisNamespace->objects.write(to);

        if (!noLoadVarOp) {
            LoadOpcode(ctx, OPCODE_NEW, { type->object, to->object });
            if (_data != nullptr) {
                data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
                LoadOpcode(ctx, OPCODE_MOV, { data->object, to->object });
            }
        }

        if (varDefineAutovalue) {
            if (_data != nullptr) {
                func_param_autovalue = anycast(Dpp_CObject *, (_data));
            }
        }

		return to;
	}

	std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
		Dpp_CObject *o = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
		Dpp_CObject *val = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));

		LoadOpcode(ctx, OPCODE_MOV, { val->object, o->object });

		return NONE;
	}

    std::any visitIdEx(DXXParser::IdExContext *ctx) override {
        const auto &idex = ctx->ID();
        const std::string &_container = (*idex.begin())->toString();
        Dpp_CObject *container = FindObject(_container);
        if (container == nullptr) {
            REPORT(E0001, _container);
        }
        Dpp_CObject *co = container;
        dpp::mapid o = container->object;
        if (idex.size() == 1) goto END;
        if (container->type != Dpp_FunctionType) {
            REPORT(E0004, _container);
        }

        for (auto it = idex.begin() + 1; it != idex.end(); ++it) {
            const std::string &_method = (*it)->toString();
            Dpp_CObject *method = MakeString(_method);
            Dpp_CObject *sub = FindSubObject(container, _method);
            if (sub == nullptr) {
                REPORT(E0005, co->id, method->id);
            }
            dpp::mapid tmp = allocMapping();

            LoadOpcode(ctx, OPCODE_METHOD, {container->object, method->object, tmp});
            o = tmp;
            container = method;
        }
    END:
        return co;
    }

    std::any visitTypedef(DXXParser::TypedefContext *ctx) override {
        std::string id = ctx->ID()->toString();
        Dpp_CObject *type = anycast(Dpp_CObject *, visitTheType(ctx->theType()));

        LinkObject(id, type);
        return NONE;
    }

    std::any visitEnum(DXXParser::EnumContext *ctx) override {
        Dpp_CObject *enum_object = MakeObject(ctx->ID()->toString(), false, true);
        enum_object->type = Dpp_ClassType;
        Integer _idata_it = 0;

        for(auto it: ctx->enumSub()) {
            std::string id = it->ID()->toString();
            Integer _idata = _idata_it;
            antlr4::tree::TerminalNode *node = it->IntegerData();
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

    /// when a {
    ///   call-a ...
    ///   call-b ...
    /// }
    /// opcode:
    /// 0  a
    /// 1  jnt(condition is a) 3  (3 -> state-sz - 1) (after visit block)
    /// 2  call-a ...
    /// 3  call-b ...
    std::any visitWhen(DXXParser::WhenContext *ctx) override {
        Dpp_CObject *is_jmp = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));
        uint32_t jmp_pos = fObj->state.vmopcodes.size();

        LoadOpcode(ctx, OPCODE_JNT, {placeholder, placeholder});
        visitBlock(ctx->block());
        dpp::mapid jmp_to = {true /* unused */, static_cast<int32_t>(block_end - 1)};
        ResetOpcode(ctx, jmp_pos, OPCODE_JNT, { jmp_to, is_jmp->object });

        return NONE;
    }

    /// when {
    ///   a -> {
    ///     call-a ...
    ///   }
    ///   b -> {
    ///     call-b ...
    ///   }
    ///   default -> {
    ///     call-c ...
    ///   }
    /// }
    /// opcode:
    /// 0  a
    /// 1  jnt(condition is a) 3 (3 -> state-sz) (after visit block-a)
    /// 2  call-a
    /// 3  jmp {when_end}
    /// 4  b
    /// 5  jnt(condition is b) 7 (7 -> state-sz) (after visit block-b)
    /// 6  call-b
    /// 7  jmp {when_end}
    /// 8 call-c
    /// {when_end} = 8 (state-sz - 1)
    std::any visitWhenExtends(DXXParser::WhenExtendsContext *ctx) override {
        Heap<uint32_t> placeholders;

        for (auto it : ctx->whenExtendsSub()) {
            Dpp_CObject *is_jmp = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(it->data()));

            uint32_t jmp1 = fObj->state.vmopcodes.size();

            LoadOpcode(it, OPCODE_JNT, { placeholder, placeholder });
            visitBlock(it->block());
            dpp::mapid next_block_begin = { true, (int32_t)(fObj->state.vmopcodes.size())};
            ResetOpcode(it, jmp1, OPCODE_JNT, {next_block_begin, is_jmp->object});
            LoadOpcode(it, OPCODE_JMP, {placeholder});
            placeholders.PushData(fObj->state.vmopcodes.size() - 1);
        }

        DXXParser::DefaultStatementContext *Default = ctx->defaultStatement();
        if (Default != nullptr) {
            visitBlock(Default->block());
        }

        for (uint32_t _placeholder : placeholders) {
            ResetOpcode(ctx, _placeholder, OPCODE_JMP, { {true, (int32_t)fObj->state.vmopcodes.size() - 1} });
        }

        return NONE;
    }

    /*
     * @return: NONE
     * Make 'switch' opcode
     */
    std::any visitWhenSwitchStatement(DXXParser::WhenSwitchStatementContext *ctx) override {
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

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        if (data->type != Dpp_IntType) {
            REPORT_NPARAM(E0014);
        }

        uint32_t jmp1 = fObj->state.vmopcodes.size();
        LoadOpcode(ctx, OPCODE_JNT, { placeholder, placeholder });

        in_loop = true;
        visitChildren(_block);
        // visitBlock(_block);
        in_loop = false;

        ResetOpcode(ctx, jmp1, OPCODE_JNT, { {true, (int32_t)(fObj->state.vmopcodes.size())}, data->object });
        LoadOpcode(ctx, OPCODE_JMP, { {true, (int32_t)state_end}});
        loop_end = fObj->state.vmopcodes.size() - 1;

        for (auto it : breaks) {
            ResetOpcode(ctx, it, OPCODE_JMP, { {true, (int32_t)loop_end} });
        }
        for (auto it : continues) {
            ResetOpcode(ctx, it, OPCODE_JMP, { {true, (int32_t)(loop_end - 1)} });
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

        in_loop = true;
        visitChildren(_block);
        // visitBlock(_block);
        in_loop = false;
        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));

        if (data->type != Dpp_IntType) {
            REPORT_NPARAM(E0014);
        }

        LoadOpcode(ctx, OPCODE_JNF, { {true, (int32_t)state_end}, data->object });
        loop_end = fObj->state.vmopcodes.size() - 1;

        for (auto it : breaks) {
            ResetOpcode(ctx, it, OPCODE_JMP, { {true, (int32_t)loop_end} });
        }
        for (auto it : continues) {
            ResetOpcode(ctx, it, OPCODE_JMP, { {true, (int32_t)(loop_end - 1)} });
        }
        breaks.clear();
        continues.clear();
        loop_end = 0;

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitBreakExpr(DXXParser::BreakExprContext *ctx) override {
        if (!in_loop) {
            REPORT_NPARAM(E0015);
        }

        breaks.PushData(fObj->state.vmopcodes.size());
        LoadOpcode(ctx, OPCODE_JMP, { placeholder });

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitContinueExpr(DXXParser::ContinueExprContext *ctx) override {
        if (!in_loop) {
            REPORT_NPARAM(E0016);
        }

        continues.PushData(fObj->state.vmopcodes.size());
        LoadOpcode(ctx, OPCODE_JMP, { placeholder });

        return NONE;
    }

    /*
     * @return: NONE
     */
    std::any visitReturn(DXXParser::ReturnContext *ctx) override {
        if (return_value == nullptr) {
            REPORT_NPARAM(E0017);
        }

        DXXParser::DataContext *_data = ctx->data();

        if (_data == nullptr) {
            if (return_value->type != Dpp_VoidType) {
                REPORT_NPARAM(E0013);
            }

            LoadOpcode(ctx, OPCODE_RET);
        }

        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(_data));
        if (data->type == Dpp_VoidType) {
            REPORT_NPARAM(E0011);
        }
        if (return_value->type != data->type && return_value->type != Dpp_ObjectType) {
            REPORT_NPARAM(E0012);
        }

        LoadOpcode(ctx, OPCODE_RET, { data->object });

        return NONE;
    }

    /*
     * @return: Dpp_CObject *
     * Make 'call function' opcode
     */
    std::any visitFunctionCall(DXXParser::FunctionCallContext *ctx) override {
        Dpp_CObject *func = anycast(Dpp_CObject *, visitIdEx(ctx->idEx()));
        Dpp_CObject *co = ((Dpp_CObject *)(func->metadata[function::FUNCTION_METADATA::RETURN_TYPE]))->object == dpp::mapid {true, VOID_TYPE} ? NONE : MakeObject("");
        Heap<dpp::mapid> params;
        Heap<Dpp_CObject *> param_list;


        if(func->type != Dpp_FunctionType && func->infos.native_function.empty()) {
            REPORT(E0018, func->id);
        }

        if(func->isNone && func->infos.native_function.empty()) {
            REPORT(E0019, func->id);
        }

        // TODO: the autovalue cannot be a function paramter, the code not write it
        // TODO: cannot compile no-paramter function call
        for(auto *it : ctx->callParamList()->data()) {
            Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(it));
            params.PushData(data->object);
            param_list.PushData(data);
        }

        /******************** Check the paramters ********************/
        auto __check_call_params = [&, ctx](Dpp_CObject *func,
            Heap<Dpp_CObject *> *params,
            Heap<Dpp_CObject *> *call_params,
            Heap<Dpp_CObject *> *autovalues) -> bool {
            if (params->size() < call_params->size()) {
                REPORT(E0022, func->id);
            }

            for (uint32_t i = 0; i < params->size(); ++i) {
                Dpp_CObject *call_arg = nullptr;
                if (call_params->size() <= i) {
                    Dpp_CObject *autovalue = autovalues->GetData(i);
                    if (autovalue == nullptr) {
                        REPORT(E0023, func->id);
                    }
                    call_arg = autovalue;
                }
                else {
                    call_arg = call_params->GetData(i);
                }

                Dpp_CObject *arg = params->GetData(i);
                if (call_arg->type == Dpp_VoidType) {
                    REPORT_NPARAM(E0024);
                }
                if (call_arg->type == Dpp_ObjectType && arg->type != Dpp_ObjectType) {
                    REPORT_NPARAM(W0001);
                }
                if (call_arg->type != arg->type && arg->type != Dpp_ObjectType) {
                    // TODO: there need two types
                    REPORT(E0025, get_ctypeid(call_arg), get_ctypeid(arg));
                }
            }

            return true;
        };

        if (!__check_call_params(func,
            _cast(Heap<Dpp_CObject *> *, func->metadata[function::FUNCTION_METADATA::PARAMS]),
            &param_list,
            _cast(Heap<Dpp_CObject *> *, func->metadata[function::FUNCTION_METADATA::AUTOVALUES]))) {
            REPORT(E0020, func->id);
        }


        if(!func->infos.native_function.empty()) {
            params.PushData(func->object);
            if (co != NONE) params.PushEnd(co->object);
            LoadOpcode(ctx, OPCODE_CALL, params);
            return co;
        }

        params.PushData(func->object);
        LoadOpcode(ctx, OPCODE_CALL, params);
        if (co != NONE) LoadOpcode(ctx, OPCODE_GETRET, { co->object });

        return co;
    }

    /*
     * @return: NONE
     * Make the 'goto' opcode
     */
    std::any visitGoto(DXXParser::GotoContext *ctx) override {
        const std::string &id = ctx->ID()->toString();

        gotos.insert({ id, fObj->state.vmopcodes.size() });
        LoadOpcode(ctx, OPCODE_JMP, { placeholder });

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

        LoadOpcode(ctx, OPCODE_NEW, { type->object, co->object });
		return co;
	}

    /*
     * @return: NONE
     * Make 'delete' opcode
     */
	std::any visitDelete(DXXParser::DeleteContext *ctx) override {
		Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));

        LoadOpcode(ctx, OPCODE_DEL, { data->object });

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
            REPORT(E0001, "null");
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
        co->type = Dpp_IntType;

        if (data->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->PlusPlus() != nullptr) {
            op = OPCODE_ADD;
        } else if (ctx->MinusMinus() != nullptr) {
            op = OPCODE_SUB;
        }

        Dpp_CObject *int1 = MakeInteger(1);
        LoadOpcode(ctx, op, { data->object, int1->object, co->object });
        LoadOpcode(ctx, OPCODE_MOV, { co->object, data->object });

        return co;
    }

    /*
     * @return: Dpp_CObject *
     */
    std::any visitNotClassExpr(DXXParser::NotClassExprContext *ctx) override {
        rt_opcode op = OPCODE_START;
        Dpp_CObject *data = anycast(Dpp_CObject *, DXXParserBaseVisitor::visit(ctx->data()));
        Dpp_CObject *co = MakeObject("");
        co->type = Dpp_IntType;

        if(data->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->Not() != nullptr) {
            op = OPCODE_NOT;
        } else if (ctx->Tilde() != nullptr) {
            op = OPCODE_BNEG;
        }

        LoadOpcode(ctx, op, { data->object, co->object });
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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }
        LoadOpcode(ctx, OPCODE_AND, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }
        LoadOpcode(ctx, OPCODE_OR, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }
        LoadOpcode(ctx, OPCODE_EQ, { ldata->object, rdata->object, co->object });
        if (ctx->NotEqual() != nullptr) {
            Dpp_CObject *co2 = MakeObject("");
            LoadOpcode(ctx, OPCODE_NOT, { co->object, co2->object });
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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->Star() != nullptr) {
            op = OPCODE_MUL;
        } else if (ctx->Div()!= nullptr) {
            op = OPCODE_DIV;
        } else if (ctx->Mod()!= nullptr) {
            op = OPCODE_MOD;
        }
        LoadOpcode(ctx, op, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->Plus() != nullptr) {
            op = OPCODE_ADD;
        } else if (ctx->Minus()!= nullptr) {
            op = OPCODE_SUB;
        }
        LoadOpcode(ctx, op, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->LeftShift() != nullptr) {
            op = OPCODE_SHL;
        } else if (ctx->RightShift() != nullptr) {
            op = OPCODE_SHR;
        }
        LoadOpcode(ctx, op, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        if (ctx->Less() != nullptr) {
            op = OPCODE_SMALLER;
            LoadOpcode(ctx, op, { ldata->object, rdata->object, co->object });
        } else if (ctx->Greater()!= nullptr) {
            op = OPCODE_BIGGER;
            LoadOpcode(ctx, op, { ldata->object, rdata->object, co->object });
        } else if (ctx->LessEqual() != nullptr) {
            Dpp_CObject *less_tmp = MakeObject("");
            Dpp_CObject *equal_tmp = MakeObject("");

            LoadOpcode(ctx, OPCODE_SMALLER, { ldata->object, rdata->object, less_tmp->object });
            LoadOpcode(ctx, OPCODE_EQ, { ldata->object, rdata->object, equal_tmp->object });
            LoadOpcode(ctx, OPCODE_OR, { less_tmp->object, equal_tmp->object, co->object });
        } else if (ctx->GreaterEqual() != nullptr) {
            Dpp_CObject *greater_tmp = MakeObject("");
            Dpp_CObject *equal_tmp = MakeObject("");

            LoadOpcode(ctx, OPCODE_BIGGER, { ldata->object, rdata->object, greater_tmp->object });
            LoadOpcode(ctx, OPCODE_EQ, { ldata->object, rdata->object, equal_tmp->object });
            LoadOpcode(ctx, OPCODE_OR, { greater_tmp->object, equal_tmp->object, co->object });
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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        LoadOpcode(ctx, OPCODE_BAND, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        LoadOpcode(ctx, OPCODE_BXOR, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (ldata->type == Dpp_VoidType || rdata->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        LoadOpcode(ctx, OPCODE_BOR, { ldata->object, rdata->object, co->object });

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
        co->type = Dpp_IntType;

        if (data->type == Dpp_VoidType) {
            REPORT_NPARAM(E0010);
        }

        LoadOpcode(ctx, OPCODE_MUL, { data->object, int_1->object, co->object });

        return co;
    }

private:
    /*
     * @return: bool
     */
    inline bool isInGlobal() { return globalNamespace == thisNamespace; }

    /*
     * @return: dpp::mapid
     * Create a dpp::mapid structure from the iterator
     */
    dpp::mapid allocMapping(bool isConst = false) {
        int32_t it = idIt.GetGlobalIterator();

        if (!(it > INT32_MIN && it < INT32_MAX)) {
            // TODO: MAY BE WE NEED A THROW
            E0026();
        }


        idIt.IncGlobalIterator();

        return dpp::mapid(isConst ? true : isInGlobal(), it);
    }

    /*
     * @return: void
     * Create a opcode and push it to main state(fObj->state)
     */
    static void LoadOpcode(antlr4::ParserRuleContext *ctx,
        rt_opcode op,
        std::initializer_list<dpp::mapid> l = {}) {
        fObj->state.vmopcodes.PushEnd(MakeOpCode(op, l, GET_LINE(ctx), GET_POS(ctx)));
    }

    static void LoadOpcode(antlr4::ParserRuleContext *ctx,
        rt_opcode op,
        Heap<dpp::mapid> &params) {
        fObj->state.vmopcodes.PushEnd(MakeOpCode(op, params, GET_LINE(ctx), GET_POS(ctx)));
    }

    /*
     * @return: void
     * Reset the opcode in the state
     */
    static void ResetOpcode(antlr4::ParserRuleContext *ctx,
        uint32_t pos,
        rt_opcode op,
        std::initializer_list<dpp::mapid> l = {}) {
        fObj->state.vmopcodes.ResetData(pos, MakeOpCode(op, l, GET_LINE(ctx), GET_POS(ctx)));
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time dpp::mapid'(See at doc/compiler/compile-time-object.md)
     * And Push the constant to the object pool
     */
    Dpp_CObject *MakeConst(dpp::mapid o, Dpp_Object *obj,
                            bool isCheck = true, bool noWrite = false) {
        Dpp_CObject *_co = new Dpp_CObject;
        _co->object = o;
        _co->id = obj->name;
        _co->type = obj->type.get();

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

    Dpp_CObject *MakeString(const std::string &s) {
        const String &str = s;
        dpp::mapid o = allocMapping(true);
        Dpp_Object *obj = dpp::make_string(str);
        obj->name = s;
        obj->type = create_ptr(Dpp_StringType);
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
    }

    Dpp_CObject *MakeInteger(Integer idata) {
        dpp::mapid o = allocMapping(true);
        Dpp_Object *obj = dpp::make_int(idata);
        obj->name = std::to_string(idata);
        obj->type = create_ptr(Dpp_IntType);
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
    }

    Dpp_CObject* MakeFloating(FloatNum data) {
        dpp::mapid o = allocMapping(true);
        Dpp_Object* obj = dpp::make_float(data);
        obj->name = std::to_string(data);
        obj->type = create_ptr(Dpp_FloatType);
        Dpp_CObject *co = MakeConst(o, obj);

        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time dpp::mapid'(See at doc/compiler/compile-time-object.md) of FunctionObject
     * And Push the function object to the object pool
     */
    Dpp_CObject *MakeFunction(DXXParser::FunctionContext *ctx,
            Dpp_Object *func,
            const struct INFOS &infos,
            Heap<Dpp_CObject *> *params,
            Heap<Dpp_CObject *> *autovalues,
            Dpp_CObject *ret,
            Throwtable *throws,
            bool isNone) {
        dpp::mapid o = allocMapping(true);
        Dpp_CObject *co = MakeConst(o, func, false, true);
        co->id = func->name;
        co->infos = infos;
        co->metadata[function::PARAMS] = params;
        co->metadata[function::RETURN_TYPE] = ret;
        co->metadata[function::THROW_TABLE] = throws;
        co->metadata[function::FUNCTION_METADATA::AUTOVALUES] = autovalues;
        co->type = Dpp_FunctionType;
        co->isNone = isNone;

        if (!co->infos.native_library.empty()) {
            FunctionObject *fun = dynamic_cast<FunctionObject *>(func);

            fun->function = std::make_shared<NativeFunc>();
            fun->function->is_native = true;
            fun->function->lib = co->infos.native_library;
            fun->function->func_id = co->infos.native_function;
        }

        Dpp_CObject *result = nullptr;

        try {
            result = FindObject(co);
        }
        catch (RetTypeNeqError &) {
            REPORT(E0002, result->id);
        }

        if(result != nullptr) {
            if (!result->isNone || co->isNone) {
                REPORT(E0002, result->id);
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

        fObj->obj_map.write(o, func);
        globalNamespace->objects.write(co);
        return co;
    }

    /*
     * @return: Dpp_CObject *
     * Make a 'Compile-time dpp::mapid'(See at doc/compiler/compile-time-object.md) of label
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
        Dpp_Object *func = dpp::new_object<FunctionObject>();
        func->name = id;

        return func;
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
        if(!co->object.is_global()) return nullptr;

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
            infos.native_function = native_func;
            infos.native_library = native_lib;
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
    antlr4::ParserRuleContext *main_context = nullptr;

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

    dpp::mapid placeholder;

    std::ostringstream opts;

    /// Configures
    bool is_output = true; // is output errors and verboses
};
#include "export.h"

forceinline dpp::vm _compile(antlr4::ANTLRInputStream &input,
    const std::string &file,
    bool is_output = false) {
    DXXLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    DXXParser parser(&tokens);
    DXXParser::MainContext *main = parser.main();

    DXXVisitor visitor(file, nullptr, is_output);
    FObject *fObj = anycast(FObject *, visitor.visit(main));

    return fObj;
}

NAMESPACE_DPP_BEGIN

DXX_API dpp::vm compile(const std::string &code, bool is_output) {
    antlr4::ANTLRInputStream input(code);
    return _compile(input, "<stdin>", is_output);
}

DXX_API dpp::vm compile(std::ifstream &ifs, const std::string &file, bool is_output) {
    antlr4::ANTLRInputStream input(ifs);
    return _compile(input, file, is_output);
}

DXX_API dpp::vm compile(std::fstream &ifs, const std::string &file, bool is_output) {
    antlr4::ANTLRInputStream input(dynamic_cast<std::ifstream &>(ifs));
    return _compile(input, file, is_output);
}

NAMESPACE_DPP_END
