/*
 * Copyright (C) 2010-2013 ARM Limited. All rights reserved.
 * 
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 * 
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __MALI_KERNEL_LINUX_H__
#define __MALI_KERNEL_LINUX_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <linux/cdev.h>     /* character device definitions */
#include "mali_kernel_license.h"
#include "mali_osk_types.h"

extern struct platform_device *mali_platform_device;
#include <linux/mali/mali_utgard.h>

#ifdef CONFIG_OF

#include <linux/of.h>
extern const struct of_device_id gpu_ids[];
#endif
void mali_platform_utilization(struct mali_gpu_utilization_data *data);
void mali_platform_device_release(struct device *device);
void mali_power_initialize(struct platform_device *pdev);

#if MALI_LICENSE_IS_GPL
/* Defined in mali_osk_irq.h */
extern struct workqueue_struct * mali_wq_normal;
#endif

struct gpu_freq_table {
	unsigned int	index;     /* any */
	unsigned int	frequency;
	unsigned int	division;
	unsigned int	freq_select;
};

#define GPU_FREQ_TABLE_SIZE 5

struct gpu_freq_table_data {
	struct gpu_freq_table 		freq_tbl[GPU_FREQ_TABLE_SIZE];
};

#ifdef __cplusplus
}
#endif

#endif /* __MALI_KERNEL_LINUX_H__ */