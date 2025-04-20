#include "io.h"
#include "struct.hpp"

_DXX_EXPORT_API dpp::object *out(dpp::vm vm) {
    std::shared_ptr<dpp::object> obj = vm->RuntimeStack.top();
    vm->RuntimeStack.pop();

    acassert(obj == nullptr);

    if (obj.get() == Dpp_NullObject) {
        std::cout << "null";
        goto END;
    }

    try {
        std::cout << object_to_string(obj.get());
    } catch (NoOperatorError &) {
        std::cout << "<object"
                  << " at " << obj << ">";
    }

END:
    return None;
}