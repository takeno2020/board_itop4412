/*
 * =============================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/14/2020 12:15:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#include "aiuart.h"
#include "aii2c.h"
#include "aii2s.h"
#include "aiwm8960.h"
#include "aitypes.h"
#include "aiexynos_4412.h"
#include "aiwave.h"

void aidelay_ms(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 3000; j++)
            ;
}

/************************************ main ************************************/
int main(int argc, char *arg[])
{
    unsigned long offset = 0x0;
    u32 *tmp = (u32 *)(wave_data + 44);
#if 0
    u16 tmp_s;
#endif

    aii2c_init();
    aiwm8960_init();
    aii2s0_init();
    aiwm8960_headphone_start();
    aii2s0_start();

    while (1) {
        while ((I2S0.CON & (0x1 << 8)) == (0x1 << 8))
            ;
        I2S0.TXD = *(tmp + offset);
#if 0
        tmp_s = *(tmp + offset);
        aiuart_print_hex(tmp_s & 0xff);
        putc(' ');
        aiuart_print_hex((tmp_s >> 8) & 0xff);
        putc(' ');
        aiuart_print_hex((tmp_s >> 16) & 0xff);
        putc(' ');
        aiuart_print_hex((tmp_s >> 24) & 0xff);
        putc('\n');
#endif
        offset++;
        if (offset > 106485)
            offset = 0x0;
    }

    return 0;
}
