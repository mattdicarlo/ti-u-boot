/*
 * Copyright (C) 2018 Vorne Industries
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware_am33xx.h>

static u32 pru_control_regs[] = {
    0x4a322000, /* PRU 0 CONTROL */
    0x4a324000  /* PRU 1 CONTROL */
};

void init_pru_icss(void)
{
    u32 rm_per_rstctrl;

    /* Make sure PRU-ICSS is released from reset */
    rm_per_rstctrl = readl(RM_PER_RSTCTRL);
    rm_per_rstctrl &= 0xFFFFFFFD; /* de-assert 0x2 */
    writel(rm_per_rstctrl, RM_PER_RSTCTRL);

    udelay(10);
}

/*
 * This assumes that the PRU text and data segments have been loaded and start address is 0x0.
 */
u32 boot_pru(u8 pru_num)
{
    u32 pru_control;

    printf("Booting PRU %d (%d)\n", pru_num, sizeof(pru_control_regs)/sizeof(pru_control_regs[0]));

    if(pru_num >= (sizeof(pru_control_regs)/sizeof(pru_control_regs[0])))
    {
        return 0;
    }

    pru_control = readl(pru_control_regs[pru_num]);

    /* Zero out the start address */
    pru_control &= 0x0000FFFF;
    writel(pru_control, pru_control_regs[pru_num]);

    /* And then enable PRU */
    pru_control |= 0x2;
    writel(pru_control, pru_control_regs[pru_num]);

    return 1;
}
