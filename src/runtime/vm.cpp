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
#include "builtin.hpp"

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

forceinline VM_API const char *GetOpcodeName(unsigned char opcode_id) {
    return opcode_name_list[opcode_id - 1];
}

forceinline VM_API const char *GetFlagName(uint8_t i) {
    return flag_name_list[i - 1];
}

VM_API FObject *MakeVM() {
	FObject *fObj = new FObject;
    RegInit(fObj);
    initBuiltin();
	return fObj;
}

VM_API int VM_Run(FObject *fObj, bool noExit) {
    uint32_t i = 0;
    for (auto &it : fObj->modules) {
        Module vm_module = OpenNativeLib((it + PLATFORM_LIB_EX).c_str());
        if (vm_module == nullptr) {
            SetError(fObj, Dpp_LibNoSymbolError, L"");
            continue;
        }
        fObj->NativeModules.write(i, vm_module);
    }

	while(fObj->state.vmopcodes.size() > fObj->state.runat) {
		OpCode opcode;
		opcode = fObj->state.vmopcodes.GetData(fObj->state.runat); // get opcode from state

		// execute the opcode and get the error code(isfail variable)
		bool isfail = Exec(opcode, fObj);
        fObj->flags = NO_FLAG; // clear the flags

		if(isfail && fObj->_error != nullptr) {
			// the opcode has error
			if(GetBit(fObj->flags, NO_OPCODE)) {
				// has a unknown opcode
				SetBit0(fObj->flags, NO_OPCODE);
				return EXIT_FAILURE; // Skip this opcode
			}

            CatchError(fObj);
		}

        if (fObj->state.vmopcodes.size() == fObj->state.runat && !fObj->callstack.empty()) {
            fObj->state = fObj->callstack.top();
            fObj->callstack.pop();
            fObj->obj_map.pop_mapping();
            fObj->return_values.push(nullptr);

            ++fObj->state.runat;
            continue;
        }

        if (opcode.opcode != OPCODE_CALL) ++fObj->state.runat;
	}

	// exit
	int exit_code = fObj->exit_code;
	EnvClean(fObj);
	if (!noExit) exit(exit_code);
    else return exit_code;
}

VM_API bool Exec(OpCode opcode, FObject *fObj) {
	if(opcode.flag != NO_FLAG) {
		fObj->flags = opcode.flag; // set the flags
	}

	WriteTHeap(theap, &opcode.params); // write the params to the 'fObj->_theap' for the opcode

	if(opcode.opcode > OPCODE_START && opcode.opcode < OPCODE_END) {
		opcode_list[opcode.opcode - 1](fObj); // call opcode
		if(error == nullptr && fObj->sig->size() == 0) return EXEC_SUCCESS;
		else return EXEC_FAILED; // failed
	} else {
		SetBit1(fObj->flags, NO_OPCODE);
		return EXEC_FAILED; // failed
	}
}

#ifndef _WIN32
void InitVMLibrary() __attribute__((constructor)) {

}
#else
BOOL WINAPI DllMain(HINSTANCE,
	DWORD,
	LPVOID) {
	return TRUE;
}
#endif
