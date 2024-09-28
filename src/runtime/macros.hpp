#ifndef _DPP_MACROS
#define _DPP_MACROS

#include <exception> // std::exception

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

#define NAMESPACE_DPP_BEGIN namespace dpp {
#define NAMESPACE_DPP_END }
#define NAMESPACE_BASE_BEGIN namespace base {
#define NAMESPACE_BASE_END }

#define Dpp_DEFINE_ERROR(id) class id : std::exception{};
#define Dpp_TYPE(id) class id : protected Dpp_Object

// Define a type with base class
#define Dpp_TYPE_EX(id, base) class id : public base

#endif // !_DPP_MACROS
