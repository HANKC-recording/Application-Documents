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
static const char *ng0 = "/home/ise/Xilinx_VM_lab/lab2_4bits_full_adder/ser_adder_tb.v";
static int ng1[] = {0, 0};
static int ng2[] = {2, 0};



static void Initial_46_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(46, ng0);

LAB2:    xsi_set_current_line(47, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2088);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(48, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2248);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2408);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(50, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2568);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(51, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2728);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2888);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(53, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3048);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3208);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(55, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 3368);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_58_1(char *t0)
{
    char t3[8];
    char t5[8];
    char *t1;
    char *t2;
    char *t4;
    char *t6;

LAB0:    t1 = (t0 + 4528U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(58, ng0);

LAB4:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 4336);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(60, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2088);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(61, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2728);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(62, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 3368);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(63, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2248);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(64, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2888);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(65, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2408);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(66, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 3048);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(67, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 2568);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    xsi_set_current_line(68, ng0);
    *((int *)t3) = xsi_vlog_rtl_dist_uniform(0, 0, -2147483648, 2147483647);
    t2 = (t3 + 4);
    *((int *)t2) = 0;
    t4 = ((char*)((ng2)));
    memset(t5, 0, 8);
    xsi_vlog_signed_mod(t5, 32, t3, 32, t4, 32);
    t6 = (t0 + 3208);
    xsi_vlogvar_wait_assign_value(t6, t5, 0, 0, 1, 0LL);
    goto LAB2;

}


extern void work_m_14890768461900608284_3602685654_init()
{
	static char *pe[] = {(void *)Initial_46_0,(void *)Always_58_1};
	xsi_register_didat("work_m_14890768461900608284_3602685654", "isim/ser_adder_ser_adder_sch_tb_isim_beh.exe.sim/work/m_14890768461900608284_3602685654.didat");
	xsi_register_executes(pe);
}
