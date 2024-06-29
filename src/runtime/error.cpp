#include "error.hpp"

bool isError(Dpp_Object *obj) {
    return (obj->reg->type == ERROR_TYPE);
}

bool isFunction(Dpp_Object *obj) {
    return (obj->reg->type == FUNCTION_TYPE);
}

DXX_API FunctionObject *getErrorHandle(Dpp_Object *obj) {
    if (!isError(obj)) {
        return nullptr;
    }

    if (((ErrorObject *)obj)->handles.size() == 0) {
        return nullptr; // standard handle
    }
    return ((ErrorObject *)obj)->handles.top();
}

DXX_API void __StdErrorHandleCatch(FObject *fObj) {
    std::wcout << L"An error throwed\n";
    std::wcout << L"    ";
    // TODO: The function not finish

    EnvClean(fObj);
    exit(1);
}

DXX_API void CatchError(FObject *fObj) {
    Dpp_Object *error = fObj->_error->err;
    std::wstring &msg = fObj->_error->msg;

    if (error == nullptr || !isError(error)) {
        return;
    }

    FunctionObject *handle = getErrorHandle(error);
    // We need not to check

    if (handle == nullptr) {
        // standard handle
        __StdErrorHandleCatch(fObj);
    } else {
        CallFunction(fObj, handle, 2, (fObj->_error->err), mkConst<StringObject, String>(msg));
    }

    ClearError(fObj);
}


