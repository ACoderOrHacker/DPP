/**
 * @file eval.h
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Eval the opcode
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _VM_EVAL_H
#define _VM_EVAL_H
#include "macros.hpp"
#include "struct.hpp"
#include "vm.hpp"

NAMESPACE_DPP_BEGIN

/**
 * @brief Eval the opcode
 * 
 * @param vm the vm instance
 * @param op the opcode
 * @return EVAL_SUCCESS success
 * @return EVAL_FAILED failed
 */
DXX_API EVAL_STATUS eval(dpp::vm vm, const dpp::bytecode &op);

/// Bytecode oprands position

/// @enum binary_operands
#define BINARY_LEFT 0
#define BINARY_RIGHT 1
#define BINARY_RESULT 2

/// @enum unary_operands
#define UNARY_OPERAND 0
#define UNARY_RESULT 1

/// @enum jump_operands
#define JMP_POSITION 0
#define JMP_CONDITION 1 // for jnt, jnf

NAMESPACE_DPP_END

Dpp_DEFINE_ERROR(InternalError)

#endif // !_VM_EVAL_H