/*
 * Copyright (C) 2018 Vorne Industries
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/arch/mux.h>

static struct module_pin_mux vorne_810_display_pin_mux[] = {
    {OFFSET(lcd_data0), (MODE(5) | SLEWCTRL)},      /* P8.45 Red 16 */
    {OFFSET(lcd_data1), (MODE(5) | SLEWCTRL)},      /* P8.46 Green 16 */
    {OFFSET(lcd_data2), (MODE(5) | SLEWCTRL)},      /* P8.43 Red 32 */
    {OFFSET(lcd_data3), (MODE(5) | SLEWCTRL)},      /* P8.44 Green 32 */
    {OFFSET(lcd_data4), (MODE(5) | SLEWCTRL)},      /* P8.41 Row 1 */
    {OFFSET(lcd_data5), (MODE(5) | SLEWCTRL)},      /* P8.42 Row 2 */
    {OFFSET(lcd_data6), (MODE(5) | SLEWCTRL)},      /* P8.39 Row 4 */
    {OFFSET(lcd_data7), (MODE(5) | SLEWCTRL)},      /* P8.40 Row 8 */
    {OFFSET(lcd_vsync), (MODE(5) | SLEWCTRL)},      /* P8.27 Blank */
    {OFFSET(lcd_hsync), (MODE(5) | SLEWCTRL)},      /* P8.29 Latch */
    {OFFSET(lcd_pclk), (MODE(5) | SLEWCTRL)},       /* P8.28 Clock */
    {OFFSET(lcd_ac_bias_en), (MODE(5) | SLEWCTRL)}, /* P8.30 NC */
	{-1},
};


void enable_vorne_810_display_pin_mux(void)
{
	configure_module_pin_mux(vorne_810_display_pin_mux);
}
