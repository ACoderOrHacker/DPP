#ifndef _DPP_PATHS_HPP
#define _DPP_PATHS_HPP
#include <filesystem>
#include "macros.hpp"

#ifdef _WIN32
#include <windows.h>
#else
#include <limits.h>
#include <unistd.h>
#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif
#endif

NAMESPACE_DPP_BEGIN

/**
 * @brief get the exectuable directory
 * @details 
 * $(installdir)
 *    -- bin/  the program is there
 *
 * @return std::filesystem::path the executable directory
 */
inline std::filesystem::path get_exepath() {
    std::filesystem::path exe_path;

#ifdef _WIN32
    char buffer[MAX_PATH];
    DWORD length = GetModuleFileNameA(nullptr, buffer, MAX_PATH);
    if (length == 0) return {};
    exe_path = buffer;

#elif defined(__APPLE__)
    char buffer[PATH_MAX];
    uint32_t size = PATH_MAX;
    if (_NSGetExecutablePath(buffer, &size) != 0) {
        buffer[size] = '\0';
    }
    char real_path[PATH_MAX];
    if (realpath(buffer, real_path) == nullptr) return {};
    exe_path = real_path;

#else
    char buffer[PATH_MAX];
    ssize_t length = readlink("/proc/self/exe", buffer, PATH_MAX);
    if (length == -1) return {};
    buffer[length] = '\0';
    exe_path = buffer;
#endif

    if (exe_path.empty()) return {};
    return exe_path;
}

/**
 * @brief get the install directory
 */
inline std::filesystem::path get_installdir() {
    return get_exepath().parent_path().parent_path();
}


NAMESPACE_DPP_END

#endif // !_DPP_PATHS_HPP