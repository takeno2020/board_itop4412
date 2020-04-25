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
#include "ai_leds_cmd.h"

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("takeno");

/* ================================ MACRO =================================== */
#define    AI_GPIO_PART2_BASE    0x11000000
#define    AI_GPL2_BASE          (AI_GPIO_PART2_BASE + 0x0100)
#define    GPL2CON               (AI_GPL2_BASE + 0x00)
#define    GPL2DAT               (AI_GPL2_BASE + 0x04)
#define    GPL2PUD               (AI_GPL2_BASE + 0x08)
#define    AI_GPK_BASE           (AI_GPIO_PART2_BASE + 0x0060)
#define    GPK1CON               (AI_GPK_BASE + 0x00)
#define    GPK1DAT               (AI_GPK_BASE + 0x04)
#define    GPK1PUD               (AI_GPK_BASE + 0x08)

#define    DEVICE_NAME           "ai_leds"
#define    DEVICE_COUNT          1
#define    AI_LEDS_MAJOR         0
#define    AI_LEDS_MINOR         234

/* ================================ GLOBAL ================================== */
static int major = AI_LEDS_MAJOR;
static int minor = AI_LEDS_MINOR;
static dev_t dev_num;
static struct class *ai_pleds_class = NULL;
static struct device *ai_pleds_dev = NULL;
static struct cdev ai_leds_cdev;
static unsigned int *led2con = NULL;
static unsigned int *led2dat = NULL;
static unsigned int *led3con = NULL;
static unsigned int *led3dat = NULL;
static unsigned char mem[2];
static int ai_led2_stat = 0;
static int ai_led3_stat = 0;


ssize_t ai_leds_write(struct file *filep, const char __user *buf,
                        size_t count, loff_t *loff);
long ai_leds_ioctl(struct file *filep, unsigned int cmd, unsigned long args);
static struct file_operations dev_ops = {
    .owner = THIS_MODULE,
    .write = ai_leds_write,
    .unlocked_ioctl = ai_leds_ioctl
};


/* =============================== FUNC ===================================== */
ssize_t ai_leds_write(struct file *filep, const char __user *buf,
                        size_t count, loff_t *ppos)
{
    unsigned int tmp = count;

    memset(mem, 0, sizeof(mem));
    if (count > sizeof(mem)) {
        tmp = sizeof(mem);
    }

    if (copy_from_user(mem, buf, tmp)) {
        return -EFAULT;
    } else {
        // mem[0] mem[1] 对应字符串 "10", led3 led2
        tmp = ioread32(led2dat);
        if (mem[0] == '1') {
            tmp |= 0x1;
        } else {
            tmp &= (~0x1);
        }
        iowrite32(tmp, led2dat);

        tmp = ioread32(led3dat);
        if (mem[1] == '1') {
            tmp |= (0x1 << 1);
        } else {
            tmp &= (~(0x1 << 1));
        }
        iowrite32(tmp, led3dat);
    }

    return count;
}

// cmd取值范围是0，1分别表示关灯和开灯
// arg取值范围：0-1，表示led灯的编号led2 --> 0, led3 --> 1
long ai_leds_ioctl(struct file *filep, unsigned int cmd, unsigned long arg)
{
    unsigned int tmp = 0;

    switch (cmd) {
    case AI_LED_ON:
        if (arg == AI_LED2) {
            tmp = ioread32(led2dat);
            tmp |= 0x1;
            iowrite32(tmp, led2dat);
        } else if (arg == AI_LED3) {
            tmp = ioread32(led3dat);
            tmp |= (0x1 << 1);
            iowrite32(tmp, led3dat);
        }
        break;
    case AI_LED_OFF:
        if (arg == AI_LED2) {
            tmp = ioread32(led2dat);
            tmp &= (~0x1);
            iowrite32(tmp, led2dat);
        } else if (arg == AI_LED3) {
            tmp = ioread32(led3dat);
            tmp &= (~(0x1 << 1));
            iowrite32(tmp, led3dat);
        }
        break;
    default:
        return -EFAULT;
    };

    return 0;
}


