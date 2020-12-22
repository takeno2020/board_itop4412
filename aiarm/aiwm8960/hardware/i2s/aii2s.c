/*
 * =============================================================================
 *
 *       Filename:  aii2s.c
 *
 *    Description:  
 *                Xi2s0CDCLK/PCM_0_EXTCLK   -> GPZ
 *                Xi2s0SCLK/PCM_0_SCLK
 *                Xi2s0LRCK/PCM_0_FSYNC
 *                Xi2s0SDO_0/PCM_0_SOUT
 *                Xi2s0SDI/PCM_0_SIN
 *                XEINT18/KP_ROW2/ALV_DBG14 -> XEINT18/KP_ROW2/ALV_DBG14/GPX2_2
 *
 *        Version:  1.0
 *        Created:  12/19/2020 11:10:47 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "aiexynos_4412.h"

void aii2s0_init(void)
{
    // 配置GPIO用于I2S功能
    GPZ.CON = GPZ.CON & ~((0xf << 4) | (0xf << 0)
                          | (0xf << 8) | (0xf << 16) | (0xf << 12));
    GPZ.CON = GPZ.CON | (0x2 << 4) | (0x2 << 0)
              | (0x2 << 8) | (0x2 << 16) | (0x2 << 12);

    // 配置相关时钟,EPLL_out = 192MHz
    EPLL_CON0 &= ~(0x1 << 31);
    EPLL_CON0 = EPLL_CON0 & ~(0x1ff << 16) & ~(0x3f << 8) & ~0x7;
    EPLL_CON0 = EPLL_CON0 | (0x60 << 16) | (0x3 << 8) | 0x2;
    EPLL_CON1 &= ~0x1;
    // 音频系统时钟选择：Main clk, FOUT_EPLL
    ASS_CLK_SRC &= ~((0x3 << 2) | 0x1);
    ASS_CLK_SRC |= (0x0 << 2) | 0x1;
    ASS_CLK_DIV &= ~(0x0f << 8);

    // Divider of I2S0
    // N + 1 = (192MHz) / (256 * 44.1Khz) = 17
    // CDCLK: 256fs = 256 * 44.1Khz = 11.2896MHz 
    // SCLK:  32fs = 32 * 44.1KHz = 1.4112MHz
    // LRCK   44.1KHz
    I2S0.PSR = (I2S0.PSR & ~(0x3f << 8)) | (0x10 << 8) | (0x1 << 15);
    I2S0.MOD &= ~((0x3 << 8) | (0x3 << 3) | (0x3 << 1));
    I2S0.MOD |= (0x2 << 8) | (0x0 << 3) | (0x0 << 1);

    // PSRAEN
    I2S0.PSR |= 0x1 << 15;

    // RCLKSRC选择I2SCLK
    I2S0.MOD |= 0x1 << 10;
    I2S0.MOD &= ~(0x1 << 11);
    I2S0.MOD &= ~(0x1 << 12);
    I2S0.MOD &= ~(0x3 << 5);
    I2S0.MOD &= ~(0x3 << 13);
    I2S0.MOD &= ~(0x3 << 18);
    I2S0.MOD &= ~(0x3 << 20);
    I2S0.MOD &= ~(0x3 << 26);
    I2S0.MOD &= ~(0x3 << 24);
    I2S0.MOD &= ~(0x1 << 28);
    I2S0.MOD &= ~(0x3 << 30);

    // Un-reset IIS module、IIS interface active 
    I2S0.CON |= 0x1 << 31; 
}

void aii2s0_start(void)
{
    I2S0.CON |= 0x1;
}

void aii2s0_stop(void)
{
    I2S0.CON &= (~0x1);
}
