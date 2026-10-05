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
static const char *ng0 = "/home/ise/Xilinx_VM_lab/CO_ALU/ALU.v";
static unsigned int ng1[] = {0U, 0U};
static unsigned int ng2[] = {1U, 0U};
static unsigned int ng3[] = {2U, 0U};
static unsigned int ng4[] = {3U, 0U};
static unsigned int ng5[] = {4U, 0U};
static unsigned int ng6[] = {5U, 0U};
static unsigned int ng7[] = {6U, 0U};
static unsigned int ng8[] = {7U, 0U};
static unsigned int ng9[] = {8U, 0U};
static unsigned int ng10[] = {9U, 0U};
static unsigned int ng11[] = {10U, 0U};
static unsigned int ng12[] = {11U, 0U};
static int ng13[] = {1, 0};
static unsigned int ng14[] = {12U, 0U};



static void Always_38_0(char *t0)
{
    char t6[8];
    char t31[8];
    char t32[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t30;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    char *t43;
    char *t44;
    unsigned int t45;
    unsigned int t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    unsigned int t52;
    int t53;
    int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    char *t61;

LAB0:    t1 = (t0 + 4928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(38, ng0);
    t2 = (t0 + 5248);
    *((int *)t2) = 1;
    t3 = (t0 + 4960);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(39, ng0);

LAB5:    xsi_set_current_line(43, ng0);
    t4 = (t0 + 2816U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(49, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng2)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB21;

LAB18:    if (t18 != 0)
        goto LAB20;

LAB19:    *((unsigned int *)t6) = 1;

LAB21:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB22;

LAB23:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB33;

LAB30:    if (t18 != 0)
        goto LAB32;

LAB31:    *((unsigned int *)t6) = 1;

LAB33:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB34;

LAB35:    xsi_set_current_line(61, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng4)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB45;

LAB42:    if (t18 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t6) = 1;

LAB45:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB46;

LAB47:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng5)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB57;

LAB54:    if (t18 != 0)
        goto LAB56;

LAB55:    *((unsigned int *)t6) = 1;

LAB57:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB58;

LAB59:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB69;

LAB66:    if (t18 != 0)
        goto LAB68;

LAB67:    *((unsigned int *)t6) = 1;

LAB69:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB70;

LAB71:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng7)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB81;

LAB78:    if (t18 != 0)
        goto LAB80;

LAB79:    *((unsigned int *)t6) = 1;

LAB81:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB82;

LAB83:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng8)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB93;

LAB90:    if (t18 != 0)
        goto LAB92;

LAB91:    *((unsigned int *)t6) = 1;

LAB93:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB94;

LAB95:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB108;

LAB105:    if (t18 != 0)
        goto LAB107;

LAB106:    *((unsigned int *)t6) = 1;

LAB108:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB109;

LAB110:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng10)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB123;

LAB120:    if (t18 != 0)
        goto LAB122;

LAB121:    *((unsigned int *)t6) = 1;

LAB123:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB124;

LAB125:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng11)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB138;

LAB135:    if (t18 != 0)
        goto LAB137;

LAB136:    *((unsigned int *)t6) = 1;

LAB138:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB139;

LAB140:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng12)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB152;

LAB149:    if (t18 != 0)
        goto LAB151;

LAB150:    *((unsigned int *)t6) = 1;

LAB152:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB153;

LAB154:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 2816U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng14)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB164;

LAB161:    if (t18 != 0)
        goto LAB163;

LAB162:    *((unsigned int *)t6) = 1;

LAB164:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB165;

LAB166:    xsi_set_current_line(125, ng0);

LAB173:    xsi_set_current_line(126, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3696);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 16);
    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3856);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 4016);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);

LAB167:
LAB155:
LAB141:
LAB126:
LAB111:
LAB96:
LAB84:
LAB72:
LAB60:
LAB48:
LAB36:
LAB24:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(43, ng0);

