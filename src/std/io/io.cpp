#include "io.h"

_DXX_EXPORT_API dpp::object *out(dpp::vm vm) {
    dpp::mapid o = vm->_theap->PopFront();

    dpp::object *obj = vm->obj_map.get(o);

	acassert(obj == nullptr);

    if (obj == Dpp_NullObject) {
        std::cout << "null";
        goto END;
    }

	try {
		std::cout << object_to_string(obj);
	} catch (NoOperatorError &) {
		std::cout << "<object" << " at " <<obj << ">";
	}

END:
    return None;
}