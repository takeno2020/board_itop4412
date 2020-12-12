/*
 * =============================================================================
 *
 *       Filename:  aiexynos_4412.h
 *
 *    Description:  Exynos4412控制器寄存器定义文件. 
 *
 *        Version:  1.0
 *        Created:  12/13/2020 12:55:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef AI_EXYNOS_4412_H_
#define AI_EXYNOS_4412_H_

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*******************************************************************************
 *                          Common Define
 ******************************************************************************/
#define    __REG(x)    (*((volatile unsigned long *)(x)))


/*******************************************************************************
 *                General Purpose Input/Output Control (GPIO)
 ******************************************************************************/
typedef struct {
    unsigned    long    CON;
    unsigned    long    DAT;
    unsigned    long    PUD;
    unsigned    long    DRV;
    unsigned    long    CONPDN;
    unsigned    long    PUDPDN;
} ai_gpio_t;

typedef struct {
    unsigned    long    CON;
    unsigned    long    DAT;
    unsigned    long    PUD;
    unsigned    long    DRV;
} ai_gpx_t;

#define        GPA0        (*((volatile ai_gpio_t *)0x11400000))
#define        GPA1        (*((volatile ai_gpio_t *)0x11400020))
#define        GPB         (*((volatile ai_gpio_t *)0x11400040))
#define        GPC0        (*((volatile ai_gpio_t *)0x11400060))
#define        GPC1        (*((volatile ai_gpio_t *)0x11400080))
#define        GPD0        (*((volatile ai_gpio_t *)0x114000A0))
#define        GPD1        (*((volatile ai_gpio_t *)0x114000A0))
#define        GPF0        (*((volatile ai_gpio_t *)0x11400180))
#define        GPF1        (*((volatile ai_gpio_t *)0x114001A0))
#define        GPF2        (*((volatile ai_gpio_t *)0x114001C0))
#define        GPF3        (*((volatile ai_gpio_t *)0x114001E0))
#define        GPK0        (*((volatile ai_gpio_t *)0x11000040))
#define        GPK1        (*((volatile ai_gpio_t *)0x11000060))
#define        GPK2        (*((volatile ai_gpio_t *)0x11000080))
#define        GPK3        (*((volatile ai_gpio_t *)0x110000A0))
#define        GPX0        (*((volatile ai_gpx_t *)0x11000C00))
#define        GPX1        (*((volatile ai_gpx_t *)0x11000C20))
#define        GPX2        (*((volatile ai_gpx_t *)0x11000C40))
#define        GPX3        (*((volatile ai_gpx_t *)0x11000C60))


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AI_EXYNOS_4412_H_ */
