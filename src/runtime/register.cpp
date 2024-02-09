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

#include "register.h"

struct RegType IntType;
struct RegType FloatType;
struct RegType StringType;
class NoType{};

struct _LinkType {
	RegType reg;
};

RegType GetReg(uint8_t type) {
	switch (type) {
	case INT_TYPE:
		return IntType;
	case FLOAT_TYPE:
		return FloatType;
	case STRING_TYPE:
		return StringType;
	default:
		throw NoType();
	}
}

// this function only can get the standard types
template<typename T, typename VAL_T> Dpp_Object *mkConst(uint8_t typeval, VAL_T val) {
	Dpp_Object *ret = NewObject<T>();
	SetObject<T, VAL_T>(ret, val);
	ret->is_const = true;
	ret->type_val = typeval;
	ret->reg = GetReg(typeval);
	return ret;
}

template<typename T, typename VAL_T> Dpp_Object *mkConstEx(FObject *fObj, uint8_t typeval, VAL_T val) {
	RegType type = fObj->types[typeval];
	Dpp_Object *ret = NewObject(type.size);
	SetObject<T, VAL_T>(ret, val);
	ret->is_const = true;
	ret->type_val = typeval;
	ret->reg = type;
	return ret;
}

Dpp_Object *IntAdd(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		ADD_MACRO(ll_lval, IntObject, Interger, INT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		ADD_MACRO(ll_lval, FloatObject, FloatNum, FLOAT_TYPE, Interger, IntObject)
	}
	return rtn;
}

