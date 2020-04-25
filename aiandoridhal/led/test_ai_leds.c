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
#include "ai_leds_cmd.h"


int main(int argc, const char *argv[])
{
    int fd = 0;
    int i = 10;

    fd = open("/dev/ai_leds", O_RDWR);
    if (fd < 0) {
        printf("failed to open /dev/ai_leds\n");
        return 0;
    }
    while (i-- > 0) {
        ioctl(fd, AI_LED_ON, AI_LED2);
        ioctl(fd, AI_LED_OFF, AI_LED3);
        sleep(1);

        ioctl(fd, AI_LED_OFF, AI_LED2);
        ioctl(fd, AI_LED_ON, AI_LED3);
        sleep(1);
    }
    close(fd);

    return 0;
}
