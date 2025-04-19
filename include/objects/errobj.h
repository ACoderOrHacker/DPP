/**
 * @file errobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the error object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_ERROROBJ_H
#define _OBJECTS_ERROROBJ_H
#include "objects/utils.h"
#include "funcobj.h"

Dpp_TYPE(ErrorObject) {
Dpp_TYPE_REGISTER_METHOD(ErrorObject)
public:
    std::stack<FunctionObject *> handles;
public:
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_EMPTY_OBJECT_SERIALIZE() // C1001 WHEN USE Dpp_OBJECT_SERIALIZE()
};

Dpp_REGISTER_TYPE(error, ErrorObject)


#endif // !_OBJECTS_ERROROBJ_H