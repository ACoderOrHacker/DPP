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
#include "error.hpp"
#include "struct.hpp"

forceinline bool is_true(dpp::object *obj);
void _import(dpp::vm vm);
void _add(dpp::vm vm);
void _sub(dpp::vm vm);
void _mul(dpp::vm vm);
void _div(dpp::vm vm);
void _mod(dpp::vm vm);
void _bneg(dpp::vm vm);
void _band(dpp::vm vm);
void _bor(dpp::vm vm);
void _bxor(dpp::vm vm);
void _shl(dpp::vm vm);
void _shr(dpp::vm vm);
void _not(dpp::vm vm);
void _eq(dpp::vm vm);
void _bigger(dpp::vm vm);
void _smaller(dpp::vm vm);
void _and(dpp::vm vm);
void _or(dpp::vm vm);
void _jmp(dpp::vm vm);
void _call(dpp::vm vm);
void _getret(dpp::vm vm);
void _calln(dpp::vm vm);
void _ret(dpp::vm vm);
void _sign(dpp::vm vm);
void _new(dpp::vm vm);
void _del(dpp::vm vm);
void _mov(dpp::vm vm);
void _method(dpp::vm vm);

#endif // !_DXX_RUNTIME
