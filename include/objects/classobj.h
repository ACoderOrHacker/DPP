/**
 * @file classobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the class object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_CLASSOBJ_H
#define _OBJECTS_CLASSOBJ_H
#include "objects/utils.h"

Dpp_TYPE(ClassObject) {
Dpp_TYPE_REGISTER_METHOD(ClassObject)
public:
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_EMPTY_OBJECT_SERIALIZE()
};

Dpp_REGISTER_TYPE(class, ClassObject)


#endif // !_OBJECTS_CLASSOBJ_H