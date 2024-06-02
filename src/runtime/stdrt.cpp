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
