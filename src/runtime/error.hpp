#include "acdpp.h"
#include "struct.hpp"
#include "stdrt.hpp"
#include "builtin.hpp"

template<typename T> VMError _SetError(Dpp_Object *err,
    T msg = nullptr) {
    VMError error;
    error.err = err;
    error.msg = msg;

    return error;
}

 forceinline VMError SetError(Dpp_Object *err,
     const String &msg = L"") {
     return _SetError<const String &>(err, msg);
}

forceinline VMError SetError(Dpp_Object *err,
    const wchar_t *msg = L"") {
    return _SetError<const wchar_t *>(err, msg);
}

forceinline void SetError(FObject *fObj,
    Dpp_Object *err,
    const String &msg = L"") {
    auto error = SetError(err, msg);

    fObj->_error = &error;
}

forceinline void SetError(FObject *fObj,
    Dpp_Object *err,
    const wchar_t *msg = L"") {
    auto error = SetError(err, msg);

    fObj->_error = &error;
}

forceinline void ClearError(FObject *fObj) {
    fObj->_error = nullptr;
}

DXX_API void __StdErrorHandleCatch(FObject *fObj);
DXX_API void CatchError(FObject *fObj);

