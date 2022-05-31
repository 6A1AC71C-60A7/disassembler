
#include <d_opcode.h>
#include <d_mnemonic.h>

///TODO: SOME ARRAYS ARE TOO SHORT AND MAY SEGFAULT IN CASE OF CORRUPTED MODR/M

opfield_t	get_instruction_by_extension_one_and_two_b_opmap(ubyte group, ubyte modrm, ubyte prefix)
{
	const ubyte mod = (modrm & 0b11000000) >> 6;
	const ubyte reg = (modrm & 0b0111000) >> 3;
	const ubyte rm = (modrm & 0b00000111);
	opfield_t	inst = {};

	switch (group)
	{
		case 0x1:
			if (prefix == 0x0)
			{
				static const opfield_t arr[] = {
					///TODO: COMPLETE ATTRIBUTES
					{ .mnemonic = ADD,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = OR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = ADC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = SBB,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = AND,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = SUB,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = XOR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = CMP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x1A:
			if (prefix == 0x0)
			{
				if (!reg)
					inst = (opfield_t){ .mnemonic = POP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			break ;

		case 0x2:
			if (prefix == 0x0)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = ROL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = ROR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = RCL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = RCR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					///TODO: NEXT 3 MNEMONIC ABIGIOUS AND NOT PRESENT
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x3:
			if (prefix == 0x0)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = TEST,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = NOT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = NEG,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = MUL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = IMUL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = DIV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = IDIV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
				};
				inst = arr[reg];
			}
			break ;

		case 0x4:
			if (prefix == 0x0 && reg < 0b010)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = INC,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = DEC,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x5:
			if (prefix == 0x0 && reg < 0b111)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = INC,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = DEC,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					///TODO: NEAR
					{ .mnemonic = CALL,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_F64 },
					///TODO: FAR
					{ .mnemonic = CALL,	.am1 = AM_E,	.ot1 = OT_P,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					///TODO: NEAR
					{ .mnemonic = JMP,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_F64 },
					///TODO: FAR
					{ .mnemonic = JMP,	.am1 = AM_M,	.ot1 = OT_P,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = PUSH,	.am1 = AM_E,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_D64 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x6:
			if (prefix == 0x0 && reg < 0b110)
			{
				static const opfield_t arr[] = {
					/// TODO: NEXT 2 HAS AMBIGIOUS ATTRIBUTES
					{ .mnemonic = SLDT,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = STR,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LLDT,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = LTR,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VERR,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = VERW,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x7:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
				{
					switch (reg)
					{
						case 0b000:
						{
							static const opfield_t arr[] = {
								{ .mnemonic = VMCALL,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = VMLAUNCH,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = VMRESUME,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = VMXOFF,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
							};
							inst = arr[rm];
							break ;
						}
						case 0b001:
						{
							static const opfield_t arr[] = {
								{ .mnemonic = MONITOR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = MWAIT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = CLAC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = STAC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								///TODO: ENCLS (I'VE BUILT THE OPTION INSTEAD OF THE MNEMONIC)
								{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							};
							inst = arr[rm];
							break ;
						}
						case 0b010:
						{
							static const opfield_t arr[] = {
								{ .mnemonic = XGETBV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = XSETBV,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = VMFUNC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = XEND,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								{ .mnemonic = XTEST,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
								///TODO: MNEMONIC ENCLU NOT PRESENT
								{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
							};
							inst = arr[rm];
							break ;
						}
						case 0b100:
							/// TODO: ABIGIOUS ATTR
							inst = (opfield_t){ .mnemonic = SMSW,	.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
							break ;

						case 0b110:
							inst = (opfield_t){ .mnemonic = LMSW,	.am1 = AM_E,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
							break ;

						case 0b111:
						{
							static const opfield_t arr[] = {
								{ .mnemonic = SWAPGS,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = S_O64 },
								{ .mnemonic = RDTSCP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
							};
							inst = arr[rm];
						}
					}
				}
				else
				{
					static const opfield_t arr[] = {
						{ .mnemonic = SGDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = SIDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = LGDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = LIDT,		.am1 = AM_M,	.ot1 = OT_S,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						///TODO: NEXT ONE ABIGIOUS ATTR
						{ .mnemonic = SMSW,		.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = LMSW,		.am1 = AM_M,	.ot1 = OT_W,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = INVLPG,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;
	
		case 0x8:
			if (prefix == 0x0)
			{
				static const opfield_t arr[] = {
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BTS,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BTR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BTC,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x9:
			if (mod == 0b11)
			{
				if (prefix == 0x0 && reg < 0b010)
				{
					static const opfield_t arr[] = {
						{ .mnemonic = RDRAND,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = RDSEED,	.am1 = AM_R,	.ot1 = OT_V,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[rm];
				}
				else if (prefix == 0xF3)
					/// TODO: RDPID MISSING MNEMONIC AND AMBIGIOUS ATTRIBUTE
					inst = (opfield_t){ .mnemonic = 0,	.am1 = AM_R,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			else
			{
				if (prefix == 0x0)
				{
					if (reg == 0b001 && reg < 0b010)
					{
						///TODO: mmmmmmm RM as index ?!?!?
						static const opfield_t arr[] = {
							{ .mnemonic = CMPXCHG8B,	.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
							{ .mnemonic = CMPXCHG16B,	.am1 = AM_M,	.ot1 = OT_DQ,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
						};
						inst = arr[rm];
					}
					else if (reg == 0b110)
						inst = (opfield_t){ .mnemonic = VMPTRLD,	.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else if (reg == 0b111)
						inst = (opfield_t){ .mnemonic = VMPTRST,	.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
				else if (prefix == 0x66 && reg == 0b110)
					inst = (opfield_t){ .mnemonic = VMCLEAR,	.am1 = AM_A,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else if (prefix == 0xF3 && reg == 0b110)
					inst = (opfield_t){ .mnemonic = VMXON,		.am1 = AM_M,	.ot1 = OT_Q,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			break ;

		case 0x10:
			/// TODO: UD1 ( HANDLE IT ? )
			break ;

		case 0x11:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
				{
					if (reg == 0b000)
						inst = (opfield_t){ .mnemonic = MOV,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else if (reg == 0b111 && rm == 0b000)
						inst = (opfield_t){ .mnemonic = XABORT,	.am1 = AM_I,	.ot1 = OT_B,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
				else if (reg == 0b000)
					inst = (opfield_t){ .mnemonic = MOV,	.am1 = AM_E,	.ot1 = OT_B,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
			}
			break ;

		case 0x12:
			if (mod == 0b11 && reg < 0b111)
			{
				if (prefix == 0x0)
				{
					static const opfield_t arr[] = {
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSRLW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSRAW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSLLW,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					static const opfield_t arr[] = {
						///TODO: ALL: VPSRLW, VPSRAW, VPSLLW MNEMONIC MISSING
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x13:
			if (mod == 0b11 && reg < 0b111)
			{
				if (prefix == 0x0)
				{
					static const opfield_t arr[] = {
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSRLD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSRAD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSLLD,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					static const opfield_t arr[] = {
						///TODO: ALL: VPS;RD, VPSRAD, VPSLLD MNEMONIC MISSING
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x14:
			if (mod == 0b11)
			{
				if (prefix == 0x0 && reg < 0b111)
				{
					static const opfield_t arr[] = {
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSRLQ,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = PSLLQ,	.am1 = AM_N,	.ot1 = OT_Q,	.am2 = AM_I,	.ot2 = OT_B,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
				else if (prefix == 0x66)
				{
					static const opfield_t arr[] = {
						/// TODO: ALL: VPSRLQ, VPSRLDQ, VPSLLQ, VPSLLDQ MISSING
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = AM_H,	.ot1 = OT_X,	.am2 = AM_U,	.ot2 = OT_X,	.am3 = AM_I,	.ot3 = OT_B,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x15:
			if (mod == 0b11)
			{
				if (prefix == 0x0)
				{
					if (reg == 0b1010)
						inst = (opfield_t){ .mnemonic = LFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else if (reg == 0b110)
						inst = (opfield_t){ .mnemonic = MFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
					else if (reg == 0b111)
						inst = (opfield_t){ .mnemonic = SFENCE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				}
				else if (prefix == 0xF3 && reg < 0b100)
				{
					static const opfield_t arr[] = {
						{ .mnemonic = RDFSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = RDGSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = WRFSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = WRGSBASE,	.am1 = AM_R,	.ot1 = OT_Y,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			else if (prefix == 0x0)
			{
				static const opfield_t arr[] = {
					///TODO: 4 FIRST MNEMONICS 
					{ .mnemonic = 0,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = 0,		.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = XSAVE,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = XRSTOR,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = XSAVEOPT,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = CLFLUSH,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;

		case 0x16:
			if (prefix == 0x0)
			{
				if (mod == 0b11)
					inst = (opfield_t){ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 };
				else
				{
					static const opfield_t arr[] = {
						/// TODO: NEXT 4 PREFETCH -> MNEMONIC AND ATTRIBUTES
						{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = 0,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 },
						{ .mnemonic = NOP,	.am1 = 0,	.ot1 = 0,	.am2 = 0,	.ot2 = 0,	.am3 = 0,	.ot3 = 0,	.am4 = 0,	.ot4 = 0,	.symbol = 0 }
					};
					inst = arr[reg];
				}
			}
			break ;

		case 0x17:
			if (prefix == 0x0 && reg < 0b100)
			{
				static const opfield_t arr[] = {
					/// TODO: MEXT 4 HAS V
					{ .mnemonic = 0,		.am1 = 0,		.ot1 = 0,		.am2 = 0,		.ot2 = 0,		.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BLSR,		.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BLSMSK,	.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 },
					{ .mnemonic = BLSI,		.am1 = AM_B,	.ot1 = OT_Y,	.am2 = AM_E,	.ot2 = OT_Y,	.am3 = 0,		.ot3 = 0,		.am4 = 0,	.ot4 = 0,	.symbol = 0 }
				};
				inst = arr[reg];
			}
			break ;
	}

	return inst;
}