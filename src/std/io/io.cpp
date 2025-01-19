#include "io.h"
#include "struct.hpp"

DXX_API dpp::object *out(dpp::vm vm) {
    Object o = vm->_theap->PopFront();

    Dpp_Object *obj = vm->obj_map.get(o);

	acassert(obj == nullptr);

    if (obj == Dpp_NullObject) {
        std::cout << "null";
        goto END;
    }

	try {
		std::cout << object_to_string(obj);
	} catch (NoOperatorError &) {
		std::cout << "<object" << " at " << obj << ">";
	}

END:
    return None;
}