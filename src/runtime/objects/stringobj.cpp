#include "objects/stringobj.h"
#include "objects/intobj.h"
#include "objects/boolobj.h"

dpp::object *StringObject::add(dpp::object *lval, dpp::object *rval) {
    return dpp::make_string(dpp::get_string(lval) + dpp::get_string(rval));
}

dpp::object *StringObject::mul(dpp::object *lval, dpp::object *rval) {
    if (!dpp::is_int(rval)) throw NoOperatorError();

    String buf;
    String src = dpp::get_string(lval);
    Integer end = dpp::get_int(rval);
    for (Integer i = 0; i < end; ++i) buf += src;

    return dpp::make_string(buf);
}

bool StringObject::is_true() {
    if (this == Dpp_NullObject) return false;

    return !dpp::get_string(this).empty();  // empty string is false, non-empty
                                            // string is true (like in C)
}

dpp::object *StringObject::notval(dpp::object *val) {
    return dpp::make_bool(dpp::is_true(val));
}

dpp::object *StringObject::equal(dpp::object *lval, dpp::object *rval) {
    return dpp::make_bool(dpp::get_string(lval) == dpp::get_string(rval));
}

std::string StringObject::to_string(dpp::object *obj) {
    return dpp::get_string(obj);
}

std::string StringObject::to_datastring(dpp::object *obj) {
    return std::string("\"") + dpp::get_string(obj) + "\"";
}

__Utils_Typeid(StringObject, "string")