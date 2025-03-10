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

#include <cstdint>
#include <stdexcept>
#include "opcodes.hpp"
#include "builtin.hpp"
#include "macros.hpp"
#include "native.hpp"
#include "objects.hpp"
#include "struct.hpp"

struct Version version; // Runtime Machine Version

void _add(dpp::vm vm) {

	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for +: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

    dpp::object *_c = nullptr;
	try {
        _c = *lobj + robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for +: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _sub(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for -: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj - robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for -: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _mul(dpp::vm vm) {
#ifdef __TEST
	std::cout << "add" << std::endl;
#endif
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);

	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for *: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj * robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for *: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _div(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for /: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj / robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for /: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    } catch (DivideZeroError &) {
        dpp::set_error(vm, Dpp_DivideZeroError, Dpp_TEXT("division by zero"));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _mod(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for %: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj % robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for %: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    } catch (DivideZeroError &) {
        dpp::set_error(vm, Dpp_DivideZeroError, Dpp_TEXT("division by zero"));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _bneg(dpp::vm vm) {
	Object _obj = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *obj = vm->obj_map.get(_obj);

    dpp::object *_c = nullptr;
    try {
        _c = ~(*obj);
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for ~: ") + dpp::get_typeid(obj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _band(dpp::vm vm) {
	Object _lnum = vm->_theap->PopFront();
	Object _rnum = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lnum = vm->obj_map.get(_lnum);
	dpp::object *rnum = vm->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for &: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *lnum & rnum;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for &: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _bor(dpp::vm vm) {
	Object _lnum = vm->_theap->PopFront();
	Object _rnum = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lnum = vm->obj_map.get(_lnum);
	dpp::object *rnum = vm->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for |: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *lnum | rnum;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for |: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _bxor(dpp::vm vm) {
	Object _lnum = vm->_theap->PopFront();
	Object _rnum = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lnum = vm->obj_map.get(_lnum);
	dpp::object *rnum = vm->obj_map.get(_rnum);

	if(lnum == Dpp_NullObject || rnum == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for ^: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *lnum ^ rnum;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for ^: ") + dpp::get_typeid(lnum) + Dpp_TEXT(", ") + dpp::get_typeid(rnum));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _shl(dpp::vm vm) {
	Object _num = vm->_theap->PopFront();
	Object _shl_count = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *num = vm->obj_map.get(_num);
	dpp::object *shl_count = vm->obj_map.get(_shl_count);

	if(num == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for <<: ") + dpp::get_typeid(num) + Dpp_TEXT(", ") + dpp::get_typeid(shl_count));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *num << shl_count;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for <<: ") + dpp::get_typeid(num) + Dpp_TEXT(", ") + dpp::get_typeid(shl_count));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _shr(dpp::vm vm) {
	Object _num = vm->_theap->PopFront();
	Object _shr_count = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *num = vm->obj_map.get(_num);
	dpp::object *shr_count = vm->obj_map.get(_shr_count);

	if(num == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for >>: ") + dpp::get_typeid(num) + Dpp_TEXT(", ") + dpp::get_typeid(shr_count));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *num >> shr_count;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for >>: ") + dpp::get_typeid(num) + Dpp_TEXT(", ") + dpp::get_typeid(shr_count));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _not(dpp::vm vm) {
	Object _obj = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *obj = vm->obj_map.get(_obj);
	dpp::object *_c = nullptr;
    try {
        _c = !(*obj);
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for !: ") + dpp::get_typeid(obj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _eq(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for ==: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
    try {
        _c = *lobj == robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for ==: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _bigger(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for >: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj > robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for >: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _smaller(dpp::vm vm) {
	Object _lval = vm->_theap->PopFront();
	Object _rval = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lval);
	dpp::object *robj = vm->obj_map.get(_rval);


	if(lobj == Dpp_NullObject || robj == Dpp_NullObject) {
		dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("unsopprted operation(s) for <: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
		return;
	}

	dpp::object *_c = nullptr;
	try {
        _c = *lobj < robj;
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("unsopprted operation(s) for <: ") + dpp::get_typeid(lobj) + Dpp_TEXT(", ") + dpp::get_typeid(robj));
        return;
    }

	vm->obj_map.write(to, _c, true);
}

void _and(dpp::vm vm) {
	Object _lobj = vm->_theap->PopFront();
	Object _robj = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lobj);
	dpp::object *robj = vm->obj_map.get(_robj);

	dpp::object *_c = dpp::make_int(dpp::is_true(lobj) && dpp::is_true(robj));
	vm->obj_map.write(to, _c, true);
}

void _or(dpp::vm vm) {
	Object _lobj = vm->_theap->PopFront();
	Object _robj = vm->_theap->PopFront();
	Object to = vm->_theap->PopFront();

	dpp::object *lobj = vm->obj_map.get(_lobj);
	dpp::object *robj = vm->obj_map.get(_robj);

	dpp::object *_c = dpp::make_int(dpp::is_true(lobj) || dpp::is_true(robj));
	vm->obj_map.write(to, _c, true);
}

// jmp when false
void _jnt(dpp::vm vm) {
    Object _jmpto = vm->_theap->PopFront();

    try {
        if (!dpp::is_true(vm->obj_map.get(vm->_theap->PopFront()))) {
            vm->state.runat = _jmpto.id;
        }
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("invaild bool object"));
    }
}

void _jnf(dpp::vm vm) {
    Object _jmpto = vm->_theap->PopFront();

    try {
        if (dpp::is_true(vm->obj_map.get(vm->_theap->PopFront()))) {
            vm->state.runat = _jmpto.id;
        }
    } catch (NoOperatorError &) {
        dpp::set_error(vm, Dpp_DataCantOperatorError, Dpp_TEXT("invaild bool object"));
    }
}

void _jmp(dpp::vm vm) {
    Object _jmpto = vm->_theap->PopFront();

    vm->state.runat = _jmpto.id;
}

void _call(dpp::vm vm) {
    vm->files.push(vm->obj_map.get_currentfile());

	Object _func = vm->_theap->PopFront();
    FunctionObject *func = (FunctionObject *)vm->obj_map.get(_func);

    uint32_t func_mapping_id = vm->obj_map.getLastCreateID();
    vm->obj_map.create_mapping(func_mapping_id);

    uint32_t i = 0;
    while (!vm->_theap->isEmpty()) {
        const Object &param = vm->_theap->PopFront();
        vm->obj_map.write({ false, i }, vm->obj_map.get(param, func_mapping_id - 1));
    }
    vm->callstack.push(vm->state);
    vm->state = func->state;
}

void _ret(dpp::vm vm) {
    // TODO: _ret cannot use like null object
    dpp::object *val = nullptr;
    if (!vm->_theap->isEmpty()) {
        val = vm->obj_map.get(vm->_theap->PopFront())->move(val);
    }

	vm->state = vm->callstack.top();
    vm->callstack.pop();
    vm->obj_map.pop_mapping();

    vm->files.pop();

    vm->return_values.push(val);
}

void _getret(dpp::vm vm) {
    Object to = vm->_theap->PopFront();

    dpp::object *val = vm->return_values.top();
    if (val != nullptr) {
        vm->obj_map.write(to, val, true);
    }
    vm->return_values.pop();
}

void _calln(dpp::vm vm) {
	// call native function
	Object _lib = vm->_theap->PopFront();
	Object _func = vm->_theap->PopFront();

	dpp::object *call_func = vm->obj_map.get(_func);

	if(dpp::is_string(call_func)) {
		String native_func = dpp::get_string(call_func);

        dpp::proc proc;
        try {
            proc = dpp::get_proc(vm->NativeModules[_lib.id], native_func);
        } catch (std::runtime_error &) {
            dpp::set_error(vm, Dpp_LibNoSymbolError, Dpp_TEXT("symbol '") + native_func + Dpp_TEXT("' not found"));
			return;
        }

		NATIVE_FUNC func = (NATIVE_FUNC)proc;
		dpp::object *ret = func(vm);
        if (ret != nullptr && !vm->_theap->isEmpty()) {
            Object _to = vm->_theap->PopFront();
            vm->obj_map.write(_to, ret, true);
        }
    } else {
        dpp::set_error(vm, Dpp_TypeNotRightError, Dpp_TEXT("internal error at calln opcode, the native function is not a string"));
    }
}

void _import(dpp::vm vm) {

}

void _new(dpp::vm vm) {
	Object _type = vm->_theap->PopFront();
	Object _to = vm->_theap->PopFront();

    dpp::object *type = vm->obj_map.get(_type);

	dpp::object *obj = nullptr;
	try {
		obj = type->new_object();
	} catch(std::bad_alloc &) {
        dpp::set_error(vm, Dpp_NoMemoryError, Dpp_TEXT("no memory to create a new object"));
		return;
	}

	vm->obj_map.write(_to, obj, true);
}

void _del(dpp::vm vm) {
    Object _obj = vm->_theap->PopFront();

    dpp::object *obj = vm->obj_map.get(_obj);

    // TODO: bug in it
    //dpp::_delete_object(obj);
}

void _mov(dpp::vm vm) {
	Object _src = vm->_theap->PopFront();
	Object _to = vm->_theap->PopFront();

	dpp::object *src = vm->obj_map.get(_src);
	dpp::object *to = vm->obj_map.get(_to);

    if(src == nullptr || to == nullptr) {
        dpp::set_error(vm, Dpp_NullPointerError, Dpp_TEXT("cannot move a null object or move to"));
        return;
    }

	dpp::object *status = src->move(to);
	if(status == nullptr) {
		// failed
        dpp::set_error(vm, Dpp_TypeNotRightError, Dpp_TEXT("cannot move from ") + dpp::get_typeid(src) + " type to " + dpp::get_typeid(to) + " type");
	}

    vm->obj_map.write(_to, status, true);
}

void _method(dpp::vm vm) {
    Object _container = vm->_theap->PopFront();
    Object _method = vm->_theap->PopFront();

    // TODO: Not Success
}
