#include "io.h"

_DXX_EXPORT_API Dpp_Object *out(FObject *fObj) {
    Object o = fObj->_theap->PopFront();

    Dpp_Object *obj = fObj->obj_map.get(o);

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