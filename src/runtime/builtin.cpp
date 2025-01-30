#include "builtin.hpp"
#include "acdpp.h"
#include "objects.hpp"
#include "struct.hpp"

dpp::object *type_object = []() -> dpp::object * {
    dpp::object *o = dpp::make_type(create_ptr(dpp::new_object<TypeObject>()));
    o->name = "type";
    TypeObject *typeo = dpp::to_type(o);
    typeo->type = create_ptr(o);
    return o;
}();

template<typename T>
dpp::object *mk_type(const std::string &id) {
    dpp::object *o = dpp::make_type(create_ptr(dpp::new_object<T>()));
    o->name = id;
    TypeObject *typeo = dpp::to_type(o);
    typeo->type = create_ptr(type_object);

	return o;
}

const std::vector<dpp::object *> builtins = {
    new dpp::object, /* Dpp_NullObject */
    newErrorObject("BaseError"), /* Dpp_BaseError */
    newErrorObject("NullPointerError"), /* Dpp_NullPointerError */
    newErrorObject("NoOperatorError"), /* Dpp_DataCantOperatorError */
    newErrorObject("TypeNotRightError"), /* Dpp_TypeNotRightError */
    newErrorObject("NoMemoryError"), /* Dpp_NoMemoryError */
    newErrorObject("NoSymbolError"), /* Dpp_LibNoSymbolError */
    newErrorObject("DivideZeroError"), /* Dpp_DivideZeroError */
    mk_type<IntObject>("int"),
	mk_type<FloatObject>("float"),
	mk_type<StringObject>("string"),
	mk_type<ClassObject>("class"),
	mk_type<ErrorObject>("error"),
	mk_type<FunctionObject>("function"),
    type_object
};

DXX_API const std::vector<dpp::object *> &get_builtins() {
    return builtins;
}

dpp::object *newErrorObject(const std::string &id) {
    dpp::object *error = dpp::new_object<ErrorObject>();
	error->name = id;

    return error;
}
