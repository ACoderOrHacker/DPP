/**
 * @file io.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines std.io
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <dpp/api.h>

/**
 * @brief defines std.io.out native function
 *
 * @param vm the virtual machine instance
 * @return dpp::object * always None
 */
_DXX_EXPORT_API dpp::object *out(dpp::vm vm);
