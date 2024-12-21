/**
 * @file api.h

 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief D++ Application Programming Interface
 *
 */

///
/// THIS FILE IS FOR USER BUT NOT FOR VM & COMPILER
/// DO NOT INCLUDE THIS FILE IN VM & COMPILER OR OTHER COMPOMENTS
///

#ifndef _INC_DXX_API
#define _INC_DXX_API

#include <iostream>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <filesystem>

#ifdef _DXX_EXPORT
#undef _DXX_EXPORT
#endif // _DXX_EXPORT

#ifdef WIN32
#define NOMINMAX
#endif

#include "compiler.hpp"
#include "objects.hpp"
#include "error.hpp"
#include "acassert.h"

#define None nullptr

namespace fs = std::filesystem;

NAMESPACE_DPP_BEGIN

const auto __stdout = std::cout.rdbuf();
const auto __stdin = std::cin.rdbuf();
const auto __stderr = std::cerr.rdbuf();

template<typename FSTREAM = std::fstream>
forceinline FSTREAM open_file(const std::string &file, std::ios_base::openmode openmode = std::ios_base::in,
                        void(* failed)(const std::string &, FSTREAM &) =
                                        [](const std::string &, FSTREAM &) -> void{
                                        }) {
    FSTREAM fs;
    fs.open(file, openmode);

    if(!fs.is_open()) {
        failed(file, fs);
        throw std::runtime_error("");
    }

    return fs;
}

template<typename FSTREAM = std::fstream>
forceinline void close_file(FSTREAM &fs) {
    fs.close();
}

forceinline bool get_files(std::vector<fs::path> &files, const fs::path &path,
            void(* failed)(const std::exception &) =
            [](const std::exception &e) -> void { std::cout << "error: " << e.what(); }) {
    try {
        files.clear();
        for (const auto &it : fs::directory_iterator(path)) {
            if (fs::is_directory(it.path()))
                continue;

            const fs::path &file = it.path();
            files.push_back(file);
        }
        return true;
    }
    catch (const std::exception &e) {
        failed(e);
    }
    return false;
}

forceinline void switch_ostream(auto stream = __stdout) {
    std::cout.rdbuf(stream);
}

forceinline void switch_istream(auto stream = __stdin) {
    std::cin.rdbuf(stream);
}

forceinline void switch_errorstream(auto stream = __stderr) {
    std::cerr.rdbuf(stream);
}

NAMESPACE_DPP_END

#endif // !_INC_DXX_API
