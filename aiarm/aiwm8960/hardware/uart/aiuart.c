/*
 * =============================================================================
 *
 *       Filename:  aiuart.c
 *
 *    Description:  使用COM3实现串口调试
 *                  BUF_XuRXD2/UART_AUDIO_RXD -> GPA1_0
 *                  BUF_XuTXD2/UART_AUDIO_TXD -> GPA1_1
 *
 *        Version:  1.0
 *        Created:  12/15/2020 10:41:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "aiexynos_4412.h"
#include "aitypes.h"

static u8 aiuart_hex_tbl[] = {'0','1','2','3','4','5','6','7','8','9',
                              'A','B','C','D','E','F'};
void aiuart_init(void)
{
    // 设置GPA1_0为RX，GPA1_1为TX
    GPA1.CON = (GPA1.CON & ~0xff) | 0x22;

    // 8bit数据位，1bit停止位，无校验位
    UART2.ULCON = 0x3;
    // 中断或轮寻模式
    UART2.UCON = 0x5;
    // 波特率: src clock - 100MHz
    UART2.UBRDIV = 0x35;
    UART2.UFRACVAL = 0x4;
}

void putc(const char ch)
{
    while (!(UART2.UTRSTAT & 0x2))
        ;/* empty */
    UART2.UTXH = ch;
    if (ch == '\n')
        putc('\r');
}

void puts(const char *str)
{
    if (str != NULL)
        while (*str != '\0')
            putc(*str++);
}

char getc(void)
{
    if (UART2.UTRSTAT & 0x1)
        return UART2.URXH;
    else
        return 0;
}

void aiuart_print_hex(const u8 ch)
{
    putc('0');
    putc('x');
    putc(aiuart_hex_tbl[ch >> 4]);
    putc(aiuart_hex_tbl[ch & 0x0f]);
}
