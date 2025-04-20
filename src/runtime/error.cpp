#include "error.hpp"

#include <cstdarg>
#include <cstdlib>
#include <iostream>

#include "fmt.h"
#include "objects.hpp"
#include "struct.hpp"

bool dpp::call_function(dpp::vm vm, FunctionObject *func, uint32_t _paramnum,
                        ...) {
    va_list l;
    va_start(l, _paramnum);
    uint32_t paramnum = _paramnum;

    ::VMState jmp_state = func->state;
    vm->obj_map.create_mapping();

    // Save the last state
    ::VMState state = vm->state;
    vm->callstack.push(state);
    vm->state = jmp_state;
    vm->state.runat = 0;

    while (_paramnum > 0) {
        vm->obj_map.write({false, (int32_t)(paramnum - _paramnum)},
                          va_arg(l, Dpp_Object *));

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
DXX_API FunctionObject *dpp::get_error_handle(dpp::object *obj) {
    acassert(!dpp::is_error(obj));

    if (((ErrorObject *)obj)->handles.empty()) {
        return nullptr;  // standard handle
    }
    return ((ErrorObject *)obj)->handles.top();
}

DXX_API void dpp::__StdErrorHandleCatch(dpp::vm vm) {
    acassert(vm == nullptr);

    auto callstack = vm->callstack;

    callstack.push(vm->state);

    fmt::print_error(vm->_error->err->name, ": ", vm->_error->msg, "\n");
    while (callstack.size() > 0) {
        auto &state = callstack.top();
        const dpp::bytecode &code = state.vmopcodes.GetData(state.runat);
        vm->log << "  -> " << state.funcname << " (" << state.file << ":"
                << code.get_op().line << ", " << code.get_op().pos << ")"
                << "\n";
        callstack.pop();
    }

    exit(EXIT_FAILURE);
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
    String &msg = vm->_error->msg;

    acassert(!dpp::is_error(error));

    if (error == nullptr) {
        return;  // no error
    }

    FunctionObject *handle = dpp::get_error_handle(error);
    // We need not to check

    if (handle == nullptr) {
        // standard handle
        __StdErrorHandleCatch(vm);
    } else {
        dpp::call_function(vm, handle, 2, (vm->_error->err),
                           dpp::make_string(msg));
    }

    dpp::clear_error(vm);
}