LAB13:    xsi_set_current_line(44, ng0);
    t28 = (t0 + 2976U);
    t29 = *((char **)t28);
    t28 = (t0 + 3136U);
    t30 = *((char **)t28);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 16, t29, 8, t30, 8);
    t28 = (t0 + 3696);
    xsi_vlogvar_assign_value(t28, t31, 0, 0, 16);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(46, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB17;

LAB14:    if (t18 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t6) = 1;

LAB17:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB12;

LAB16:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB17;

LAB20:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB21;

LAB22:    xsi_set_current_line(49, ng0);

LAB25:    xsi_set_current_line(50, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 16, t22, 8, t28, 8);
    t21 = (t0 + 3296U);
    t29 = *((char **)t21);
    memset(t32, 0, 8);
    xsi_vlog_unsigned_add(t32, 16, t31, 16, t29, 1);
    t21 = (t0 + 3696);
    xsi_vlogvar_assign_value(t21, t32, 0, 0, 16);
    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB29;

LAB26:    if (t18 != 0)
        goto LAB28;

LAB27:    *((unsigned int *)t6) = 1;

LAB29:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB24;

LAB28:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB29;

LAB32:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB33;

LAB34:    xsi_set_current_line(55, ng0);

LAB37:    xsi_set_current_line(56, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_minus(t31, 16, t22, 8, t28, 8);
    t21 = (t0 + 3696);
    xsi_vlogvar_assign_value(t21, t31, 0, 0, 16);
    xsi_set_current_line(57, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB41;

LAB38:    if (t18 != 0)
        goto LAB40;

LAB39:    *((unsigned int *)t6) = 1;

LAB41:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB36;

LAB40:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB41;

LAB44:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB45;

LAB46:    xsi_set_current_line(61, ng0);

LAB49:    xsi_set_current_line(62, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    memset(t31, 0, 8);
    xsi_vlog_unsigned_minus(t31, 16, t22, 8, t28, 8);
    t21 = (t0 + 3296U);
    t29 = *((char **)t21);
    memset(t32, 0, 8);
    xsi_vlog_unsigned_minus(t32, 16, t31, 16, t29, 1);
    t21 = (t0 + 3696);
    xsi_vlogvar_assign_value(t21, t32, 0, 0, 16);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB53;

LAB50:    if (t18 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t6) = 1;

LAB53:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB48;

LAB52:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB53;

LAB56:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB57;

LAB58:    xsi_set_current_line(67, ng0);

LAB61:    xsi_set_current_line(68, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng2)));
    memset(t31, 0, 8);
    xsi_vlog_unsigned_minus(t31, 16, t22, 8, t21, 16);
    t28 = (t0 + 3696);
    xsi_vlogvar_assign_value(t28, t31, 0, 0, 16);
    xsi_set_current_line(69, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(70, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB65;

LAB62:    if (t18 != 0)
        goto LAB64;

LAB63:    *((unsigned int *)t6) = 1;

LAB65:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB60;

LAB64:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB65;

LAB68:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB69;

LAB70:    xsi_set_current_line(73, ng0);

LAB73:    xsi_set_current_line(74, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng2)));
    memset(t31, 0, 8);
    xsi_vlog_unsigned_add(t31, 16, t22, 8, t21, 16);
    t28 = (t0 + 3696);
    xsi_vlogvar_assign_value(t28, t31, 0, 0, 16);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t6 + 4);
    t7 = (t4 + 4);
    t9 = *((unsigned int *)t4);
    t10 = (t9 >> 8);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t7);
    t13 = (t12 >> 8);
    t14 = (t13 & 1);
    *((unsigned int *)t5) = t14;
    t8 = (t0 + 3856);
    xsi_vlogvar_assign_value(t8, t6, 0, 0, 1);
    xsi_set_current_line(76, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB77;

LAB74:    if (t18 != 0)
        goto LAB76;

LAB75:    *((unsigned int *)t6) = 1;

LAB77:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB72;

LAB76:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB77;

LAB80:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB81;

LAB82:    xsi_set_current_line(79, ng0);

LAB85:    xsi_set_current_line(80, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    memcpy(t31, t22, 8);
    t21 = (t0 + 3696);
    xsi_vlogvar_assign_value(t21, t31, 0, 0, 16);
    xsi_set_current_line(81, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 3856);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB89;

LAB86:    if (t18 != 0)
        goto LAB88;

LAB87:    *((unsigned int *)t6) = 1;

LAB89:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB84;

LAB88:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB89;

LAB92:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB93;

LAB94:    xsi_set_current_line(89, ng0);

LAB97:    xsi_set_current_line(90, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    t33 = *((unsigned int *)t22);
    t34 = *((unsigned int *)t28);
    t35 = (t33 & t34);
    *((unsigned int *)t31) = t35;
    t21 = (t22 + 4);
    t29 = (t28 + 4);
    t30 = (t31 + 4);
    t36 = *((unsigned int *)t21);
    t37 = *((unsigned int *)t29);
    t38 = (t36 | t37);
    *((unsigned int *)t30) = t38;
    t39 = *((unsigned int *)t30);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB98;

LAB99:
LAB100:    t61 = (t0 + 3696);
    xsi_vlogvar_assign_value(t61, t31, 0, 0, 16);
    xsi_set_current_line(91, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB104;

LAB101:    if (t18 != 0)
        goto LAB103;

LAB102:    *((unsigned int *)t6) = 1;

LAB104:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB96;

LAB98:    t41 = *((unsigned int *)t31);
    t42 = *((unsigned int *)t30);
    *((unsigned int *)t31) = (t41 | t42);
    t43 = (t22 + 4);
    t44 = (t28 + 4);
    t45 = *((unsigned int *)t22);
    t46 = (~(t45));
    t47 = *((unsigned int *)t43);
    t48 = (~(t47));
    t49 = *((unsigned int *)t28);
    t50 = (~(t49));
    t51 = *((unsigned int *)t44);
    t52 = (~(t51));
    t53 = (t46 & t48);
    t54 = (t50 & t52);
    t55 = (~(t53));
    t56 = (~(t54));
    t57 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t57 & t55);
    t58 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t58 & t56);
    t59 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t59 & t55);
    t60 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t60 & t56);
    goto LAB100;

