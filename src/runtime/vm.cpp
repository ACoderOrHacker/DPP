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
#include <fmt/core.h>
#include <fmt/color.h>
#include "vm.hpp"
#include "builtin.hpp"
#include "native.hpp"
#include "objects.hpp"
#include "opcodes.hpp"
#include "struct.hpp"

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
	&_jmp,
	&_call,
    &_getret,
	&_calln,
	&_ret,
	&_sign,
	&_new,
    &_del,
	&_mov,
    &_method,
	&_exit
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
    "jmp",
    "call",
    "getret",
    "calln",
    "ret",
    "sign",
    "new",
    "del",
    "mov",
    "method",
    "exit"
};

const char *flag_name_list[8] = {
    "null",
    "null",
    "null",
    "null",
    "JMP_FALSE",
    "JMP_TRUE",
    "null",
    "null"
};

forceinline VM_API const char *dpp::get_opcode_name(unsigned char opcode_id) {
    return opcode_name_list[opcode_id - 1];
}

VM_API const char *dpp::get_flag_name(uint8_t i) {
    return flag_name_list[i - 1];
}

template<typename T>
dpp::object *mk_type(const std::string &id) {
    dpp::object *o = dpp::make_type(dpp::new_object<T>());
    o->name = id;

	return o;
}

VM_API dpp::vm dpp::create_vm() {

    initBuiltin();

	dpp::vm vm = new FObject;
	// TODO: null and error not supported
    vm->obj_map.write({ true, BUILTIN::BUILTIN_NULL }, Dpp_NullObject);
    vm->obj_map.write({ true, BUILTIN::BUILTIN_NULLPOINTER_ERROR }, Dpp_NullPointerError);
    vm->obj_map.write({ true, BUILTIN::INT_TYPE }, mk_type<IntObject>("int"));
    vm->obj_map.write({ true, BUILTIN::FLOAT_TYPE }, mk_type<FloatObject>("float"));
    vm->obj_map.write({ true, BUILTIN::STRING_TYPE }, mk_type<StringObject>("string"));
    vm->obj_map.write({ true, BUILTIN::CLASS_TYPE }, mk_type<ClassObject>("class"));
    vm->obj_map.write({ true, BUILTIN::ERROR_TYPE }, mk_type<ErrorObject>("error"));
    vm->obj_map.write({ true, BUILTIN::FUNCTION_TYPE }, mk_type<FunctionObject>("function"));

	return vm;
}

VM_API int dpp::run(dpp::vm vm, bool noExit) {
    uint32_t i = 0;
    for (auto &it : vm->modules) {
        dpp::native_module vm_module;
        try {
            vm_module = dpp::open(it);
        } catch(std::runtime_error &) {
            fmt::print(fmt::fg(fmt::color::red), "[dpp.startup] failed to load native module {}\n", it);
            exit(1);
        }

        vm->NativeModules.write(i, vm_module);
    }

	while(vm->state.vmopcodes.size() > vm->state.runat) {
		OpCode opcode;
		opcode = vm->state.vmopcodes.GetData(vm->state.runat); // get opcode from state

		// execute the opcode and get the error code(isfail variable)
		bool isfail = dpp::exec(opcode, vm);
        vm->flags = NO_FLAG; // clear the flags

		if(isfail && vm->_error != nullptr) {
			// the opcode has error
			if(GetBit(vm->flags, NO_OPCODE)) {
				// has a unknown opcode
				SetBit0(vm->flags, NO_OPCODE);
				return EXIT_FAILURE; // Skip this opcode
			}

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

	// exit
	int exit_code = vm->exit_code;
	dpp::delete_vm(vm);
	if (!noExit) exit(exit_code);
    return exit_code;
}

VM_API bool dpp::exec(const OpCode &opcode, dpp::vm vm) {
	if(opcode.flag != NO_FLAG) {
		vm->flags = opcode.flag; // set the flags
	}

    *vm->_theap = opcode.params; // write the params to the 'vm->_theap' for the opcode

	if(opcode.opcode > OPCODE_START && opcode.opcode < OPCODE_END) {
		opcode_list[opcode.opcode - 1](vm); // call opcode
		if(vm->_error == nullptr && vm->sig->size() == 0) return EXEC_SUCCESS;
		else return EXEC_FAILED; // failed
	} else {
		SetBit1(vm->flags, NO_OPCODE);
		return EXEC_FAILED; // failed
	}
}

#ifndef _WIN32
void InitVMLibrary() __attribute__((constructor));
void InitVMLibrary() {
    initBuiltin();
}
#else
BOOL WINAPI DllMain(HINSTANCE,
	DWORD,
	LPVOID) {
    initBuiltin();
	return TRUE;
}
#endif
