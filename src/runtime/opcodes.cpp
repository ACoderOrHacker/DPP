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

#include "opcodes.hpp"
#include <cstdint>
#include "struct.hpp"

struct Version version; // Runtime Machine Version

void _add(FObject *fObj) {

	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj + robj;

	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _sub(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj - robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _mul(FObject *fObj) {
#ifdef __TEST
	std::cout << "add" << std::endl;
#endif
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj * robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _div(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj / robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _mod(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj % robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _bneg(FObject *fObj) {
	Object _obj = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *obj = fObj->obj_map.get(_obj);
	Dpp_Object *_c = ~(*obj);
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _band(FObject *fObj) {
	Object _lnum = theap->PopFront();
	Object _rnum = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lnum = fObj->obj_map.get(_lnum);
	Dpp_Object *rnum = fObj->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = *lnum & rnum;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
		return;
	}

	fObj->obj_map.write(to, _c, true);
}

void _bor(FObject *fObj) {
	Object _lnum = theap->PopFront();
	Object _rnum = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lnum = fObj->obj_map.get(_lnum);
	Dpp_Object *rnum = fObj->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = *lnum | rnum;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
		return;
	}

	fObj->obj_map.write(to, _c, true);
}

void _bxor(FObject *fObj) {
	Object _lnum = theap->PopFront();
	Object _rnum = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lnum = fObj->obj_map.get(_lnum);
	Dpp_Object *rnum = fObj->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = *lnum ^ rnum;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
		return;
	}

	fObj->obj_map.write(to, _c, true);
}

void _shl(FObject *fObj) {
	Object _num = theap->PopFront();
	Object _shl_count = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *num = fObj->obj_map.get(_num);
	Dpp_Object *shl_count = fObj->obj_map.get(_shl_count);

	if(num == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = *num << shl_count;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
		return;
	}

	fObj->obj_map.write(to, _c, true);
}

void _shr(FObject *fObj) {
	Object _num = theap->PopFront();
	Object _shr_count = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *num = fObj->obj_map.get(_num);
	Dpp_Object *shr_count = fObj->obj_map.get(_shr_count);

	if(num == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = *num >> shr_count;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
		return;
	}

	fObj->obj_map.write(to, _c, true);
}

void _not(FObject *fObj) {
	Object _obj = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *obj = fObj->obj_map.get(_obj);
	Dpp_Object *_c = !(*obj);
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _eq(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj == robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _bigger(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj > robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _smaller(FObject *fObj) {
	Object _lval = theap->PopFront();
	Object _rval = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lval);
	Dpp_Object *robj = fObj->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		SetError(fObj, Dpp_NullPointerError, L"");
		return;
	}

	Dpp_Object *_c = nullptr;
	_c = *lobj < robj;
	if(_c == nullptr) {
		SetError(fObj, Dpp_DataCantOperatorError, L"");
	}
	fObj->obj_map.write(to, _c, true);
}

void _and(FObject *fObj) {
	Object _lobj = theap->PopFront();
	Object _robj = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lobj);
	Dpp_Object *robj = fObj->obj_map.get(_robj);

	Dpp_Object *_c = mkConst<IntObject, Interger>(isTrue(lobj) && isTrue(robj));
	fObj->obj_map.write(to, _c, true);
}

void _or(FObject *fObj) {
	Object _lobj = theap->PopFront();
	Object _robj = theap->PopFront();
	Object to = theap->PopFront();

	Dpp_Object *lobj = fObj->obj_map.get(_lobj);
	Dpp_Object *robj = fObj->obj_map.get(_robj);

	Dpp_Object *_c = mkConst<IntObject, Interger>(isTrue(lobj) || isTrue(robj));
	fObj->obj_map.write(to, _c, true);
}

void _jmp(FObject *fObj) {
	Object _jmpto = theap->PopFront();

    if (GetBit(fObj->flags, JMP_TRUE) == 1) {
        if (isTrue(fObj->obj_map.get(theap->PopFront()))) {
            fObj->state.runat = _jmpto.id;
        }
    } else if (GetBit(fObj->flags, JMP_FALSE) == 1) {
        if (!isTrue(fObj->obj_map.get(theap->PopFront()))) {
            fObj->state.runat = _jmpto.id;
        }
    }
	fObj->state.runat = _jmpto.id;
}

void _call(FObject *fObj) {
	Object _func = *theap->begin();
    FunctionObject *func = (FunctionObject *)fObj->obj_map.get(_func);

    fObj->obj_map.create_mapping(fObj->obj_map.getLastCreateID());
    uint32_t i = 0;
    for (; i < func->params.size(); ++i){
        const Object &param = func->params.GetData(i);
        fObj->obj_map.write(param, fObj->obj_map.get(theap->PopFront()));
    }
    fObj->callstack.push(fObj->state);
    fObj->state = func->state;
}

void _calln(FObject *fObj) {
	// call native function
	Object _lib = theap->PopFront();
	Object _func = theap->PopFront();

	Dpp_Object *call_func = fObj->obj_map.get(_func);

	if(IS_TYPE_EQUAL(GetObjectType(call_func), STRING_TYPE)) {
		String _native_func = GetObjectData<StringObject, String>(call_func);

		std::string native_func = WStrToPChar(_native_func);
		NativeProc proc = GetNativeProc(fObj->NativeModules[_lib.id], native_func.c_str());
		if(proc == nullptr) {
            SetError(fObj, Dpp_LibNoSymbolError, L"");
			return;
		}
		NATIVE_FUNC func = (NATIVE_FUNC)proc;
		Dpp_Object *ret = func(fObj);
        if (ret != nullptr) {
            Object _to = theap->PopFront();
            fObj->obj_map.write(_to, ret, true);
        }
    }
    else {
        SetError(fObj, Dpp_TypeNotRightError, L"");
    }
}

void _import(FObject *fObj) {

}

void _ret(FObject *fObj) {
	fObj->state = fObj->callstack.top();
}

void _sign(FObject *fObj) {

}
/*
void _sign(FObject *fObj) {
	Object _signal = theap->PopFront();
#ifdef __TEST
	std::cout << GetBit(fObj->flags, 0) << " " << GetBit(fObj->flags, 1) << std::endl;
#endif
	if(GetBit(fObj->flags, 0) == 1) {
		// error bit
		if(GetBit(fObj->flags, 1) == 1) {
			// set error function
			fObj->error_accept.write(_signal.id, theap->PopFront());
		} else {
			// throw error
			error->PushData(_signal);
		}
	} else {
		// signal bit
		if(GetBit(fObj->flags, 1) == 1) {

			// set signal function
			fObj->signal_accept.write(_signal.id, theap->PopFront());
		} else {
			// push a signal to signal pool
			fObj->sig->PushData((SIGNAL)_signal.id);
		}
	}
}
*/
void _new(FObject *fObj) {
	Object _type = theap->PopFront();
	Object _to = theap->PopFront();

    Dpp_Object *type = fObj->obj_map.get(_type);

	Dpp_Object *obj = nullptr;
	try {
		obj = NewObject(type->reg->size + sizeof(Dpp_Object));
        obj->reg = new RegType;
        *obj->reg = *type->reg;
        obj->reg->init(obj);
	} catch(std::bad_alloc &) {
        SetError(fObj, Dpp_NoMemoryError, L"");
		return;
	} catch(TypeNotRightError &) {
        SetError(fObj, Dpp_TypeNotRightError, L"");
		return;
	}

	fObj->obj_map.write(_to, obj, true);
}

void _del(FObject *fObj) {
    Object _obj = theap->PopFront();

    Dpp_Object *obj = fObj->obj_map.get(_obj);

    STATUS status = DeleteObject(obj);

    if(status == STATUS_FAILED) {
        SetError(fObj, Dpp_NullPointerError, L"");
    }
}

void _mov(FObject *fObj) {
	Object _src = theap->PopFront();
	Object _to = theap->PopFront();

	Dpp_Object *src = fObj->obj_map.get(_src);
	Dpp_Object *to = fObj->obj_map.get(_to);

    if(src == nullptr || to == nullptr) {
        SetError(fObj, Dpp_NullPointerError, L"");
        return;
    }

	Dpp_Object *status = src->move(to);
	if(status == nullptr) {
		// failed
        SetError(fObj, Dpp_TypeNotRightError, L"");
	}

    fObj->obj_map.write(_to, status, true);
}

void _method(FObject *fObj) {
    Object _container = theap->PopFront();
    Object _method = theap->PopFront();

    // TODO: Not Success
}

void _exit(FObject *fObj) {
	Object _exitcode = theap->PopFront();

	fObj->exit_code = (int)_exitcode.id;
	fObj->sig->PushData(EXIT);
}
/*
  void _convert(FObject *fObj,
  ErrorPool *error,
  Tmp_Heap *theap) {
  Object convert_id = theap->PopFront(); // convert_id is the 'pConvertList' id
  Object _obj = theap->PopFront();
  Object to = theap->PopFront();

  Dpp_Object *obj = fObj->obj_map.get(_obj);

  Dpp_Object *rtn = fObj->pConvertList[convert_id.id](error, obj);
  fObj->obj_map.write(to.id, rtn);
  }
 */
