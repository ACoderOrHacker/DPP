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
	&_calln,
	&_ret,
	&_sign,
	&_new,
    &_del,
	&_mov,
	&_exit
};

VM_API FObject *MakeVM() {
	FObject *fObj = new FObject;
    RegInit(fObj);
	return fObj;
}

VM_API void VM_Run(FObject *fObj) {
	while(fObj->state.vmopcodes.size() > fObj->state.runat) {
		OpCode opcode;
		opcode = fObj->state.vmopcodes.GetData(fObj->state.runat); // get opcode from state

		// execute the opcode and get the error code(isfail variable)
		bool isfail = Exec(opcode, fObj);

		if(isfail) {
			// the opcode has error
			if(GetBit(fObj->flags, NO_OPCODE)) {
				// has a unknown opcode
				SetBit0(fObj->flags, NO_OPCODE);
				return; // Skip this opcode
			}

            CatchError(fObj);
            /*else if (GetBit(fObj->flags, HAS_SIGNAL)) {
				// has a signal to execute
				SetBit0(fObj->flags, HAS_SIGNAL);
				while(!fObj->sig->isEmpty()) {
					theap->PushData(fObj->signal_accept[fObj->sig->PopData()]);
					_call(fObj); // call the signal accept function
				}
				return;
			}*/
            /*
			// execute failed
			while(!error->isEmpty()) {
				theap->PushData(fObj->error_accept[error->PopData().id]);
				_call(fObj); // call the error accept function
			}*/
		}

        ++fObj->state.runat;
	}

	// exit
	int exit_code = fObj->exit_code;
	EnvClean(fObj);
	exit(exit_code);
}

VM_API bool Exec(OpCode opcode, FObject *fObj) {
	if(opcode.flag != NO_FLAG) {
		fObj->flags = opcode.flag; // set the flags
	}

	WriteTHeap(theap, &opcode.params); // write the params to the 'fObj->_theap' for the opcode

	if(opcode.opcode > OPCODE_START && opcode.opcode < OPCODE_END) {
		opcode_list[opcode.opcode](fObj); // call opcode
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
