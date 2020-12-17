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

void aii2c_init(void)
{
    GPB.CON = (GPB.CON & ~0xff) | 0x33;
}

void aii2c_write(u8 reg, u16 val)
{

}

u16 aii2c_read(u8 reg)
{
    u16 val = 0;


    return val;
}
