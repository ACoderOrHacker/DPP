#ifndef _DPP_MACROS
#define _DPP_MACROS

#define NO_OPCODE 8
#define HAS_SIGNAL 7

#define NO_FLAG 0b00000000

#define DATA_CANT_OPERATOR_ID 0
#define DATA_NULLP_ID 1
#define LIB_NO_SYMBOL_ID 2
#define NO_MEM_ID 3
#define TYPE_NOT_RIGHT_ID 4

#define GetBit(x, bit) ((x & (1 << bit)) >> bit)
#define SetBit1(x, bit) ((x) |= (1 << (bit)))
#define SetBit0(x, bit) ((x) &= ~ (1 << (bit)))

#endif // !_DPP_MACROS
