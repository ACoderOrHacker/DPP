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
#include <streambuf>
#include <string>
#include <cereal/details/helpers.hpp>
#include "cereal/archives/json.hpp"
#include "configs.h"
#include <dpp/defines.h>

#ifdef _DXX_EXPORT
#undef _DXX_EXPORT
#endif // _DXX_EXPORT

#include "struct.hpp"
#include "serialize.hpp"
#include "vm.hpp"
#include "compiler.hpp"
#include "fmt.h"
#include "objects.hpp"
#include "error.hpp"

#define None nullptr

NAMESPACE_DPP_BEGIN

const auto __stdout = std::cout.rdbuf();
const auto __stdin = std::cin.rdbuf();
const auto __stderr = std::cerr.rdbuf();

/**
 * @brief check if a string start with a prefix
 *
 * @param str a string
 * @param prefix the prefix
 * @return true the string start with the prefix
 * @return false the string not start with the prefix
 */
bool startswith(const std::string &str, const std::string &prefix) {
    return str.rfind(prefix, 0) == 0;
}

/**
 * @brief open a file with openmode
 *
 * @tparam FSTREAM file stream type
 * @param file the file to open
 * @param openmode open the file with this mode
 * @param failed calls it if this function not found the file
 * @return FSTREAM the opened file stream
 */
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

/**
 * @brief close a file
 *
 * @tparam FSTREAM file stream type
 * @param fs the file stream to close
 * @return void
 */
template<typename FSTREAM = std::fstream>
forceinline void close_file(FSTREAM &fs) {
    fs.close();
}

/**
 * @brief get the files in the path
 *
 * @param files the results of this function
 * @param path the path to get the files
 * @param failed calls it if this function failed
 * @return bool return true if success, otherwise return false
 */
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

/**
 * @brief get stem from file
 *
 * @param path the file path
 */
forceinline std::string get_stem(const fs::path &path) {
    return path.filename().stem().string();
}

/**
 * @brief get stem from file
 *
 * @param path the file path
 */
forceinline std::string get_stem(const std::string &path) {
    return fs::path(path).filename().stem().string();
}

/**
 * @brief switch the standard output stream(std::cout) to other stream
 *
 * @param stream the stream to switch to
 * @return void
 */
forceinline void switch_ostream(std::streambuf *stream = __stdout) {
    std::cout.rdbuf(stream);
}

/**
 * @brief switch the standard input stream(std::cin) to other stream
 *
 * @param stream the stream to switch to
 * @return void
 */
forceinline void switch_istream(std::streambuf *stream = __stdin) {
    std::cin.rdbuf(stream);
}

/**
 * @brief switch the standard error stream(std::cerr) to other stream
 *
 * @param stream the stream to switch to
 * @return void
 */
forceinline void switch_errorstream(std::streambuf *stream = __stderr) {
    std::cerr.rdbuf(stream);
}

/**
 * @brief run a D++ Program file as a script
 *
 * @param filename the file to run
 * @param failed calls it if this function not found the file
 * @return int returns the exit code
 */
forceinline int run_script(const std::string &filename,
        void(* failed)(const std::string &, std::ifstream &) =
            [](const std::string &, std::ifstream &) -> void {},
        bool is_output = false) {
    std::ifstream ifs = dpp::open_file<std::ifstream>(filename, std::ios_base::in, failed);

    dpp::vm vm = dpp::compile(ifs, filename, is_output);
    dpp::close_file<std::ifstream>(ifs);

    return dpp::run(vm, false);
}

/**
 * @brief get D++ compile time
 *
 * @return std::string the formated string
 */
forceinline std::string get_compile_time() {
    return std::string(__DATE__) + ", " + __TIME__;
}

/**
 * @brief Get D++ compiler infos
 *
 * @return std::string the formated compiler information
 */
