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
#include "dylib.hpp"

DXX_API std::string WStrToPChar(std::wstring wstr) {
	return std::string(wstr.begin(), wstr.end());
}

DXX_API std::wstring stringToWstring(std::string str) {
	return std::wstring(str.begin(), str.end());
}

dpp::native_module dpp::open(const std::string &lib) {
    try {
        return dpp::native_module(lib);
    } catch (dylib::exception &) {
        throw std::runtime_error("Failed to open native library:" + lib);
    }
}

DXX_API dpp::proc dpp::get_proc(const dpp::native_module &m, const std::string &proc_id) {
    try {
        return m.get_symbol(proc_id);
    } catch (dylib::exception &) {
        throw std::runtime_error("Failed to get native proc address: " + proc_id);
    }
}

DXX_API void dpp::close(dpp::native_module m) {
    m.close();
}
