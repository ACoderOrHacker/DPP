/**
 * @file compileinfos.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines compile-information structure
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef COMPILEINFOS_H
#define COMPILEINFOS_H
#include "compiler.hpp"

NAMESPACE_DPP_BEGIN

/**
 * @brief Defines compile-information structure
 *
 */
struct compile_infos {
    Namespace *global_ns; // Global namespace
    IDIterator id_iter; // ID iterator
};

NAMESPACE_DPP_END

#endif // !COMPILEINFOS_H