LAB103:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB104;

LAB107:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB108;

LAB109:    xsi_set_current_line(94, ng0);

LAB112:    xsi_set_current_line(95, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    t33 = *((unsigned int *)t22);
    t34 = *((unsigned int *)t28);
    t35 = (t33 | t34);
    *((unsigned int *)t31) = t35;
    t21 = (t22 + 4);
    t29 = (t28 + 4);
    t30 = (t31 + 4);
    t36 = *((unsigned int *)t21);
    t37 = *((unsigned int *)t29);
    t38 = (t36 | t37);
    *((unsigned int *)t30) = t38;
    t39 = *((unsigned int *)t30);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB113;

LAB114:
LAB115:    t61 = (t0 + 3696);
    xsi_vlogvar_assign_value(t61, t31, 0, 0, 16);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB119;

LAB116:    if (t18 != 0)
        goto LAB118;

LAB117:    *((unsigned int *)t6) = 1;

LAB119:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB111;

LAB113:    t41 = *((unsigned int *)t31);
    t42 = *((unsigned int *)t30);
    *((unsigned int *)t31) = (t41 | t42);
    t43 = (t22 + 4);
    t44 = (t28 + 4);
    t45 = *((unsigned int *)t43);
    t46 = (~(t45));
    t47 = *((unsigned int *)t22);
    t53 = (t47 & t46);
    t48 = *((unsigned int *)t44);
    t49 = (~(t48));
    t50 = *((unsigned int *)t28);
    t54 = (t50 & t49);
    t51 = (~(t53));
    t52 = (~(t54));
    t55 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t55 & t51);
    t56 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t56 & t52);
    goto LAB115;

LAB118:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB119;

LAB122:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB123;

LAB124:    xsi_set_current_line(99, ng0);

