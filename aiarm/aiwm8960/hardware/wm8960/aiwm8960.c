/*
 * =============================================================================
 *
 *       Filename:  aiwm8960.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/20/2020 12:08:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "aii2c.h"

void aiwm8960_init(void)
{
    // 复位寄存器
    aii2c_write(0x0f, 0x0);
    // 设置电源
    aii2c_write(0x19, 0x3 << 7 | 0x1 << 6);
}
