/**
 * @file venv.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief create a virtual environment
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _VENV_H
#define _VENV_H
#include <dpp/plugins.h>
#include <filesystem>
#include "acdpp.h"
#include "macros.hpp"

NAMESPACE_DPP_BEGIN
NAMESPACE_BEGIN(venv)

/**
 * @brief create a virtual environment
 *
 * @param path the path of the virtual environment
 * @param dpp_executables the executables of D++
 * @param is_cover is cover the existing virtual environment
 */
void create(const std::string &path,
    const std::vector<fs::path> &dpp_executables,
    bool is_cover = false);

/**
 * @brief activate a virtual environment
 *
 * @param path the path of the virtual environment
 */
void activate(const std::string &path);

/**
 * @brief deactivate a virtual environment
 *
 * @param path the path of the virtual environment
 */
void deactivate(const std::string &path);

_DXX_EXPORT_API void venv(const dpp::plugin_args &args);

NAMESPACE_END
NAMESPACE_DPP_END

#endif // !_VENV_H