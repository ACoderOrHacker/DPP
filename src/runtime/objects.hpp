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

#ifndef DPPDEF_OBJECTS
#define DPPDEF_OBJECTS

#include "struct.hpp"
#define OBJECT_HEAD Dpp_Object head;

class TypeNotRightError{};

// Warning : All object's value will named 'val'
struct IntObject {
	OBJECT_HEAD
	Interger val = 0; // interger value
};

struct FloatObject {
	OBJECT_HEAD
	FloatNum val; // floating number value
};

struct StringObject {
	OBJECT_HEAD
	String val; // string value
};

#define CLASS_OBJECT OBJECT_HEAD Heap<Dpp_Object *> members;
struct ClassObject {
    CLASS_OBJECT
};

struct ErrorObject {
    CLASS_OBJECT
    std::stack<Dpp_Object *> handles;
};

struct FunctionObject {
	OBJECT_HEAD
	struct VMState state;
	Heap<Object> params;
};

/*
struct BitObject {
	OBJECT_HEAD
	bit val; // bit value
};
 */
struct ObjectObject {
	OBJECT_HEAD // only has object head
};

#ifdef CPP_NATIVEAPI
// this object is api
template<typename MODEL> struct ModelObject {
	OBJECT_HEAD
	MODEL val;
};
#endif // CPP_NATIVEAPI

// create a object and return the object head

Dpp_Object *NewObject(size_t size);
bool DeleteObject(Dpp_Object *obj);

template<typename T> Dpp_Object *NewObject() {
	void *ptr = malloc(sizeof(T));
	T *obj = (T *)ptr;
	return &obj->head;
}

template<typename T> void DeleteObject(Dpp_Object *obj) {
	T del_obj = (T)obj;
	delete del_obj;
}

template<typename T, typename RTN_T> inline RTN_T GetObjectData(Dpp_Object *obj) {
	return (((T *)obj)->val);
}

inline uint16_t GetObjectType(Dpp_Object *obj) {
	return (obj->reg->type);
}

template<typename T, typename VAL_T> inline void SetObject(Dpp_Object *obj, VAL_T val) {
	((T *)obj)->val = val;
}
#endif // !DPPDEF_OBJECTS
