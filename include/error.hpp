#include "acdpp.h"
#include "struct.hpp"
#include "objects.hpp"

NAMESPACE_DPP_BEGIN

bool call_function(dpp::vm vm,
    FunctionObject *func,
    uint32_t _paramnum,
    ...);

/**
 * @brief clean the vm
 *
 * @param vm
 */
forceinline void delete_vm(dpp::vm vm) {
    acassert(vm == nullptr);

	delete vm;
	vm = nullptr;
}

template<typename T> VMError _set_error(dpp::object *err,
    T msg = nullptr) {
    VMError error;
    error.err = err;
    error.msg = msg;

    return error;
}

 forceinline VMError set_error(dpp::object *err,
     const String &msg = L"") {
     return _set_error<const String &>(err, msg);
}

forceinline VMError SetError(Dpp_Object *err,
    const wchar_t *msg = L"") {
    return _set_error<const wchar_t *>(err, msg);
}

forceinline void set_error(FObject *fObj,
    Dpp_Object *err,
    const String &msg = L"") {
    auto error = new VMError(set_error(err, msg));

    fObj->_error = error;
}

forceinline void set_error(FObject *fObj,
    Dpp_Object *err,
    const wchar_t *msg = L"") {
    auto *error = new VMError(SetError(err, msg));

    fObj->_error = error;
}

forceinline void clear_error(FObject *fObj) {
    fObj->_error = nullptr;
}

DXX_API FunctionObject *get_error_handle(Dpp_Object *obj);
DXX_API void __StdErrorHandleCatch(dpp::vm vm);
DXX_API void catch_error(FObject *fObj);

NAMESPACE_DPP_END