forceinline std::string get_compiler_infos() {
#ifdef __clang__
    return std::to_string(__clang_major__) + "." + std::to_string(__clang_minor__) + "." + std::to_string(__clang_patchlevel__);
#elif defined(__GNUC__)
    return std::to_string(__GNUC__) + "." + std::to_string(__GNUC_MINOR__) + "." + std::to_string(__GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    return std::string("MSC .v") + std::to_string(_MSC_VER);
#else
    return "unknown";
#endif
}

/**
 * @brief get the system is 32bit or 64bit
 * @warning this function can only get 32-bit or 64-bit, others will return "unknown" (include 8-bit, etc)
 *
 * @return const char * "32-bit" or "64-bit"
 */
forceinline const char *get_system_32bits_or_64bits() {
    constexpr void *ptr = nullptr;
    switch (sizeof(ptr)) {
        case 8:
            return "64-bit";
            break;
        case 4:
            return "32-bit";
            break;
        default:
            return "unknown";
            break;
    }
}

/**
 * @brief get the platform infos
 *
 * @return const char * the platform string
 */
forceinline const char *get_platform() {
    return DXX_PLAT;
}

/**
 * @brief output infos in command line
 * like version, compiler, platform, etc.
 *
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
    return std::to_string(ver.ver.high) + "." + std::to_string(ver.ver.low);
}

/**
 * @brief get a virtual machine from files
 *
 * @param file the file name
 * @param cfg the runtime configures
 * @param nofile_failed the callback when file not found
 * @param load_failed the callback when load failed
 * @param cfg_failed the callback when load runtime configures failed
 */
forceinline dpp::vm get_vm(const std::string &file, dpp::runtime_config &cfg,
    void (* nofile_failed)(const std::string &, std::ifstream &) = [](const std::string &file, std::ifstream &) -> void {
                            fmt::print_error("cannot open file '", file, "'\n");
                            exit(EXIT_FAILURE);
                        },
    void (* load_failed)(cereal::Exception &) = [](cereal::Exception &e) {
                        fmt::print_error("error: invaild input file\n");
                        fmt::print_error("    message: ", e.what(), "\n");
                        exit(EXIT_FAILURE);
                    },
    void (* cfg_failed)(cereal::Exception &) = [](cereal::Exception &e) {
                        fmt::print_error("error: invaild input file\n");
                        fmt::print_error("    message: ", e.what(), "\n");
                        exit(EXIT_FAILURE);
                    }) {
    std::ifstream fs = dpp::open_file<std::ifstream>(file,
                        std::ios::binary,
                        nofile_failed);

    dpp::vm vm = dpp::create_vm(false);
    *vm = dpp::serialize::load<FObject>(dynamic_cast<std::istream &>(fs),
                    load_failed);

    const fs::path &filepath = fs::path(file);
    const fs::path &cfgpath = filepath.parent_path() / (dpp::get_stem(filepath) + ".runtime-cfg.json");
    if (fs::exists(cfgpath)) {
        cfg = read_runtime_config(cfgpath.string());
    } else {
        cfg = dpp::runtime_config();
    }

    dpp::close_file(fs);
    return vm;
}

/**
 * @brief create a virtual machine to files
 *
 * @param file the file name
 * @param vm the virtual machine
 * @param create_failed the callback when create files
 * @param load_failed the callback whne load failed
 */
forceinline dpp::vm set_vm(const std::string &file, dpp::vm vm,
    void (* create_failed)(const std::string &, std::ofstream &) = [](const std::string &file, std::ofstream &) -> void {
        fmt::print_error("error: cannot create '", get_stem(file), ".dppo", "'. maybe you have no premission.\n");
        exit(EXIT_FAILURE);
    },
    void (* load_failed)(cereal::Exception &) = [](cereal::Exception &e) {
                            fmt::print_error("error: internal error\n");
                            fmt::print_error("    message: ", e.what(), "\n");
                            exit(EXIT_FAILURE);
                        }) {
    std::ofstream ofs = dpp::open_file<std::ofstream>(file, std::ios::binary,
        create_failed);

    dpp::serialize::save<FObject>(ofs, *vm,
                        load_failed);

    dpp::close_file(ofs);

    return vm;
}

/**
 * @brief get the file type from magic number
 *
 * @param magic_number
 * @return std::string the file type string
 */
forceinline std::string get_file_type(const std::string &magic_number) {
    if(magic_number == "DPPO") {
        return "D++ Object File";
    } else {
        return "Unknown";
    }
}

/**
 * @brief output vm structure to command line
 *
 * @param vm the vm instance
 * @param isOutputInformation output information of dpp if is true
 */
forceinline void output_vm(dpp::vm vm, bool isOutputInformation = true) {
    const auto &opt_state = [](::VMState &state) -> void {
        uint32_t i = 0;
        for(auto &it : state.vmopcodes) {
            std::string s;

            s += std::string("    .") + std::to_string(i) + ": " + dpp::get_opcode_name(it.opcode) + " ";

            for (auto &param : it.params) {
                s += std::string(param.isInGlobal ? GLOBAL_OBJECT_SHOW_SIGN : LOCAL_OBJECT_SHOW_SIGN) + std::to_string(param.id) + std::string(" ");
            }
            fmt::print(s, "\n");

/*
            size_t space_num = 100 - s.size();
            if (space_num > 0) {
                fmt::print(std::string(space_num, ' '));
            } else {
                // space_num <= 0
                // std::length_error: string too long
                fmt::print(std::string(s.size() + 10, ' '));
            }*/
            ++i;
        }
    };

    if (isOutputInformation) dpp::output_information();

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
    if (vm->state.vmopcodes.isEmpty()) { fmt::print("state: {}\n"); }
    else {
        fmt::print("state: {\n");
        opt_state(vm->state);
        fmt::print("}\n");
    }

    fmt::print("\n");
    uint32_t i = 0;
    for (auto it : gmap) {
        if (it != nullptr && it->name != "function" && dpp::is_function(it)) {
            fmt::print("function ", it->name.empty() ? "unknown" : it->name, "(", GLOBAL_OBJECT_SHOW_SIGN, i, "): {", "\n");
            opt_state(_cast(FunctionObject *, it)->state);
            fmt::print("}\n\n");
        }
        ++i;
    }

    fmt::print("\n");
    fmt::print("global: {\n");
    for(uint32_t index = BUILTIN_END; index < gmap.size(); ++index) {
        auto obj = gmap[index];
		if (obj == nullptr) {
            fmt::print("    .", index, ": unknown\n");
            continue;
        }

        try {
            fmt::print("    .", index, ": ", object_to_datastring(obj), "\n");
        } catch (NoOperatorError &) {
            fmt::print("    .", index, ": unknown\n");
        }
    }
    fmt::print("}\n");
}

std::vector<std::string> string_split(const std::string &str, char delim) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

NAMESPACE_DPP_END

#endif // !_INC_DXX_API
