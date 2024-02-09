#ifndef _NATIVE_LIB
#define _NATIVE_LIB

#ifdef _MSC_VER
// MSVC Compiler
#pragma warning(disable : 4244)
#endif // _MSC_VER

#include <string>

#ifdef _WIN32
#include <windows.h>
typedef HMODULE Module;
typedef FARPROC NativeProc;
#elif __linux__
#include <dlfcn.h>
#endif

Module OpenNativeLib(const char *libname);
NativeProc GetNativeProc(Module m, const char *procname);
void FreeNativeLib(Module m);
const char *WStrToPChar(std::wstring wstr);

#endif // !_NATIVE_LIB
