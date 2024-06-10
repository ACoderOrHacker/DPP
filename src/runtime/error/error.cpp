#include "error.h"

bool isError(Dpp_Object *obj) {
    return (obj->reg->type == ERROR_TYPE);
}

bool isFunction(Dpp_Object *obj) {
    return (obj->reg->type == FUNCTION_TYPE);
}

FunctionObject *getErrorHandle(Dpp_Object *obj) {
    if (!isError(obj)) {
        return nullptr;
    }

    if (((ErrorObject *)obj)->handles.size() == 0) {
        return nullptr; // standard handle
    }
    return ((ErrorObject *)obj)->handles.top();
}

void __StdErrorHandleCatch(FObject *fObj) {
    std::wcout << L"An error throwed\n";
    std::wcout << L"    ";

    EnvClean(fObj);
    exit(1);
}

#define err (fObj->_error->err)
#define msg (fObj-_error->msg)
void CatchError(FObject *fObj) {
    if (err == nullptr || !isError(err)) {
        return;
    }

    
    FunctionObject *handle = getErrorHandle(err);
    // We need not to check

    if (handle == nullptr) {
        // standard handle
        __StdErrorHandleCatch(fObj);
    } else {
        CallFunction(fobj, handle, 2, err, mkConst<StringObject, String>(msg));
    }

    ClearError(fObj);
}
#undef err
#undef msg

