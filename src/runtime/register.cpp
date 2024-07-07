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

#include "register.hpp"

struct RegType IntType;
struct RegType FloatType;
struct RegType StringType;
struct RegType ClassType;
struct RegType ErrorType;
struct RegType FunctionType;
class NoType{};

struct _LinkType {
	RegType reg;
};

DXX_API RegType GetReg(const std::type_info &type) {

    if (type == typeid(Interger)) {
        return IntType;
    } else if (type == typeid(FloatNum)) {
        return FloatType;
    } else if (type == typeid(String)) {
        return StringType;
    } else {
        throw NoType();
    }
}

DXX_API Dpp_Object *mkFunction(std::string id) {
    Dpp_Object *o = NewObject<FunctionObject>();
    FunctionObject *func = (FunctionObject *)o;

    o->name = id;
    o->isTypeObject = false;
    o->reg = &FunctionType;

    return o;
}

Dpp_Object *IntAdd(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;
	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		ADD_MACRO(ll_lval, IntObject, Interger, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		ADD_MACRO(ll_lval, FloatObject, FloatNum, Interger, IntObject)
	}
	return rtn;
}

Dpp_Object *IntSub(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		SUB_MACRO(ll_lval, IntObject, Interger, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		SUB_MACRO(ll_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntMul(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MUL_MACRO(ll_lval, IntObject, Interger, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		MUL_MACRO(ll_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntDiv(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		DIV_MACRO(ll_lval, IntObject, Interger, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		DIV_MACRO(ll_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *IntMod(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MOD_MACRO(ll_lval, IntObject, Interger, Interger, IntObject)
	}
	return rtn;
}

Dpp_Object *IntShl(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(ll_lval << GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntShr(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(ll_lval >> GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBand(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(ll_lval & GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBor(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(ll_lval | GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBxor(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	Interger ll_lval = GetObjectData<IntObject, Interger>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(ll_lval ^ GetObjectData<IntObject, Interger>(rval));
	}
	return rtn;
}

Dpp_Object *IntBneg(Dpp_Object *val) {

	Dpp_Object *rtn = nullptr;

	uint8_t type = GetObjectType(val);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		rtn = mkConst<IntObject, Interger>(~ GetObjectData<IntObject, Interger>(val));
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
		ADD_MACRO(f_lval, FloatObject, FloatNum, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		ADD_MACRO(f_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatSub(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		SUB_MACRO(f_lval, FloatObject, FloatNum, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		SUB_MACRO(f_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatMul(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		MUL_MACRO(f_lval, FloatObject, FloatNum, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		MUL_MACRO(f_lval, FloatObject, FloatNum, FloatNum, FloatObject)
	}
	return rtn;
}

Dpp_Object *FloatDiv(Dpp_Object *lval, Dpp_Object *rval) {

	Dpp_Object *rtn = nullptr;

	FloatNum f_lval = GetObjectData<FloatObject, FloatNum>(lval);
	uint8_t type = GetObjectType(rval);
	if(IS_TYPE_EQUAL(INT_TYPE, type)) {
		DIV_MACRO(f_lval, FloatObject, FloatNum, Interger, IntObject)
	} else if(IS_TYPE_EQUAL(FLOAT_TYPE, type)) {
		DIV_MACRO(f_lval, FloatObject, FloatNum, FloatNum, FloatObject)
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
    ClassType.type = CLASS_TYPE;
    ErrorType.type = ERROR_TYPE;
    FunctionType.type = FUNCTION_TYPE;
    ClassType.size = sizeof(ClassObject);
    ErrorType.size = sizeof(ErrorObject);
    FunctionType.size = sizeof(FunctionObject);

    Dpp_Object *__inttype = NewObject<ObjectObject>();
    Dpp_Object *__floattype = NewObject<ObjectObject>();
    Dpp_Object *__stringtype = NewObject<ObjectObject>();
    Dpp_Object *__classtype = NewObject<ObjectObject>();
    Dpp_Object *__errortype = NewObject<ObjectObject>();
    Dpp_Object *__functiontype = NewObject<ObjectObject>();

    __inttype->reg = &IntType;
    __floattype->reg = &FloatType;
    __stringtype->reg = &StringType;
    __classtype->reg = &ClassType;
    __errortype->reg = &ErrorType;
    __functiontype->reg = &FunctionType;

    __inttype->isTypeObject = true;
    __floattype->isTypeObject = true;
    __stringtype->isTypeObject = true;
    __classtype->isTypeObject = true;
    __errortype->isTypeObject = true;
    __functiontype->isTypeObject = true;

	fObj->obj_map.write({false, INT_TYPE}, __inttype);
	fObj->obj_map.write({false, FLOAT_TYPE}, __floattype);
    fObj->obj_map.write({false, STRING_TYPE}, __stringtype);
    fObj->obj_map.write({false, CLASS_TYPE}, __classtype);
    fObj->obj_map.write({false, ERROR_TYPE}, __errortype);
    fObj->obj_map.write({false, FUNCTION_TYPE}, __functiontype);
}

inline void RegSet(Dpp_Object *obj, RegType *reg) {obj->reg = reg;}

Dpp_Object *StdBigger(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}

	switch (lval->reg->type) {
	case FLOAT_TYPE:
        goto LVAL_FLOAT;
	case INT_TYPE:
        goto LVAL_INT;
	case STRING_TYPE:
        goto LVAL_STRING;
	default:
		goto LVAL_DEFAULT;
	}
	LVAL_INT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_FLOAT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) > GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) > GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_STRING:
	if(rval->reg->type == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) > GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(_bool);
	} else {
		return nullptr;
	}

	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(lval > rval);
}

Dpp_Object *StdSmaller(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}

	switch (lval->reg->type) {
	case INT_TYPE:
		goto LVAL_INT;
	case FLOAT_TYPE:
		goto LVAL_FLOAT;
	case STRING_TYPE:
		goto LVAL_STRING;
	default:
		goto LVAL_DEFAULT;
	}
	LVAL_INT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_FLOAT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) < GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) < GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_STRING:
	if(rval->reg->type == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) < GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(_bool);
	} else {
		return nullptr;
	}

	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(lval < rval);
}

Dpp_Object *StdEqual(Dpp_Object *lval, Dpp_Object *rval) {
	if(lval == nullptr || rval == nullptr) {
		return nullptr;
	}

	switch (lval->reg->type) {
	case INT_TYPE:
		goto LVAL_INT;
	case FLOAT_TYPE:
		goto LVAL_FLOAT;
	case STRING_TYPE:
		goto LVAL_STRING;
	default:
		goto LVAL_DEFAULT;
	}
	LVAL_INT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// int and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// int and floating number
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_FLOAT:
	switch (rval->reg->type) {
		case INT_TYPE:{
			// floating number and int
			bool _bool = GetObjectData<IntObject, Interger>(lval) == GetObjectData<IntObject, Interger>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE:{
			// floating number and floating number
			bool _bool = GetObjectData<FloatObject, FloatNum>(lval) == GetObjectData<FloatObject, FloatNum>(rval);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return nullptr; // error
	}

	LVAL_STRING:
	if(rval->reg->type == STRING_TYPE) {
		bool _bool = GetObjectData<StringObject, String>(lval) == GetObjectData<StringObject, String>(rval);
		return mkConst<IntObject, Interger>(_bool);
	} else {
		return nullptr;
	}

	LVAL_DEFAULT:
	return mkConst<IntObject, Interger>(lval == rval);
}

Dpp_Object *StdNot(Dpp_Object *val) {
	if(val == nullptr) {
		return nullptr;
	}


	switch (val->reg->type) {
		case INT_TYPE: {
			bool _bool = ! GetObjectData<IntObject, Interger>(val);
			return mkConst<IntObject, Interger>(_bool);
		}
		case FLOAT_TYPE: {
			bool _bool = ! GetObjectData<FloatObject, FloatNum>(val);
			return mkConst<IntObject, Interger>(_bool);
		}
	default:
		return mkConst<IntObject, Interger>(!val);
	}

}
