

#pragma once

#include <d_types.h>

/*
** Legacy prefixes masks
*/

/// Certain read-modify-write instructions are executed atomically
#define LP_LOCK_MASK (udword)(0x1)
/// Repeat string handling instructions
#define LP_REPNX_MASK (udword)(LP_LOCK_MASK << 1)
/// Repeat string handling instructions
#define LP_REPX_MASK (udword)(LP_REPNX_MASK << 1)
/// Use references within CS segment instead of the stack (ignored on x64)
#define LP_CS_MASK (udword)(LP_REPX_MASK << 1)
/// Use references within SS segment instead of the stack (ignored on x64)
#define LP_SS_MASK (udword)(LP_CS_MASK << 1)
/// Use references within DS segment instead of the stack (ignored on x64)
#define LP_DS_MASK (udword)(LP_SS_MASK << 1)
/// Use references within ES segment instead of the stack (ignored on x64)
#define LP_ES_MASK (udword)(LP_DS_MASK << 1)
/// Use references within FS segment instead of the stack
#define LP_FS_MASK (udword)(LP_ES_MASK << 1)
/// Use references within GS segment instead of the stack
#define LP_GS_MASK (udword)(LP_FS_MASK << 1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (weak hint)
#define LP_NOBRANCH_MASK (udword)(LP_GS_MASK << 1)
/// Used to lessen the impact of branch misprediction somewhat, 
///		only supported by Intel since the Pentium 4 (strong hint)
#define LP_BRANCH_MASK (udword)(LP_NOBRANCH_MASK << 1)
/// Operand size
#define LP_OPSZ_MASK (udword)(LP_BRANCH_MASK << 1)
/// Address size
#define LP_ADDRSZ_MASK (udword)(LP_OPSZ_MASK << 1)

/*
** Mandatory prefixes masks
*/

#define MP_0x66_MASK (udword)(LP_ADDRSZ_MASK << 1)
#define MP_0xF2_MASK (udword)(MP_0x66_MASK << 1)
#define MP_0xF3_MASK (udword)(MP_0xF2_MASK << 1)

/*
** REX prefixes masks
*/

/// When 1, a 64-bit operand size is used. Otherwise, when 0, the default operand size is used
#define RP_REXW_MASK (udword)(MP_0xF3_MASK << 1)
/// This 1-bit value is an extension to the MODRM.reg field
#define RP_REXR_MASK (udword)(RP_REXW_MASK << 1)
/// This 1-bit value is an extension to the SIB.index field
#define RP_REXE_MASK (udword)(RP_REXR_MASK << 1)
/// This 1-bit value is an extension to the MODRM.rm field or the SIB.base field
#define RP_REXB_MASK (udword)(RP_REXE_MASK << 1)

///TODO: Maybe not need it for operand_r
/* Operand kind get */
#define GET_OP1_TYPE(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x4) >> 0x4) & 0b00000011)
#define GET_OP1_TYPE(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x4) >> 0x6) & 0b00000011)

///TODO: Maybe not need it for operand_r
/* Operands kinds */
#define FL_OP1_IMM 0x0
#define FL_OP1_MEM 0x1
#define FL_OP1_REG 0x2
#define FL_OP1_UNUSED 0x3 // free to use for something
#define FL_OP2_IMM 0x0
#define FL_OP2_MEM 0x2
#define FL_OP2_REG 0x2
#define FL_OP2_UNUSED 0x3 // free to use for something

/*
** VEX/XOP members values 
*/

/// Prefix: 0xC4 (3 bytes VEX) | 0xC5 (2 byte VEX) | 0x8F (3 byte XOP)
#define VEXXOP_PREFIX_GET(x) (ubyte)(*(ubyte*)&(x))
/// This 1-bit value is an 'inverted' extension to the MODRM.reg field (the inverse of REX.R)
#define VEXXOP_R_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte)) & 0b00000001)
/// This 1-bit value is an 'inverted' extension to the SIB.index field (the inverse of REX.X)
#define VEXXOP_X_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) + 0x1) & 0b00000010)
/// This 1-bit value is an 'inverted' extension to the MODRM.rm field or the SIB.base field (the inverse of REX.B)
#define VEXXOP_B_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) + 0x3) & 0b00000100)
/// Specifies the opcode map to use
#define VEXXOP_MAP_SELECT_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte)) >> 0x3) & 0b00011111)
/// For integer instructions: when 1, a 64-bit operand size is used; otherwise, when 0, the default operand size is used (equivalent with REX.W)
/// For non-integer instructions, this bit is a general opcode extension bit
#define VEXXOP_WE_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) * 2) & 0b00000001)
/// An additional operand for the instruction, the value of the XMM or YMM register is 'inverted'
#define VEXXOP_VVVV_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2) >> 0x1) & 0b00001111)
/// When 0, a 128-bit vector lengh is used. Otherwise, when 1, a 256-bit vector length is used
#define VEXXOP_L_GET(x) (ubyte)(*(ubyte*)(&(x) + sizeof(ubyte) * 2 + 0x5) & 0b00100000)
/// Specifies an implied mandatory prefix for the opcode:
/// 00 (none) | 01 (0x66) | 10 (0xF3) | 11 (0xF2)
#define VEXXOP_PP_GET(x) (ubyte)((*(ubyte*)(&(x) + sizeof(ubyte) * 2) >> 0x7) & 0b00000011)

typedef enum
{
    NOP // We could sort the mnemonics in a specific order in a way to make ranges (groups)
} mnemonic_t;

typedef struct
{
	ubyte prefix[4];
	ubyte opcode[3];
	mnemonic_t mnemonic;
	ubyte vexxop[3];
	ubyte mod_rm;
	ubyte sib;
	uqword displacement;

	///TODO: register doesn't need 8 bytes to be stored
	/// operand_r does not need to be a 8 bytes
	/// MAX_OPCODE_LEN == 15bytes
	/// And all addresses (rvalue) are register relative ?
	uqword operand_r;
	uqword operand_l;
} instuction_t;