#ifndef _DPP_MACROS
#define _DPP_MACROS

#include <exception> // std::exception
#include <cereal/types/base_class.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/access.hpp>

/*
 * The Status Code
 */
typedef bool STATUS;
#define STATUS_SUCCESS 1
#define STATUS_FAILED 0

#define NO_OPCODE 8
#define HAS_SIGNAL 7

#define JMP_TRUE 6
#define JMP_FALSE 5

#define NO_FLAG 0b00000000

#define DATA_CANT_OPERATOR_ID 0
#define DATA_NULLP_ID 1
#define LIB_NO_SYMBOL_ID 2
#define NO_MEM_ID 3
#define TYPE_NOT_RIGHT_ID 4

#define GetBit(x, bit) ((x & (1 << bit)) >> bit)
#define SetBit1(x, bit) ((x) |= (1 << (bit)))
#define SetBit0(x, bit) ((x) &= ~ (1 << (bit)))

#ifdef _WIN32
#define LIB_PREFIX ""
#define PLATFORM_LIB_EX ".dll"
#elif defined(__linux__)
#define LIB_PREFIX "lib"
#define PLATFORM_LIB_EX ".so"
#endif

#define NAMESPACE_BEGIN(ns) namespace ns {
#define NAMESPACE_END }
#define NAMESPACE_DPP_BEGIN NAMESPACE_BEGIN(dpp)
#define NAMESPACE_DPP_END NAMESPACE_END
#define NAMESPACE_BASE_BEGIN NAMESPACE_BEGIN(base)
#define NAMESPACE_BASE_END NAMESPACE_END

#define Dpp_DEFINE_ERROR(id) class id : std::exception{};
#define Dpp_TYPE(id) class DXX_API id : public Dpp_Object
#define Dpp_TYPE_REGISTER_METHOD(id) \
    public: \
    forceinline dpp::object *new_object() override { return (dpp::object *)new id; } \
    forceinline dpp::object *move(dpp::object *obj) override { dpp::_delete_object(obj); id *_o = dynamic_cast<id *>(this->new_object()); *_o = *(id *)this; return (dpp::object *)_o; } \
    bool is_true(dpp::object *); \


#define Dpp_SERIALIZE(...) \
    private: \
    friend class cereal::access; \
    template <typename Archive> \
    void serialize(Archive &ar) { ar(__VA_ARGS__); }

#define Dpp_OBJECT_SERIALIZE(...) Dpp_SERIALIZE(cereal::base_class<dpp::object>(this), __VA_ARGS__)
#define Dpp_EMPTY_OBJECT_SERIALIZE() Dpp_SERIALIZE(cereal::base_class<dpp::object>(this))


#define Dpp_REGISTER_TYPE(dpptype, cpptype) \
NAMESPACE_DPP_BEGIN                                                                       \
    forceinline bool is_##dpptype(dpp::object *obj) { return dynamic_cast<cpptype*>(obj) != nullptr; } \
    forceinline cpptype* to_##dpptype(dpp::object *obj) { return dynamic_cast<cpptype*>(obj); }        \
NAMESPACE_DPP_END

#define Dpp_REGISTER_SERIALIZE(type) CEREAL_REGISTER_TYPE(type)

#define Dpp_REGISTER_TYPE_EX(dpptype, cpptype, valid)      \
Dpp_REGISTER_TYPE(dpptype, cpptype)                        \
NAMESPACE_DPP_BEGIN                                        \
    forceinline auto get_##dpptype(dpp::object *obj) { return to_##dpptype(obj)->valid; } \
    forceinline void set_##dpptype(dpp::object *obj, auto val) { const auto &_obj = to_##dpptype(obj); _obj->valid = val; } \
    forceinline dpp::object *make_##dpptype(auto val) { \
        cpptype *obj = (cpptype *)dpp::new_object<cpptype>(); \
        obj->valid = val; \
        return (dpp::object *)obj; } \
NAMESPACE_DPP_END

Dpp_DEFINE_ERROR(NoOperatorError)
Dpp_DEFINE_ERROR(DivideZeroError)

#endif // !_DPP_MACROS