Dpp_Object *IntSub(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		SUB_MACRO(ll_lval, IntObject, Interger, INT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		SUB_MACRO(ll_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntMul(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MUL_MACRO(ll_lval, IntObject, Interger, INT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		MUL_MACRO(ll_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntDiv(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		DIV_MACRO(ll_lval, IntObject, Interger, INT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		DIV_MACRO(ll_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntMod(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MOD_MACRO(ll_lval, IntObject, Interger, INT_TYPE, Interger, IntObject)
	}
	return rtn;
}

Dpp_Object *IntShl(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ll_lval << GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntShr(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ll_lval >> GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBand(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ll_lval & GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBor(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ll_lval | GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBxor(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ll_lval ^ GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBneg(Dpp_Object *val) {
	
	Dpp_Object *rtn = nullptr;
	
	uint8_t type = GetObjectType(val);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(INT_TYPE, ~ GetObjectData<IntObject, Interger>(val));
	}
	return rtn;
	
}

bool IntPrint(Dpp_Object *print_obj) {
	if(IS_TYPE_EQUAL(GetObjectType(print_obj), INT_TYPE)) {
		std::cout << GetObjectData<IntObject, Interger>(print_obj);
		return true;
	} else {
		return false; // failed to print
	}
}

Dpp_Object *FloatAdd(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		ADD_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		ADD_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatSub(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		SUB_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		SUB_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatMul(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MUL_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		MUL_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatDiv(Dpp_Object *lval, Dpp_Object *rval) {
	
	Dpp_Object *rtn = nullptr;
	
	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		DIV_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		DIV_MACRO(f_lval, FloatObject, FloatNum, FLOAT_TYPE, FloatNum, FloatObject)
	}
	return rtn;
}

bool FloatPrint(Dpp_Object *print_obj) {
	if(IS_TYPE_EQUAL(GetObjectType(print_obj), FLOAT_TYPE)) {
		std::cout << GetObjectData<FloatObject, FloatNum>(print_obj);
		return true;
	} else {
		return false; // failed to print
	}
}

// for string
Dpp_Object *StringAdd(Dpp_Object *lval, Dpp_Object *rval) {
	Dpp_Object *rtn = nullptr;
	
	String ws_lval = GetObjectData<StringObject, String>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(STRING_TYPE, type)) {
		String _rval = GetObjectData<StringObject, String>(lval);
		String val = ws_lval + _rval;
		rtn = NewObject<StringObject>();
		SetObject<StringObject, String>(rtn, val);
	}
	return rtn; // error at string add
}

bool StringPrint(Dpp_Object *print_obj) {
	if(IS_TYPE_EQUAL(GetObjectType(print_obj), STRING_TYPE)) {
		std::wcout << GetObjectData<StringObject, String>(print_obj);
		return true;
	} else {
		return false; // failed to print
	}
}

// register the based types
void RegInit(FObject *fObj) {
	// init the types
	IntType = {INT_TYPE, sizeof(Interger), &IntAdd, &IntSub, &IntMul, &IntDiv, &IntMod, &IntShl, &IntShr, &IntBand, &IntBor, &IntBxor, &IntBneg, &StdBigger, &StdSmaller, &StdEqual, &StdNot, &IntPrint, nullptr, nullptr};
	FloatType = {FLOAT_TYPE, sizeof(FloatNum), &FloatAdd, &FloatSub, &FloatMul, &FloatDiv, nullptr, nullptr, nullptr, nullptr, nullptr,nullptr, nullptr, &StdBigger, &StdSmaller, &StdEqual, &StdNot, &FloatPrint, nullptr, nullptr};
	StringType = {STRING_TYPE, sizeof(String), &StringAdd, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, &StdBigger, &StdSmaller, &StdEqual, &StdNot, &StringPrint, nullptr, nullptr};
	
	fObj->types.write(INT_TYPE, IntType);
	fObj->types.write(FLOAT_TYPE, FloatType);
	fObj->types.write(STRING_TYPE, StringType);
}

inline void RegSet(Dpp_Object *obj, RegType reg) {obj->reg = reg;}

Dpp_Object *StdBigger(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}
	
	if(lval->is_const && rval->is_const) {
		switch (lval->type_val) {
		case INT_TYPE:
			goto LVAL_INT; 
		case FLOAT_TYPE:
			goto LVAL_FLOAT;
		case STRING_TYPE:
			goto LVAL_STRING;
		default:
			goto LVAL_DEFAULT;
		}
	}
	LVAL_INT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_FLOAT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) > GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_STRING:
	if(rval->type_val == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) > GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(INT_TYPE, _bool);
	} else {
		return nullptr;
	}
	
	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(INT_TYPE, lval > rval);
}

Dpp_Object *StdSmaller(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}
	
	if(lval->is_const && rval->is_const) {
		switch (lval->type_val) {
		case INT_TYPE:
			goto LVAL_INT; 
		case FLOAT_TYPE:
			goto LVAL_FLOAT;
		case STRING_TYPE:
			goto LVAL_STRING;
		default:
			goto LVAL_DEFAULT;
		}
	}
	LVAL_INT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_FLOAT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) < GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_STRING:
	if(rval->type_val == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) < GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(INT_TYPE, _bool);
	} else {
		return nullptr;
	}
	
	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(INT_TYPE, lval < rval);
}

Dpp_Object *StdEqual(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}
	
	if(lval->is_const && rval->is_const) {
		switch (lval->type_val) {
		case INT_TYPE:
			goto LVAL_INT; 
		case FLOAT_TYPE:
			goto LVAL_FLOAT;
		case STRING_TYPE:
			goto LVAL_STRING;
		default:
			goto LVAL_DEFAULT;
		}
	}
	LVAL_INT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_FLOAT:
	switch (rval->type_val) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) == GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(INT_TYPE, _bool);
		}
	default:
		return nullptr; // error
	}
	
	LVAL_STRING:
	if(rval->type_val == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) == GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(INT_TYPE, _bool);
	} else {
		return nullptr;
	}
	
	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(INT_TYPE, lval == rval);
}

Dpp_Object *StdNot(Dpp_Object *val) {
	if(val == nullptr) {
		return nullptr;
	}
	
	if(val->is_const) {
		switch (val->type_val) {
			case INT_TYPE: {
				bool _bool = ! GetObjectData<IntObject, Interger>(val);
				return mkConst<IntObject, Interger>(INT_TYPE, _bool);
			}	
			case FLOAT_TYPE: {
				bool _bool = ! GetObjectData<FloatObject, FloatNum>(val);
				return mkConst<IntObject, Interger>(INT_TYPE, _bool);
			}
		default:
			return mkConst<IntObject, Interger>(INT_TYPE, !val);
		}
	} else {
		return mkConst<IntObject, Interger>(INT_TYPE, !val);
	}
	
}
