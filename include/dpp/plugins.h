/**
 * @file plugins.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Define Plugins API
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef DPP_PLUGINS_H
#define DPP_PLUGINS_H
#include <dpp/api.h>
#include <filesystem>

NAMESPACE_DPP_BEGIN

struct plugin_args {
    fs::path output_dir;
    fs::path dpp_executable_file;
    std::vector<std::string> args;
};

using plugin_init_func = void (const plugin_args &);

NAMESPACE_DPP_END

#endif // !DPP_PLUGINS_H