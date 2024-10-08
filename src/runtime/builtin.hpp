#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <cstdint>

#include "struct.hpp"

enum BUILTIN : uint32_t {
    BUILTIN_NULL = 0,
    BUILTIN_NULLPOINTER_ERROR, /* NullPointerError */
    BUILTIN_OUT, // 'out' function in builtin
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    CLASS_TYPE,
    ERROR_TYPE,
    FUNCTION_TYPE,

    BUILTIN_END // the builtin list end
};

/*
  Dpp_NullObject malloc must be used,
  if not, when null is accessed,
  it may cause segfault
*/


Dpp_Object *newErrorObject();

void initBuiltin();

extern Object Dpp_Null;

extern DXX_API Dpp_Object *Dpp_NullObject;

extern DXX_API Dpp_Object *Dpp_BaseError;

extern DXX_API Dpp_Object *Dpp_NullPointerError;

extern DXX_API Dpp_Object *Dpp_DataCantOperatorError;

extern DXX_API Dpp_Object *Dpp_TypeNotRightError;

extern DXX_API Dpp_Object *Dpp_NoMemoryError;

extern DXX_API Dpp_Object *Dpp_LibNoSymbolError;

#endif // !_DXX_BUILTIN_H