/**
 * @file boolobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the bool object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_BOOLOBJ_H
#define _OBJECTS_BOOLOBJ_H
#include "objects/utils.h"
#include "struct.hpp"

/**
 * @brief BoolObject
 * it defines a object that can be just true or false.
 */
Dpp_TYPE(BoolObject) {
Dpp_TYPE_REGISTER_METHOD(BoolObject)
public:
    bool val = false; // boolean value
public:
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    bool is_true() override;
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_SERIALIZE(val)
};

Dpp_REGISTER_TYPE_EX(bool, BoolObject, val)

#endif // !_OBJECTS_BOOLOBJ_H