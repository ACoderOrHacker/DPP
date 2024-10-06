#include <iostream>
#include "objects.hpp"
#include "error.hpp"

bool dpp::call_function(dpp::vm vm,
    FunctionObject *func,
    uint32_t _paramnum,
    ...) {
    va_list l;
    va_start(l, _paramnum);
    uint32_t paramnum = _paramnum;

    uint32_t create_frame = vm->obj_map.getLastCreateID();
    ::VMState jmp_state = func->state;
    vm->obj_map.create_mapping(create_frame, jmp_state.isLambda);

    // Save the last state
    ::VMState state = vm->state;
    vm->callstack.push(state);
    vm->state = jmp_state;
    vm->state.runat = 0;

    while (_paramnum > 0) {
        vm->obj_map.write({false, paramnum - _paramnum}, va_arg(l, Dpp_Object *));

        --paramnum;
    }

    return true;
}

/**
 * @brief Get the error handle
 *
 * @param obj
 * @return FunctionObject *
 */
DXX_API FunctionObject *dpp::get_error_handle(Dpp_Object *obj) {
    acassert(!dpp::is_error(obj));

    if (((ErrorObject *)obj)->handles.empty()) {
        return nullptr; // standard handle
    }
    return ((ErrorObject *)obj)->handles.top();
}

DXX_API void dpp::__StdErrorHandleCatch(dpp::vm vm) {
    acassert(vm == nullptr);

    std::wcout << L"An error throwed\n";
    std::wcout << L"    ";
    // TODO: The function not finish

    dpp::delete_vm(vm);
    exit(1);
}

/**
 * @brief catch error from vm
 *
 * @param vm
 * @return DXX_API
 */
DXX_API void dpp::catch_error(dpp::vm vm) {
    acassert(vm == nullptr);

    dpp::object *error = vm->_error->err;
    std::wstring &msg = vm->_error->msg;

    acassert(!dpp::is_error(error));

    if (error == nullptr) {
        return; // no error
    }

    FunctionObject *handle = dpp::get_error_handle(error);
    // We need not to check

    if (handle == nullptr) {
        // standard handle
        __StdErrorHandleCatch(vm);
    } else {
        dpp::call_function(vm, handle, 2, (vm->_error->err), dpp::make_string(msg));
    }

    dpp::clear_error(vm);
}
