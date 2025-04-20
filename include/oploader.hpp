/**
 * @file oploader.hpp
 * @author ACoderOrHacker (sgy2788@163.com)
 * @brief Load bytecodes for a state.
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef _OPLOADER_HPP_
#define _OPLOADER_HPP_
#include "macros.hpp"
#include "struct.hpp"

NAMESPACE_DPP_BEGIN

class oploader {
private:
    dpp::state &state;
public:
    explicit oploader(dpp::state &state) : state(state) {}

    void change_state(dpp::state &state) { this->state = state; }

    static dpp::bytecode create(rt_opcode op, 
        dpp::mapid operand_0 = {},
        dpp::mapid operand_1 = {},
        dpp::mapid operand_2 = {},
        uint32_t line = 1,
        uint32_t pos = 0) {
        return dpp::bytecode({op, line, pos}, operand_0, operand_1, operand_2);
    }

    oploader &load(rt_opcode op, 
        dpp::mapid operand_0 = {},
        dpp::mapid operand_1 = {},
        dpp::mapid operand_2 = {},
        uint32_t line = 1,
        uint32_t pos = 0) {
        state.vmopcodes.PushEnd(oploader::create(op, operand_0, operand_1, operand_2, line, pos));

        return *this;
    }

    oploader &load(dpp::bytecode &code) { state.vmopcodes.PushEnd(code); return *this; }

    oploader &reset(uint32_t posInState,
        rt_opcode op, 
        dpp::mapid operand_0 = {},
        dpp::mapid operand_1 = {},
        dpp::mapid operand_2 = {},
        uint32_t line = 1,
        uint32_t pos = 0) {
        state.vmopcodes.ResetData(posInState, create(op, operand_0, operand_1, operand_2, line, pos));

        return *this;
    }

    oploader &reset(uint32_t posInState, dpp::bytecode code) { state.vmopcodes.ResetData(posInState, code); return *this; }

    oploader &load_new(dpp::mapid type, dpp::mapid result, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_NEW, type, result, {}, line, pos);

        return *this;
    }

    oploader &load_del(dpp::mapid data, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_DEL, data, {}, {}, line, pos);

        return *this;
    }

    oploader &load_mov(dpp::mapid src, dpp::mapid dst, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_MOV, src, dst, {}, line, pos);

        return *this;
    }

    oploader &load_add(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_ADD, left, right, result, line, pos);

        return *this;
    }

    oploader &load_sub(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_SUB, left, right, result, line, pos);

        return *this;
    }

    oploader &load_mul(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_MUL, left, right, result, line, pos);

        return *this;
    }

    oploader &load_div(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_DIV, left, right, result, line, pos);

        return *this;
    }

    oploader &load_mod(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_MOD, left, right, result, line, pos);

        return *this;
    }

    oploader &load_shl(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_SHL, left, right, result, line, pos);

        return *this;
    }

    oploader &load_shr(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_SHR, left, right, result, line, pos);

        return *this;
    }

    oploader &load_smaller(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_SMALLER, left, right, result, line, pos);

        return *this;
    }

    oploader &load_bigger(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_BIGGER, left, right, result, line, pos);

        return *this;
    }

    oploader &load_band(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_BAND, left, right, result, line, pos);

        return *this;
    }

    oploader &load_bor(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_BOR, left, right, result, line, pos);

        return *this;
    }

    oploader &load_bxor(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_BXOR, left, right, result, line, pos);

        return *this;
    }

    oploader &load_and(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_AND, left, right, result, line, pos);

        return *this;
    }

    oploader &load_or(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_OR, left, right, result, line, pos);

        return *this;
    }

    oploader &load_eq(dpp::mapid left, dpp::mapid right, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_EQ, left, right, result, line, pos);

        return *this;
    }

    oploader &load_not(dpp::mapid obj, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_NOT, obj, result, {}, line, pos);

        return *this;
    }

    oploader &load_bneg(dpp::mapid obj, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_BNEG, obj, result, {}, line, pos);

        return *this;
    }

    oploader &load_jmp(uint32_t posInState, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_JMP, dpp::mapid(posInState), {}, {}, line, pos);

        return *this;
    }

    oploader &load_jnt(uint32_t posInState, dpp::mapid condition, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_JNT, dpp::mapid(posInState), condition, {}, line, pos);

        return *this;
    }

    oploader &load_jnf(uint32_t posInState, dpp::mapid condition, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_JNT, dpp::mapid(posInState), condition, {}, line, pos);

        return *this;
    }

    static dpp::bytecode create_jnt(uint32_t posInState, dpp::mapid condition, uint32_t line = 1, uint32_t pos = 0) {
        return create(OPCODE_JNT, dpp::mapid(posInState), condition, {}, line, pos);
    }

    static dpp::bytecode create_jnf(uint32_t posInState, dpp::mapid condition, uint32_t line = 1, uint32_t pos = 0) {
        return create(OPCODE_JNF, dpp::mapid(posInState), condition, {}, line, pos);
    }

    static dpp::bytecode create_jmp(uint32_t posInState, uint32_t line = 1, uint32_t pos = 0) {
        return create(OPCODE_JMP, dpp::mapid(posInState), {}, {}, line, pos);
    }

    oploader &load_call(dpp::mapid func, dpp::mapid result /* for native function with return values */, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_CALL, func, result, {}, line, pos);

        return *this;
    }

    oploader &load_method(dpp::mapid container, dpp::mapid method, dpp::mapid result,
        uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_METHOD, container, method, result, line, pos);

        return *this;
    }


    oploader &load_pop(dpp::mapid result, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_POP, result, {}, {}, line, pos);

        return *this;
    }

    oploader &load_push(dpp::mapid data, uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_PUSH, data, {}, {}, line, pos);

        return *this;
    }

    oploader &load_ret(uint32_t line = 1, uint32_t pos = 0) {
        load(OPCODE_RET, {}, {}, {}, line, pos);

        return *this;
    }
};

NAMESPACE_DPP_END


#endif // !_OPLOADER_HPP_