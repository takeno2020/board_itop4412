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
#include "ai_leds_driver.h"
#include "ai_leds_driver_define.h"

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

/* ================================ GLOBAL ================================== */
static unsigned char mem[5];
static int major = AI_LEDS_MAJOR;
static int minor = AI_LEDS_MINOR;
static dev_t dev_num;
static struct class *ai_pleds_class = NULL;
static struct device *ai_pleds_dev = NULL;
static struct cdev ai_leds_cdev;
static unsigned int *gpl2con = NULL;
static unsigned int *gpl2dat = NULL;
static unsigned int *gpl2pud = NULL;
static unsigned int *gpk1con = NULL;
static unsigned int *gpk1dat = NULL;
static unsigned int *gpk1pud = NULL;


// 只处理从start开始的四个字节，并且高位在前，即buf[start]为最高位
static unsigned int bytes_to_uint(unsigned char buf[], int start)
{
    unsigned int n = 0;

    n = ((unsigned int)buf[start]) << 24 | ((unsigned int)buf[start + 1]) << 16
        | ((unsigned int)buf[start + 2]) << 8 | ((unsigned int)buf[start + 3]);

    return n;
}

static void uint_to_bytes(unsigned int n, unsigned char buf[], int start)
{
    buf[start] = n >> 24;
    buf[start + 1] = n >> 16;
    buf[start + 2] = n >> 8;
    buf[start + 3] = n;
}

static ssize_t ai_leds_hal_write(struct file *filep, const char __user *buf, 
                                size_t count, loff_t *ppos)
{
    if (copy_from_user(mem, buf, sizeof(mem))) {
        return -EFAULT;
    } else {
        unsigned int reg_type = mem[0];
        unsigned int value = bytes_to_uint(mem, 1);
        switch (reg_type) {
        case AI_LEDS_HAL_WRITE_GPL2CON:
            iowrite32(value, gpl2con);
            break;
        case AI_LEDS_HAL_WRITE_GPL2DAT:
            iowrite32(value, gpl2dat);
            break;
        case AI_LEDS_HAL_WRITE_GPL2PUD:
            iowrite32(value, gpl2pud);
            break;
        case AI_LEDS_HAL_WRITE_GPK1CON:
            iowrite32(value, gpk1con);
            break;
        case AI_LEDS_HAL_WRITE_GPK1DAT:
            iowrite32(value, gpk1dat);
            break;
        case AI_LEDS_HAL_WRITE_GPK1PUD:
            iowrite32(value, gpk1pud);
            break;
        default:
            printk(KERN_INFO "Nothing to be written!!!\n");
            return 0;
        };
    }
    return sizeof(mem);
}

static ssize_t ai_leds_hal_read(struct file *filep, char __user *buf, 
                                size_t count, loff_t *ppos)
{
    unsigned int reg_type = mem[0];
    unsigned int reg_val = 0;

    switch (reg_type) {
    case AI_LEDS_HAL_READ_GPL2CON:
        reg_val = ioread32(gpl2con);
        break;
    case AI_LEDS_HAL_READ_GPL2DAT:
        reg_val = ioread32(gpl2dat);
        break;
    case AI_LEDS_HAL_READ_GPL2PUD:
        reg_val = ioread32(gpl2pud);
        break;
    case AI_LEDS_HAL_READ_GPK1CON:
        reg_val = ioread32(gpk1con);
        break;
    case AI_LEDS_HAL_READ_GPK1DAT:
        reg_val = ioread32(gpk1dat);
        break;
    case AI_LEDS_HAL_READ_GPK1PUD:
        reg_val = ioread32(gpk1pud);
        break;
    default:
        printk(KERN_ERR "Nothing to be read!!!\n");
        return 0;
    };

    uint_to_bytes(reg_val, mem, 1);
    if (copy_to_user(buf, (void *)mem, 5)) {
        return -EFAULT;
    }

    return 5;
}

static struct file_operations dev_ops = {
    .owner = THIS_MODULE,
    .write = ai_leds_hal_write,
    .read = ai_leds_hal_read
};

static int ai_leds_init(void)
{
    int ret = -1;

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
        printk(KERN_WARNING "register_chrdev_region failed!\n");
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
        printk(KERN_ERR "device_create failed!\n");
        ret = PTR_ERR(ai_pleds_dev);
        goto err_device_create;
    }

    ret = -1;
    gpl2con = ioremap(GPL2CON, 4);
    if (gpl2con == NULL) {
        printk(KERN_ERR "ioremap gpl2con failed!\n");
        goto err_gpl2con_ioremap;
    }
    gpl2dat = ioremap(GPL2DAT, 4);
    if (gpl2dat == NULL) {
        printk(KERN_ERR "ioremap gpl2dat failed!\n");
        goto err_gpl2dat_ioremap;
    }
    gpl2pud = ioremap(GPL2PUD, 4);
    if (gpl2pud == NULL) {
        printk(KERN_ERR "ioremap gpl2pud failed!\n");
        goto err_gpl2pud_ioremap;
    }
    gpk1con = ioremap(GPK1CON, 4);
    if (gpk1con == NULL) {
        printk(KERN_ERR "ioremap gpk1con failed!\n");
        goto err_gpk1con_ioremap;
    }
    gpk1dat = ioremap(GPK1DAT, 4);
    if (gpk1dat == NULL) {
        printk(KERN_ERR "ioremap gpk1dat failed!\n");
        goto err_gpk1dat_ioremap;
    }
    gpk1pud = ioremap(GPK1PUD, 4);
    if (gpk1pud == NULL) {
        printk(KERN_ERR "ioremap gpk1pud failed!\n");
        goto err_gpk1pud_ioremap;
    }

    printk(KERN_ALERT DEVICE_NAME" ai_led_hal_init success!!!\n");
    return 0;

err_gpk1pud_ioremap:
    iounmap(gpk1dat);
err_gpk1dat_ioremap:
    iounmap(gpk1con);
err_gpk1con_ioremap:
    iounmap(gpl2pud);
err_gpl2pud_ioremap:
    iounmap(gpl2dat);
err_gpl2dat_ioremap:
    iounmap(gpl2con);
err_gpl2con_ioremap:
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
    iounmap(gpk1pud);
    iounmap(gpk1dat);
    iounmap(gpk1con);
    iounmap(gpl2pud);
    iounmap(gpl2dat);
    iounmap(gpl2con);
    device_destroy(ai_pleds_class, dev_num);
    class_destroy(ai_pleds_class);
    cdev_del(&ai_leds_cdev);
    unregister_chrdev_region(dev_num, DEVICE_COUNT);

    printk(KERN_ALERT "ai_leds_hal_exit success!\n");
}

module_init(ai_leds_init);
module_exit(ai_leds_exit);
