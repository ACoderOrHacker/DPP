/**
 * @file configs.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Define configures for runtime
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _DPP_CONFIGS_H
#define _DPP_CONFIGS_H
#include <dpp/defines.h>

NAMESPACE_DPP_BEGIN

/**
 * @brief runtime configures, user define
 *
 */
struct runtime_config {
    /**
     * @brief for max_xxx or min_xxx, -1 means no limit for this configure
     *
     */
    constexpr static auto nolimit = -1;

    /**
     * @brief the max memory usage for the process
     *
     */
    int64_t max_memory = nolimit;

Dpp_SERIALIZE(Dpp_NVP(max_memory))
};

NAMESPACE_DPP_END

#endif // !_DPP_CONFIGS_H