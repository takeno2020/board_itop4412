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
    aii2c_write(0x1a, 0x1f8 << 3);
    aii2c_write(0x2f, 0x1 << 2 | 0x1 << 3);

    // 设置时钟
    // MCLK -> SYSCLKDIV -> SYSCLK -> DAC/ADCDIV -> DAC/ADC
    aii2c_write(0x04, 0x00);

    // 设置ADC-DAC
    aii2c_write(0x5, 0x0);

    // 设置audio interface
    //I2S format 16 bits word length
    aii2c_write(0x7, 0x2);

    // 设置OUTPUTS
    aii2c_write(0x2, 0x1ff);
    aii2c_write(0x3, 0x1ff);
    aii2c_write(0x18, 0x1 << 6);

    // 设置DAC VOLUME
    aii2c_write(0xa, 0x1ff);
    aii2c_write(0xb, 0x1ff);

    // 设置mixer
    aii2c_write(0x22, 0x1 << 8 | 0x1 << 7);
    aii2c_write(0x25, 0x1 << 8 | 0x1 << 7);
}
