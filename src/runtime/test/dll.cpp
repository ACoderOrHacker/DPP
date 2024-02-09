// this is a dll sample

#include "rt_test.hpp"
#include <iostream>

extern "C" __declspec(dllexport) Dpp_Object *__add(FObject *) {
	return mkConst<IntObject, Interger>(INT_TYPE, 1 + 2);
}
