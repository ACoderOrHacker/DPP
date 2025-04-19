/**
 * @file base_object.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the utilities for built-in objects.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef __OBJ_UTILS_H__
#define __OBJ_UTILS_H__
#include <sstream>
#include <cereal/types/memory.hpp>
#include "builtin.hpp"
#include "struct.hpp"

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

/**
 * @brief convert the val to hex string
 *
 * @tparam T the value type
 * @param val the value
 * @return std::string
 */
template<typename T>
forceinline std::string to_hex(const T &val) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << val;
    return "0x" + ss.str();
}

forceinline std::string get_typeid(dpp::object *obj) {
    acassert(obj == nullptr);

    if (obj == Dpp_NullObject) {
        return "null";
    }

    return obj->get_typeid();
}

NAMESPACE_DPP_END

#define __Utils_NormalToString(struct_name, type) \
    std::string struct_name::to_string(dpp::object *obj) { \
        return "<" type " " + obj->name + " at " + \
            dpp::to_hex(std::to_string(reinterpret_cast<uintptr_t>(obj))) + ">"; \
    }

#define __Utils_NormalToDataString(struct_name, type) \
    std::string struct_name::to_datastring(dpp::object *obj) { \
        return "<" type " " + obj->name + " at " + \
            dpp::to_hex(std::to_string(reinterpret_cast<uintptr_t>(obj))) + ">"; \
    }

#define __Utils_Typeid(struct_name, id) \
    std::string struct_name::get_typeid() { \
        return id; \
    }

#endif // !__OBJ_UTILS_H__