/*
 * Copyright(c) 2012-2013, LG Electronics Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __SLIMPORT_H
#define __SLIMPORT_H

#include <linux/err.h>

struct anx7808_platform_data
{
	int gpio_p_dwn;
	int gpio_reset;
	int gpio_int;
	int gpio_cbl_det;
	const char *vdd10_name;
	const char *avdd33_name;
};

#ifdef CONFIG_SLIMPORT_ANX7808
int slimport_read_edid_block(int block, uint8_t *edid_buf);
bool slimport_is_connected(void);
unchar sp_get_link_bw(void);
void sp_set_link_bw(unchar link_bw);
#else
static inline int slimport_read_edid_block(int block, uint8_t *edid_buf) { return -ENOSYS; }
static inline bool slimport_is_connected(void) { return false; }
static inline unchar sp_get_link_bw(void) { return 0};
static inline void sp_set_link_bw(unchar link_bw) {};
#endif

#endif
