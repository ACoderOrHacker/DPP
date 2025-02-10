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
#include <map>
#include <cstdint>
#include <memory>
#include <string>
#include <stack>
#include <cereal/types/stack.hpp>
#include <cereal/types/unordered_map.hpp>
#include <unordered_map>

#if defined(_MSC_VER) && !defined(__clang__)
#pragma warning(disable : 4267)
#pragma warning(push)
#pragma warning(disable : 4251)
#endif // _MSC_VER

#include "acassert.h"
#include "acdpp.h"
#include "macros.hpp"
#include "array.hpp"
#include "heap.hpp"
#include "native.hpp"

typedef long long Integer;
typedef double FloatNum;

#ifdef Dpp_USING_STRING
using String = std::string;
using Char = char;
#define Dpp_TEXT(str) str
#else
using String = std::wstring;
using Char = wchar_t;
#define Dpp_TEXT(str) L##str
#endif

struct VMState;
class Dpp_Object;

enum rt_opcode : unsigned char {
    OPCODE_START,
    OPCODE_IMPORT,
	OPCODE_ADD,
	OPCODE_SUB,
	OPCODE_MUL,
	OPCODE_DIV,
	OPCODE_MOD,
	OPCODE_BNEG,
	OPCODE_BAND,
	OPCODE_BOR,
	OPCODE_BXOR,
	OPCODE_SHL,
	OPCODE_SHR,
	OPCODE_NOT,
	OPCODE_EQ,
	OPCODE_BIGGER,
	OPCODE_SMALLER,
	OPCODE_AND,
	OPCODE_OR,
	OPCODE_JNT,
    OPCODE_JNF,
    OPCODE_JMP,
	OPCODE_CALL,
    OPCODE_GETRET,
	OPCODE_RET,
	OPCODE_NEW,
    OPCODE_DEL,
	OPCODE_MOV,
    OPCODE_METHOD,
    OPCODE_END
};

typedef struct _Object {
    bool isInGlobal = true;
    uint32_t id = 0;

	bool operator ==(const _Object &o) const { return (this->id == o.id &&
                                        this->isInGlobal == o.isInGlobal); }
    bool operator !=(const _Object &o) const { return !(*this == o); }

Dpp_SERIALIZE(Dpp_NVP(isInGlobal), Dpp_NVP(id))
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
    Dpp_Object() = default;
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
        virtual std::string to_datastring(Dpp_Object *) {
            throw NoOperatorError();
        }
        virtual std::string get_typeid() {
            throw NoOperatorError();
        }
        virtual Dpp_Object *notval(Dpp_Object *) {
            throw NoOperatorError();
        }

	public:
		std::string name;
        std::shared_ptr<Dpp_Object> type = nullptr;
        std::unordered_map<std::string, std::shared_ptr<Dpp_Object>> methods;

Dpp_SERIALIZE(Dpp_NVP(name), Dpp_NVP(type), Dpp_NVP(methods))
};

forceinline DXX_API std::string object_to_string(Dpp_Object *obj) { acassert(obj == nullptr); return obj->to_string(obj); }
forceinline DXX_API std::string object_to_datastring(Dpp_Object *obj) { acassert(obj == nullptr); return obj->to_datastring(obj); }

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
        Array<std::shared_ptr<Dpp_Object>> *func_mapping = this->getMapping(o, mapping_id);
        Dpp_Object *obj = ((*func_mapping)[o.id]).get();

		return obj;
    }

	Dpp_Object *get(Object o) {
		Array<std::shared_ptr<Dpp_Object>> *func_mapping = getMapping(o);
        Dpp_Object *obj = ((*func_mapping)[o.id]).get();

		return obj;
	}

	void write(Object o, Dpp_Object *obj, bool isRewrite = false) {
		Array<std::shared_ptr<Dpp_Object>> *func_mapping = this->getMapping(o);
        auto ptr = std::make_shared<Dpp_Object>();
        ptr.reset(obj);
		if(!isRewrite) {
            func_mapping->write(o.id, ptr);
        } else {
            func_mapping->rewrite(o.id, ptr);
        }
	}

	void create_mapping(uint32_t mapping_id) {
		Array<std::shared_ptr<Dpp_Object>> *mapping = new Array<std::shared_ptr<Dpp_Object>>;
		mappings.write(mapping_id, *mapping);
	}

    void pop_mapping() {
        mappings.pop();
    }

    [[nodiscard]] const std::string &get_currentfile() const {
        return currentfile;
    }

    void set_currentfile(const std::string &currentfile) {
        ObjectMapping::currentfile = currentfile;
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
            convert.write(i, it.get());
            ++i;
        }

        return convert;
    }

private:
    std::string currentfile;
    Array<std::shared_ptr<Dpp_Object>> global;
	Array<Array<std::shared_ptr<Dpp_Object>>> mappings;
    auto getMapping(Object &_o) -> Array<std::shared_ptr<Dpp_Object>> * {
		if (_o.isInGlobal) {
			return &global;
		}

		return const_cast<Array<std::shared_ptr<Dpp_Object>> *>(&*(--mappings.end()));
	}

    auto getMapping(Object &_o, uint32_t mapping_id) -> Array<std::shared_ptr<Dpp_Object>> * {
		if (_o.isInGlobal) {
			return &global;
		}
		return const_cast<Array<std::shared_ptr<Dpp_Object>> *>(&*(mappings.begin() + mapping_id - 1));
	}

Dpp_SERIALIZE(Dpp_NVP(global), Dpp_NVP(currentfile))
};

typedef struct _VMError {
    Dpp_Object *err = nullptr;
    String msg;
} VMError;

typedef struct _OpCode {
    rt_opcode opcode = OPCODE_START;
    Heap<Object> params;
    uint32_t line = 1;
    uint16_t pos = 0;

Dpp_SERIALIZE(Dpp_NVP(opcode), Dpp_NVP(params), Dpp_NVP(line), Dpp_NVP(pos))
} OpCode;

typedef Heap<Object> Tmp_Heap;

struct VMState {
	Heap<OpCode> vmopcodes;
	uint32_t runat = 0;

Dpp_SERIALIZE(Dpp_NVP(vmopcodes))
};

typedef struct _FObject {
public:
	_FObject() {
        _theap = new Tmp_Heap;
    }
	~_FObject() = default;

public:
	Tmp_Heap *_theap;
    VMError *_error = nullptr;
public:
    std::unordered_map<std::string, dylib> libraries;
	ObjectMapping obj_map; // mapped object
	std::stack<struct VMState> callstack;
    std::stack<Dpp_Object *> return_values;
	struct VMState state;
	int exit_code = EXIT_SUCCESS;

    bool is_next = true; // is run next opcode?
public:
    std::stack<std::string> files; // storge files

Dpp_SERIALIZE(Dpp_NVP(obj_map),  Dpp_NVP(state), Dpp_NVP(files))
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

#if defined(_MSC_VER) && !defined(__clang__)
#pragma warning(pop)
#endif // _MSC_VER

#endif // !_STRUCT_H
