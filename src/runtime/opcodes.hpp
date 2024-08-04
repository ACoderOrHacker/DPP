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

#ifndef _DXX_RUNTIME_
#define _DXX_RUNTIME_
#include <iostream>
#include <string>
#include "error.hpp"
#include "struct.hpp"
#include "stdrt.hpp"

#define theap (fObj->_theap)
#define error (fObj->_error)

void _import(FObject *fObj);
void _add(FObject *fObj);
void _sub(FObject *fObj);
void _mul(FObject *fObj);
void _div(FObject *fObj);
void _mod(FObject *fObj);
void _bneg(FObject *fObj);
void _band(FObject *fObj);
void _bor(FObject *fObj);
void _bxor(FObject *fObj);
void _shl(FObject *fObj);
void _shr(FObject *fObj);
void _not(FObject *fObj);
void _eq(FObject *fObj);
void _bigger(FObject *fObj);
void _smaller(FObject *fObj);
void _and(FObject *fObj);
void _or(FObject *fObj);
void _jmp(FObject *fObj);
void _call(FObject *fObj);
void _calln(FObject *fObj);
void _ret(FObject *fObj);
void _sign(FObject *fObj);
void _new(FObject *fObj);
void _del(FObject *fObj);
void _mov(FObject *fObj);
void _exit(FObject *fObj);

#endif // !_DXX_RUNTIME
