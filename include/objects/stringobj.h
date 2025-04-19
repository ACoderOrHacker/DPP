/**
 * @file stringobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines string object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECT_STRINGOBJ_H
#define _OBJECT_STRINGOBJ_H
#include "objects/utils.h"

Dpp_TYPE(StringObject) {
Dpp_TYPE_REGISTER_METHOD(StringObject)
public:
    String str;
public:
    dpp::object *add(dpp::object *, dpp::object *) override;
    dpp::object *mul(dpp::object *, dpp::object *) override;
    bool is_true() override;
    dpp::object *notval(dpp::object *) override;
    dpp::object *equal(dpp::object *, dpp::object *) override;
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;

Dpp_OBJECT_SERIALIZE(str)
};

Dpp_REGISTER_TYPE_EX(string, StringObject, str)


#endif // !_OBJECT_STRINGOBJ_h