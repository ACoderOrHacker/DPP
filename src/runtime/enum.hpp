#ifndef _ENUM_H
#define _ENUM_H

enum SIGNAL {
	EXIT
};

enum AUTO_BLOCK_ID {
	NO_AUTO,
	NOW_STATE_ID
};

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
	OPCODE_JMP,
	OPCODE_CALL,
    OPCODE_GETRET,
	OPCODE_CALLN,
	OPCODE_RET,
	OPCODE_SIGN,
	OPCODE_NEW,
    OPCODE_DEL,
	OPCODE_MOV,
    OPCODE_METHOD,
	OPCODE_EXIT,
    OPCODE_END
};
#endif // !_ENUM_H
