#ifndef _NATIVE_LIB
#define _NATIVE_LIB

#ifdef _MSC_VER
// MSVC Compiler
#pragma warning(disable : 4244)
#endif // _MSC_VER

#include <string>
#include <stdexcept>
#include "acdpp.h"
#include "macros.hpp"
#ifdef _WIN32
#include <windows.h>
typedef HMODULE Module;
typedef FARPROC NativeProc;
#elif __linux__
#include <dlfcn.h>
typedef void *Module;
typedef void *NativeProc;
#endif

DXX_API Module OpenNativeLib(const char *libname);
DXX_API NativeProc GetNativeProc(Module m, const char *procname);
DXX_API bool FreeNativeLib(Module m);
DXX_API std::string WStrToPChar(std::wstring wstr);
DXX_API std::wstring stringToWstring(std::string str);

NAMESPACE_DPP_BEGIN

NAMESPACE_BASE_BEGIN

std::string to_module_id(const std::string &lib) {
#ifdef _WIN32
    return lib + ".dll";
#elif defined(__linux__)
    return "lib" + lib + ".so";
#endif
}

NAMESPACE_BASE_END

// Defines types

using native_module = Module;
using proc = NativeProc;

dpp::native_module open(const std::string &lib) {
    dpp::native_module m;
    if ((m = OpenNativeLib(dpp::base::to_module_id(lib).c_str())) == nullptr) {
        throw std::runtime_error("Failed to open native library: " + lib);
    }

    return m;
}

dpp::proc get_proc(dpp::native_module m, const std::string &proc_id) {

    dpp::proc _proc;
    if ((_proc = GetNativeProc(m, proc_id.c_str())) == nullptr) {
        throw std::runtime_error("Failed to get native proc address: " + proc_id);
    }

    return _proc;
}

void close(dpp::native_module m) {
    if (!FreeNativeLib(m)) {
        throw std::runtime_error("Failed to close native library.");
    }
}

forceinline std::string to_pchar(const std::wstring &wstr) {
    return WStrToPChar(wstr);
}

forceinline std::wstring to_wchar(const std::string &str) {
    return stringToWstring(str);
}

NAMESPACE_DPP_END
#endif // !_NATIVE_LIB
