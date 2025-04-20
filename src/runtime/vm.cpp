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

/*
  This is an external library that contains all the export functions of the VM
 */
#include "vm.hpp"

#include <cstdlib>
#include <stdexcept>

#include "builtin.hpp"
#include "eval.h"
#include "fmt.h"
#include "macros.hpp"
#include "native.hpp"
#include "objects.hpp"
#include "struct.hpp"
#include "error.hpp"



std::map<const char *, dpp::OpType> opcode_infos = {
    {"nop", dpp::OpType::NO_OPERANDS},
    {"push", dpp::OpType::ONE_OPERAND},
    {"pop", dpp::OpType::ONE_OPERAND},
    {"import", dpp::OpType::ONE_OPERAND}, // TODO
    {"add", dpp::OpType::THREE_OPERANDS},
    {"sub", dpp::OpType::THREE_OPERANDS},
    {"mul", dpp::OpType::THREE_OPERANDS},
    {"div", dpp::OpType::THREE_OPERANDS},
    {"mod", dpp::OpType::THREE_OPERANDS},
    {"bneg", dpp::OpType::TWO_OPERANDS},
    {"band", dpp::OpType::THREE_OPERANDS},
    {"bor", dpp::OpType::THREE_OPERANDS},
    {"bxor", dpp::OpType::THREE_OPERANDS},
    {"shl", dpp::OpType::THREE_OPERANDS},
    {"shr", dpp::OpType::THREE_OPERANDS},
    {"not", dpp::OpType::TWO_OPERANDS},
    {"eq", dpp::OpType::THREE_OPERANDS},
    {"bigger", dpp::OpType::THREE_OPERANDS},
    {"smaller", dpp::OpType::THREE_OPERANDS},
    {"and", dpp::OpType::THREE_OPERANDS},
    {"or", dpp::OpType::THREE_OPERANDS},
    {"jnt", dpp::OpType::TWO_OPERANDS},
    {"jnf", dpp::OpType::TWO_OPERANDS},
    {"jmp", dpp::OpType::ONE_OPERAND},
    {"call", dpp::OpType::ONE_OPERAND},
    {"ret", dpp::OpType::NO_OPERANDS},
    {"new", dpp::OpType::TWO_OPERANDS},
    {"del", dpp::OpType::ONE_OPERAND},
    {"mov", dpp::OpType::TWO_OPERANDS},
    {"method", dpp::OpType::THREE_OPERANDS}
};

VM_API const char *dpp::get_opcode_name(unsigned char opcode_id) {
    return std::next(opcode_infos.begin(), opcode_id - 1)->first;
}

VM_API dpp::OpType dpp::get_opcode_type(unsigned char opcode_id) {
    return std::next(opcode_infos.begin(), opcode_id - 1)->second;
}

VM_API dpp::vm dpp::create_vm(bool add_builtin) {
    dpp::vm vm = new FObject;
    if (!add_builtin) return vm;
    const auto &builtins = get_builtins();

    for (int32_t i = 0; i < BUILTIN::BUILTIN_END; ++i) {
        vm->obj_map.write({true, i}, builtins.at(i));
    }

    return vm;
}

std::string getDateString() {
    std::time_t t = std::time(nullptr);
    std::tm tm{};

#if defined(_WIN32)
    localtime_s(&tm, &t);  // Windows
#else
    localtime_r(&t, &tm);  // Linux/macOS
#endif

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d-%H-%M-%S");
    return ss.str();
}

VM_API int dpp::run(dpp::vm vm, bool noExit) {
#ifdef Dpp_LOG_IN_FILE
    std::ofstream log_file(dpp::get_logdir() / "log-dpp" /
                           (getDateString() + ".log"));
    vm->log = dpp::logger(dynmaic_cast<std::ostream &>(log_file));
#else
    vm->log = dpp::logger(std::cout);
#endif

    dpp::bytecode code;
    try {
        while (vm->state.vmopcodes.size() > vm->state.runat) {
            code = vm->state.vmopcodes.GetData(
                vm->state.runat);  // get opcode from state

            EVAL_STATUS isfail = EVAL_SUCCESS;
            // execute the opcode and get the error code(isfail variable)
            isfail = dpp::eval(vm, code);

            if (isfail == EVAL_FAILED) {
                dpp::catch_error(vm);
            }

            if (vm->state.vmopcodes.size() == vm->state.runat &&
                !vm->callstack.empty()) {
                exit_frame(vm);
            }

            ++vm->state.runat;
        }
    } catch (InternalError &e) {
        vm->exit_code = EXIT_FAILURE;
        vm->log << "[ERROR] Internal error: " << e.what() << "\n";
        goto EXIT;
    }

EXIT:

#ifdef Dpp_LOG_IN_FILE
    log_file.close();
#endif

    // exit
    int exit_code = vm->exit_code;
    // TODO: there is a bug when delete
    // dpp::delete_vm(vm);
    if (!noExit) exit(exit_code);
    return exit_code;
}
