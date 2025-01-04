#ifndef DPP_MODULES_H
#define DPP_MODULES_H

#include <cstdint>
#include <stdexcept>
#include <format>
#include <string>
#include "macros.hpp"
#include "struct.hpp"
#include "vm.hpp"

#include <dpp/api.h>
#include "configs/configs.h"
#include "fmt.h"
#undef error
#undef theap

#define GLOBAL_OBJECT_SHOW_SIGN "@"
#define LOCAL_OBJECT_SHOW_SIGN "%"

namespace fmt = dpp::fmt;

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
    return DXX_PLAT;
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
 * @param vm
 * @param isOutputCopyright
 */
void output_vm(dpp::vm vm, bool isOutputCopyright = true) {
    const auto &opt_state = [](::VMState &state) -> void {
        uint32_t i = 0;
        for(auto &it : state.vmopcodes) {
            std::string s;

            s += std::string("    .") + std::to_string(i) + dpp::get_flags_name(it.flag) + ": " + dpp::get_opcode_name(it.opcode);

            for (auto &param : it.params) {
                s += std::string(param.isInGlobal ? GLOBAL_OBJECT_SHOW_SIGN : LOCAL_OBJECT_SHOW_SIGN) + std::to_string(param.id) + std::string(" ");
            }
            fmt::print(s);

            size_t space_num = 100 - s.size();
            if (space_num > 0) {
                fmt::print(std::string(space_num, ' '));
            } else {
                // space_num <= 0
                // std::length_error: string too long
                fmt::print(std::string(s.size() + 10, ' '));
            }
            ++i;
        }
    };

    if (isOutputCopyright) dpp::output_information();

    auto gmap = vm->obj_map.getGlobalMapping();

    fmt::print("\n");
    if (vm->modules.size() == 0) { fmt::print("modules: {}\n"); }
    else {
        fmt::print("modules: {\n");
        for(auto &it: vm->modules) {
            fmt::print("    ", it, "\n");
        }
        fmt::print("}\n");
    }

    fmt::print("\n");
    if (vm->state.vmopcodes.isEmpty() == 0) { fmt::print("state: {}\n"); }
    else {
        fmt::print("state: {\n");
        opt_state(vm->state);
        fmt::print("}\n");
    }

    fmt::print("\n");
    uint32_t i = 0;
    for (auto it : gmap) {
        if (it != nullptr && it->name != "function" && dpp::is_function(it)) {
            fmt::print("function: {", it->name.empty() ? "unknown" : it->name, GLOBAL_OBJECT_SHOW_SIGN, i, "\n");
            opt_state(_cast(FunctionObject *, it)->state);
            fmt::print("}\n");
        }
        ++i;
    }

    fmt::print("\n");
    fmt::print("global: {\n");
    for(uint32_t index = BUILTIN_END; index < gmap.size(); ++index) {
        auto obj = gmap[index];
		if (obj == nullptr) fmt::print("    .", GLOBAL_OBJECT_SHOW_SIGN, index, ": unknown\n");

        try {
            fmt::print("    .", GLOBAL_OBJECT_SHOW_SIGN, index, ": ", object_to_string(obj), "\n");
        } catch (NoOperatorError &) {
            fmt::print("    .", GLOBAL_OBJECT_SHOW_SIGN, index, ": unknown\n");
        }
    }
    fmt::print("}\n");
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
