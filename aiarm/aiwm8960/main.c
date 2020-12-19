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
    char ch = '\0';

    while (1) {
        ch = getc();
        if (ch)
            putc('M');
        puts("takeno !\n");
        aidelay_ms(2000);
    }

    return 0;
}
