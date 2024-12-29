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

#include <string>
#include "objects.hpp"
#include "builtin.hpp"
#include "native.hpp"
#include "struct.hpp"

dpp::object *IntObject::add(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) + rval_int);
}

dpp::object *IntObject::sub(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) - rval_int);
}

dpp::object *IntObject::mul(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) * rval_int);
}

dpp::object *IntObject::div(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    if (rval_int == 0) throw DivideZeroError();

    return dpp::make_int(dpp::get_int(lval) / rval_int);
}

dpp::object *IntObject::mod(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    if (rval_int == 0) throw DivideZeroError();

    return dpp::make_int(dpp::get_int(lval) % rval_int);
}

dpp::object *IntObject::bneg(dpp::object *val) {
    return dpp::make_int(~dpp::get_int(val));
}

dpp::object *IntObject::band(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_int(lval) & dpp::get_int(rval));
}

dpp::object *IntObject::bor(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_int(lval) | dpp::get_int(rval));
}

dpp::object *IntObject::bxor(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_int(lval) ^ dpp::get_int(rval));
}

dpp::object *IntObject::shl(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_int(lval) << dpp::get_int(rval));
}

dpp::object *IntObject::shr(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_int(lval) >> dpp::get_int(rval));
}

bool IntObject::is_true() {
    if (this == Dpp_NullObject) return false;

    return dpp::get_int(this) != 0; // 0 is false, non-zero is true (like in C)
}

dpp::object *IntObject::notval(dpp::object *val) {
    return dpp::make_int(!dpp::is_true(val));
}

dpp::object *IntObject::equal(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) == rval_int);
}

dpp::object *IntObject::bigger(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) > rval_int);
}

dpp::object *IntObject::smaller(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_int(lval) < rval_int);
}

std::string IntObject::to_string(dpp::object *obj) {
    return std::to_string(dpp::get_int(obj));
}

dpp::object *FloatObject::add(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;
    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_float(dpp::get_float(lval) + rval_float);
}

dpp::object *FloatObject::sub(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;
    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_float(dpp::get_float(lval) - rval_float);
}

dpp::object *FloatObject::mul(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;
    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_float(dpp::get_float(lval) * rval_float);
}

dpp::object *FloatObject::div(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;
    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    if (rval_float == 0.0) throw DivideZeroError();

    return dpp::make_float(dpp::get_float(lval) / rval_float);
}

bool FloatObject::is_true() {
    if (this == Dpp_NullObject) return false;

    return dpp::get_float(this) != 0.0; // 0 is false, non-zero is true (like in C)
}

dpp::object *FloatObject::notval(dpp::object *val) {
    return dpp::make_int(!dpp::is_true(val));
}

dpp::object *FloatObject::equal(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_float(lval) == rval_float);
}

dpp::object *FloatObject::bigger(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_float(lval) > rval_float);
}

dpp::object *FloatObject::smaller(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw TypeNotRightError();
    }

    return dpp::make_int(dpp::get_float(lval) < rval_float);
}

std::string FloatObject::to_string(dpp::object *obj) {
    return std::to_string(dpp::get_float(obj));
}

dpp::object *StringObject::add(dpp::object *lval, dpp::object *rval) {
    return dpp::make_string(dpp::get_string(lval) + dpp::get_string(rval));
}

dpp::object *StringObject::mul(dpp::object *lval, dpp::object *rval) {
    if (!dpp::is_int(rval)) throw TypeNotRightError();

    String buf;
    String src = dpp::get_string(lval);
    Integer end = dpp::get_int(rval);
    for (Integer i = 0; i < end; ++i) buf += src;

    return dpp::make_string(buf);
}

bool StringObject::is_true() {
    if (this == Dpp_NullObject) return false;

    return !dpp::get_string(this).empty(); // empty string is false, non-empty string is true (like in C)
}

dpp::object *StringObject::notval(dpp::object *val) {
    return dpp::make_int(dpp::is_true(val));
}

dpp::object *StringObject::equal(dpp::object *lval, dpp::object *rval) {
    return dpp::make_int(dpp::get_string(lval) == dpp::get_string(rval));
}

std::string StringObject::to_string(dpp::object *obj) {
    return dpp::to_pchar(dpp::get_string(obj));
}