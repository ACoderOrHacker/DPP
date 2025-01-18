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

#include "macros.hpp"
#ifndef _COMPILER_H

#include <climits>
#include <cstdint>
#include <cstring>
#include <string>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <initializer_list>

#undef _DXX_EXPORT
#include "enum.hpp"
#include "acdpp.h"
#include "acassert.h"
#include "builtin.hpp"
#include "metadata.h"
#include "export.h"

#define VOID_TYPE UINT_MAX
#define OBJECT_TYPE (UINT_MAX - 1)

DXX_API FObject *fObj = new FObject;

NAMESPACE_DPP_BEGIN

DXX_API FObject *compile(const std::string &code);
DXX_API FObject *compile(std::ifstream &ifs);
DXX_API FObject *compile(std::fstream &ifs);

NAMESPACE_DPP_END

struct _Dpp_CObject;
class RetTypeNeqError : std::exception {};
bool throw_when_neq = false;

typedef std::unordered_map<std::string, struct _Dpp_CObject *> Throwtable;

struct INFOS {
public:
    unsigned is_compiletime : 1;
    unsigned is_final : 1;
    unsigned is_override : 1;
    unsigned is_inline : 1;
    unsigned is_static : 1;
    unsigned is_public : 1;
    unsigned is_protected : 1;
    unsigned is_private : 1;
    unsigned is_constructor : 1;
    unsigned is_destructor : 1;
    std::string native_library;
    std::string native_function;
public:
    bool operator ==(const INFOS &infos) const {
        return is_compiletime == infos.is_compiletime &&
            is_final == infos.is_final &&
            is_override == infos.is_override &&
            is_inline == infos.is_inline &&
            is_static == infos.is_static &&
            is_public == infos.is_public &&
            is_protected == infos.is_protected &&
            is_private == infos.is_private &&
            is_constructor == infos.is_constructor &&
            is_destructor == infos.is_destructor &&
            native_library == infos.native_library &&
            native_function == infos.native_function;
    }

    bool operator !=(const INFOS &infos) const {
        return !(*this == infos);
    }

    struct INFOS &operator =(const INFOS &infos) {
        if (this == &infos) {
            return *this;
        }

        is_compiletime = infos.is_compiletime;
        is_final = infos.is_final;
        is_override = infos.is_override;
        is_inline = infos.is_inline;
        is_static = infos.is_static;
        is_public = infos.is_public;
        is_protected = infos.is_protected;
        is_private = infos.is_private;
        is_constructor = infos.is_constructor;
        is_destructor = infos.is_destructor;
        native_library = infos.native_library;
        native_function = infos.native_function;

        return *this;
    }

    struct INFOS &operator |=(const INFOS &infos) {
        if (this == &infos) {
            return *this;
        }

        is_compiletime |= infos.is_compiletime;
        is_final |= infos.is_final;
        is_override |= infos.is_override;
        is_inline |= infos.is_inline;
        is_static |= infos.is_static;
        is_public |= infos.is_public;
        is_protected |= infos.is_protected;
        is_private |= infos.is_private;
        is_constructor |= infos.is_constructor;
        is_destructor |= infos.is_destructor;
        native_library = infos.native_library;
        native_function = infos.native_function;

        return *this;
    }
};

typedef struct _Dpp_CObject {
public:
	Object object;
    std::string id;
    struct INFOS infos;
    bool isNone = false;
    uint32_t type = OBJECT_TYPE;
    Array<_Dpp_CObject *> subs;
    void *metadata[8] = {};
public:
    bool operator ==(_Dpp_CObject *co) const {
        if(co->id != id || co->type != type) {
            return false;
        }

#define METADATA_EQ(pos, type) (*_cast(type *, co->metadata[(pos)]) == *_cast(type *, metadata[(pos)]))
        switch(type) {
            case FUNCTION_TYPE:
            if (co->infos != infos) return false;

            if (METADATA_EQ(function::FUNCTION_METADATA::PARAMS, Heap<_Dpp_CObject *>)      &&
                METADATA_EQ(function::FUNCTION_METADATA::AUTOVALUES, Heap<_Dpp_CObject *>) &&
                METADATA_EQ(function::FUNCTION_METADATA::THROW_TABLE, Throwtable)) {
                if (_cast(_Dpp_CObject *, metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object != _cast(_Dpp_CObject *, co->metadata[function::FUNCTION_METADATA::RETURN_TYPE])->object) {
                    if(throw_when_neq) throw RetTypeNeqError();

                    return false;
                }
                return true;
            }

            default:
            return true;
        }
#undef METADATA_EQ
    }
} Dpp_CObject;

class Namespace {
public:
    Array<Dpp_CObject *> objects;
	Array<Namespace *> namespaces;
    Array<Namespace *> parents;

public:
    Namespace *NewNamespace() {
        Namespace *ns = new Namespace;

        ns->parents.write(this);
        namespaces.write(ns);

        return ns;
    }

    void RemoveObject(Dpp_CObject *co,
        bool(*checker)(Dpp_CObject *, Dpp_CObject *) = [](Dpp_CObject *v1, Dpp_CObject *v2) {
            return *v1 == v2;
        }) {

        for (auto it : objects) {
            if(it == nullptr) continue;

            if (checker(it, co)) {
                acassert(it == nullptr);
                objects.remove(it);
            }
        }
    }
};

class IDIterator {
public:
    IDIterator() {
        global = BUILTIN_END;
    }
    ~IDIterator() = default;

    void IncIterator() noexcept {
        if (idIt.empty()) ++global;
        else ++idIt.top();
    }

    void IncGlobalIterator() noexcept {
        ++global;
    }

    void DecIterator() noexcept {
        --idIt.top();
    }

    void DecGlobalIterator() noexcept {
        --global;
    }

    void PushIterator() noexcept {
        idIt.push(0);
    }

    void PopIterator() noexcept {
        idIt.pop();
    }

    uint32_t GetTopIterator() noexcept {
        if (idIt.empty()) return global;
        else return idIt.top();
    }

    [[nodiscard]] uint32_t GetGlobalIterator() const noexcept {
        return global;
    }
private:
    std::stack<uint32_t> idIt;
    uint32_t global;
};

DXX_API OpCode MakeOpCode(rt_opcode op,
    OpcodeFlags flags = OpcodeFlags(),
    std::initializer_list<Object> l = {}) {
    OpCode _op;
    _op.params = *new Heap<Object>;
    _op.opcode = op;
    _op.flag = flags;

    uint32_t i = 0;
    for (auto it : l) {
        _op.params.SetData(i, it);
        ++i;
    }

    return _op;
}

DXX_API OpCode MakeOpCode(rt_opcode op,
    OpcodeFlags flags,
    Heap<Object> &params) {
    OpCode _op;
    _op.opcode = op;
    _op.flag = flags;
    _op.params = params;

    return _op;
}

#endif
