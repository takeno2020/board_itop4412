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
    // 复位wm8960寄存器
    aii2c_write(0x0f, 0x0);

    /* 设置电源 */
    // VMID 2x50k, VREF上电, Master clock enabled
    aii2c_write(0x19, 0x00c0);
    // headphone,spk,out3,pll电源全都关闭 
    aii2c_write(0x1a, 0x0000);
    aii2c_write(0x2f, 0x0000);

    // 设置时钟
    // MCLK -> SYSCLKDIV -> SYSCLK -> DAC/ADCDIV -> DAC/ADC
    aii2c_write(0x04, 0x0000);

    // 设置ADC-DAC: DAC静音，不使用去加重
    aii2c_write(0x5, 0x0008);

    // 设置audio interface
    //I2S format 16 bits word length
    aii2c_write(0x7, 0x0002);
    
    // ADCLRC/GPIO1作为Jack detect input,Mic基准电压0.9 * AVDD
    aii2c_write(0x30, 0x0002);
    aii2c_write(0x09, 0x0040);

    // 设置OUTPUTS: 0DB
    aii2c_write(0x2, 0x179);
    aii2c_write(0x3, 0x179);

    // Left ADC Digital Volume Control 0db
    aii2c_write(0x15, 0x01c3);
}

void aiwm8960_headphone_start()
{
    u16 val = 0;
    // DAC L/R, L/R OUT1 Output Buffer, PLL Enable Power up
    aii2c_write(0x1a, 0x01e0);

    // 设置DAC VOLUME: -28db
    aii2c_write(0xa, 0x01c5);
    aii2c_write(0xb, 0x01c5);
    aii2c_write(0x5, 0x0000);

    // 设置mixer
    aii2c_write(0x22, 0x0100);
    aii2c_write(0x25, 0x0100);

    // L/R Output Mixer Enable
    val = aii2c_read(0x2f);
    val |= (0x1 << 2) | (0x1 << 3);
    aii2c_write(0x2f, val);
}
