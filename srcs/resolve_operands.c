
#include <d_portability.h>
#include <d_instruction.h>
#include <d_register.h>
#include <d_opcode.h>
#include <d_utils.h>

#define IS_AMBIGIOUS(x) ((x) >= OR_8 && (x) <= OR_512)

static reg_t	get_general_purpose_register(uqword index)
{
	static const reg_t regs[] = {
		D_REG_RAX, D_REG_RCX, D_REG_RDX, D_REG_RBX,
		D_REG_RSP, D_REG_RBP, D_REG_RSI, D_REG_RDI,
		D_REG_R8,  D_REG_R9,  D_REG_R10, D_REG_R11,
		D_REG_R12, D_REG_R13, D_REG_R14, D_REG_R15
	};

	return regs[index];
}

// static reg_t get_x87_register(uqword index)
// {
//     static const reg_t regs[] = {
//         D_REG_ST0, D_REG_ST1, D_REG_ST2, D_REG_ST3,
//         D_REG_ST4, D_REG_ST5, D_REG_ST6, D_REG_ST7
//     };

//     return regs[index];
// }

static reg_t get_mmx_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_MMX0, D_REG_MMX1, D_REG_MMX2, D_REG_MMX3,
        D_REG_MMX4, D_REG_MMX5, D_REG_MMX6, D_REG_MMX7,
        D_REG_MMX0B, D_REG_MMX1B, D_REG_MMX2B, D_REG_MMX3B,
        D_REG_MMX4B, D_REG_MMX5B, D_REG_MMX6B, D_REG_MMX7B
    };

    return regs[index];
}

static reg_t get_xmm_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_XMM0, D_REG_XMM1, D_REG_XMM2, D_REG_XMM3,
        D_REG_XMM4, D_REG_XMM5, D_REG_XMM6, D_REG_XMM7,
        D_REG_XMM8, D_REG_XMM9, D_REG_XMM10, D_REG_XMM11,
        D_REG_XMM12, D_REG_XMM13, D_REG_XMM14, D_REG_XMM15,
        D_REG_XMM16, D_REG_XMM17, D_REG_XMM18, D_REG_XMM19,
        D_REG_XMM20, D_REG_XMM21, D_REG_XMM22, D_REG_XMM23,
        D_REG_XMM24, D_REG_XMM25, D_REG_XMM26, D_REG_XMM27,
        D_REG_XMM28, D_REG_XMM29, D_REG_XMM30, D_REG_XMM31
    };

    return regs[index];
}

static reg_t get_ymm_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_YMM0, D_REG_YMM1, D_REG_YMM2, D_REG_YMM3,
        D_REG_YMM4, D_REG_YMM5, D_REG_YMM6, D_REG_YMM7,
        D_REG_YMM8, D_REG_YMM9, D_REG_YMM10, D_REG_YMM11,
        D_REG_YMM12, D_REG_YMM13, D_REG_YMM14, D_REG_YMM15,
        D_REG_YMM16, D_REG_YMM17, D_REG_YMM18, D_REG_YMM19,
        D_REG_YMM20, D_REG_YMM21, D_REG_YMM22, D_REG_YMM23,
        D_REG_YMM24, D_REG_YMM25, D_REG_YMM26, D_REG_YMM27,
        D_REG_YMM28, D_REG_YMM29, D_REG_YMM30, D_REG_YMM31
    };

    return regs[index];
}

static reg_t get_zmm_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_ZMM0, D_REG_ZMM1, D_REG_ZMM2, D_REG_ZMM3,
        D_REG_ZMM4, D_REG_ZMM5, D_REG_ZMM6, D_REG_ZMM7,
        D_REG_ZMM8, D_REG_ZMM9, D_REG_ZMM10, D_REG_ZMM11,
        D_REG_ZMM12, D_REG_ZMM13, D_REG_ZMM14, D_REG_ZMM15,
        D_REG_ZMM16, D_REG_ZMM17, D_REG_ZMM18, D_REG_ZMM19,
        D_REG_ZMM20, D_REG_ZMM21, D_REG_ZMM22, D_REG_ZMM23,
        D_REG_ZMM24, D_REG_ZMM25, D_REG_ZMM26, D_REG_ZMM27,
        D_REG_ZMM28, D_REG_ZMM29, D_REG_ZMM30, D_REG_ZMM31
    };

    return regs[index];
}