static int ai_leds_init(void)
{
    int ret = -1;
    unsigned int val;

    cdev_init(&ai_leds_cdev, &dev_ops);
    ai_leds_cdev.owner = THIS_MODULE;

    if (major > 0) {
        dev_num = MKDEV(major, minor);
        ret = register_chrdev_region(dev_num, DEVICE_COUNT, DEVICE_NAME);
    } else {
        ret = alloc_chrdev_region(&ai_leds_cdev.dev, minor,
                                    DEVICE_COUNT, DEVICE_NAME);
        major = MAJOR(ai_leds_cdev.dev);
        minor = MINOR(ai_leds_cdev.dev);
        dev_num = ai_leds_cdev.dev;
    }
    if (ret < 0) {
        printk(KERN_WARNING "register_chrdev_region() failed\n");
        goto err_alloc_chrdev_region_or_register;
    }

    ret = cdev_add(&ai_leds_cdev, dev_num, DEVICE_COUNT);
    if (ret < 0) {
        printk(KERN_ERR "cdev_add failed!\n");
        goto err_cdev_add;
    }
    ai_pleds_class = class_create(THIS_MODULE, DEVICE_NAME);
    if (IS_ERR(ai_pleds_class)) {
        printk(KERN_ERR "class_create failed!\n");
        ret = PTR_ERR(ai_pleds_class);
        goto err_class_create;
    }
    ai_pleds_dev = device_create(ai_pleds_class, NULL, dev_num, NULL, DEVICE_NAME);
    if (IS_ERR(ai_pleds_dev)) {
        printk(KERN_ERR "device_create failed\n");
        ret = PTR_ERR(ai_pleds_dev);
        goto err_device_create;
    }

    led2con = ioremap(GPL2CON, 4);
    if (led2con == NULL) {
        printk(KERN_ERR "ioremap led2con failed!\n");
        goto err_ioremap_led2con;
    }
    led2dat = ioremap(GPL2DAT, 4);
    if (led2dat == NULL) {
        printk(KERN_ERR "ioremap led2data failed\n");
        goto err_ioremap_led2dat;
    }

    led3con = ioremap(GPK1CON, 4);
    if (led3con == NULL) {
        printk(KERN_ERR "ioremap led3con failed\n");
        goto err_ioremap_led3con;
    }
    led3dat = ioremap(GPK1DAT, 4);
    if (led3dat == NULL) {
        printk(KERN_ERR "ioremap led3data failed\n");
        goto err_ioremap_led3dat;
    }

    printk(KERN_ALERT DEVICE_NAME" ai_led_init succcess!");
    // GPL2_0  GPK1_1
    val = (ioread32(led2con) & (0xf << (0 * 4))) | (0x1 << (0 * 4));
    iowrite32(val, led2con);
    if (ai_led2_stat == 1) {
        iowrite32(1, led2dat);
    } else {
        iowrite32(0, led2dat);
    }
    val = (ioread32(led3con) & (0xf << (1 * 4))) | (0x1 << (1 * 4));
    iowrite32(val, led3con);
    if (ai_led3_stat == 1) {
        iowrite32(1, led3dat);
    } else {
        iowrite32(0, led3dat);
    }
    return 0;

err_ioremap_led3dat:
    iounmap(led3con);
err_ioremap_led3con:
    iounmap(led2dat);
err_ioremap_led2dat:
    iounmap(led2con);
err_ioremap_led2con:
    device_destroy(ai_pleds_class, dev_num);
err_device_create:
    class_destroy(ai_pleds_class);
err_class_create:
    cdev_del(&ai_leds_cdev);
err_cdev_add:
    unregister_chrdev_region(dev_num, DEVICE_COUNT);
err_alloc_chrdev_region_or_register:
    return ret;
}

static void ai_leds_exit(void)
{
    iounmap(led3dat);
    iounmap(led3con);
    iounmap(led2dat);
    iounmap(led2con);
    device_destroy(ai_pleds_class, dev_num);
    class_destroy(ai_pleds_class);
    cdev_del(&ai_leds_cdev);
    unregister_chrdev_region(dev_num, DEVICE_COUNT);
    printk(KERN_ALERT "ai_led_exit success!");
}

module_param(ai_led2_stat, int, S_IRUGO | S_IWUSR);
module_param(ai_led3_stat, int, S_IRUGO | S_IWUSR);
module_init(ai_leds_init);
module_exit(ai_leds_exit);
