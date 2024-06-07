#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <stdint.h>

#include "struct.hpp"
#include "objects.hpp"
#include "builtin.symbols.hpp"

enum BUILTIN : unsigned char {
    BUILTIN_NULL = 0,
    BUILTIN_NULLPOINTER_ERROR, /* NullPointerError */

    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    OBJECT_TYPE,

    BUILTIN_END // the builtin list end
};

/*
  Dpp_NullObject malloc must be used,
  if not, when null is accessed,
  it may cause segfault
*/


Dpp_Object *newErrorObject();

void initBuiltin();

#endif // !_DXX_BUILTIN_H