static reg_t get_segmemt_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_ES, D_REG_CS, D_REG_SS, D_REG_DS,
        D_REG_FS, D_REG_GS, 0, 0,
        D_REG_ESB, D_REG_CSB, D_REG_SSB, D_REG_DSB,
        D_REG_FSB, D_REG_GSB
    };

    return regs[index];
}

static reg_t get_control_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_CR0, D_REG_CR1, D_REG_CR2, D_REG_CR3,
        D_REG_CR4, D_REG_CR5, D_REG_CR6, D_REG_CR7,
        D_REG_CR8, D_REG_CR9, D_REG_CR10, D_REG_CR11,
        D_REG_CR12, D_REG_CR13, D_REG_CR14, D_REG_CR15
    };

    return regs[index];
}

static reg_t get_debug_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_DR0, D_REG_DR1, D_REG_DR2, D_REG_DR3,
        D_REG_DR4, D_REG_DR5, D_REG_DR6, D_REG_DR7,
        D_REG_DR8, D_REG_DR9, D_REG_DR10, D_REG_DR11,
        D_REG_DR12, D_REG_DR13, D_REG_DR14, D_REG_DR15
    };

    return regs[index];
}

static reg_t get_k_register(uqword index)
{
    static const reg_t regs[] = {
        D_REG_K0, D_REG_K1, D_REG_K2, D_REG_K3,
        D_REG_K4, D_REG_K5, D_REG_K6, D_REG_K7
    };

    return regs[index];
}

