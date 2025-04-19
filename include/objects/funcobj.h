/**
 * @file funcobj.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines the function object.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OBJECTS_FUNCOBJ_H
#define _OBJECTS_FUNCOBJ_H
#include "objects/utils.h"

struct NativeFunc {
    std::string lib;
    std::string func_id;
    bool is_native = false;

    NATIVE_FUNC native_func;

Dpp_SERIALIZE(Dpp_NVP(lib), Dpp_NVP(func_id), Dpp_NVP(is_native))
};

Dpp_TYPE(FunctionObject) {
Dpp_TYPE_REGISTER_METHOD(FunctionObject)
public:
    struct VMState state; // for normal function
    std::shared_ptr<NativeFunc> function = nullptr; // for native function

public:
    std::string to_string(dpp::object *) override;
    std::string to_datastring(dpp::object *) override;
    std::string get_typeid() override;
Dpp_OBJECT_SERIALIZE(state, function)
};

Dpp_REGISTER_TYPE(function, FunctionObject)

#endif // !_OBJECTS_FUNCOBJ_H