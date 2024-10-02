#include <iostream>
#include "dpp/api.h"
#include "objects.hpp"
#include "error.hpp"

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
