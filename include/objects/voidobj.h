/**
 * @file voidobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the void object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_VOIDOBJ_H
#define _OBJECTS_VOIDOBJ_H
#include "objects/utils.h"

/**
 * @brief VoidObject
 * it defines a 'empty' object. That can be 'null' or 'void' in some languages.
 * 
 */
Dpp_TYPE(VoidObject) {
Dpp_TYPE_REGISTER_METHOD(VoidObject)
public:
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_EMPTY_OBJECT_SERIALIZE()
};

Dpp_REGISTER_TYPE(void, VoidObject)

#endif // !_OBJECTS_VOIDOBJ_H