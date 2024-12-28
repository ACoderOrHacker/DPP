#ifndef _NATIVE_LIB
#define _NATIVE_LIB

#ifdef _MSC_VER
// MSVC Compiler
#pragma warning(disable : 4244)
#endif // _MSC_VER

#include <string>
#include <stdexcept>
#include <dylib.hpp>
#include "acdpp.h"
#include "macros.hpp"

DXX_API std::string WStrToPChar(std::wstring wstr);
DXX_API std::wstring stringToWstring(std::string str);

NAMESPACE_DPP_BEGIN

// Defines types

using native_module = dylib;
using proc = dylib::native_symbol_type;

DXX_API dpp::native_module open(const std::string &lib);
DXX_API dpp::proc get_proc(const dpp::native_module &m, const std::string &proc_id);
DXX_API void close(dpp::native_module m);

forceinline std::string to_pchar(const std::wstring &wstr) {
    return WStrToPChar(wstr);
}

forceinline std::wstring to_wchar(const std::string &str) {
    return stringToWstring(str);
}

NAMESPACE_DPP_END
#endif // !_NATIVE_LIB