static void revolve_operand(instruction_t* const inst, reg_t* const dest, ubyte am, ubyte ot, ubyte* const skip)
{
	DEBUG("[DEBUG] RESOLVE OPERAND: AM: %d OT: %d\n", am, ot);

    if (am == AM_ZERO)
		return ;

    /* ModR/M 'reg' field is extended by 1 bit by REX.R prefix or by VEX.~R.
        ModR/M 'rm' field is extended by 1 bit by REX.B prefix or by VEX.~B. */

    const ubyte modrm_mod = MODRM_MOD_GET(inst->mod_rm);
    const ubyte modrm_reg = MODRM_REG_EXTENDED_GET(inst);
    ubyte modrm_rm = MODRM_RM_EXTENDED_GET(inst);

    ubyte vex_vvvv;

    if (*(udword*)inst->prefix & OP_EVEX_MASK)
        vex_vvvv = EVEX_VVVVV_EXTENDTED_GET(inst->vexxop);
    else
        vex_vvvv = (inst->vexxop[2] == 0 ? ~VEXXOP2_VVVV_GET(inst->vexxop) : ~VEXXOP_VVVV_GET(inst->vexxop)) & 0xF;

    DEBUG("MODRM BYTE: 0x%02X\n", inst->mod_rm);
    DEBUG("MODRM REG: %d\n", modrm_reg);
    DEBUG("MODRM RM: %d\n", modrm_rm);
    DEBUG("VEX VVVV is: %d\n", vex_vvvv);

    /// ABOVE SEEMS HANDLED IN 'MODRM_REG_EXTENDED_GET'
    // if (0 /* 3 bytes VEX opcode */)
    //     modrm_rm |= (((*(udword*)inst->prefix & RP_REXB_MASK)) << 3) | (~VEXXOP_B_GET(inst->vexxop) << 3);

    ///TODO: Maybe is more cleaver to test if mod != 0b11 here !

    if (am < DR_RAX)
    {
        switch (am)
        {
            case AM_B:
                *dest = get_general_purpose_register(vex_vvvv);
                break ;

            case AM_C:
                *dest = get_control_register(modrm_reg);
                break ;

            case AM_D:
                *dest = get_debug_register(modrm_reg);
                break ;

            case AM_E:
                *dest = modrm_mod == 0b11 ? get_general_purpose_register(modrm_rm) : D_REG_ADDR;
                break ;

            case AM_F:
                *dest = D_REG_RFLAGS;
                break ;

            case AM_G:
                *dest = get_general_purpose_register(modrm_reg);
                break ;

            case AM_H:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(vex_vvvv);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(vex_vvvv);
                else if (*(udword*)inst->prefix & OS_DQQWORD_MASK)
                    *dest = get_zmm_register(vex_vvvv);
                break ;

            case AM_L:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(inst->immediate & 0xF);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(inst->immediate & 0xF);
                else if (*(udword*)inst->prefix & OS_DQQWORD_MASK)
                    *dest = get_zmm_register(inst->immediate & 0xF);
                break ;

            case AM_M:
                *dest = D_REG_ADDR;
                break ;

            case AM_N:
                *dest = get_mmx_register(modrm_rm);
                break ;

            case AM_O:
                ///TODO: WTF
                break ;

            case AM_P:
                *dest = get_mmx_register(modrm_reg);
                break ;

            case AM_Q:
                *dest = modrm_mod == 0b11 ? get_mmx_register(modrm_rm) : D_REG_ADDR;
                break ;

            case AM_R:
                *dest = get_general_purpose_register(modrm_rm);
                break ;

            case AM_S:
                *dest = get_segmemt_register(modrm_reg);
                break ;

            case AM_U:
                if (modrm_mod == 0b11)
                {
                    if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                        *dest = get_xmm_register(modrm_rm);
                    else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                        *dest = get_ymm_register(modrm_rm);
                    else if (*(udword*)inst->prefix & OS_DQQWORD_MASK)
                        *dest = get_zmm_register(modrm_rm);
                }
                else
                    *dest = D_REG_ADDR;
                break ;

            case AM_V:
                if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                    *dest = get_xmm_register(modrm_reg);
                else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                    *dest = get_ymm_register(modrm_reg);
                else if (*(udword*)inst->prefix & OS_DQQWORD_MASK)
                    *dest = get_zmm_register(modrm_reg);
                break ;

            case AM_W:
                if (modrm_mod == 0b11)
                {
                    ///TODO: 
                    if (*(udword*)inst->prefix & OS_DQWORD_MASK)
                        *dest = get_xmm_register(modrm_rm);
                    else if (*(udword*)inst->prefix & OS_QQWORD_MASK)
                        *dest = get_ymm_register(modrm_rm);
                    else if (*(udword*)inst->prefix & OS_DQQWORD_MASK)
                        *dest = get_zmm_register(modrm_rm);
                }
                else
                    *dest = D_REG_ADDR;
                break ;

            case AM_X:
                *dest = D_REG_PAIR_DS_RSI;
                break ;

            case AM_Y:
                *dest = D_REG_PAIR_ES_RDI;
                break ;

            case AM_KR:
                *dest = get_k_register(modrm_reg & 0x7);
                break ;

            case AM_KRM:
                *dest = get_k_register(modrm_rm & 0x7);
                break ;

            case AM_KV:
                *dest = get_k_register(vex_vvvv & 0x7);
                break ;

            case AM_KM:
                *dest = modrm_mod == 0b11 ? get_k_register(modrm_rm) : D_REG_ADDR;
                break ;
        }
    }
	else
	{
		if (ot == DRS_87)
			*dest = am - 14;
		else if (am < DR_AH)
		{
			*dest = am - 30;
			if (IS_AMBIGIOUS(ot))
            {
                if (*(udword*)inst->prefix & RP_REXB_MASK)
                    *dest += 8;
        		*skip = 0x1;
            }
		}
		else
		{
			switch (am)
			{
				case DR_AH:
					*dest = D_REG_AH;
					break ;

				case DR_CH:
					*dest = D_REG_CH;
					break ;

				case DR_DH:
					*dest = D_REG_DH;
					break ;

				case DR_BH:
					*dest = D_REG_BH;
					break ;
			}
		}
	}

    DEBUG("REG IS: %d\n", *dest);
}

__always_inline
void	resolve_operands(instruction_t* const dest, opfield_t instruction)
{
    ubyte skip;
    ubyte attr_index = 0x0;

    reg_t* const	regs[] = { &dest->reg1, &dest->reg2, &dest->reg3 };
    const byte		ams[] = {instruction.am1, instruction.am2, instruction.am3, instruction.am4 };
    const byte		ots[] = {instruction.ot1, instruction.ot2, instruction.ot3, instruction.ot4 };

    for (uqword i = 0 ; i < ARRLEN(regs) ; i++)
    {
		skip = 0x0;
        revolve_operand(dest, regs[i], ams[attr_index], ots[attr_index], &skip);

        /* Addressing Mode H ((E)VEX.VVVV) is ignored for instructions with no (E)VEX prefix. */
        if (ams[attr_index] == AM_H && !(*(udword*)dest->prefix & OP_EVEX_MASK || dest->vexxop[0]))
            i--;

        attr_index += skip + 1;
    }
}
