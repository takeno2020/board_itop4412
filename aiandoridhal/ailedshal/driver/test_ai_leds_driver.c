/*
 * =============================================================================
 *
 *       Filename:  test_ai_leds.c
 *
 *    Description:  测试iTop-4412开发板的led驱动
 *
 *        Version:  1.0
 *        Created:  03/31/2019 02:37:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (djy), 1449107534@qq.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>


int main(int argc, const char *argv[])
{
    int fd = -1;
    char *usage = "Usage: test_ai_leds_hal <r|w> <dev_file> <byte_count> \
                   [byte1] [byte2] ... [byten]";

    if (argc < 4) {
        printf("%s\n", usage);
        return 0;
    }

    char cmd[2] = {0};
    strncpy(cmd, argv[1], 1);
    if (strncmp("r", cmd, 1) != 0 && strncmp("w", cmd, 1) != 0) {
        printf("%s\n", usage);
        return 0;
    }

    char dev_filename[64] = {0};
    strncpy(dev_filename, argv[2], strlen(argv[2]));
    int byte_count = atoi(argv[3]);
    unsigned char buf[byte_count];
    int i = 0;

    if (strncmp(cmd, "w", 1) == 0) {
        for (i = 0; i < byte_count; i++) {
            buf[i] = atoi(argv[4 + i]);
        }

        fd = open(dev_filename, O_WRONLY);
        if (fd < 0) {
            printf("Write: open %s failed!!!\n", dev_filename);
            return 0;
        }

        write(fd, buf, byte_count);
    } else if (strncmp(cmd, "r", 1) == 0) {
        fd = open(dev_filename, O_RDWR);
        if (fd < 0) {
            printf("Read: open %s failed!!!\n", dev_filename);
            return 0;
        }
        buf[0] = atoi(argv[4]);
        write(fd, buf, 1);
        read(fd, buf, byte_count);
        printf("Read: %d bytes:", byte_count);
        for (i = 0; i < byte_count; i++) {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }

    close(fd);
    return 0;
}
