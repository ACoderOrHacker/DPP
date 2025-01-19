/**
 * @file builtin.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief defines built-in objects and its id
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef _DXX_BUILTIN_H
#define _DXX_BUILTIN_H

#include <cstdint>
#include "struct.hpp"

/**
 * @brief built-ins object id
 *
 */
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

/**
 * @brief create a new error object
 *
 * @return dpp::object*
 * @internal
 */
dpp::object *newErrorObject(const std::string &);

/**
 * @brief get all builtins object
 *
 * @return const std::vector<dpp::object *> &
 */
DXX_API const std::vector<dpp::object *> &get_builtins();

/**
 * @brief get the builtin object by id
 *
 * @internal
 */
#define _BUILTINS(id) (get_builtins()[id])

/**
 * @brief the null object with Object type
 *
 */
#define Dpp_Null {true, 0}

/**
 * @brief reference to 'null'
 *
 */
#define Dpp_NullObject _BUILTINS(BUILTIN_NULL)

/**
 * @brief reference to 'BaseError'
 *
 */
#define Dpp_BaseError _BUILTINS(BUILTIN_BASE_ERROR)

/**
 * @brief reference to 'NullPointerError'
 *
 */
#define Dpp_NullPointerError _BUILTINS(BUILTIN_NULLPOINTER_ERROR)

/**
 * @brief reference to 'NoOperatorError'
 *
 */
#define Dpp_DataCantOperatorError _BUILTINS(BUILTIN_NO_OPERATOR_ERROR)

/**
 * @brief reference to 'TypeNotRightError'
 *
 */
#define Dpp_TypeNotRightError _BUILTINS(BUILTIN_TYPE_NOT_RIGHT_ERROR)

/**
 * @brief reference to 'NoMemoryError'
 *
 */
#define Dpp_NoMemoryError _BUILTINS(BUILTIN_NO_MEMORY_ERROR)

/**
 * @brief reference to 'NoSymbolError'
 *
 */
#define Dpp_LibNoSymbolError _BUILTINS(BUILTIN_LIB_NO_SYMBOL_ERROR)

/**
 * @brief reference to 'DivideZeroError'
 *
 */
#define Dpp_DivideZeroError _BUILTINS(BUILTIN_DIVIDE_ZERO_ERROR)

#endif // !_DXX_BUILTIN_H