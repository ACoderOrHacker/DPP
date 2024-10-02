/*
MIT License

Copyright (c) 2023 ACoderOrHacker

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef DPPDEF_OBJECTS
#define DPPDEF_OBJECTS

#include <type_traits>
#include "builtin.hpp"
#include "struct.hpp"
#include "macros.hpp"
#include "acoder/acassert/acassert.h"

Dpp_DEFINE_ERROR(TypeNotRightError)

/*
struct BitObject {
	OBJECT_HEAD
	bit val; // bit value
};
 */

NAMESPACE_DPP_BEGIN

// This function may throw an std::bad_alloc
template<class T> forceinline Dpp_Object *new_object() {
    static_assert(std::is_base_of<T, Dpp_Object>::value, "<dpp::new_object>: T must base from Dpp_Object");

    return (Dpp_Object *)new T;
}

template<class T> forceinline Dpp_Object *delete_object(Dpp_Object *obj) {
    static_assert(std::is_base_of<T, Dpp_Object>::value, "<dpp::new_object>: T must base from Dpp_Object");
    acassert(obj == nullptr || obj == Dpp_NullObject);

    delete obj;
    obj = Dpp_NullObject;
    return obj;
}

NAMESPACE_DPP_END

Dpp_TYPE(IntObject) {
public:
    Integer val = 0; // integer value
public:
};

Dpp_REGISTER_TYPE_EX(int, IntObject, val)

Dpp_TYPE(FloatObject) {
public:
    FloatNum val = 0.0; // floating number value
public:
};

Dpp_REGISTER_TYPE_EX(float, FloatObject, val)

Dpp_TYPE(StringObject) {
public:
    String val; // string value
public:
};

Dpp_REGISTER_TYPE_EX(string, StringObject, val)

Dpp_TYPE(ClassObject) {
public:
    Heap<Dpp_Object *> members; // members of the class
public:
};

Dpp_REGISTER_TYPE(class, ClassObject)

Dpp_TYPE(FunctionObject) {
public:
    struct VMState state;
};

Dpp_REGISTER_TYPE(function, FunctionObject)

Dpp_TYPE_EX(ErrorObject, ClassObject) {
public:
    std::stack<FunctionObject *> handles;
};

Dpp_REGISTER_TYPE(error, ErrorObject)

#endif // !DPPDEF_OBJECTS
