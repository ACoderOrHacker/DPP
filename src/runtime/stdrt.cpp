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

#include "stdrt.hpp"

bool isTrue(Dpp_Object *obj) {
	switch (obj->reg->type) {
	case INT_TYPE:
		if(GetObjectData<IntObject, Interger>(obj) != 0)
			return true;
		else
			return false;
	case FLOAT_TYPE:
		if(GetObjectData<FloatObject, FloatNum>(obj) != 0.0)
			return true;
		else
			return false;
	case STRING_TYPE:
		if(GetObjectData<StringObject, String>(obj) != L"")
			return true;
		else
			return false;
	default:
		return (bool)obj;
	}

}

void WriteTHeap(Tmp_Heap *__theap, Tmp_Heap *src) {
	__theap = src;
}

void EnvClean(FObject *fObj) {
	delete fObj;
	fObj = nullptr;
}

bool CallFunction(FObject *fObj,
    FunctionObject *func,
    uint32_t _paramnum,
    ...) {
    va_list l;
    va_start(l, _paramnum);
    uint32_t paramnum = _paramnum;

    uint32_t create_frame = fObj->obj_map.getLastCreateID();
    struct VMState jmp_state = func->state;
    fObj->obj_map.create_mapping(create_frame, jmp_state.isLambda);

    // Save the last state
    struct VMState state = fObj->state;
    fObj->callstack.push(state);
    fObj->state = jmp_state;
    fObj->state.runat = 0;

    while (_paramnum > 0) {
        fObj->obj_map.write({false, paramnum - _paramnum}, va_arg(l, Dpp_Object *));

        --paramnum;
    }

    return true;
}
