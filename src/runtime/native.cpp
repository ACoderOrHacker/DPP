/*
  MIT License

  Copyright (c) 2023 ACoderOrHacker

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#include "native.hpp"

DXX_API Module OpenNativeLib(const char *libname) {
	Module module;
#ifdef _WIN32
	module = LoadLibrary(libname);
	if(module == NULL) {
		return nullptr;
	}
#else
    module = dlopen(libname, RTLD_LAZY);
    if(module == NULL) {
        return nullptr;
    }
#endif
	return module;
}

DXX_API NativeProc GetNativeProc(Module m, const char *procname) {
	NativeProc proc;
#ifdef _WIN32
	proc = GetProcAddress(m, TEXT(procname));
	if(proc == NULL) {
		return nullptr;
	}
#else
    proc = dlsym(m, procname);
    if(proc == NULL) {
        return nullptr;
    }
#endif
	return proc;
}

DXX_API bool FreeNativeLib(Module m) {
#ifdef _WIN32
	return FreeLibrary(m) == TRUE;
#else
    return dlclose(m) == 0;
#endif
}

DXX_API std::string WStrToPChar(std::wstring wstr) {
	return std::string(wstr.begin(), wstr.end());
}

DXX_API std::wstring stringToWstring(std::string str) {
	return std::wstring(str.begin(), str.end());
}

DXX_API std::string dpp::base::to_module_id(const std::string &lib) {
#ifdef _WIN32
    return lib + ".dll";
#elif defined(__linux__)
    return "lib" + lib + ".so";
#endif
}

dpp::native_module dpp::open(const std::string &lib) {
    dpp::native_module m;
    if ((m = OpenNativeLib(dpp::base::to_module_id(lib).c_str())) == nullptr) {
        throw std::runtime_error("Failed to open native library: " + lib);
    }

    return m;
}

DXX_API dpp::proc dpp::get_proc(dpp::native_module m, const std::string &proc_id) {

    dpp::proc _proc;
    if ((_proc = GetNativeProc(m, proc_id.c_str())) == nullptr) {
        throw std::runtime_error("Failed to get native proc address: " + proc_id);
    }

    return _proc;
}

DXX_API void dpp::close(dpp::native_module m) {
    if (!FreeNativeLib(m)) {
        throw std::runtime_error("Failed to close native library.");
    }
}