LAB127:    xsi_set_current_line(100, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = (t0 + 3136U);
    t28 = *((char **)t21);
    t33 = *((unsigned int *)t22);
    t34 = *((unsigned int *)t28);
    t35 = (t33 ^ t34);
    *((unsigned int *)t31) = t35;
    t21 = (t22 + 4);
    t29 = (t28 + 4);
    t30 = (t31 + 4);
    t36 = *((unsigned int *)t21);
    t37 = *((unsigned int *)t29);
    t38 = (t36 | t37);
    *((unsigned int *)t30) = t38;
    t39 = *((unsigned int *)t30);
    t40 = (t39 != 0);
    if (t40 == 1)
        goto LAB128;

LAB129:
LAB130:    t43 = (t0 + 3696);
    xsi_vlogvar_assign_value(t43, t31, 0, 0, 16);
    xsi_set_current_line(101, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB134;

LAB131:    if (t18 != 0)
        goto LAB133;

LAB132:    *((unsigned int *)t6) = 1;

LAB134:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB126;

LAB128:    t41 = *((unsigned int *)t31);
    t42 = *((unsigned int *)t30);
    *((unsigned int *)t31) = (t41 | t42);
    goto LAB130;

LAB133:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB134;

LAB137:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB138;

LAB139:    xsi_set_current_line(104, ng0);

LAB142:    xsi_set_current_line(105, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    memset(t31, 0, 8);
    t21 = (t31 + 4);
    t28 = (t22 + 4);
    t33 = *((unsigned int *)t22);
    t34 = (~(t33));
    *((unsigned int *)t31) = t34;
    *((unsigned int *)t21) = 0;
    if (*((unsigned int *)t28) != 0)
        goto LAB144;

LAB143:    t39 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t39 & 65535U);
    t40 = *((unsigned int *)t21);
    *((unsigned int *)t21) = (t40 & 65535U);
    t29 = (t0 + 3696);
    xsi_vlogvar_assign_value(t29, t31, 0, 0, 16);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB148;

LAB145:    if (t18 != 0)
        goto LAB147;

LAB146:    *((unsigned int *)t6) = 1;

LAB148:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB141;

LAB144:    t35 = *((unsigned int *)t31);
    t36 = *((unsigned int *)t28);
    *((unsigned int *)t31) = (t35 | t36);
    t37 = *((unsigned int *)t21);
    t38 = *((unsigned int *)t28);
    *((unsigned int *)t21) = (t37 | t38);
    goto LAB143;

LAB147:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB148;

LAB151:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB152;

LAB153:    xsi_set_current_line(112, ng0);

LAB156:    xsi_set_current_line(113, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng13)));
    memset(t31, 0, 8);
    xsi_vlog_unsigned_lshift(t31, 16, t22, 8, t21, 32);
    t28 = (t0 + 3696);
    xsi_vlogvar_assign_value(t28, t31, 0, 0, 16);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 2976U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 7);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 7);
    t14 = (t13 & 1);
    *((unsigned int *)t2) = t14;
    t5 = (t0 + 3856);
    xsi_vlogvar_assign_value(t5, t6, 0, 0, 1);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB160;

LAB157:    if (t18 != 0)
        goto LAB159;

LAB158:    *((unsigned int *)t6) = 1;

LAB160:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB155;

LAB159:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB160;

LAB163:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB164;

LAB165:    xsi_set_current_line(118, ng0);

LAB168:    xsi_set_current_line(119, ng0);
    t21 = (t0 + 2976U);
    t22 = *((char **)t21);
    t21 = ((char*)((ng13)));
    memset(t31, 0, 8);
    xsi_vlog_unsigned_rshift(t31, 16, t22, 8, t21, 32);
    t28 = (t0 + 3696);
    xsi_vlogvar_assign_value(t28, t31, 0, 0, 16);
    xsi_set_current_line(120, ng0);
    t2 = (t0 + 2976U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t6 + 4);
    t4 = (t3 + 4);
    t9 = *((unsigned int *)t3);
    t10 = (t9 >> 0);
    t11 = (t10 & 1);
    *((unsigned int *)t6) = t11;
    t12 = *((unsigned int *)t4);
    t13 = (t12 >> 0);
    t14 = (t13 & 1);
    *((unsigned int *)t2) = t14;
    t5 = (t0 + 3856);
    xsi_vlogvar_assign_value(t5, t6, 0, 0, 1);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 3696);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB172;

LAB169:    if (t18 != 0)
        goto LAB171;

LAB170:    *((unsigned int *)t6) = 1;

LAB172:    t22 = (t0 + 4016);
    xsi_vlogvar_assign_value(t22, t6, 0, 0, 1);
    goto LAB167;

LAB171:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB172;

}


extern void work_m_13437232199096434381_0841572388_init()
{
	static char *pe[] = {(void *)Always_38_0};
	xsi_register_didat("work_m_13437232199096434381_0841572388", "isim/ALU8bit_tb_isim_beh.exe.sim/work/m_13437232199096434381_0841572388.didat");
	xsi_register_executes(pe);
}
