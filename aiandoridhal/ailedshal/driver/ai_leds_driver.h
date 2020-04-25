/*
 * =============================================================================
 *
 *       Filename:  ai_leds.c
 *
 *    Description: LED2 --> KP_COL0  --> AA4(XGNSS_GPIO_0/GPL2_0)
 *                 LED3 --> VDD50_EN --> J2(Xmmc1CMD/GPK1_1)
 *                 高电平点亮，低电平熄灭
 *
 *        Version:  1.0
 *        Created:  03/31/2019 10:49:32 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef _AI_LEDS_DRIVER_H_
#define _AI_LEDS_DRIVER_H_

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h> // printk
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/stat.h>

#define    DEVICE_NAME           "ai_leds_hal"
#define    DEVICE_COUNT          1
#define    AI_LEDS_MAJOR         0
#define    AI_LEDS_MINOR         234

#endif /* _AI_LEDS_DRIVER_H_ */
