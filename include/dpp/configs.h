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
#include <fstream>
#include <cereal/archives/json.hpp>
#include "macros.hpp"

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

/**
 * @brief read/write the runtime configures from/to file
 *
 * @details the Fstream and Archive are must be {std::ifstream, cereal::JSONInputArchive} or {std::ofstream, cereal::JSONOutputArchive}
 *
 * @tparam Fstream the file stream type
 * @tparam Archive the archive type
 * @param file the file path
 * @param cfg the configures to read/write
 *
 * @return struct runtime_config the configure
 */
template<typename Fstream = std::ifstream, typename Archive = cereal::JSONInputArchive>
struct runtime_config rw_runtime_config(const std::string &file,
    runtime_config &cfg) {
    static_assert(std::is_same_v<Fstream, std::ifstream> && std::is_same_v<Archive, cereal::JSONInputArchive>
                || std::is_same_v<Fstream, std::ofstream> && std::is_same_v<Archive, cereal::JSONOutputArchive>, "invaild Fstream with Archive");

    Fstream fs(file);
    if (!fs.is_open()) {
        return runtime_config {};
    }

    Archive archive(fs);
    archive(cereal::make_nvp("runtime-config", cfg));

    return cfg;
}

/**
 * @brief read runtime configures from file
 *
 * @param file the file path
 * @return runtime_config the configures
 */
forceinline runtime_config read_runtime_config(const std::string &file) {
    struct runtime_config cfg;
    return rw_runtime_config<std::ifstream, cereal::JSONInputArchive>(file, cfg);
}

/**
 * @brief write runtime configures from file
 *
 * @param file the file path
 * @param cfg the configures
 */
forceinline void write_runtime_config(const std::string &file,
    runtime_config &cfg) {
    rw_runtime_config<std::ofstream, cereal::JSONOutputArchive>(file, cfg);
}

NAMESPACE_DPP_END

#endif // !_DPP_CONFIGS_H