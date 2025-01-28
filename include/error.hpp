/**
 * @file error.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines errors catch and throw interfaces
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "acdpp.h"
#include "struct.hpp"
#include "objects.hpp"

NAMESPACE_DPP_BEGIN

bool call_function(dpp::vm vm,
    FunctionObject *func,
    uint32_t _paramnum,
    ...);

/**
 * @brief clean the vitrual machine
 *
 * @param vm the vm instance
 */
forceinline void delete_vm(dpp::vm vm) {
    acassert(vm == nullptr);

	delete vm;
	vm = nullptr;
}

/**
 * @brief create a new error
 * 
 * @tparam T the type of message
 * @param err the error object
 * @param msg the message of the error
 * @return VMError the error instance in virtual machine
 */
template<typename T> VMError _set_error(dpp::object *err,
    T msg = nullptr) {
    VMError error;
    error.err = err;
    error.msg = msg;

    return error;
}

/**
 * @brief create a new error
 * 
 * @param err the error object
 * @param msg the message of the error
 * @return VMError the error instance in virtual machine
 */
 forceinline VMError set_error(dpp::object *err,
     const String &msg = L"") {
     return _set_error<const String &>(err, msg);
}

/**
 * @brief create a new error
 * 
 * @param err the error object
 * @param msg the message of the error
 * @return VMError the error instance in virtual machine
 */
forceinline VMError SetError(Dpp_Object *err,
    const wchar_t *msg = L"") {
    return _set_error<const wchar_t *>(err, msg);
}

/**
 * @brief create a new error
 * 
 * @param err the error object
 * @param msg the message of the error
 * @return VMError the error instance in virtual machine
 */
forceinline void set_error(FObject *fObj,
    Dpp_Object *err,
    const String &msg = L"") {
    auto error = new VMError(set_error(err, msg));

    fObj->_error = error;
}

/**
 * @brief create a new error
 * 
 * @param err the error object
 * @param msg the message of the error
 * @return VMError the error instance in virtual machine
 */
forceinline void set_error(FObject *fObj,
    Dpp_Object *err,
    const wchar_t *msg = L"") {
    auto *error = new VMError(SetError(err, msg));

    fObj->_error = error;
}

/**
 * @brief clear the error in virtual machine
 * 
 * @param vm the virtual machine
 * @return void
 */
forceinline void clear_error(dpp::vm vm) {
    vm->_error = nullptr;
}

/**
 * @brief get the top error handle in object
 * 
 * @param obj the error object
 * @return FunctionObject * the error handle
 */
DXX_API FunctionObject *get_error_handle(dpp::object *obj);

/**
 * @brief the standard error handle in virtual machine, when the error has no handle, it will be called
 * 
 * @param vm the virtual machine
 * @return void
 */
DXX_API void __StdErrorHandleCatch(dpp::vm vm);

/**
 * @brief catch the error in virtual machine
 * 
 * @param vm the virtual machine
 * @return void
 */
DXX_API void catch_error(dpp::vm vm);

NAMESPACE_DPP_END