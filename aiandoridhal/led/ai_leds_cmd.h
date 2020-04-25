/*
 * =============================================================================
 *
 *       Filename:  ai_leds_cmd.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2019 10:27:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (djy), 1449107534@qq.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef _AI_LEDS_CMD_H_
#define _AI_LEDS_CMD_H_

#include <linux/ioctl.h>

#define    AI_LEDS_MAGIC    'A'
#define    AI_LED_ON        _IO(AI_LEDS_MAGIC, 0)
#define    AI_LED_OFF       _IO(AI_LEDS_MAGIC, 1)
#define    AI_LED2          0
#define    AI_LED3          1

#endif /* _AI_LEDS_CMD_H_ */

