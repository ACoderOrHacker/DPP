#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <stdint.h>

#include "struct.h"
#include "objects.h"

enum BUILTIN : unsigned char {
	BUILTIN_NULL = 0,
	BUILTIN_NULLPOINTER_ERROR, /* NullPointerError */
	
	BUILTIN_END // the builtin list end
};

/*
  Dpp_NullObject malloc must be used, 
  if not, when null is accessed, 
  it may cause segfault  
*/

Object Dpp_Null = { false, 0 };

Dpp_Object *Dpp_NullObject;

Dpp_Object *Dpp_BaseError;

Dpp_Object *Dpp_NullPointerError;

Dpp_Object *Dpp_DataCantOperatorError;

Dpp_Object *newErrorObject() {
	Dpp_Object *error = NewObject<ClassObject>();
	((ErrorObject *)error)->header = *(ClassObject *)Dpp_BaseError;

	return error;
}

void initBuiltin() {
	Dpp_NullObject = NewObject<ObjectObject>();

	Dpp_BaseError = NewObject<ErrorObject>();

	Dpp_NullPointerError = newErrorObject();

	Dpp_DataCantOperatorError = newErrorObject();
}

#endif // !_DXX_BUILTIN_H