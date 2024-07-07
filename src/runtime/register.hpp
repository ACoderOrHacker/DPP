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
#include <typeinfo>
#include "struct.hpp"
#include "objects.hpp"
#include "builtin.hpp"

#define IS_TYPE_EQUAL(type1, type2) (type1 == type2)

// This file is used to register the function with type

#define ADD_MACRO(add_lval, ret_object, ret_type, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = add_lval + _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(val);
#define SUB_MACRO(sub_lval, ret_object, ret_type, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = sub_lval - _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(val);
#define MUL_MACRO(mul_lval, ret_object, ret_type, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = mul_lval * _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(val);
#define DIV_MACRO(div_lval, ret_object, ret_type, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = div_lval / _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(val);
#define MOD_MACRO(mod_lval, ret_object, ret_type, rvaltype, rvalobject) rvaltype _rval = GetObjectData<rvalobject, rvaltype>(rval); \
                                                                                ret_type val = mod_lval % _rval;                            \
                                                                                rtn = mkConst<ret_object, ret_type>(val);

struct _LinkType;

DXX_API RegType GetReg(const std::type_info &type);

// this function only can get the standard types
template<typename T, typename VAL_T> Dpp_Object *mkConst(VAL_T val) {
    Dpp_Object *ret = NewObject<T>();
    SetObject<T, VAL_T>(ret, val);
    auto reg = GetReg(typeid(VAL_T));

    ret->reg = &reg;
    return ret;
}

DXX_API Dpp_Object *mkFunction(std::string id);

template<typename T, typename VAL_T> Dpp_Object *mkConstEx(FObject *fObj, uint8_t typeval, VAL_T val) {
    RegType *type = fObj->obj_map.get({ 0, typeval })->reg;
    Dpp_Object *ret = NewObject(type->size);
    SetObject<T, VAL_T>(ret, val);
    ret->reg->type = typeval;
    ret->reg = type;
    return ret;
}

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
inline void RegSet(Dpp_Object *obj, RegType *reg);

Dpp_Object *StdBigger(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdSmaller(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdEqual(Dpp_Object *lval, Dpp_Object *rval);
Dpp_Object *StdNot(Dpp_Object *val);

#endif // !REGISTER

