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
#include <cstdint>
#include <string>
#include <stack>

#ifdef _MSC_VER
#pragma warning(disable : 4267)
#pragma warning(push)
#pragma warning(disable : 4251)
#endif // _MSC_VER

#include "acassert.h"
#include "acdpp.h"
#include "macros.hpp"
#include "array.hpp"
#include "heap.hpp"
#include "enum.hpp"
#include "native.hpp"

typedef long long Integer;
typedef double FloatNum;
typedef std::wstring String;

struct VMState;
class Dpp_Object;

typedef struct _Object {
public:
	bool isInGlobal = true;
	uint32_t id = 0;

	bool operator ==(_Object o) const { return (this->id == o.id &&
                                        this->isInGlobal == o.isInGlobal); }

Dpp_SERIALIZE(isInGlobal, id)
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

class DXX_API Dpp_Object {
public:
    virtual ~Dpp_Object() = default; // virtual destructor

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
        virtual bool is_true() { throw NoOperatorError(); }
        virtual Dpp_Object *new_object() {
            return new Dpp_Object;
        }
		virtual Dpp_Object *move(Dpp_Object *obj) {
            delete obj;
            obj = nullptr;
            obj = this->new_object();
            *obj = *this;

            return obj;
        }
		bool moveref(Dpp_Object *obj); // move the ref to the object

    public:
        virtual Dpp_Object *add(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *sub(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *mul(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *div(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *mod(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *shl(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *shr(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *band(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *bor(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *bxor(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *bneg(Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *bigger(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *smaller(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *equal(Dpp_Object *, Dpp_Object *) {
            throw NoOperatorError();
        }

        virtual std::string to_string(Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual Dpp_Object *notval(Dpp_Object *) {
            throw NoOperatorError();
        }

	public:
		std::string name;
        uint32_t type;
		char info = 0; // see doc/object/info.md

Dpp_SERIALIZE(name, type, info)
};

forceinline DXX_API std::string object_to_string(Dpp_Object *obj) { acassert(obj == nullptr); return obj->to_string(obj); }

class ObjectMapping {
public:
	ObjectMapping() = default;
    ~ObjectMapping() = default;

public:
	uint32_t getLastCreateObjectID() {
        return mappings.size() == 0 ? global.size() + 1 : mappings[mappings.size()].size() + 1;
	}

	uint32_t getLastCreateID() { return mappings.size() + 1; }

    Dpp_Object *get(Object o, uint32_t mapping_id) {
        Array<Dpp_Object> func_mapping = this->getMapping(o, mapping_id);
        Dpp_Object obj = func_mapping[o.id];

        // this object is not at stack if running at vm
		return &obj;
    }

	Dpp_Object *get(Object o) {
		Array<Dpp_Object> func_mapping = getMapping(o);
        Dpp_Object obj = func_mapping[o.id];

        // this object is not at stack if running at vm
		return &obj;
	}

	void write(Object o, Dpp_Object *obj, bool isRewrite = false) {
		Array<Dpp_Object> func_mapping = this->getMapping(o);
		if(!isRewrite) {
            func_mapping.write(o.id, *obj);
        } else {
            func_mapping.rewrite(o.id, *obj);
        }
	}

	void create_mapping(uint32_t mapping_id) {
		Array<Dpp_Object> *mapping = new Array<Dpp_Object>;
		mappings.write(mapping_id, *mapping);
	}

    void pop_mapping() {
        mappings.pop();
    }

    /**
     * @brief Get the Global Mapping
     *
     * @return Array<Dpp_Object *>
     */
    Array<Dpp_Object *> getGlobalMapping() {
        Array<Dpp_Object *> convert;

        uint32_t i = 0;
        for(auto &it : global) {
            // Dpp_Object * is a dynamic pointer (new Dpp_Object)
            convert.write(i, &it);
            ++i;
        }

        return convert;
    }

private:
    Array<Dpp_Object> global;
	Array<Array<Dpp_Object>> mappings;

	Array<Dpp_Object> getMapping(Object &_o) {
		if (_o.isInGlobal) {
			return global;
		}
		return *(--mappings.end());
	}

    Array<Dpp_Object> getMapping(Object &_o, uint32_t mapping_id) {
		if (_o.isInGlobal) {
			return global;
		}
		return *(mappings.begin() + mapping_id - 1);
	}

Dpp_SERIALIZE(global)
};

typedef struct _VMError {
    Dpp_Object *err = nullptr;
    String msg;
} VMError;

typedef struct _OpCode {
    rt_opcode opcode = OPCODE_START;
	char flag = NO_FLAG;
    Heap<Object> params;

Dpp_SERIALIZE(opcode, flag, params)
} OpCode;

typedef Heap<Object> Tmp_Heap;
typedef Heap<Dpp_Object *> ErrorPool;
typedef Heap<Object> WarningPool;
typedef Heap<SIGNAL> Signal;

typedef Dpp_Object *(*ConvertFunction)(ErrorPool *, Dpp_Object *);

struct VMState {
	Heap<OpCode> vmopcodes;
	uint32_t runat = 0;

Dpp_SERIALIZE(vmopcodes)
};

typedef struct _FObject {
public:
	_FObject(){
		_theap = new Tmp_Heap;
		sig = new Signal;

        uint32_t i = 0;
        for(auto &it: modules) {
            NativeModules.write(i, OpenNativeLib((it + PLATFORM_LIB_EX).c_str()));
            ++i;
        }
	}
	~_FObject() = default;

public:
	Tmp_Heap *_theap;
    VMError *_error = nullptr;
public:
    Array<Module> NativeModules;
	Array<std::string> modules;
	ObjectMapping obj_map; // mapped object
	std::stack<struct VMState> callstack;
    std::stack<Dpp_Object *> return_values;
	Signal *sig;
	struct VMState state;
	char flags = NO_FLAG;
	int exit_code = EXIT_SUCCESS;

Dpp_SERIALIZE(modules, obj_map, state)
} FObject;

typedef Dpp_Object *(* NATIVE_FUNC)(FObject *);

// apis
NAMESPACE_DPP_BEGIN

// Defines types

using object = Dpp_Object;
using vm = FObject *;
using state = struct VMState;
using error = VMError;
using opcode = OpCode;
using mapping = ObjectMapping; // mapped object

forceinline Version get_version() {
    Version ver = {};
    ver.ver.high = VERSION_HIGH;
    ver.ver.low = VERSION_LOW;

    return ver;
}
NAMESPACE_DPP_END

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif // !_STRUCT_H
