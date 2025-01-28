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
#include "dpp/api.h"

NAMESPACE_DPP_BEGIN

using plugin_args = std::vector<std::string>;
using plugin_init_func = void (const plugin_args &);

NAMESPACE_DPP_END

#endif // !DPP_PLUGINS_H