//
// Created by ACoder on 2024/7/3.
//

#ifndef DPP_MODULES_H
#define DPP_MODULES_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fmt/core.h>

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

#endif //DPP_MODULES_H
