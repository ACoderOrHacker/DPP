#include "builtin.hpp"
#include "objects.hpp"
#include "struct.hpp"

Object Dpp_Null = { false, 0 };

DXX_API dpp::object *Dpp_NullObject;

DXX_API dpp::object *Dpp_BaseError;

DXX_API dpp::object *Dpp_NullPointerError;

DXX_API dpp::object *Dpp_DataCantOperatorError;

DXX_API dpp::object *Dpp_TypeNotRightError;

DXX_API dpp::object *Dpp_NoMemoryError;

DXX_API dpp::object *Dpp_LibNoSymbolError;

DXX_API dpp::object *Dpp_DivideZeroError;

dpp::object *newErrorObject() {
    dpp::object *error = dpp::new_object<ErrorObject>();

    return error;
}

void initBuiltin() {
    Dpp_NullObject = new dpp::object;

    Dpp_BaseError = dpp::new_object<ClassObject>();

    Dpp_NullPointerError = newErrorObject();

    Dpp_DataCantOperatorError = newErrorObject();

    Dpp_TypeNotRightError = newErrorObject();

    Dpp_NoMemoryError = newErrorObject();

    Dpp_LibNoSymbolError = newErrorObject();

    Dpp_DivideZeroError = newErrorObject();
}