#include "objects/floatobj.h"
#include "objects/intobj.h"
#include "objects/boolobj.h"

dpp::object *FloatObject::add(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;
    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw NoOperatorError();
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
        throw NoOperatorError();
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
        throw NoOperatorError();
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
        throw NoOperatorError();
    }

    if (rval_float == 0.0) throw DivideZeroError();

    return dpp::make_float(dpp::get_float(lval) / rval_float);
}

bool FloatObject::is_true() {
    if (this == Dpp_NullObject) return false;

    return dpp::get_float(this) !=
           0.0;  // 0 is false, non-zero is true (like in C)
}

dpp::object *FloatObject::notval(dpp::object *val) {
    return dpp::make_bool(!dpp::is_true(val));
}

dpp::object *FloatObject::equal(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_float(lval) == rval_float);
}

dpp::object *FloatObject::bigger(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_float(lval) > rval_float);
}

dpp::object *FloatObject::smaller(dpp::object *lval, dpp::object *rval) {
    FloatNum rval_float;

    if (dpp::is_float(rval)) {
        rval_float = dpp::get_float(rval);
    } else if (dpp::is_int(rval)) {
        rval_float = (FloatNum)dpp::get_int(rval);
    } else {
        throw NoOperatorError();
    }

    return dpp::make_bool(dpp::get_float(lval) < rval_float);
}

std::string FloatObject::to_string(dpp::object *obj) {
    return std::to_string(dpp::get_float(obj));
}

std::string FloatObject::to_datastring(dpp::object *obj) {
    return std::to_string(dpp::get_float(obj));
}

__Utils_Typeid(FloatObject, "float")
