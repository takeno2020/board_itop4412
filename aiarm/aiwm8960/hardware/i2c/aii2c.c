/*
 * =============================================================================
 *
 *       Filename:  aii2c.c
 *
 *    Description:  wm8960 i2c控制程序
 *                  XspiCSn0/I2C_4_SCL -> AE21 -> XspiCSn0/I2C_4_SCL/GPB_1
 *                  XspiCLK0/I2C_4_SDA -> AD20 -> XspiCLK0/I2C_4_SDA/GPB_0
 *
 *        Version:  1.0
 *        Created:  12/17/2020 10:11:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "aiexynos_4412.h"
#include "aii2c.h"

#define    AI_WM8960_DEV_ADDR    0x1a

static u16 WM8960_REGVAL_TBL[56] = {
    0X0097,0X0097,0X0000,0X0000,0X0000,0X0008,0X0000,0X000A,
    0X01C0,0X0000,0X00FF,0X00FF,0X0000,0X0000,0X0000,0X0000,
    0X0000,0X007B,0X0100,0X0032,0X0000,0X00C3,0X00C3,0X01C0,
    0X0000,0X0000,0X0000,0X0000,0X0000,0X0000,0X0000,0X0000,
    0X0100,0X0100,0X0050,0X0050,0X0050,0X0050,0X0000,0X0000,
    0X0000,0X0000,0X0040,0X0000,0X0000,0X0050,0X0050,0X0000,
    0X0002,0X0037,0X004D,0X0080,0X0008,0X0031,0X0026,0X00E9
}; 

static void aii2c_delay_ms(int n)
{
    int i, j;

    while (n--) {
        for (i = 0; i < 5; i++)
            for (j = 0; j < 514; j++)
                ;
    }
}

void aii2c_init(void)
{
    GPB.CON = (GPB.CON & ~0xff) | 0x33;
}

void aii2c_write(u8 reg, u16 val)
{
    u16 aa = reg;
    u16 data = (aa << 9) | (val & 0x1ff);

    // 对时钟源进行512倍预分频,打开IIC中断
    // 每次完成一个字节的收发后中断标志位会自动置位
    I2C4.CON = I2C4.CON | (0x1 << 6) | (0x1 << 5);
    I2C4.STAT = 0xd0;

    I2C4.DS = AI_WM8960_DEV_ADDR << 1;
    // 设置IIC模式为主机发送模式、发送起始信号启用总线、使能IIC发送和接收
    I2C4.STAT = 0xf0;
    // 等待从机接受完一个字节后产生应答信号（应答后中断挂起位自动置位）
    while(!(I2C4.CON & (0x1 << 4)));

    I2C4.DS = (data >> 8) & 0xff;
    I2C4.CON = I2C4.CON & (~(0x1 << 4));
    while(!(I2C4.CON & (0x1 << 4)));

    I2C4.DS = data & 0xff;
    I2C4.CON = I2C4.CON & (~(0x1 << 4));
    while(!(I2C4.CON & (0x1 << 4)));

    I2C4.STAT = 0xd0;
    I2C4.CON = I2C4.CON & (~(0x1 << 4));
    WM8960_REGVAL_TBL[reg] = val;
    aii2c_delay_ms(5);
}

u16 aii2c_read(u8 reg)
{
    return WM8960_REGVAL_TBL[reg];
}
