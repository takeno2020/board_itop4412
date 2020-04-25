#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>


MODULE_LICENSE("Dual BSD/GPL");


#define DEV_NAME "wordcount"

#define AI_TRUE (-1)
#define AI_FALSE (0)

static unsigned char mem[10000];
static int word_count = 0;


static int is_spacewhite(char ch)
{
    if (ch == 32 || ch == 9 || ch == 13 || ch == 10)
      return AI_TRUE;
    else
      return AI_FALSE;
}

static int get_word_count(const char *buf)
{
    int n = 1;
    int i = 0;
    char c = ' ';

    int flag = 0;
    if (*buf == '\0') {
        return 0;
    }

    if (is_spacewhite(*buf) == AI_TRUE) {
        n--;
    }

    for (; (c = *(buf + i)) != '\0'; i++) {
        if ((flag == 1) && (is_spacewhite(c) == AI_FALSE)) {
            flag = 0;
        } else if((flag == 1) && (is_spacewhite(c) == AI_TRUE)) {
            continue;
        }

        if (is_spacewhite(c) == AI_TRUE) {
            n++;
            flag = 1;
        }
    }

    if (is_spacewhite(*(buf + i - 1)) == AI_TRUE) {
        n--;
    }
    return n;
}

static ssize_t word_count_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
    int ret = -1;
    unsigned char temp[4];

    temp[0] = word_count >> 24;
    temp[1] = word_count >> 16;
    temp[2] = word_count >> 8;
    temp[3] = word_count;

    ret = copy_to_user(buf, (void*)temp, 4);
    if (ret < 0) {
        return -EINVAL;
    }
    printk("read count: %d\n", (int)count);

    return count;
}

static ssize_t word_count_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    int ret = -1;
    ssize_t written = count;

    ret = copy_from_user(mem, buf, count);
    if (ret < 0) {
        return -ENOMEM;
    }
    mem[count] = '\0';
    printk("write: mem = %s\n", mem);
    word_count = get_word_count(mem);
    printk("write: word count %d\n", (int)word_count);
    return written;
}


static struct file_operations dev_fops = {
    .owner = THIS_MODULE,
    .read = word_count_read,
    .write = word_count_write
};

static struct miscdevice dev_misc = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = DEV_NAME,
    .fops = &dev_fops
};


static int word_count_init(void)
{
    int ret = -1;

    ret = misc_register(&dev_misc);


    printk("word_count_init_success\n");
    return ret;
}

static void word_count_exit(void)
{
    misc_deregister(&dev_misc);

    printk("word count exit success\n");
}

module_init(word_count_init);
module_exit(word_count_exit);
