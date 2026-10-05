/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "%8t ns |  %b  |    %h    (%3d)     |    %h    (%3d)     |  %b  =>      %h        |  %b  |  %b ";
static const char *ng1 = "/home/ise/Xilinx_VM_lab/CO_ALU/ALU_tb.v";
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {170U, 0U};
static unsigned int ng4[] = {85U, 0U};
static unsigned int ng5[] = {1U, 0U};
static int ng6[] = {0, 0};
static int ng7[] = {13, 0};
static const char *ng8 = "-------------------------------------------------------------------------------------------------------";
static const char *ng9 = " \346\231\202\351\226\223(Time) | Opcode | Operand1 (\345\215\201\345\205\255/\345\215\201\351\200\262\344\275\215) | Operand2 (\345\215\201\345\205\255/\345\215\201\351\200\262\344\275\215) | Cin =>  Result (\345\215\201\345\205\255\351\200\262\344\275\215) |  C  |  Z ";
static const char *ng10 = "ALU_wave.vcd";

void Monitor_63_2(char *);
void Monitor_63_2(char *);


static void Monitor_63_2_Func(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    char *t24;

LAB0:    t2 = xsi_vlog_time(t1, 1000.0000000000000, 10.000000000000000);
    t3 = (t0 + 1768);
    t4 = (t3 + 56U);
    t5 = *((char **)t4);
    t6 = (t0 + 1928);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    t9 = (t0 + 1928);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    t12 = (t0 + 2088);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t0 + 2088);
    t16 = (t15 + 56U);
    t17 = *((char **)t16);
    t18 = (t0 + 2248);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    t21 = (t0 + 1048U);
    t22 = *((char **)t21);
    t21 = (t0 + 1208U);
    t23 = *((char **)t21);
    t21 = (t0 + 1368U);
    t24 = *((char **)t21);
    xsi_vlogfile_write(1, 0, 3, ng0, 11, t0, (char)118, t1, 64, (char)118, t5, 4, (char)118, t8, 8, (char)118, t11, 8, (char)118, t14, 8, (char)118, t17, 8, (char)118, t20, 1, (char)118, t22, 16, (char)118, t23, 1, (char)118, t24, 1);

LAB1:    return;
}

static void Initial_31_0(char *t0)
{
    char t6[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;

LAB0:    t1 = (t0 + 3320U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(31, ng1);

LAB4:    xsi_set_current_line(33, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1768);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);
    xsi_set_current_line(34, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(35, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(36, ng1);
    t2 = ((char*)((ng2)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(39, ng1);
    t2 = (t0 + 3128);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(42, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1928);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(43, ng1);
    t2 = ((char*)((ng4)));
    t3 = (t0 + 2088);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(44, ng1);
    t2 = ((char*)((ng5)));
    t3 = (t0 + 2248);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(47, ng1);
    xsi_set_current_line(47, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 2408);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 4);

LAB6:    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng7)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    if (*((unsigned int *)t7) != 0)
        goto LAB8;

LAB7:    t8 = (t5 + 4);
    if (*((unsigned int *)t8) != 0)
        goto LAB8;

LAB11:    if (*((unsigned int *)t4) < *((unsigned int *)t5))
        goto LAB9;

LAB10:    t10 = (t6 + 4);
    t11 = *((unsigned int *)t10);
    t12 = (~(t11));
    t13 = *((unsigned int *)t6);
    t14 = (t13 & t12);
    t15 = (t14 != 0);
    if (t15 > 0)
        goto LAB12;

LAB13:    xsi_set_current_line(52, ng1);
    xsi_vlog_finish(1);
    goto LAB1;

LAB8:    t9 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t9) = 1;
    goto LAB10;

LAB9:    *((unsigned int *)t6) = 1;
    goto LAB10;

LAB12:    xsi_set_current_line(47, ng1);

LAB14:    xsi_set_current_line(48, ng1);
    t16 = (t0 + 2408);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t19 = (t0 + 1768);
    xsi_vlogvar_assign_value(t19, t18, 0, 0, 4);
    xsi_set_current_line(49, ng1);
    t2 = (t0 + 3128);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(47, ng1);
    t2 = (t0 + 2408);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng5)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 4, t4, 4, t5, 4);
    t7 = (t0 + 2408);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 4);
    goto LAB6;

}

static void Initial_58_1(char *t0)
{

LAB0:    xsi_set_current_line(58, ng1);

LAB2:    xsi_set_current_line(59, ng1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    xsi_set_current_line(60, ng1);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    xsi_set_current_line(61, ng1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    xsi_set_current_line(63, ng1);
    Monitor_63_2(t0);

LAB1:    return;
}

static void Initial_67_3(char *t0)
{
    char *t1;

LAB0:    xsi_set_current_line(67, ng1);

LAB2:    xsi_set_current_line(68, ng1);
    xsi_vcd_dumpfile(ng10);
    xsi_set_current_line(69, ng1);
    t1 = ((char*)((ng6)));
    xsi_vcd_dumpvars_args(*((unsigned int *)t1), t0, (char)109, t0, (char)101);

LAB1:    return;
}

void Monitor_63_2(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 3872);
    t2 = (t0 + 4384);
    xsi_vlogfile_monitor((void *)Monitor_63_2_Func, t1, t2);

LAB1:    return;
}


extern void work_m_17292639129365847391_1660568446_init()
{
	static char *pe[] = {(void *)Initial_31_0,(void *)Initial_58_1,(void *)Initial_67_3,(void *)Monitor_63_2};
	xsi_register_didat("work_m_17292639129365847391_1660568446", "isim/ALU8bit_tb_isim_beh.exe.sim/work/m_17292639129365847391_1660568446.didat");
	xsi_register_executes(pe);
}
