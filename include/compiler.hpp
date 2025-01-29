/**
 * @file compiler.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Defines compiler API and other compile-time structures
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _COMPILER_H
#define _COMPILER_H

#include <climits>
#include <cstdint>
#include <string>
#include <fstream>
#include <unordered_map>
#include <stack>
#include <initializer_list>

#undef _DXX_EXPORT
#include "acdpp.h"
#include "acassert.h"
#include "builtin.hpp"
#include "metadata.h"
#include "export.h"

#define VOID_TYPE UINT_MAX
#define OBJECT_TYPE (UINT_MAX - 1)

/**
 * @brief when the return type is not equal to the function's return type, throw this error
 *
 */
Dpp_DEFINE_ERROR(RetTypeNeqError)

bool throw_when_neq = false;

NAMESPACE_DPP_BEGIN

/**
 * @brief compile D++ code
 *
 * @param code the D++ code string
 * @return dpp::vm the vm instance
 */
DXX_API dpp::vm compile(const std::string &code, bool is_output = false);

/**
 * @brief compile D++ code
 *
 * @param ifs the D++ code filestream
 * @return dpp::vm the vm instance
 */
DXX_API dpp::vm compile(std::ifstream &ifs, const std::string &file, bool is_output = false);

/**
 * @brief compile D++ code
 *
 * @param ifs the D++ code filestream
 * @return dpp::vm the vm instance
 */
DXX_API dpp::vm compile(std::fstream &ifs, const std::string &file, bool is_output = false);

NAMESPACE_DPP_END

/**
 * @brief the compile-time object in compiler
 *
 * @details include symbols, types, its object position, etc.
 *
 */
struct _Dpp_CObject;

/**
 * @brief the throw table in function
 *
 */
typedef std::unordered_map<std::string, struct _Dpp_CObject *> Throwtable;

/**
 * @brief the compile-time object informations(like final, static, inline, etc.)
 *
 */
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

/**
 * @brief the compile-time scope
 *
 * @details it often contains with brackets
 *
 */
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

/**
 * @brief iterator for Object::id
 *
 * @details when define a new object, the iterator will be increased
 *
 */
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

/**
 * @brief genrate a opcode from op and l
 *
 * @param op the opcode
 * @param l the opcode's paramters
 * @return OpCode the genrated opcode
 */
DXX_API OpCode MakeOpCode(rt_opcode op,
    std::initializer_list<Object> l = {},
    uint32_t line = 0,
    uint32_t pos = 0) {
    OpCode _op;
    _op.opcode = op;
    _op.line = line;
    _op.pos = pos;

    uint32_t i = 0;
    for (auto it : l) {
        _op.params.SetData(i, it);
        ++i;
    }

    return _op;
}

/**
 * @brief genrate a opcode from op and l
 *
 * @param op the opcode
 * @param params the opcode's paramters
 * @return OpCode the genrated opcode
 */
DXX_API OpCode MakeOpCode(rt_opcode op,
    Heap<Object> &params,
    uint32_t line,
    uint32_t pos) {
    OpCode _op;
    _op.opcode = op;
    _op.params = params;
    _op.line = line;
    _op.pos = pos;

    return _op;
}

#endif
