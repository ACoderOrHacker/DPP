/**
 * @file floatobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the float object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_FLOAT_H
#define _OBJECTS_FLOAT_H
#include "objects/utils.h"

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
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;

Dpp_OBJECT_SERIALIZE(val)
};

Dpp_REGISTER_TYPE_EX(float, FloatObject, val)

#endif // !_OBJECTS_FLOAT_H