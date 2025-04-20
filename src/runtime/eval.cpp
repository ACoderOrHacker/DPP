#include "eval.h"
#include "macros.hpp"
#include "objects/funcobj.h"
#include "objects/utils.h"
#include "struct.hpp"
#include "builtin.hpp"
#include "error.hpp"
#include "vm.hpp"

#define vmswitch switch
#define vmcase(op) case op
#define vmdefault default

/// Helper macros
#define _GET_MAPID(operand) (code.get_operand##operand())
#define GET_MAPID(operand) _GET_MAPID(operand)
#define GET_OBJECT(mapid) (vm->obj_map.get((mapid)))
#define GET(operand) (GET_OBJECT(GET_MAPID(operand)))
#define PUT(mapid, obj) do { vm->obj_map.write(mapid, obj, true); } while(0);
#define arithmetic_binary(op) \
    do { \
        dpp::object *lobj = GET(BINARY_LEFT); \
        dpp::object *robj = GET(BINARY_RIGHT); \
        dpp::mapid result = GET_MAPID(BINARY_RESULT); \
        if (lobj == Dpp_NullObject) {/* Just lobj because this operation calls lobj's function */ \
            dpp::set_error(vm, Dpp_NullPointerError, \
                Dpp_TEXT("unsupported operation(s) for " #op ": ") + \
                    dpp::get_typeid(lobj) + Dpp_TEXT(", ") + \
                    dpp::get_typeid(robj)); \
            break; \
        } \
        dpp::object *result_obj = nullptr; \
        try { \
            result_obj = *lobj op robj;\
        } catch(NoOperatorError &) { \
            dpp::set_error(vm, Dpp_DataCantOperatorError, \
                Dpp_TEXT("unsopprted operation(s) for " #op ": ") + \
                    dpp::get_typeid(lobj) + Dpp_TEXT(", ") + \
                    dpp::get_typeid(robj)); \
            break; \
        } \
        PUT(result, result_obj); \
    } while(0);

#define arithmetic_unary(op) \
    do { \
        dpp::object *obj = GET(UNARY_OPERAND); \
        dpp::mapid result = GET_MAPID(UNARY_RESULT); \
        if (obj == Dpp_NullObject) { \
            dpp::set_error(vm, Dpp_NullPointerError, \
                Dpp_TEXT("unsupported operation(s) for " #op ": ") + \
                dpp::get_typeid(obj)); \
            break; \
        } \
        dpp::object *result_obj = nullptr; \
        try { \
            result_obj = op (*obj); \
        } catch(NoOperatorError &) { \
            dpp::set_error( \
                vm, Dpp_DataCantOperatorError, \
                Dpp_TEXT("unsopprted operation(s) for " #op ": ") + dpp::get_typeid(obj)); \
            break; \
        } \
        PUT(result, result_obj); \
    } while(0);

#define JMP_POS(pos) do { vm->state.runat = (pos); } while(0);

NAMESPACE_DPP_BEGIN

DXX_API bool eval(dpp::vm vm, const dpp::bytecode &code) {
    vmswitch (code.get_op().op) {

        /// nop
        /// @details NOT DO ANYTHING
        vmcase(OPCODE_NOP):{
            break;
        }

        /// push %{0}
        /// @details push %{0} to stack
        vmcase(OPCODE_PUSH): {
            vm->RuntimeStack.push(std::make_shared<dpp::object>(*GET(UNARY_OPERAND)));
            break;
        }

        /// pop %{0}
        /// @details pop from stack and put it to %{0}
        vmcase(OPCODE_POP): {
            PUT(GET_MAPID(UNARY_OPERAND), vm->RuntimeStack.top().get());
            vm->RuntimeStack.pop();
            break;
        }

        /// import TODO: add documentation
        vmcase(OPCODE_IMPORT): {
            // TODO
            break;
        }

        /// add %{0} %{1} %{2}
        /// @details add %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_ADD): {
            arithmetic_binary(+);
            break;
        }

        /// sub %{0} %{1} %{2}
        /// @details sub %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_SUB): {
            arithmetic_binary(-);
            break;
        }

        /// mul %{0} %{1} %{2}
        /// @details mul %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_MUL): {
            arithmetic_binary(*);
            break;
        }

        /// div %{0} %{1} %{2}
        /// @details div %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_DIV): {
            try {
                arithmetic_binary(/);
            } catch (DivideZeroError &) {
                dpp::set_error(vm, Dpp_DivideZeroError, Dpp_TEXT("division by zero"));
            }
            break;
        }

        /// mod %{0} %{1} %{2}
        /// @details mod %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_MOD): {
            try {
                arithmetic_binary(%);
            } catch (DivideZeroError &) {
                dpp::set_error(vm, Dpp_DivideZeroError, Dpp_TEXT("division by zero"));
            }
            break;
        }

        /// bneg %{0} %{1}
        /// @details run bit negative %{0} and put the result to %{1}
        vmcase(OPCODE_BNEG): {
            arithmetic_unary(~);
            break;
        }

        /// band %{0} %{1} %{2}
        /// @details run bit and %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_BAND): {
            arithmetic_binary(&);
            break;
        }

        /// bor %{0} %{1} %{2}
        /// @details run bit or %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_BOR): {
            arithmetic_binary(|);
            break;
        }

        /// bxor %{0} %{1} %{2}
        /// @details run bit xor %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_BXOR): {
            arithmetic_binary(^);
            break;
        }

        /// shl %{0} %{1} %{2}
        /// @details run shift left %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_SHL): {
            arithmetic_binary(<<);
            break;
        }

        /// shr %{0} %{1} %{2}
        /// @details run shift right %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_SHR): {
            arithmetic_binary(>>);
            break;
        }

        /// not %{0} %{1}
        /// @details run not(!) %{0} and put the result to %{1}
        vmcase(OPCODE_NOT): {
            arithmetic_unary(!);
            break;
        }

        /// eq %{0} %{1} %{2}
        /// @details run equal(==) %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_EQ): {
            arithmetic_binary(==);
            break;
        }

        /// bigger %{0} %{1} %{2}
        /// @details run bigger(>) %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_BIGGER): {
            arithmetic_binary(>);
            break;
        }

        /// smaller %{0} %{1} %{2}
        /// @details run smaller(<) %{0} and %{1} and put the result to %{2}
        vmcase(OPCODE_SMALLER): {
            arithmetic_binary(<);
            break;
        }

        /// and %{0} %{1} %{2}
        /// @details get a boolean value of (%{0} && %{1}) and put the result to %{2}
        vmcase(OPCODE_AND): {
            dpp::object *lobj = GET(BINARY_LEFT);
            dpp::object *robj = GET(BINARY_RIGHT);
            dpp::mapid result = GET_MAPID(BINARY_RESULT);

            dpp::object *result_obj = dpp::make_bool(dpp::is_true(lobj) && dpp::is_true(robj));

            PUT(result, result_obj);
            break;
        }

        /// or %{0} %{1} %{2}
        /// @details get a boolean value of (%{0} || %{1}) and put the result to %{2}
        vmcase(OPCODE_OR): {
            dpp::object *lobj = GET(BINARY_LEFT);
            dpp::object *robj = GET(BINARY_RIGHT);
            dpp::mapid result = GET_MAPID(BINARY_RESULT);

            dpp::object *result_obj = dpp::make_bool(dpp::is_true(lobj) || dpp::is_true(robj));

            PUT(result, result_obj);
            break;
        }

        /// jnt %{0} %{1}
        /// @details jump to %{0} if %{1} is not true
        vmcase(OPCODE_JNT): { // jmp if not true
            uint32_t jmpto = GET_MAPID(JMP_POSITION).as_number(); // the position to jump to

            try {
                if (!dpp::is_true(GET(JMP_CONDITION))) {
                    JMP_POS(jmpto);
                }
            } catch(NoOperatorError &) {
                dpp::set_error(vm, Dpp_DataCantOperatorError,
                    Dpp_TEXT("invaild bool object"));
            }
            break;
        }

        /// jnf %{0} %{1}
        /// @details jump to %{0} if %{1} is true
        vmcase(OPCODE_JNF): { // jmp if true
            uint32_t jmpto = GET_MAPID(JMP_POSITION).as_number(); // the position to jump to

            try {
                if (dpp::is_true(GET(JMP_CONDITION))) {
                    JMP_POS(jmpto);
                }
            } catch(NoOperatorError &) {
                dpp::set_error(vm, Dpp_DataCantOperatorError,
                    Dpp_TEXT("invaild bool object"));
            }
            break;
        }

        /// jmp %{0}
        /// @details jump to %{0}
        vmcase(OPCODE_JMP): {
            JMP_POS(GET_MAPID(JMP_POSITION).as_number());
            break;
        }

        /// call %{0} %{1}?
        /// @details call %{0}. If it is a native, then put the result to %{1} 
        vmcase(OPCODE_CALL): {
            dpp::object *obj = GET(UNARY_OPERAND);

            if (!dpp::is_function(obj)) {
                dpp::set_error(
                    vm, Dpp_TypeNotRightError,
                    Dpp_TEXT("cannot call ") + dpp::get_typeid(obj) + " type"
                );
                break;
            }

            FunctionObject *func = (FunctionObject *)obj;

            // if is native
            if (func->function != nullptr && func->function->is_native) {
                // the function is native function
                const auto &it = vm->libraries.find(func->function->lib);

                try {
                    if (it != vm->libraries.end()) {
                        func->function->native_func =
                            (*it).second.get_function<dpp::object *(dpp::vm)>(
                                func->function->func_id);
                    } else {
                        std::filesystem::path lib_pth = vm->module_searcher.search(
                            dylib::decoration(func->function->lib));
                        dylib lib(lib_pth);
                        func->function->native_func =
                            lib.get_function<dpp::object *(dpp::vm)>(
                                func->function->func_id);
                        vm->libraries.insert(std::make_pair(func->function->lib, lib));
                    }
                } catch (dylib::exception &e) {
                    dpp::set_error(vm, Dpp_LibNoSymbolError, e.what());
                    break;
                } catch (dpp::ModuleNotFoundError &e) {
                    dpp::set_error(vm, Dpp_ModuleNotFoundError, e.what());
                    break;
                }

                dpp::object *ret = func->function->native_func(vm);
                if (ret != nullptr) {
                    dpp::mapid result = GET_MAPID(UNARY_RESULT);
                    PUT(result, ret);
                }

                break;
            }
    
            // for normal function
            vm->obj_map.create_mapping();
            vm->callstack.push(vm->state);
            vm->state = func->state;
            vm->state.funcname = func->name;
            vm->state.runat = -1;
            break;
        }

        /// ret
        /// @details return from the current function
        vmcase(OPCODE_RET): {
            exit_frame(vm);
            break;
        }

        /// new %{0} %{1}
        /// @details create a new object of %{0} and put it to %{1}
        vmcase(OPCODE_NEW): {
            dpp::object *type = GET(UNARY_OPERAND);
            dpp::mapid result = GET_MAPID(UNARY_RESULT);

            dpp::object *result_obj = nullptr;
            try {
                result_obj = type->new_object();
            } catch (std::bad_alloc &) {
                dpp::set_error(vm, Dpp_NoMemoryError,
                            Dpp_TEXT("no memory to create a new object"));
                break;
            }

            PUT(result, result_obj);
            break;
        }

        /// del %{0}
        /// @details delete %{0} object
        vmcase(OPCODE_DEL): {
            // TODO
            break;
        }

        /// mov %{0} %{1}
        /// @details move %{0} to %{1}
        vmcase(OPCODE_MOV): {
            dpp::object *src = GET(UNARY_OPERAND);
            dpp::mapid dst = GET_MAPID(UNARY_RESULT);

            dpp::object *dst_object = GET_OBJECT(dst);

            if (dst_object == Dpp_NullObject) {
                dpp::set_error(vm, Dpp_NullPointerError,
                    Dpp_TEXT("cannot move a object to null"));
                break;
            }

            dpp::object *status = src->move(dst_object);
            if (status == nullptr) {
                // failed
                dpp::set_error(vm, Dpp_TypeNotRightError,
                            Dpp_TEXT("cannot move from ") + dpp::get_typeid(src) +
                                " type to " + dpp::get_typeid(dst_object) + " type");
            }

            PUT(dst, status);
            break;
        }

        /// method %{0} %{1} %{2}
        /// @details get %{1} object from %{0} and put it to %{2}
        vmcase(OPCODE_METHOD): {
            dpp::object *container = GET(BINARY_LEFT);
            dpp::object *method = GET(BINARY_RIGHT);
            dpp::mapid result = GET_MAPID(BINARY_RESULT);

            if (container == Dpp_NullObject) {
                dpp::set_error(vm, Dpp_NullPointerError,
                               Dpp_TEXT("cannot call method on null object"));
                break;
            }

            if (dpp::is_string(method)) {
                String method_name = dpp::get_string(method);
        
                dpp::object *it_container = container;
                dpp::object *found_method = nullptr;
        
                // instance havs a type, and the type's type is Dpp_TypeType,
                // Dpp_TypeType's type is itself
                while (it_container != Dpp_TypeType) {
                    const auto &it = container->methods.find(method_name);
                    if (it != container->methods.end()) {
                        // found it
                        found_method = it->second.get();
                    }
        
                    it_container = it_container->type.get();
                }
        
                if (found_method == nullptr) {
                    dpp::set_error(
                        vm, Dpp_NoMethodError,
                        Dpp_TEXT("method '") + method_name + Dpp_TEXT("' not found"));
                    break;
                }
        
                PUT(result, found_method);
            } else {
                dpp::set_error(vm, Dpp_TypeNotRightError,
                               Dpp_TEXT("method name must be a string"));
                break;
            }
            break;
        }

        // unknown opcodes
        vmcase(OPCODE_START): // just a placeholder
        vmcase(OPCODE_END): // just a placeholder
        vmdefault:
            throw InternalError("unknown opcode '" + std::to_string(code.get_op().op) + "'");
    }

    if (vm->_error == nullptr) { return EVAL_SUCCESS; }

    return EVAL_FAILED;
}

NAMESPACE_DPP_END