/*
MIT License

Copyright (c) 2023 ACoderOrHacker

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef REGISTER
#define REGISTER

#include <iostream>
#include "struct.h"
#include "objects.h"

#define IS_TYPE_EQUAL(type1, type2) (type1 == type2)
#define INT_TYPE 0
#define FLOAT_TYPE 1
#define STRING_TYPE 2
#define OBJECT_TYPE 3

// This file is used to register the function with type

#define ADD_MACRO(add_lval, ret_object, ret_type, ret_id, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = add_lval + _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(ret_id, val);
#define SUB_MACRO(sub_lval, ret_object, ret_type, ret_id, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = sub_lval - _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(ret_id, val);
#define MUL_MACRO(mul_lval, ret_object, ret_type, ret_id, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = mul_lval * _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(ret_id, val);
#define DIV_MACRO(div_lval, ret_object, ret_type, ret_id, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = div_lval / _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(ret_id, val);
#define MOD_MACRO(mod_lval, ret_object, ret_type, ret_id, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = mod_lval % _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(ret_id, val);

struct _LinkType;

RegType GetReg(uint8_t type);
template<typename T, typename VAL_T> Dpp_Object *mkConst(uint8_t typeval, VAL_T val);

// for interger
Dpp_Object *IntAdd(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntSub(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntMul(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntDiv(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntMod(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntShl(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntShr(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntBand(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntBor(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntBxor(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *IntBneg(Dpp_Object *val);
bool IntPrint(Dpp_Object *print_obj);

// for floating number
Dpp_Object *FloatAdd(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *FloatSub(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *FloatMul(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *FloatDiv(Dpp_Object *lval, Dpp_Object *rval);
bool FloatPrint(Dpp_Object *print_obj);

// for string
Dpp_Object *StringAdd(Dpp_Object *lval, Dpp_Object *rval);
bool StringPrint(Dpp_Object *print_obj);

void RegInit(FObject *fObj);
inline void RegSet(Dpp_Object *obj, RegType reg);

Dpp_Object *StdBigger(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdSmaller(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdEqual(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdNot(Dpp_Object *val);

#endif // !REGISTER

