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
#include <thread>
#include "acoder/acassert/acassert.h"
#include "builtin.hpp"
#include "stdrt.hpp"
#include "opcodes.hpp"
#include "macros.hpp"
#include "struct.hpp"
#include "acdpp.h"

#define EXEC_FAILED true
#define EXEC_SUCCESS false
#define vmswitch switch
#define vmcase case
#define VM_API DXX_API

typedef void(* OpcodeFunc)(FObject *);

// VM Init constructor
#ifndef _WIN32
void InitVMLibrary() __attribute__((constructor));
#else
BOOL WINAPI DllMain(HINSTANCE, DWORD, LPVOID);
#endif // !_WIN32

forceinline VM_API const char *GetOpcodeName(unsigned char opcode_id);
forceinline VM_API const char *GetFlagName(uint8_t i);
VM_API FObject *MakeVM();
VM_API bool Exec(OpCode, FObject *);
VM_API void VM_Run(FObject *fObj, bool noExit);
