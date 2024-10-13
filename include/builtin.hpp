#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <cstdint>

#include "struct.hpp"

enum BUILTIN : uint32_t {
    BUILTIN_NULL = 0,
	BUILTIN_BASE_ERROR, /* BaseError */
    BUILTIN_NULLPOINTER_ERROR, /* NullPointerError */
	BUILTIN_NO_OPERATOR_ERROR, /* NoOperatorError */
	BUILTIN_TYPE_NOT_RIGHT_ERROR, /* TypeNotRightError */
	BUILTIN_NO_MEMORY_ERROR, /* NoMemoryError */
	BUILTIN_LIB_NO_SYMBOL_ERROR, /* NoSymbolError */
	BUILTIN_DIVIDE_ZERO_ERROR, /* DivideZeroError */
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    CLASS_TYPE,
    ERROR_TYPE,
    FUNCTION_TYPE,
    TYPE_TYPE,

    BUILTIN_END // the builtin list end
};

/*
  Dpp_NullObject malloc must be used,
  if not, when null is accessed,
  it may cause segfault
*/


dpp::object *newErrorObject();

void initBuiltin();

extern Object Dpp_Null;

extern DXX_API dpp::object *Dpp_NullObject;

extern DXX_API dpp::object *Dpp_BaseError;

extern DXX_API dpp::object *Dpp_NullPointerError;

extern DXX_API dpp::object *Dpp_DataCantOperatorError;

extern DXX_API dpp::object *Dpp_TypeNotRightError;

extern DXX_API dpp::object *Dpp_NoMemoryError;

extern DXX_API dpp::object *Dpp_LibNoSymbolError;

extern DXX_API dpp::object *Dpp_DivideZeroError;

#endif // !_DXX_BUILTIN_H