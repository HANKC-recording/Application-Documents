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

#include "xsi.h"

struct XSI_INFO xsi_info;



int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    unisims_ver_m_03716419850979525607_3443532839_init();
    unisims_ver_m_15469197826776211918_2316096324_init();
    unisims_ver_m_03261540892355984254_1323117156_init();
    work_m_01886321519029200365_2979166180_init();
    work_m_10566188093435168353_3524211890_init();
    work_m_16541823861846354283_2073120511_init();


    xsi_register_tops("work_m_10566188093435168353_3524211890");
    xsi_register_tops("work_m_16541823861846354283_2073120511");


    return xsi_run_simulation(argc, argv);

}
