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

#include "versiondef.hpp"
#include "logger.hpp"
#include "searcher.hpp"
#include "acassert.h"
#include "acdpp.h"
#include "macros.hpp"
#include "array.hpp"
#include "heap.hpp"
#include "native.hpp"

typedef long long Integer;
typedef double FloatNum;

// String defines
using String = std::string;
using Char = char;
#define Dpp_TEXT(str) str

struct VMState;
class Dpp_Object;

NAMESPACE_DPP_BEGIN


class mapid {
private:
    /// sign bit : 1 when the object is global
    int32_t id;

    int32_t set_sign_bit_1(int32_t x) const {
        return (int32_t)((uint32_t)x | UINT32_C(0x80000000));
    }

    int32_t set_sign_bit_0(int32_t x) const {
        return (int32_t)((uint32_t)x & UINT32_C(0x7FFFFFFF));
    }
public:
    mapid() = default;

    mapid(bool is_global, int32_t id) {
        this->id = is_global ? set_sign_bit_1(id) : set_sign_bit_0(id);
    }

    explicit mapid(std::pair<bool, int32_t> &map) {
        this->id = map.first ? set_sign_bit_1(map.second) : set_sign_bit_0(map.second);
    }

    /**
     * @brief this function converts a uint32_t number from int32_t. Storge as a uint32_t.
     * 
     */
    explicit mapid(uint32_t number) { this->id = *(int32_t *)(&number); }

    ~mapid() = default;

    bool is_global() const {
        return (set_sign_bit_1(id) == id);
    }

    int32_t get_id() const {
        return set_sign_bit_0(id);
    }

    int32_t data() const {
        return id;
    }

    /**
     * @brief return as a uint32_t number. Must initialize with mapid(uint32_t).
     * 
     */
    uint32_t as_number() const { 
        return *(uint32_t *)(&id);
    }

    bool operator ==(const mapid &other) const {
        return (is_global() == other.is_global()) && (this->data() == other.data());
    }

    bool operator !=(const mapid &other) const {
        return !(*this == other);
    }

Dpp_SERIALIZE(Dpp_NVP(id))
};

NAMESPACE_DPP_END

enum rt_opcode : unsigned char {
    OPCODE_START,
    OPCODE_NOP,
    OPCODE_PUSH,
    OPCODE_POP,
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
	OPCODE_RET,
	OPCODE_NEW,
    OPCODE_DEL,
	OPCODE_MOV,
    OPCODE_METHOD,
    OPCODE_END
};

class DXX_API Dpp_Object{
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
            return "unknown";
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

    Dpp_Object *get(dpp::mapid o, uint32_t mapping_id) {
        Array<std::shared_ptr<Dpp_Object>> *func_mapping = this->getMapping(o, mapping_id);
        Dpp_Object *obj = ((*func_mapping)[o.get_id()]).get();

		return obj;
    }

	Dpp_Object *get(dpp::mapid o) {
		Array<std::shared_ptr<Dpp_Object>> *func_mapping = getMapping(o);
        Dpp_Object *obj = ((*func_mapping)[o.get_id()]).get();

		return obj;
	}

	void write(dpp::mapid o, Dpp_Object *obj, bool isRewrite = false) {
		Array<std::shared_ptr<Dpp_Object>> *func_mapping = this->getMapping(o);
        auto ptr = std::make_shared<Dpp_Object>();
        ptr.reset(obj);
        uint32_t id = (uint32_t)o.get_id();
		if(!isRewrite) {
            func_mapping->write(id, ptr);
        } else {
            func_mapping->rewrite(id, ptr);
        }
	}

	void create_mapping() {
		mappings.push([](Array<std::shared_ptr<Dpp_Object>> &mapping) { mapping.resize(1); });
	}

    void pop_mapping() {
        mappings.pop();
    }

    void tiny_global() {
        global.resize(global.size());
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
    Array<std::shared_ptr<Dpp_Object>> global;
	Array<Array<std::shared_ptr<Dpp_Object>>> mappings;
    inline auto getMapping(dpp::mapid _o) -> Array<std::shared_ptr<Dpp_Object>> * {
		if (_o.is_global()) {
			return &global;
		}

		return const_cast<Array<std::shared_ptr<Dpp_Object>> *>(&*(--mappings.end()));
	}

    inline auto getMapping(dpp::mapid _o, uint32_t mapping_id) -> Array<std::shared_ptr<Dpp_Object>> * {
		if (_o.is_global()) {
			return &global;
		}
		return const_cast<Array<std::shared_ptr<Dpp_Object>> *>(&*(mappings.begin() + mapping_id - 1));
	}

Dpp_SERIALIZE(Dpp_NVP(global))
};

typedef struct _VMError {
    Dpp_Object *err = nullptr;
    String msg;
} VMError;

class _bytecode {
public:
    // TODO: Of course. this is a bug, if there is a object in there, the list will not show. Maybe sometimes I will fix it.
    constexpr static auto fill = static_cast<uint32_t>(-1);
    struct ExtendsOpcode {
        rt_opcode op;
        uint32_t line;
        uint32_t pos;
    Dpp_SERIALIZE(Dpp_NVP(op), Dpp_NVP(line), Dpp_NVP(pos))
    };

