#include "objects/boolobj.h"
#include "struct.hpp"

bool BoolObject::is_true() {
    return val;
}

dpp::object *BoolObject::notval(dpp::object *obj) {
    return dpp::make_bool(!obj->is_true());
}

dpp::object *BoolObject::equal(dpp::object *lval, dpp::object *rval) {
    return dpp::make_bool(lval->is_true() == rval->is_true());
}

std::string BoolObject::to_string(dpp::object *obj) {
    return obj->is_true() ? "true" : "false";
}

std::string BoolObject::to_datastring(dpp::object *obj) {
    return obj->is_true() ? "true" : "false";
}

__Utils_Typeid(BoolObject, "bool")