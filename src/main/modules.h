#ifndef DPP_MODULES_H
#define DPP_MODULES_H

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif // _MSC_VER

#include "vm.hpp"
#include "serialization/Serialization.hpp"
#undef error
#undef theap

#include <filesystem>
#include <boost/json.hpp>
#include <fmt/core.h>
#include <fmt/color.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

fs::path root = fs::current_path().parent_path();
const fs::path examples_path = root / "examples";

auto *__stdout = std::cout.rdbuf();
auto *__stdin = std::cin.rdbuf();

std::string GetCompileDate() {
    return fmt::format("{} {}", __DATE__, __TIME__);
}

std::string GetCompilerInfo() {
#ifdef __clang__
    return fmt::format("{}.{}.{}", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    return fmt::format("{}.{}.{}", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL);
#elif defined(_MSC_VER)
    return fmt::format("MSC .v{}", _MSC_VER);
#else
    return "Unknown";
#endif
}

const char *Get64BitOr32Bit() {
#if defined(__LP64__) || defined(_WIN64)
    return "64bit";
#else
    return "32bit";
#endif
}

const char *GetPlatform() {
#if defined(_WIN32)
    return "win32";
#elif defined(__linux__)
    return "linux";
#else
    return "unknown platform";
#endif
}

void OutputInformation() {
    auto opt = fmt::format("D++ {} ({}) [{} {}] on {}\n",
                            DXX_VERSION,
                            GetCompileDate(),
                            GetCompilerInfo(),
                            Get64BitOr32Bit(),
                            GetPlatform());

    std::cout << opt;
}

std::string GetVersionString(Version ver) {
    return fmt::format("{}.{}", ver.ver.high, ver.ver.low);
}

std::string GetFileTypeFromMagicNumber(const std::string &MagicNumber) {
    if(MagicNumber == "DPPO") {
        return "D++ Object File";
    } else {
        return "Unknown";
    }
}

void OutputFileHeader(const FileHeader &header) {
    fmt::print("FileHeader:\n");
    fmt::print("    Type: {}", GetFileTypeFromMagicNumber(header.MagicNumber));
    fmt::print("    Compile Version: {}", GetVersionString(header.version));
    fmt::print("    Lowest Version: {}", GetVersionString(header.LowestVersion));
}

std::string GetFlagsName(char flag) {
    if(flag == NO_FLAG) {
        return "null";
    }

    std::string s;
    for(int i = 1; i <= 8; ++i) {
        if(GetBit(flag, i)) {
            s += fmt::format("{} ", GetFlagName(i));
        }
    }

    return s;
}

void OutputS_FObject(S_FObject *s_fObj, bool isOutputCopyright = true) {
    auto opt_state = [](struct VMState state) -> void {
        uint32_t i = 0;
        for(auto &it : state.vmopcodes) {
            std::string s;

            s += fmt::format("    [{}] {} ", i, GetOpcodeName(it.opcode));

            for (auto &param : it.params) {
                s += fmt::format("[{}, {}] ", param.isInGlobal ? "Global" : "Local", param.id);
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
            fmt::print("flag: {}\n", GetFlagsName(it.flag));

            ++i;
        }
    };
    fmt::print("\n");
    if (isOutputCopyright) fmt::print("D++ Debug Tools. Copyright (c) ACoderOrHacker. All rights reserved.\n");

    OutputFileHeader(s_fObj->header);

    fmt::print("\n");
    fmt::print("Dependent modules: \n");
    for(auto &it: s_fObj->modules) {
        fmt::print("    {}\n", it);
    }

    fmt::print("\n");
    fmt::print("Main State: \n");
    opt_state(s_fObj->state);

    fmt::print("\n");
    uint32_t i = 0;
    for (auto it : s_fObj->global_mapping) {
        if (it != nullptr && it->reg != nullptr && it->name != "function" && it->reg->type == FUNCTION_TYPE) {
            fmt::print("Function: {} [Global, {}]\n", it->name.empty() ? "unknown" : it->name, i);
            opt_state(_cast(FunctionObject *, it)->state);
            fmt::print("\n");
        }
        ++i;
    }

    fmt::print("\n");
    fmt::print("Global Object Mapping:\n");
    for(uint32_t index = BUILTIN_END; index < s_fObj->global_mapping.size(); ++index) {
        Dpp_Object *obj = s_fObj->global_mapping[index];
        fmt::print("    [{}] {}\n", index, to_string(obj));
    }
}

void OutputFObject(FObject *fObj, bool isOutputCopyright = true) {
    OutputS_FObject(GetS_FObject(fObj), isOutputCopyright);
}

bool GetFiles(std::vector<fs::path> &files, const fs::path &path) {
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
        std::cout << "error: " << e.what();
    }
    return false;
}

void SetOstream(const std::stringstream &stream) {
    std::cout.rdbuf(stream.rdbuf());
}

auto *GetOstream() {
    return std::cout.rdbuf();
}

void RestoreOstream() {
    std::cout.rdbuf(__stdout);
}

void CheckTest(const std::string &id, const std::string &buf) {
    std::ifstream file;
    fs::path tests_path(examples_path / "tests.json");
    file.open(tests_path.string());
    if (!file.is_open()) {
        fmt::print(fmt::fg(fmt::color::red), "\nerror: cannot find tests.json file\n");
        exit(1);
    }
    boost::json::value jv = boost::json::parse(file);
    boost::json::object &json = jv.as_object();

    boost::json::array &tests = json["tests"].as_array();
    for (auto &it : tests) {
        boost::json::object &test = it.as_object();
        const std::string &_id = test["id"].as_string().c_str();
        if (_id == id) {
            const std::string &_buf = test["buf"].as_string().c_str();
            if (buf != _buf) {
                fmt::print(fmt::fg(fmt::color::red), "\nerror: test '{}' failed, result is wrong\n", id);
                fmt::print("    Source buffer: {}\n", _buf);
                fmt::print("    Buffer: {}\n", buf);
                exit(1);
            }
        }
    }

    fmt::print(fmt::fg(fmt::color::green), "\nTest {} passed\n", id);
}

#endif //DPP_MODULES_H
