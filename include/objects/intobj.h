/**
 * @file intobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the integer structure
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_INTEGER_H
#define _OBJECTS_INTEGER_H
#include "objects/utils.h"

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
    dpp::object *bigger(dpp::object *, dpp::object *) override;
    dpp::object *smaller(dpp::object *, dpp::object *) override;
    bool is_true() override;
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;

Dpp_OBJECT_SERIALIZE(val)
};

Dpp_REGISTER_TYPE_EX(int, IntObject, val)

#endif // !_OBJECTS_INTEGER_H