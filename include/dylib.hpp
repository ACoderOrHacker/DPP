/**
 * @file dylib.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief C++ cross-platform wrapper around dynamic loading of shared libraries
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _DYLIB_HPP_
#define _DYLIB_HPP_
#include <stdexcept>
#if ((defined(_MSVC_LANG) && _MSVC_LANG >= 201703L) || __cplusplus >= 201703L)
#define DYLIB_CPP17
#include <filesystem>
#endif

#if (defined(_WIN32) || defined(_WIN64))
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class dylib {
    constexpr static const char *prefix =
#if defined(_WIN32) || defined(_WIN64)
        "";
#else
        "lib";
#endif
    constexpr static const char *suffix =
#if defined(_WIN32) || defined(_WIN64)
        ".dll";
#elif defined(__APPLE__)
        ".dylib";
#else
        ".so";
#endif

public:
    using native_handle_type =
#if defined(_WIN32) || defined(_WIN64)
        HMODULE;
#else
        void *;
#endif

    using native_symbol_type =
#if defined(_WIN32) || defined(_WIN64)
        FARPROC;
#else
        void *;
#endif

    class exception : public std::runtime_error {
    public:
        explicit exception(const std::string &msg) : std::runtime_error(msg) {}
    };

    dylib() = default;

    dylib(const std::string &lib, bool decorations = true) {
        std::string libname;
        if (decorations) libname = prefix + lib + suffix;
        else libname = lib;

        open(libname);
    }

    dylib(const std::filesystem::path &lib) {
        open(lib);
    }


    ~dylib() {
        close();
    }

    /**
     * @brief open file to handle
     *
     * @param path
     */
    void open(const std::string &path) {
#if defined(_WIN32) || defined(_WIN64)
        handle = LoadLibrary(path.c_str());
#else
        handle = dlopen(path.c_str(), RTLD_LAZY);
#endif
        if (!handle) throw exception("no such file");
    }

#ifdef DYLIB_CPP17
    /**
     * @brief open file to handle
     *
     * @param path file path
     */
    void open(const std::filesystem::path &path) {
        open(path.string());
    }
#endif

    /**
     * @brief close handle
     *
     */
    void close() {
#if defined(_WIN32) || defined(_WIN64)
        if (handle != nullptr) FreeLibrary(handle);
#else
        if (handle != nullptr) dlclose(handle);
#endif
    }

    /**
     * @brief Get symbol from library
     *
     * @param name the symbol name
     * @return native_symbol_type the symbol
     */
    [[nodiscard]] native_symbol_type get_symbol(const std::string &name) const {
        native_symbol_type sym = nullptr;

#if defined(_WIN32) || defined(_WIN64)
        sym = GetProcAddress(handle, name.c_str());
#else
        sym = dlsym(handle, name.c_str());
#endif
        if (!sym) {
            throw dylib::exception("no such symbol " + name);
        }

        return sym;
    }

    /**
     * @brief get function from library
     *
     * @tparam T function type
     * @param func the function name
     * @return T * the function pointer
     */
    template<typename T>
    [[nodiscard]] T *get_function(const std::string &func) const {
        return reinterpret_cast<T *>(get_symbol(func));
    }

    bool has_symbol(const std::string &name) const {
        return get_symbol(name) != nullptr;
    }

private:
    native_handle_type handle {nullptr};
};

#endif // !_DYLIB_HPP_