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
#include <boost/serialization/stack.hpp>
#include "builtin.hpp"
#include "struct.hpp"
#include "macros.hpp"
#include "acoder/acassert/acassert.h"

Dpp_DEFINE_ERROR(TypeNotRightError)

NAMESPACE_DPP_BEGIN

// This function may throw an std::bad_alloc
template<class T> forceinline Dpp_Object *new_object() {
    static_assert(std::is_base_of_v<Dpp_Object, T>, "<dpp::new_object>: T must base from Dpp_Object");


    return (Dpp_Object *)new T;
}

template<class T> forceinline Dpp_Object *delete_object(Dpp_Object *obj) {
    static_assert(std::is_base_of_v<Dpp_Object, T>, "<dpp::new_object>: T must base from Dpp_Object");
    acassert(obj == nullptr || obj == Dpp_NullObject);

    delete obj;
    obj = Dpp_NullObject;
    return obj;
}

forceinline Dpp_Object *_delete_object(Dpp_Object *obj) {
    delete obj;
    obj = Dpp_NullObject;
    return obj;
}

NAMESPACE_DPP_END

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4251)
#endif // _MSC_VER

Dpp_TYPE(IntObject) {
Dpp_TYPE_REGISTER_METHOD(IntObject)
public:
    Integer val = 0; // integer value
public:
    dpp::object *add(dpp::object *, dpp::object *) override;
    dpp::object *sub(dpp::object *, dpp::object *) override;
    dpp::object *mul(dpp::object *, dpp::object *) override;
    dpp::object *div(dpp::object *, dpp::object *) override;
    dpp::object *mod(dpp::object *, dpp::object *) override;
    dpp::object *bneg(dpp::object *) override;
    dpp::object *band(dpp::object *, dpp::object *) override;
    dpp::object *bor(dpp::object *, dpp::object *) override;
    dpp::object *bxor(dpp::object *, dpp::object *) override;
    dpp::object *shl(dpp::object *, dpp::object *) override;
    dpp::object *shr(dpp::object *, dpp::object *) override;
    bool is_true() override;
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    dpp::object *bigger(dpp::object *, dpp::object *) override;
    dpp::object *smaller(dpp::object *, dpp::object *) override;
    std::string to_string(dpp::object *) override;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & val;
}
};

Dpp_REGISTER_TYPE_EX(int, IntObject, val)

Dpp_TYPE(FloatObject) {
Dpp_TYPE_REGISTER_METHOD(FloatObject)
public:
    FloatNum val = 0.0; // floating number value
public:
    dpp::object *add(dpp::object *, dpp::object *) override;
    dpp::object *sub(dpp::object *, dpp::object *) override;
    dpp::object *mul(dpp::object *, dpp::object *) override;
    dpp::object *div(dpp::object *, dpp::object *) override;
    bool is_true() override;
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    dpp::object *bigger(dpp::object *, dpp::object *) override;
    dpp::object *smaller(dpp::object *, dpp::object *) override;
    std::string to_string(dpp::object *) override;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & val;
}
};

Dpp_REGISTER_TYPE_EX(float, FloatObject, val)

Dpp_TYPE(StringObject) {
Dpp_TYPE_REGISTER_METHOD(StringObject)
public:
    String val; // string value
public:
    dpp::object *add(dpp::object *, dpp::object *) override;
    dpp::object *mul(dpp::object *, dpp::object *) override;
    bool is_true() override;
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    std::string to_string(dpp::object *) override;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & val;
}
};

Dpp_REGISTER_TYPE_EX(string, StringObject, val)

Dpp_TYPE(ClassObject) {
Dpp_TYPE_REGISTER_METHOD(ClassObject)
public:
    Heap<Dpp_Object *> members; // members of the class

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & members;
}
};

Dpp_REGISTER_TYPE(class, ClassObject)

Dpp_TYPE(FunctionObject) {
Dpp_TYPE_REGISTER_METHOD(FunctionObject)
public:
    struct VMState state;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & state;
}
};

Dpp_REGISTER_TYPE(function, FunctionObject)

Dpp_TYPE(ErrorObject) {
Dpp_TYPE_REGISTER_METHOD(ErrorObject)
public:
    std::stack<FunctionObject *> handles;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
}
};

Dpp_REGISTER_TYPE(error, ErrorObject)

Dpp_TYPE(TypeObject) {
Dpp_TYPE_REGISTER_METHOD(TypeObject)
public:
    TypeObject() { type = nullptr; }
    ~TypeObject() override { delete type; type = nullptr; }
    dpp::object *type;

Dpp_SERIALIZE {
    Dpp_OBJECT_SERIALIZE
    ar & type;
}
};

Dpp_REGISTER_TYPE_EX(type, TypeObject, type)

NAMESPACE_DPP_BEGIN

/**
 * @brief check the object is true or false
 *
 * @param obj
 * @return true
 * @return false
 */
forceinline bool is_true(dpp::object *obj) {
    acassert(obj == nullptr);

    return obj->is_true();
}

NAMESPACE_DPP_END

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif // !DPPDEF_OBJECTS
