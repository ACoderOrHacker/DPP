#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <cstdint>

#include "struct.hpp"

enum BUILTIN : uint32_t {
    BUILTIN_NULL = 0,
	BUILTIN_BASE_ERROR, /* BaseError */
    BUILTIN_NULLPOINTER_ERROR, /* NullPointerError */
	BUILTIN_NO_OPERATOR_ERROR, /* NoOperatorError */
	BUILTIN_TYPE_NOT_RIGHT_ERROR, /* TypeNotRightError */
	BUILTIN_NO_MEMORY_ERROR, /* NoMemoryError */
	BUILTIN_LIB_NO_SYMBOL_ERROR, /* NoSymbolError */
	BUILTIN_DIVIDE_ZERO_ERROR, /* DivideZeroError */
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE,
    CLASS_TYPE,
    ERROR_TYPE,
    FUNCTION_TYPE,
    TYPE_TYPE,

    BUILTIN_END // the builtin list end
};

/*
  Dpp_NullObject malloc must be used,
  if not, when null is accessed,
  it may cause segfault
*/


dpp::object *newErrorObject(const std::string &);

/**
 * @brief get all builtins object
 *
 * @return const std::vector<dpp::object *> &
 */
DXX_API const std::vector<dpp::object *> &get_builtins();

/// Builtins
#define _BUILTINS(id) (get_builtins()[id])

#define Dpp_Null {true, 0}
#define Dpp_NullObject _BUILTINS(BUILTIN_NULL)
#define Dpp_BaseError _BUILTINS(BUILTIN_BASE_ERROR)
#define Dpp_NullPointerError _BUILTINS(BUILTIN_NULLPOINTER_ERROR)
#define Dpp_DataCantOperatorError _BUILTINS(BUILTIN_NO_OPERATOR_ERROR)
#define Dpp_TypeNotRightError _BUILTINS(BUILTIN_TYPE_NOT_RIGHT_ERROR)
#define Dpp_NoMemoryError _BUILTINS(BUILTIN_NO_MEMORY_ERROR)
#define Dpp_LibNoSymbolError _BUILTINS(BUILTIN_LIB_NO_SYMBOL_ERROR)
#define Dpp_DivideZeroError _BUILTINS(BUILTIN_DIVIDE_ZERO_ERROR)

#endif // !_DXX_BUILTIN_H