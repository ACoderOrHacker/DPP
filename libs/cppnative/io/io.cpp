#include "io.h"

_DXX_EXPORT_API Dpp_Object *out(FObject *fObj) {
    Object o = theap->PopFront();

    Dpp_Object *obj = fObj->obj_map.get(o);

    if (obj == nullptr) {
        SetError(fObj, Dpp_NullPointerError, L"Cannot output null pointer");
        return None;
    }

    if (obj->reg == nullptr || obj->reg->to_string == nullptr) {
		std::cout << "<object" << " at " << obj << ">";
        // fmt::print("<object '{}' at {}>", obj->name, (uintptr_t)obj);
        goto END;
    }

    std::cout << obj->reg->to_string(obj);
	// fmt::print("{}", obj->reg->to_string());
END:
    return None;
}