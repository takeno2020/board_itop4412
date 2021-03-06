/*
 * =============================================================================
 *
 *       Filename:  aiuart.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/15/2020 11:21:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef AI_UART_H_
#define AI_UART_H_
#include "aitypes.h"


void aiuart_init(void);
void putc(const char ch);
void puts(const char *str);
char getc(void);
void aiuart_print_hex(const u8 ch);


#endif /* AI_UART_H_ */
