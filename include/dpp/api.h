#ifndef _INC_DXX_API
#define _INC_DXX_API

#include <iostream>
#include <fstream>
#include <ios>
#include <stdexcept>
#include <filesystem>

#include "vm.hpp"
#include "objects.hpp"
#include "acoder/acassert/acassert.h"
#define _DXX_API

#define None nullptr

namespace fs = std::filesystem;

NAMESPACE_DPP_BEGIN

const auto __stdout = std::cout.rdbuf();
const auto __stdin = std::cin.rdbuf();
const auto __stderr = std::cerr.rdbuf();

std::fstream open_file(const std::string &file, std::ios_base::openmode openmode = std::ios_base::in,
                        void(* failed)(const std::string &, std::fstream &) =
                                        [](const std::string &, std::fstream &) -> void{}) {
    std::fstream fs;
    fs.open(file, openmode);

    if(!fs.is_open()) {
        failed(file, fs);
        throw std::runtime_error("");
    }

    return fs;
}

void close_file(std::fstream &fs) {
    fs.close();
}

bool get_files(std::vector<fs::path> &files, const fs::path &path,
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

void switch_ostream(auto stream = __stdout) {
    std::cout.rdbuf(stream);
}

void switch_istream(auto stream = __stdin) {
    std::cin.rdbuf(stream);
}

void switch_errorstream(auto stream = __stderr) {
    std::cerr.rdbuf(stream);
}

/**
 * @brief check the object is true or false
 *
 * @param obj
 * @return true
 * @return false
 */
bool is_true(dpp::object *obj) {
    acassert(obj == nullptr);

    return obj->is_true();
}

/**
 * @brief clean the vm
 *
 * @param vm
 */
void delete_vm(dpp::vm vm) {
    acassert(vm == nullptr);

	delete vm;
	vm = nullptr;
}

bool call_function(dpp::vm vm,
    FunctionObject *func,
    uint32_t _paramnum,
    ...) {
    va_list l;
    va_start(l, _paramnum);
    uint32_t paramnum = _paramnum;

    uint32_t create_frame = vm->obj_map.getLastCreateID();
    struct VMState jmp_state = func->state;
    vm->obj_map.create_mapping(create_frame, jmp_state.isLambda);

    // Save the last state
    struct VMState state = vm->state;
    vm->callstack.push(state);
    vm->state = jmp_state;
    vm->state.runat = 0;

    while (_paramnum > 0) {
        vm->obj_map.write({false, paramnum - _paramnum}, va_arg(l, Dpp_Object *));

        --paramnum;
    }

    return true;
}

NAMESPACE_DPP_END

#endif // !_INC_DXX_API
