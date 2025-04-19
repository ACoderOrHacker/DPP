/**
 * @file typeobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the type object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_TYPEOBJ_H
#define _OBJECTS_TYPEOBJ_H
#include "macros.hpp"
#include "objects/utils.h"

Dpp_TYPE(TypeObject) {
Dpp_TYPE_REGISTER_METHOD(TypeObject)
public:
    TypeObject() { type = nullptr; }
    std::shared_ptr<dpp::object> typeinstance;
public:
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_OBJECT_SERIALIZE(typeinstance)
};

Dpp_REGISTER_TYPE_EX(type, TypeObject, typeinstance)

#endif // !_OBJECTS_TYPEOBJ_H