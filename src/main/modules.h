//
// Created by ACoder on 2024/7/3.
//

#ifndef DPP_MODULES_H
#define DPP_MODULES_H

#define _CRT_SECURE_NO_WARNINGS

#include <boost/filesystem.hpp>
#include <fmt/core.h>
#include <iostream>

#include "vm.hpp"
#include "serialization/Serialization.hpp"

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
    auto opt = fmt::format("D++ {} ({}) [{} {}] on {}\n", DXX_VERSION,
                           GetCompileDate(),
                           GetCompilerInfo(),
                           Get64BitOr32Bit(),
                           GetPlatform());

    std::cout << opt;
}

std::string GetVersionString(Version ver) {
    return fmt::format("{}.{}", ver.ver.high, ver.ver.low);
}

std::string GetFileTypeFromMagicNumber(std::string MagicNumber) {
    if(MagicNumber == "DPPO") {
        return "D++ Object File";
    } else {
        return "Unknown";
    }
}

void OutputFileHeader(FileHeader header) {
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

void OutputS_FObject(S_FObject *_s_fObj, bool isOutputCopyright = true) {
    S_FObject __s_fObj;
    __s_fObj = *_s_fObj;
    S_FObject *s_fObj = &__s_fObj;
    fmt::print("\n");
    if (isOutputCopyright) fmt::print("D++ Debug Tools. Copyright (c) ACoderOrHacker. All rights reserved.\n");

    OutputFileHeader(s_fObj->header);

    fmt::print("\n");
    fmt::print("Dependent modules: \n");
    for(auto it: s_fObj->modules) {
        fmt::print("    {}\n", it);
    }

    uint32_t i = 0;
    fmt::print("\n");
    fmt::print("Main State: \n");
    while(s_fObj->state.vmopcodes.size() > 0) {
        OpCode it = s_fObj->state.vmopcodes.PopData();
        std::string s;

        s += fmt::format("    [{}] {} ", i, GetOpcodeName(it.opcode));
        while(it.params.size() > 0) {
            Object param = it.params.PopData();
            s += fmt::format("[{}, {}] ", param.isInGlobal ? "Global" : "Local", param.id);
        }
        std::cout << s;
        int space_num = 100 - s.size();
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

bool GetFiles(std::vector<boost::filesystem::path> &files, boost::filesystem::path path) {
    try {
        files.clear();
        for (const auto &it : boost::filesystem::directory_iterator(path)) {
            if (boost::filesystem::is_directory(it.path()))
                continue;

            boost::filesystem::path file = it.path();
            files.push_back(file);
        }
        return true;
    }
    catch (const std::exception &e) {
        std::cout << "error: " << e.what();
    }
    return false;
}

#endif //DPP_MODULES_H
