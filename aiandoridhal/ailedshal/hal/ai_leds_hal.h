/*
 * =============================================================================
 *
 *       Filename:  ai_leds_hal.h
 *
 *    Description:  the header of hal
 *
 *        Version:  1.0
 *        Created:  04/19/2019 12:17:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (djy), 1449107534@qq.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef _AI_LEDS_HAL_H_
#define _AI_LEDS_HAL_H_

#include <hardware/hardware.h>
#include <fcntl.h>
#include <cutils/log.h>

struct ai_led_module_t {
    struct hw_module_t hw_module;
};

struct ai_led_control_device_t {
    struct hw_device_t hw_device;
    int (*ai_set_on)(struct ai_led_control_device_t *dev, int32_t led);
    int (*ai_set_off)(struct ai_led_control_device_t *dev, int32_t led);
};

#define AI_LED_HARDWARE_MODULE_ID "ai_led_hal"

#endif /* _AI_LEDS_HAL_H_ */

