/**
 * @file api.h

 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief D++ Application Programming Interface
 *
 */

///
/// THIS FILE IS FOR USER BUT NOT FOR VM & COMPILER
/// DO NOT INCLUDE THIS FILE IN VM & COMPILER
///

#ifndef _INC_DXX_API
#define _INC_DXX_API

#include <iostream>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <filesystem>

#ifdef _DXX_EXPORT
#undef _DXX_EXPORT
#endif // _DXX_EXPORT

#ifdef WIN32
#define NOMINMAX
#endif

#include "vm.hpp"
#include "compiler.hpp"
#include "objects.hpp"
#include "error.hpp"

#define None nullptr
#define GLOBAL_OBJECT_SHOW_SIGN "@"
#define LOCAL_OBJECT_SHOW_SIGN "%"

namespace fs = std::filesystem;

NAMESPACE_DPP_BEGIN

const auto __stdout = std::cout.rdbuf();
const auto __stdin = std::cin.rdbuf();
const auto __stderr = std::cerr.rdbuf();

template<typename FSTREAM = std::fstream>
forceinline FSTREAM open_file(const std::string &file, std::ios_base::openmode openmode = std::ios_base::in,
                        void(* failed)(const std::string &, FSTREAM &) =
                                        [](const std::string &, FSTREAM &) -> void{
                                        }) {
    FSTREAM fs;
    fs.open(file, openmode);

    if(!fs.is_open()) {
        failed(file, fs);
        throw std::runtime_error("");
    }

    return fs;
}

template<typename FSTREAM = std::fstream>
forceinline void close_file(FSTREAM &fs) {
    fs.close();
}

forceinline bool get_files(std::vector<fs::path> &files, const fs::path &path,
            void(* failed)(const std::exception &) =
            [](const std::exception &e) -> void { std::cout << "error: " << e.what(); }) {
    try {
        files.clear();
        for (const auto &it : fs::directory_iterator(path)) {
            if (fs::is_directory(it.path()))
                continue;

            const fs::path &file = it.path();
            files.push_back(file);
        }
        return true;
    }
    catch (const std::exception &e) {
        failed(e);
    }
    return false;
}

forceinline void switch_ostream(auto stream = __stdout) {
    std::cout.rdbuf(stream);
}

forceinline void switch_istream(auto stream = __stdin) {
    std::cin.rdbuf(stream);
}

forceinline void switch_errorstream(auto stream = __stderr) {
    std::cerr.rdbuf(stream);
}

forceinline int run_script(const std::string &filename,
        void(* failed)(const std::string &, std::ifstream &) =
            [](const std::string &, std::ifstream &) -> void {}) {
    std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios_base::in);

    dpp::vm vm = compile(ifs);
    dpp::close_file<std::ifstream>(ifs);

    return dpp::run(vm, false);
}

/**
 * @brief Get the compile time
 */
forceinline std::string get_compile_time() {
    return std::format("{}.{}", __DATE__, __TIME__);
}

/**
 * @brief Get the compiler infos
 *
 * @return std::string
 */
forceinline std::string get_compiler_infos() {
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
forceinline const char *get_system_32bits_or_64bits() {
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
forceinline const char *get_platform() {
    return DXX_PLAT;
}

/**
 * @brief output infos in command line
 * like version, compiler, platform, etc.
 * @return void
 */
forceinline void output_information() {
    fmt::print("D++ ", DXX_VERSION, "(", dpp::get_compile_time(), ") ", "[", dpp::get_compiler_infos(), "] on ", dpp::get_platform());
}

/**
 * @brief Get the version string
 *
 * @param ver the version structure
 * @return std::string
 */
forceinline std::string get_version_string(Version ver) {
    return std::format("{}.{}", ver.ver.high, ver.ver.low);
}

/**
 * @brief Get the file type from magic number
 *
 * @param MagicNumber
 * @return std::string
 */
forceinline std::string get_file_type(const std::string &magic_number) {
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
forceinline std::string get_flags_name(char flag) {
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
forceinline void output_vm(dpp::vm vm, bool isOutputCopyright = true) {
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

NAMESPACE_DPP_END

#endif // !_INC_DXX_API
