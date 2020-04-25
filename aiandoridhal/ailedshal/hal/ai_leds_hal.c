/*
 * =============================================================================
 *
 *       Filename:  ai_leds_hal.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/19/2019 10:23:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (djy), 1449107534@qq.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "ai_leds_hal.h"
#include "ai_leds_driver_define.h"

int dev_fd = 0;

/*******************************************************************************
 * Function:        ai_led_on_off
 * Description:     led开关通用函数
 * Input:           dev    --> 设备
 *                  led    --> LED序号，目前只有2和3，即板子上的LED2和LED3
 *                  on_off --> 1表示开，0表示关
 * Return:          0  success
 *                  -1  failure
 * Others:          none
*******************************************************************************/
int ai_led_on_off(struct ai_led_control_device_t *dev, int32_t led, int32_t on_off)
{
    if (led >= 2 && led <=3) {
        if (on_off == 1) {
            LOGI("LED Stub: set %d on", led);
        } else {
            LOGI("LED Stub: set %d off", led);
        }

        unsigned char buf[5];

        switch (led) {
        case 2:
            buf[0] = AI_LEDS_HAL_READ_GPL2DAT;
            write(dev_fd, buf, 5);
            read(dev_fd, buf, 5);
            buf[0] = AI_LEDS_HAL_WRITE_GPL2DAT;
            if (on_off == 1) {
                buf[4] |= 0x1;
            } else if (on_off == 0) {
                buf[4] &= 0xfe;
            }
            break;
        case 3:
            buf[0] = AI_LEDS_HAL_READ_GPK1DAT;
            write(dev_fd, buf, 5);
            read(dev_fd, buf, 5);
            buf[0] = AI_LEDS_HAL_WRITE_GPK1DAT;
            if (on_off == 1) {
                buf[4] |= 0x02;
            } else if (on_off == 0) {
                buf[4] &= (~0x02);
            }
            break;
        }
        write(dev_fd, buf, 5);
    } else {
        LOGI("LED Stub: set led %d on error, no this led", led);
        return -1;
    } return 0;
}

int ai_led_on(struct ai_led_control_device_t *dev, int32_t led)
{
    return ai_led_on_off(dev, led, 1);
}

int ai_led_off(struct ai_led_control_device_t *dev, int32_t led)
{
    return ai_led_on_off(dev, led, 0);
}

int ai_led_device_close(struct hw_device_t *device)
{
    struct ai_led_control_device_t *ctx = (struct ai_led_control_device_t *)device;
    if (ctx) {
        free(ctx);
    }
    close(dev_fd);
    return 0;
}

static void ai_leds_init_reg()
{
    int tmp = 0;
    unsigned char buf[5] = {0};

    buf[0] = AI_LEDS_HAL_READ_GPL2CON;
    write(dev_fd, buf, 5);
    read(dev_fd, buf, 5);
    buf[4] = (buf[4] & 0xf0) | 0x1;
    buf[0] = AI_LEDS_HAL_WRITE_GPL2CON;
    write(dev_fd, buf, 5);

    buf[0] = AI_LEDS_HAL_READ_GPK1CON;
    write(dev_fd, buf, 5);
    read(dev_fd, buf, 5);
    buf[4] = (buf[4] & (~(0xf << (1 * 4)))) | (0x1 << (1 * 4));
    buf[0] = AI_LEDS_HAL_WRITE_GPK1CON;
    write(dev_fd, buf, 5);
}

static int ai_led_device_open(const struct hw_module_t *module, const char *name,
                                struct hw_device_t **device)
{
    struct ai_led_control_device_t *dev = NULL;

    LOGI("ai_led_device_open 1");
    dev = (struct ai_led_control_device_t *)malloc(sizeof(*dev));
    memset(dev, 0, sizeof(*dev));
    dev->hw_device.tag = HARDWARE_MODULE_TAG;
    dev->hw_device.version = 0;
    dev->hw_device.module = (struct hw_module_t *)module;
    dev->hw_device.close = ai_led_device_close;
    dev->ai_set_on = ai_led_on;
    dev->ai_set_off = ai_led_off;
    *device = (struct hw_device_t *)dev;

    dev_fd = open("/dev/ai_leds_hal", O_RDWR);
    if (dev_fd < 0) {
        LOGI("LED Stub: open ai_leds_hal fail.\n");
    } else {
        LOGI("LED Stub: open ai_leds_hal success.\n");
    }

    ai_leds_init_reg();
    return 0;
}

static struct hw_module_methods_t ai_led_module_methods = {
    open: ai_led_device_open
};

struct ai_led_module_t HAL_MODULE_INFO_SYM = {
    hw_module: {
                    tag: HARDWARE_MODULE_TAG,
                    version_major: 1,
                    version_minor: 0,
                    id: AI_LED_HARDWARE_MODULE_ID,
                    name: "Sample LED HAL Stub",
                    author: "Aitakeno",
                    methods: &ai_led_module_methods,
                }
};

