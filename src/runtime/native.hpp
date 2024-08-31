#ifndef _NATIVE_LIB
#define _NATIVE_LIB

#ifdef _MSC_VER
// MSVC Compiler
#pragma warning(disable : 4244)
#endif // _MSC_VER

#include <string>
#include "acdpp.h"
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
DXX_API void FreeNativeLib(Module m);
DXX_API std::string WStrToPChar(std::wstring wstr);
DXX_API std::wstring stringToWstring(std::string str);
#endif // !_NATIVE_LIB
