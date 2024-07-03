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

#ifndef _STRUCT_H
#define _STRUCT_H
#include <stdint.h>
#include <iostream>
#include <cstring>
#include <string>
#include <stack>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

#ifdef _MSC_VER
#pragma warning(disable : 4267)
#endif // _MSC_VER

#include "acdpp.h"
#include "macros.hpp"
#include "array.hpp"
#include "heap.hpp"
#include "set.hpp"
#include "enum.hpp"
#include "native.hpp"

typedef long long Interger;
typedef double FloatNum;
typedef std::wstring String;

struct VMState;
class Dpp_Object;

typedef struct _Object {
public:
	bool isInGlobal = true;
	uint32_t id = 0;

	bool operator ==(_Object o) { return (this->id == o.id &&
		                          this->isInGlobal == o.isInGlobal); }
} Object;

struct _Version {
	unsigned char low;
	unsigned char high;
};

struct Version {
	union {
		struct _Version ver;
		short version;
	};
}; // D++ Version structure

typedef Dpp_Object *(* nb_func)(Dpp_Object *, Dpp_Object *);
typedef Dpp_Object *(* nb_func1)(Dpp_Object *); // only 1 param
typedef bool(*print_func)(Dpp_Object *);
typedef Dpp_Object *(* logic_func)(Dpp_Object *, Dpp_Object *);
typedef Dpp_Object *(* logic_func1)(Dpp_Object *);
typedef void (* mem_free_func)(Dpp_Object *);
typedef void (* mem_alloc_func)(Dpp_Object *);

Dpp_Object *StdBigger(Dpp_Object *, Dpp_Object *);
Dpp_Object *StdSmaller(Dpp_Object *, Dpp_Object *);
Dpp_Object *StdEqual(Dpp_Object *, Dpp_Object *);
Dpp_Object *StdNot(Dpp_Object *);
struct RegType {

	uint8_t type;
	size_t size;

	// for number
	// number function if is nullptr value, call interpter no function of this operator
	nb_func nb_add = nullptr;
	nb_func nb_sub = nullptr;
	nb_func nb_mul = nullptr;
	nb_func nb_div = nullptr;
	nb_func nb_mod = nullptr;
	nb_func nb_shl = nullptr;
	nb_func nb_shr = nullptr;
	nb_func nb_band = nullptr;
	nb_func nb_bor = nullptr;
	nb_func nb_bxor = nullptr;
	nb_func1 nb_bneg = nullptr;

	logic_func bigger = nullptr;
	logic_func smaller = nullptr;
	logic_func equal = nullptr;
	logic_func1 notval = nullptr;

	print_func print = nullptr;

	mem_free_func mem_free = nullptr; // free the data
	mem_alloc_func mem_alloc = nullptr; // alloc and init the data
};

class Dpp_Object {
	public:
		Dpp_Object(){};
	public:
		Dpp_Object *operator +(Dpp_Object *obj);
		Dpp_Object *operator -(Dpp_Object *obj);
		Dpp_Object *operator *(Dpp_Object *obj);
		Dpp_Object *operator /(Dpp_Object *obj);
		Dpp_Object *operator %(Dpp_Object *obj);
		Dpp_Object *operator >(Dpp_Object *obj);
		Dpp_Object *operator <(Dpp_Object *obj);
		Dpp_Object *operator ==(Dpp_Object *obj);
		Dpp_Object *operator !();
		Dpp_Object *operator <<(Dpp_Object *obj);
		Dpp_Object *operator >>(Dpp_Object *obj);
		Dpp_Object *operator |(Dpp_Object *obj);
		Dpp_Object *operator &(Dpp_Object *obj);
		Dpp_Object *operator ^(Dpp_Object *obj);
		Dpp_Object *operator ~();
		bool print();
		bool move(Dpp_Object *obj); // move object to object
		bool moveref(Dpp_Object *obj); // move the ref to the object
	public:
		std::string name;
		char info = 0; // see doc/object/info.md
		RegType *reg = nullptr;
        bool isTypeObject = false;
};

class ObjectMapping {
public:
	ObjectMapping() {
		this->is_lambda.write(0, false); // global mapping
	}

public:
	uint32_t getLastCreateObjectID() {
		Array<Dpp_Object *> mapping = mappings[mappings.size()];
		return mapping.size() + 1;
	}

	uint32_t getLastCreateID() { return mappings.size() + 1; }

	Dpp_Object *get(Object o) {
		Array<Dpp_Object *> func_mapping = this->getMapping(o);
		return func_mapping[o.id];
	}

	void write(Object o, Dpp_Object *obj) {
		Array<Dpp_Object *> func_mapping = this->getMapping(o);
		func_mapping.write(o.id, obj);
	}

	void create_mapping(uint32_t mapping_id, bool is_lambda = false) {
		Array<Dpp_Object *> *mapping = new Array<Dpp_Object *>;
		this->mappings.write(mapping_id, *mapping);
		this->is_lambda.write(mapping_id, is_lambda);
	}

private:
	Array<Array<Dpp_Object *>> mappings;
	Array<bool> is_lambda;

	Array<Dpp_Object *> getMapping(Object &_o) {
		if (_o.isInGlobal) {
			return mappings[0];
		}
		return *mappings.end();
	}
};

typedef struct _VMError {
    Dpp_Object *err = nullptr;
    String msg;
} VMError;

typedef struct _OpCode {
    rt_opcode opcode;
	char flag;
    Heap<Object> params;
} OpCode;

typedef Heap<Object> Tmp_Heap;
typedef Heap<Dpp_Object *> ErrorPool;
typedef Heap<Object> WarningPool;
typedef Heap<SIGNAL> Signal;

typedef Dpp_Object *(*ConvertFunction)(ErrorPool *, Dpp_Object *);

struct VMState {
	Heap<OpCode> vmopcodes;
	uint32_t runat = 0;
	bool isLambda = false;
};

typedef struct _FObject {
public:
	_FObject(){
		_theap = new Tmp_Heap;
		sig = new Signal;

	}
	~_FObject() {}

public:
	Tmp_Heap *_theap;
    VMError *_error = nullptr;
public:
	Array<Module> modules;
	ObjectMapping obj_map; // mapped object
	std::stack<struct VMState> callstack;
	Signal *sig;
	struct VMState state;
	char flags = NO_FLAG;
	int exit_code = EXIT_SUCCESS;

private:
    friend class boost::serialization::access;
    template<typename Archive> void serialization(Archive &ar, unsigned int version) {
        ar & modules;
        ar & obj_map;
        ar & state;
    }
} FObject;

typedef Dpp_Object *(* NATIVE_FUNC)(FObject *);
#endif // !_STRUCT_H
