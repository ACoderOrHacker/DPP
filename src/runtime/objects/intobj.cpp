#include "objects/intobj.h"
#include "objects/floatobj.h"
#include "objects/boolobj.h"

dpp::object *IntObject::add(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;
    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw NoOperatorError();
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
        throw NoOperatorError();
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
        throw NoOperatorError();
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
        throw NoOperatorError();
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
        throw NoOperatorError();
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

    return dpp::get_int(this) != 0;  // 0 is false, non-zero is true (like in C)
}

dpp::object *IntObject::notval(dpp::object *val) {
    return dpp::make_bool(!dpp::is_true(val));
}

dpp::object *IntObject::equal(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_int(lval) == rval_int);
}

dpp::object *IntObject::bigger(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_int(lval) > rval_int);
}

dpp::object *IntObject::smaller(dpp::object *lval, dpp::object *rval) {
    Integer rval_int;

    if (dpp::is_float(rval)) {
        rval_int = (Integer)dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_int = dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_int(lval) < rval_int);
}

std::string IntObject::to_string(dpp::object *obj) {
    return std::to_string(dpp::get_int(obj));
}

std::string IntObject::to_datastring(dpp::object *obj) {
    return std::to_string(dpp::get_int(obj));
}

__Utils_Typeid(IntObject, "int")