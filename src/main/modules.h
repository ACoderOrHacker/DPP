#ifndef DPP_MODULES_H
#define DPP_MODULES_H

#include <iostream>
#include <stdexcept>
#include <format>
#include "macros.hpp"
#include "vm.hpp"
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include <dpp/api.h>
#include "serialization/Serialization.hpp"
#include "configs/configs.h"
#include "fmt.h"
#undef error
#undef theap

namespace fmt = dpp::fmt;

fs::path root = fs::current_path().parent_path();
const fs::path examples_path = root / "examples";

NAMESPACE_DPP_BEGIN

/**
 * @brief Get the compile time
 */
std::string get_compile_time() {
    return std::format("{}.{}", __DATE__, __TIME__);
}

/**
 * @brief Get the compiler infos
 *
 * @return std::string
 */
std::string get_compiler_infos() {
#ifdef __clang__
    return std::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    return std::format("{}.{}.{}", __GNUC__,  __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    return std::format("MSC .v{}", _MSC_VER);
#else
    return "Unknown";
#endif
}

/**
 * @brief get the system is 32bit or 64bit
 *
 * @return const char *
 */
const char *get_system_32bits_or_64bits() {
#if defined(__LP64__) || defined(_WIN64)
    return "64bit";
#else
    return "32bit";
#endif
}

/**
 * @brief Get the platform infos
 *
 * @return const char*
 */
const char *get_platform() {
#if defined(_WIN32)
    return "win32";
#elif defined(__linux__)
    return "linux";
#else
    return "unknown platform";
#endif
}

/**
 * @brief output infos in command line
 * like version, compiler, platform, etc.
 * @return void
 */
void output_information() {
    fmt::print("D++ ", DXX_VERSION, "(", dpp::get_compile_time(), ") ", "[", dpp::get_compiler_infos(), "] on ", dpp::get_platform());
}

/**
 * @brief Get the version string
 *
 * @param ver the version structure
 * @return std::string
 */
std::string get_version_string(Version ver) {
    return std::format("{}.{}", ver.ver.high, ver.ver.low);
}

/**
 * @brief Get the file type from magic number
 *
 * @param MagicNumber
 * @return std::string
 */
std::string get_file_type(const std::string &magic_number) {
    if(magic_number == "DPPO") {
        return "D++ Object File";
    } else {
        return "Unknown";
    }
}

/**
 * @brief output file header to command line
 *
 * @param header the output file header
 */
void output_fileheader(const FileHeader &header) {
    fmt::print("FileHeader:\n");
    fmt::print("    Type: ", dpp::get_file_type(header.MagicNumber));
    fmt::print("    Compile Version: ", dpp::get_version_string(header.version));
    fmt::print("    Lowest Version: ", dpp::get_version_string(header.LowestVersion));
}

/**
 * @brief Get the flags name
 *
 * @param flag
 * @return std::string
 */
std::string get_flags_name(char flag) {
    if(flag == NO_FLAG) {
        return "null";
    }

    std::string s;
    for(int i = 1; i <= 8; ++i) {
        if(GetBit(flag, i)) {
            s += std::format("{} ", dpp::get_flag_name(i));
        }
    }

    return s;
}

/**
 * @brief output vm structure to command line
 *
 * @param s_fObj
 * @param isOutputCopyright
 */
void output_s_vm(S_FObject *s_fObj, bool isOutputCopyright = true) {
    auto opt_state = [](::VMState state) -> void {
        uint32_t i = 0;
        for(auto &it : state.vmopcodes) {
            std::string s;

            s += std::format("[{}] ",i , dpp::get_opcode_name(it.opcode), " ");

            for (auto &param : it.params) {
                s += std::format("[{}, {}] ", param.isInGlobal ? "Global" : "Local", param.id);
            }
            std::cout << s;
            size_t space_num = 100 - s.size();
            if (space_num > 0) {
                std::cout << std::string(space_num, ' ');
            }
            else {
                // space_num <= 0
                // std::length_error: string too long
                std::cout << std::string(s.size() + 10, ' ');
            }
            fmt::print("flag: ", dpp::get_flags_name(it.flag), "\n");

            ++i;
        }
    };
    fmt::print("\n");
    if (isOutputCopyright) fmt::print("D++ Debug Tools. Copyright (c) ACoderOrHacker. All rights reserved.\n");

    dpp::output_fileheader(s_fObj->header);

    fmt::print("\n");
    fmt::print("Dependent modules: \n");
    for(auto &it: s_fObj->modules) {
        fmt::print("    ", it, "\n");
    }

    fmt::print("\n");
    fmt::print("Main State: \n");
    opt_state(s_fObj->state);

    fmt::print("\n");
    uint32_t i = 0;
    for (auto it : s_fObj->global_mapping) {
        if (it != nullptr && it->name != "function" && dpp::is_function(it)) {
            fmt::print("Function: ", it->name.empty() ? "unknown" : it->name, " [Global, ", i, "]\n");
            opt_state(_cast(FunctionObject *, it)->state);
            fmt::print("\n");
        }
        ++i;
    }

    fmt::print("\n");
    fmt::print("Global Object Mapping:\n");
    for(uint32_t index = BUILTIN_END; index < s_fObj->global_mapping.size(); ++index) {
        Dpp_Object *obj = s_fObj->global_mapping[index];
		if (obj == nullptr) fmt::print("    [", index, "] ", "unknown\n");

        try {
            fmt::print("    [", index, "] ", object_to_string(obj), "\n");
        } catch (NoOperatorError &) {
            fmt::print("    [", index, "] ", "unknown", "\n");
        }
    }
}

/**
 * @brief output vm structure to command line
 *
 * @param fObj
 * @param isOutputCopyright
 */
void output_vm(FObject *fObj, bool isOutputCopyright = true) {
    dpp::output_s_vm(GetS_FObject(fObj), isOutputCopyright);
}

void check_test(const std::string &id, const std::string &buf) {
    dpp::switch_ostream(dpp::__stdout);

    fs::path tests_path(examples_path / "tests.json");

    const dpp::tests &tests = dpp::load_tests(tests_path.string());
    try {
        const std::string &test_buf = tests.tests.at(id);
        if (test_buf != buf) {
            fmt::print_error("\nerror: test '", id, "' failed, result is wrong\n");
            fmt::print("    Source buffer: ", test_buf, "\n");
            fmt::print("    Buffer: ", buf, "\n");
            exit(1);
        }
    } catch(std::out_of_range &) {
        fmt::print_error("\nerror: test '", id, "' not found\n");
        exit(1);
    }

    fmt::print_success("\nTest ", id, " passed\n");
}

NAMESPACE_DPP_END

#endif //DPP_MODULES_H
