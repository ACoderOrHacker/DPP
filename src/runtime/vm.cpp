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
#include <cstdlib>
#include <stdexcept>
#include "vm.hpp"
#include "builtin.hpp"
#include "fmt.h"
#include "macros.hpp"
#include "native.hpp"
#include "objects.hpp"
#include "opcodes.hpp"
#include "struct.hpp"

Dpp_DEFINE_ERROR(InternalError)

const OpcodeFunc opcode_list[256] = {
    &_import,
	&_add,
	&_sub,
	&_mul,
	&_div,
	&_mod,
	&_bneg,
	&_band,
	&_bor,
	&_bxor,
	&_shl,
	&_shr,
	&_not,
	&_eq,
	&_bigger,
	&_smaller,
	&_and,
	&_or,
	&_jnt,
    &_jnf,
    &_jmp,
	&_call,
    &_getret,
	&_calln,
	&_ret,
	&_new,
    &_del,
	&_mov,
    &_method
};

const char *opcode_name_list[256] = {
    "import",
    "add",
    "sub",
    "mul",
    "div",
    "mod",
    "bneg",
    "band",
    "bor",
    "bxor",
    "shl",
    "shr",
    "not",
    "eq",
    "bigger",
    "smaller",
    "and",
    "or",
    "jnt",
    "jnf",
    "jmp",
    "call",
    "getret",
    "calln",
    "ret",
    "new",
    "del",
    "mov",
    "method"
};

VM_API const char *dpp::get_opcode_name(unsigned char opcode_id) {
    return opcode_name_list[opcode_id - 1];
}

VM_API dpp::vm dpp::create_vm(bool add_builtin) {
    dpp::vm vm = new FObject;
    if (!add_builtin) return vm;
	const auto &builtins = get_builtins();

	for(uint32_t i = 0; i < BUILTIN::BUILTIN_END; ++i) {
		vm->obj_map.write({ true, i }, builtins.at(i));
	}

	return vm;
}

VM_API int dpp::run(dpp::vm vm, bool noExit) {
    uint32_t i = 0;
    for (auto &it : vm->modules) {
        try {
            vm->NativeModules.write(i, dpp::open(it), true /* unused */);
        } catch(std::runtime_error &) {
            fmt::print_error("startup: cannot load dynamic library ", it, "\n");
            vm->exit_code = EXIT_FAILURE;
            goto EXIT;
        }
    }

	while(vm->state.vmopcodes.size() > vm->state.runat) {
		const OpCode &opcode = vm->state.vmopcodes.GetData(vm->state.runat); // get opcode from state

        bool isfail = EXEC_SUCCESS;
        try {
            // execute the opcode and get the error code(isfail variable)
		    isfail = dpp::exec(opcode, vm);
        } catch (InternalError &) {
            vm->exit_code = EXIT_FAILURE;
            goto EXIT;
        }

		if(isfail == EXEC_FAILED && vm->_error != nullptr) {
            dpp::catch_error(vm);
		}

        if (vm->state.vmopcodes.size() == vm->state.runat && !vm->callstack.empty()) {
            vm->state = vm->callstack.top();
            vm->callstack.pop();
            vm->obj_map.pop_mapping();
            vm->return_values.push(nullptr);

            ++vm->state.runat;
            continue;
        }

        if (opcode.opcode != OPCODE_CALL) ++vm->state.runat;
	}

EXIT:
	// exit
	int exit_code = vm->exit_code;
    // TODO: there is a bug when delete
	// dpp::delete_vm(vm);
	if (!noExit) exit(exit_code);
    return exit_code;
}

VM_API bool dpp::exec(const OpCode &opcode, dpp::vm vm) {
    *vm->_theap = opcode.params; // write the params to the 'vm->_theap' for the opcode

	if(opcode.opcode > OPCODE_START && opcode.opcode < OPCODE_END) {
		opcode_list[opcode.opcode - 1](vm); // call opcode
		if(vm->_error == nullptr) return EXEC_SUCCESS;
		else return EXEC_FAILED; // failed
	} else {
		throw InternalError(); // no opcode
	}
}

#ifndef _WIN32
void InitVMLibrary() __attribute__((constructor));
void InitVMLibrary() {}
#else
BOOL WINAPI DllMain(HINSTANCE,
	DWORD,
	LPVOID) {
	return TRUE;
}
#endif