    _bytecode() = default;
    ~_bytecode() = default;

    /// Constructors
    explicit _bytecode(struct ExtendsOpcode _op) : op(_op) {}
    explicit _bytecode(struct ExtendsOpcode _op, dpp::mapid _operand_0) : op(_op), operand_0(_operand_0) {}
    explicit _bytecode(struct ExtendsOpcode _op, dpp::mapid _operand_0, dpp::mapid _operand_1) : op(_op), operand_0(_operand_0), operand_1(_operand_1) {}
    explicit _bytecode(struct ExtendsOpcode _op, dpp::mapid _operand_0, dpp::mapid _operand_1, dpp::mapid _oprand_2) : op(_op), operand_0(_operand_0), operand_1(_operand_1), operand_2(_oprand_2) {}

    _bytecode &operator=(const _bytecode &other) = default;

    [[nodiscard]] struct ExtendsOpcode get_op() const { return op; }

    void set_op(struct ExtendsOpcode _op) { op = _op; }

    [[nodiscard]] dpp::mapid get_operand0() const {
        return operand_0;
    }

    [[nodiscard]] dpp::mapid get_operand1() const {
        return operand_1;
    }

    [[nodiscard]] dpp::mapid get_operand2() const {
        return operand_2;
    }

    [[nodiscard]] dpp::mapid set_operand0(dpp::mapid _operand_0) {
        return operand_0 = _operand_0;
    }

    [[nodiscard]] dpp::mapid set_operand1(dpp::mapid _operand_1) {
        return operand_1 = _operand_1;
    }

    [[nodiscard]] dpp::mapid set_operand2(dpp::mapid _operand_2) {
        return operand_2 = _operand_2;
    }
private:
    struct ExtendsOpcode op {};

    /// Oprands
    dpp::mapid operand_0 {fill};
    dpp::mapid operand_1 {fill};
    dpp::mapid operand_2 {fill};

Dpp_SERIALIZE(Dpp_NVP(op), Dpp_NVP(operand_0), Dpp_NVP(operand_1), Dpp_NVP(operand_2))
};

struct VMState {
	Heap<_bytecode> vmopcodes;
	uint32_t runat = 0;
    std::string file;
    std::string funcname;

Dpp_SERIALIZE(Dpp_NVP(vmopcodes), Dpp_NVP(file), Dpp_NVP(funcname))
};

typedef struct _FObject {
public:
	_FObject() = default;
	~_FObject() = default;

public:
    VMError *_error = nullptr;

    dpp::logger log;
public:
    std::stack<Dpp_Object *> RuntimeStack;
    std::unordered_map<std::string, dylib> libraries;
	ObjectMapping obj_map; // mapped object
	std::stack<struct VMState> callstack;
	struct VMState state;
    dpp::searcher module_searcher;
	int exit_code = EXIT_SUCCESS;

Dpp_SERIALIZE(Dpp_NVP(obj_map),  Dpp_NVP(state))
} FObject;

/**
 * @brief Pop the current object mapping and the state.
 * Returns a value to FObject::return_values.
 *
 * @param vm the virtual machine
 * @param val the return value
 */
void exit_frame(FObject *vm);

typedef Dpp_Object *(* NATIVE_FUNC)(FObject *);

// apis
NAMESPACE_DPP_BEGIN

// Defines types

template <typename T>
using ref = std::shared_ptr<T>;

using object = Dpp_Object;
using pobject = dpp::object *;
using serializable_object = std::shared_ptr<dpp::object>;
using serializable_pobject = dpp::serializable_object *;

using vm = FObject *;
using bytecode = _bytecode;
using state = ::VMState;
using error = VMError;
using mapping = ObjectMapping; // mapped object

NAMESPACE_DPP_END


#if defined(_MSC_VER) && !defined(__clang__)
#pragma warning(pop)
#endif // _MSC_VER

#endif // !_STRUCT_H
