#include "builtin.hpp"
#include "objects.hpp"

Object Dpp_Null = { false, 0 };

Dpp_Object *Dpp_NullObject;

Dpp_Object *Dpp_BaseError;

Dpp_Object *Dpp_NullPointerError;

Dpp_Object *Dpp_DataCantOperatorError;

Dpp_Object *Dpp_TypeNotRightError;

Dpp_Object *Dpp_NoMemoryError;

Dpp_Object *Dpp_LibNoSymbolError;

Dpp_Object *newErrorObject() {
    Dpp_Object *error = NewObject<ClassObject>();
    ClassObject *_class = (ClassObject *)error;
    *_class = *(ClassObject *)Dpp_BaseError;

    return error;
}

void initBuiltin() {
    Dpp_NullObject = NewObject<ObjectObject>();

    Dpp_BaseError = NewObject<ErrorObject>();

    Dpp_NullPointerError = newErrorObject();

    Dpp_DataCantOperatorError = newErrorObject();

    Dpp_TypeNotRightError = newErrorObject();

    Dpp_NoMemoryError = newErrorObject();

    Dpp_LibNoSymbolError = newErrorObject();
}