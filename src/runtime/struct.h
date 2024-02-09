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

#ifdef _MSC_VER
#include "compilers/msvc.h"
#endif // _MSC_VER

#include "acdpp.h"
#include "macros.h"
#include "array.hpp"
#include "heap.hpp"
#include "set.hpp"
#include "enum.h"
#include "native.h"

typedef long long Interger;
typedef double FloatNum;
typedef std::wstring String;

struct VMState;
class Dpp_Object;

typedef struct _Object {
public:
	AUTO_BLOCK_ID auto_block_id = NO_AUTO; // will control the 'block_id'
	uint32_t block_id = 0; // 0 is global block id
	
	/*
	  This is the offset value for the largest parent layer that can be read and written
	  only lambda function use it
	*/
	uint32_t block_backoffset = 0; // block can read and write parent objects
	uint32_t id = 0;
	
	bool operator ==(_Object o) { return (this->id == o.id && 
		                          this->block_backoffset == o.block_backoffset && 
		                          this->block_id == o.block_id); }
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
		bool is_const = false;
		uint8_t type_val;
		RegType reg;
};

class ObjectMapping {
public:
	ObjectMapping() {
		this->is_lambda.write(0, false); // global mapping
	}
	
public:
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
		Array<Dpp_Object *> func_mapping;
		
		Object o = _o;
		if(o.auto_block_id == NOW_STATE_ID) o.block_id = this->mappings.size();
		if(is_lambda[o.block_id]) {
			// a lambda function
			func_mapping = this->mappings[o.block_id - o.block_backoffset];
		} else {
			func_mapping = this->mappings[o.block_id];
		}
		return func_mapping;
	}
};

typedef struct _OpCode {
    rt_opcode opcode;
	char flag;
    std::deque<Object> params;
} OpCode;

typedef Heap<Object> Tmp_Heap;
typedef Heap<Object> ErrorPool;
typedef Heap<Object> WarningPool;
typedef Heap<SIGNAL> Signal;

typedef Dpp_Object *(*ConvertFunction)(ErrorPool *, Dpp_Object *);

struct VMState {
	Heap<OpCode> vmopcodes;
	uint32_t runat;
	bool isLambda = false;
};

typedef struct FObject {
	public:
		FObject(){_theap = new Tmp_Heap; _error = new ErrorPool; sig = new Signal; nullobject = new Dpp_Object;}
		~FObject() {}

	public:
		Tmp_Heap *_theap;
		ErrorPool *_error;
	public:
		Dpp_Object *nullobject;
		Array<RegType> types;
		Array<Module> modules;
		Array<Object> stderror;
		ObjectMapping obj_map; // mapped object
		Array<Object> error_accept;
		Array<Object> signal_accept;
		Array<ConvertFunction> ConvertList;
	    Set<Dpp_Object *, Dpp_Object *> *conversion_set;
		std::stack<Object> error_afsa; // Error accepting function staging area
		std::stack<struct VMState> callstack;
		Signal *sig;
		struct VMState state;
		Array<struct VMState> all_states;
		char flags;
		int exit_code = EXIT_SUCCESS;
		
} FObject;

typedef Dpp_Object *(* NATIVE_FUNC)(FObject *);
#endif // !_STRUCT_H
