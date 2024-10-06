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

dpp::object *newErrorObject(const std::string &id) {
    dpp::object *error = dpp::new_object<ErrorObject>();
	error->name = id;

    return error;
}

void initBuiltin() {
    Dpp_NullObject = new dpp::object;

    Dpp_BaseError = newErrorObject("BaseError");

    Dpp_NullPointerError = newErrorObject("NullPointerError");

    Dpp_DataCantOperatorError = newErrorObject("NoOperatorError");

    Dpp_TypeNotRightError = newErrorObject("TypeNotRightError");

    Dpp_NoMemoryError = newErrorObject("NoMemoryError");

    Dpp_LibNoSymbolError = newErrorObject("NoSymbolError");

    Dpp_DivideZeroError = newErrorObject("DivideZeroError");
}