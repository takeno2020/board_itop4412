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
    unsigned    long    CON;       // configuration register
    unsigned    long    DAT;       // data register
    unsigned    long    PUD;       // pull-up/ pull-down register
    unsigned    long    DRV;       // drive strength control register
    unsigned    long    CONPDN;    // power down mode configuration register
    unsigned    long    PUDPDN;    // power down mode pull-up/ pull-down register
} ai_gpio_t;

typedef struct {
    unsigned    long    CON;
    unsigned    long    DAT;
    unsigned    long    PUD;
    unsigned    long    DRV;
} ai_gpx_t;

#define        GPA0        (*((volatile ai_gpio_t *)0X11400000))
#define        GPA1        (*((volatile ai_gpio_t *)0X11400020))
#define        GPB         (*((volatile ai_gpio_t *)0X11400040))
#define        GPC0        (*((volatile ai_gpio_t *)0X11400060))
#define        GPC1        (*((volatile ai_gpio_t *)0X11400080))
#define        GPD0        (*((volatile ai_gpio_t *)0X114000A0))
#define        GPD1        (*((volatile ai_gpio_t *)0X114000C0))
#define        GPF0        (*((volatile ai_gpio_t *)0X11400180))
#define        GPF1        (*((volatile ai_gpio_t *)0X114001A0))
#define        GPF2        (*((volatile ai_gpio_t *)0X114001C0))
#define        GPF3        (*((volatile ai_gpio_t *)0X114001E0))
#define        GPJ0        (*((volatile ai_gpio_t *)0X11400240))
#define        GPJ1        (*((volatile ai_gpio_t *)0X11400260))
#define        GPK0        (*((volatile ai_gpio_t *)0X11000040))
#define        GPK1        (*((volatile ai_gpio_t *)0X11000060))
#define        GPK2        (*((volatile ai_gpio_t *)0X11000080))
#define        GPK3        (*((volatile ai_gpio_t *)0X110000A0))
#define        GPL0        (*((volatile ai_gpio_t *)0X110000C0))
#define        GPL1        (*((volatile ai_gpio_t *)0X110000E0))
#define        GPL2        (*((volatile ai_gpio_t *)0X11000100))
#define        GPM0        (*((volatile ai_gpio_t *)0X11000260))
#define        GPM1        (*((volatile ai_gpio_t *)0X11000280))
#define        GPM2        (*((volatile ai_gpio_t *)0X110002A0))
#define        GPM3        (*((volatile ai_gpio_t *)0X110002C0))
#define        GPM4        (*((volatile ai_gpio_t *)0X110002E0))
#define        GPV0        (*((volatile ai_gpio_t *)0X106E0000))
#define        GPV1        (*((volatile ai_gpio_t *)0X106E0020))
#define        GPV2        (*((volatile ai_gpio_t *)0X106E0060))
#define        GPV3        (*((volatile ai_gpio_t *)0X106E0080))
#define        GPV4        (*((volatile ai_gpio_t *)0X106E00C0))
#define        GPX0        (*((volatile ai_gpx_t *)0X11000C00))
#define        GPX1        (*((volatile ai_gpx_t *)0X11000C20))
#define        GPX2        (*((volatile ai_gpx_t *)0X11000C40))
#define        GPX3        (*((volatile ai_gpx_t *)0X11000C60))
#define        GPY0        (*((volatile ai_gpio_t *)0X11000120))
#define        GPY1        (*((volatile ai_gpio_t *)0X11000140))
#define        GPY2        (*((volatile ai_gpio_t *)0X11000160))
#define        GPY3        (*((volatile ai_gpio_t *)0X11000180))
#define        GPY4        (*((volatile ai_gpio_t *)0X110001A0))
#define        GPY5        (*((volatile ai_gpio_t *)0X110001C0))
#define        GPY6        (*((volatile ai_gpio_t *)0X110001E0))
#define        GPZ         (*((volatile ai_gpio_t *)0X03860000))

#define        ETC0PUD     __REG(0X11000208)
#define        ETC0DRV     __REG(0X1100020C)
#define        ETC1PUD     __REG(0X11400228)
#define        ETC1DRV     __REG(0X1140022C)
#define        ETC6PUD     __REG(0X11000228)
#define        ETC6DRV     __REG(0X1100022C)
#define        ETC7PUD     __REG(0X106E0048)
#define        ETC7DRV     __REG(0X106E004C)
#define        ETC8PUD     __REG(0X106E00A8)
#define        ETC8DRV     __REG(0X106E00AC)


/*******************************************************************************
 *                           External Interrupt
 ******************************************************************************/
/* External interrupt configuration register */
#define        EXT_INT1_CON                   __REG(0X11400700)
#define        EXT_INT2_CON                   __REG(0X11400704)
#define        EXT_INT3_CON                   __REG(0X11400708)
#define        EXT_INT4_CON                   __REG(0X1140070C)
#define        EXT_INT5_CON                   __REG(0X11400710)
#define        EXT_INT6_CON                   __REG(0X11400714)
#define        EXT_INT7_CON                   __REG(0X11400718)
#define        EXT_INT8_CON                   __REG(0X11000724)
#define        EXT_INT9_CON                   __REG(0X11000728)
#define        EXT_INT10_CON                  __REG(0X1100072C)
#define        EXT_INT11_CON                  __REG(0X11000730)
#define        EXT_INT12_CON                  __REG(0X11000734)
#define        EXT_INT13_CON                  __REG(0X11400730)
#define        EXT_INT14_CON                  __REG(0X11400734)
#define        EXT_INT15_CON                  __REG(0X11400738)
#define        EXT_INT16_CON                  __REG(0X1140073C)
#define        EXT_INT21_CON                  __REG(0X11400740)
#define        EXT_INT22_CON                  __REG(0X11400744)
#define        EXT_INT23_CON                  __REG(0X11000708)
#define        EXT_INT24_CON                  __REG(0X1100070C)
#define        EXT_INT25_CON                  __REG(0X11000710)
#define        EXT_INT26_CON                  __REG(0X11000714)
#define        EXT_INT27_CON                  __REG(0X11000718)
#define        EXT_INT28_CON                  __REG(0X1100071C)
#define        EXT_INT29_CON                  __REG(0X11000720)
#define        EXT_INT30_CON                  __REG(0X106E0700)
#define        EXT_INT31_CON                  __REG(0X106E0704)
#define        EXT_INT32_CON                  __REG(0X106E0708)
#define        EXT_INT33_CON                  __REG(0X106E070C)
#define        EXT_INT34_CON                  __REG(0X106E0710)
#define        EXT_INT40_CON                  __REG(0X11000E00)
#define        EXT_INT41_CON                  __REG(0X11000E04)
#define        EXT_INT42_CON                  __REG(0X11000E08)
#define        EXT_INT43_CON                  __REG(0X11000E0C)
#define        EXT_INT50_CON                  __REG(0X03860700)

/* External interrupt filter configuration register */
#define        EXT_INT1_FLTCON0               __REG(0X11400800)
#define        EXT_INT1_FLTCON1               __REG(0X11400804)
#define        EXT_INT2_FLTCON0               __REG(0X11400808)
#define        EXT_INT2_FLTCON1               __REG(0X1140080C)
#define        EXT_INT3_FLTCON0               __REG(0X11400810)
#define        EXT_INT3_FLTCON1               __REG(0X11400814)
#define        EXT_INT4_FLTCON0               __REG(0X11400818)
#define        EXT_INT4_FLTCON1               __REG(0X1140081C)
#define        EXT_INT5_FLTCON0               __REG(0X11400820)
#define        EXT_INT5_FLTCON1               __REG(0X11400824)
#define        EXT_INT6_FLTCON0               __REG(0X11400828)
#define        EXT_INT6_FLTCON1               __REG(0X1140082C)
#define        EXT_INT7_FLTCON0               __REG(0X11400830)
#define        EXT_INT7_FLTCON1               __REG(0X11400834)
#define        EXT_INT8_FLTCON0               __REG(0X11000848)
#define        EXT_INT8_FLTCON1               __REG(0X1100084C)
#define        EXT_INT9_FLTCON0               __REG(0X11000850)
#define        EXT_INT9_FLTCON1               __REG(0X11000854)
#define        EXT_INT10_FLTCON0              __REG(0X11000858)
#define        EXT_INT10_FLTCON1              __REG(0X1100085C)
#define        EXT_INT11_FLTCON0              __REG(0X11000860)
#define        EXT_INT11_FLTCON1              __REG(0X11000864)
#define        EXT_INT12_FLTCON0              __REG(0X11000868)
#define        EXT_INT12_FLTCON1              __REG(0X1100086C)
#define        EXT_INT13_FLTCON0              __REG(0X11400860)
#define        EXT_INT13_FLTCON1              __REG(0X11400864)
#define        EXT_INT14_FLTCON0              __REG(0X11400868)
#define        EXT_INT14_FLTCON1              __REG(0X1140086C)
#define        EXT_INT15_FLTCON0              __REG(0X11400870)
#define        EXT_INT15_FLTCON1              __REG(0X11400874)
#define        EXT_INT16_FLTCON0              __REG(0X11400878)
#define        EXT_INT16_FLTCON1              __REG(0X1140087C)
#define        EXT_INT21_FLTCON0              __REG(0X11400880)
#define        EXT_INT21_FLTCON1              __REG(0X11400884)
#define        EXT_INT22_FLTCON0              __REG(0X11400888)
#define        EXT_INT22_FLTCON1              __REG(0X1140088C)
#define        EXT_INT23_FLTCON0              __REG(0X11000810)
#define        EXT_INT23_FLTCON1              __REG(0X11000814)
#define        EXT_INT24_FLTCON0              __REG(0X11000818)
#define        EXT_INT24_FLTCON1              __REG(0X1100081C)
#define        EXT_INT25_FLTCON0              __REG(0X11000820)
#define        EXT_INT25_FLTCON1              __REG(0X11000824)
#define        EXT_INT26_FLTCON0              __REG(0X11000828)
#define        EXT_INT26_FLTCON1              __REG(0X1100082C)
#define        EXT_INT27_FLTCON0              __REG(0X11000830)
#define        EXT_INT27_FLTCON1              __REG(0X11000834)
#define        EXT_INT28_FLTCON0              __REG(0X11000838)
#define        EXT_INT28_FLTCON1              __REG(0X1100083C)
#define        EXT_INT29_FLTCON0              __REG(0X11000840)
#define        EXT_INT29_FLTCON1              __REG(0X11000844)
#define        EXT_INT30_FLTCON0              __REG(0X106E0800)
#define        EXT_INT30_FLTCON1              __REG(0X106E0804)
#define        EXT_INT31_FLTCON0              __REG(0X106E0808)
#define        EXT_INT31_FLTCON1              __REG(0X106E080C)
#define        EXT_INT32_FLTCON0              __REG(0X106E0810)
#define        EXT_INT32_FLTCON1              __REG(0X106E0814)
#define        EXT_INT33_FLTCON0              __REG(0X106E0818)
#define        EXT_INT33_FLTCON1              __REG(0X106E081C)
#define        EXT_INT34_FLTCON0              __REG(0X106E0820)
#define        EXT_INT34_FLTCON1              __REG(0X106E0824)
#define        EXT_INT40_FLTCON0              __REG(0X11000E80)
#define        EXT_INT40_FLTCON1              __REG(0X11000E84)
#define        EXT_INT41_FLTCON0              __REG(0X11000E88)
#define        EXT_INT41_FLTCON1              __REG(0X11000E8C)
#define        EXT_INT42_FLTCON0              __REG(0X11000E90)
#define        EXT_INT42_FLTCON1              __REG(0X11000E94)
#define        EXT_INT43_FLTCON0              __REG(0X11000E98)
#define        EXT_INT43_FLTCON1              __REG(0X11000E9C)
#define        EXT_INT50_FLTCON0              __REG(0X03860800)
#define        EXT_INT50_FLTCON1              __REG(0X03860804)

/* External interrupt mask register */
#define        EXT_INT1_MASK                  __REG(0X11400900)
#define        EXT_INT2_MASK                  __REG(0X11400904)
#define        EXT_INT3_MASK                  __REG(0X11400908)
#define        EXT_INT4_MASK                  __REG(0X1140090C)
#define        EXT_INT5_MASK                  __REG(0X11400910)
#define        EXT_INT6_MASK                  __REG(0X11400914)
#define        EXT_INT7_MASK                  __REG(0X11400918)
#define        EXT_INT8_MASK                  __REG(0X11000924)
#define        EXT_INT9_MASK                  __REG(0X11000928)
#define        EXT_INT10_MASK                 __REG(0X1100092C)
#define        EXT_INT11_MASK                 __REG(0X11000930)
#define        EXT_INT12_MASK                 __REG(0X11000934)
#define        EXT_INT13_MASK                 __REG(0X11400930)
#define        EXT_INT14_MASK                 __REG(0X11400934)
#define        EXT_INT15_MASK                 __REG(0X11400938)
#define        EXT_INT16_MASK                 __REG(0X1140093C)
#define        EXT_INT21_MASK                 __REG(0X11400940)
#define        EXT_INT22_MASK                 __REG(0X11400944)
#define        EXT_INT23_MASK                 __REG(0X11000908)
#define        EXT_INT24_MASK                 __REG(0X1100090C)
#define        EXT_INT25_MASK                 __REG(0X11000910)
#define        EXT_INT26_MASK                 __REG(0X11000914)
#define        EXT_INT27_MASK                 __REG(0X11000918)
#define        EXT_INT28_MASK                 __REG(0X1100091C)
#define        EXT_INT29_MASK                 __REG(0X11000920)
#define        EXT_INT30_MASK                 __REG(0X106E0900)
#define        EXT_INT31_MASK                 __REG(0X106E0904)
#define        EXT_INT32_MASK                 __REG(0X106E0908)
#define        EXT_INT33_MASK                 __REG(0X106E090C)
#define        EXT_INT34_MASK                 __REG(0X106E0910)
#define        EXT_INT40_MASK                 __REG(0X11000F00)
#define        EXT_INT41_MASK                 __REG(0X11000F04)
#define        EXT_INT42_MASK                 __REG(0X11000F08)
#define        EXT_INT43_MASK                 __REG(0X11000F0C)
#define        EXT_INT50_MASK                 __REG(0X03860900)

/* External interrupt pending register */
#define        EXT_INT1_PEND                  __REG(0X11400A00)
#define        EXT_INT2_PEND                  __REG(0X11400A04)
#define        EXT_INT3_PEND                  __REG(0X11400A08)
#define        EXT_INT4_PEND                  __REG(0X11400A0C)
#define        EXT_INT5_PEND                  __REG(0X11400A10)
#define        EXT_INT6_PEND                  __REG(0X11400A14)
#define        EXT_INT7_PEND                  __REG(0X11400A18)
#define        EXT_INT8_PEND                  __REG(0X11000A24)
#define        EXT_INT9_PEND                  __REG(0X11000A28)
#define        EXT_INT10_PEND                 __REG(0X11000A2C)
#define        EXT_INT11_PEND                 __REG(0X11000A30)
#define        EXT_INT12_PEND                 __REG(0X11000A34)
#define        EXT_INT13_PEND                 __REG(0X11400A30)
#define        EXT_INT14_PEND                 __REG(0X11400A34)
#define        EXT_INT15_PEND                 __REG(0X11400A38)
#define        EXT_INT16_PEND                 __REG(0X11400A3C)
#define        EXT_INT21_PEND                 __REG(0X11400A40)
#define        EXT_INT22_PEND                 __REG(0X11400A44)
#define        EXT_INT23_PEND                 __REG(0X11000A08)
#define        EXT_INT24_PEND                 __REG(0X11000A0C)
#define        EXT_INT25_PEND                 __REG(0X11000A10)
#define        EXT_INT26_PEND                 __REG(0X11000A14)
#define        EXT_INT27_PEND                 __REG(0X11000A18)
#define        EXT_INT28_PEND                 __REG(0X11000A1C)
#define        EXT_INT29_PEND                 __REG(0X11000A20)
#define        EXT_INT30_PEND                 __REG(0X106E0A00)
#define        EXT_INT31_PEND                 __REG(0X106E0A04)
#define        EXT_INT32_PEND                 __REG(0X106E0A08)
#define        EXT_INT33_PEND                 __REG(0X106E0A0C)
#define        EXT_INT34_PEND                 __REG(0X106E0A10)
#define        EXT_INT40_PEND                 __REG(0X11000F40)
#define        EXT_INT41_PEND                 __REG(0X11000F44)
#define        EXT_INT42_PEND                 __REG(0X11000F48)
#define        EXT_INT43_PEND                 __REG(0X11000F4C)
#define        EXT_INT50_PEND                 __REG(0X03860A00)

/* Current service register */
#define        EXT_INT_SERVICE_XA             __REG(0X11000B08)
#define        EXT_INT_SERVICE_XB             __REG(0X11400B08)
#define        EXT_INT_SERVICE_XC             __REG(0X106E0B08)
#define        EXT_INT_SERVICE_XD             __REG(0X03860B08)

/* Current service pending register */
#define        EXT_INT_SERVICE_PEND_XA        __REG(0X11000B0C)
#define        EXT_INT_SERVICE_PEND_XB        __REG(0X11400B0C)
#define        EXT_INT_SERVICE_PEND_XC        __REG(0X106E0B0C)
#define        EXT_INT_SERVICE_PEND_XD        __REG(0X03860B0C)

/* External interrupt group fixed priority control register */
#define        EXT_INT_GRPFIXPRI_XA           __REG(0X11000B10)
#define        EXT_INT_GRPFIXPRI_XB           __REG(0X11400B10)
#define        EXT_INT_GRPFIXPRI_XC           __REG(0X106E0B10)
#define        EXT_INT_GRPFIXPRI_XD           __REG(0X03860B10)

/* External interrupt fixed priority control register */
#define        EXT_INT1_FIXPRI                __REG(0X11400B14)
#define        EXT_INT2_FIXPRI                __REG(0X11400B18)
#define        EXT_INT3_FIXPRI                __REG(0X11400B1C)
#define        EXT_INT4_FIXPRI                __REG(0X11400B20)
#define        EXT_INT5_FIXPRI                __REG(0X11400B24)
#define        EXT_INT6_FIXPRI                __REG(0X11400B28)
#define        EXT_INT7_FIXPRI                __REG(0X11400B2C)
#define        EXT_INT8_FIXPRI                __REG(0X11000B38)
#define        EXT_INT9_FIXPRI                __REG(0X11000B3C)
#define        EXT_INT10_FIXPRI               __REG(0X11000B40)
#define        EXT_INT11_FIXPRI               __REG(0X11000B44)
#define        EXT_INT12_FIXPRI               __REG(0X11000B48)
#define        EXT_INT13_FIXPRI               __REG(0X11400B44)
#define        EXT_INT14_FIXPRI               __REG(0X11400B48)
#define        EXT_INT15_FIXPRI               __REG(0X11400B4C)
#define        EXT_INT16_FIXPRI               __REG(0X11400B50)
#define        EXT_INT21_FIXPRI               __REG(0X11400B54)
#define        EXT_INT22_FIXPRI               __REG(0X11400B58)
#define        EXT_INT23_FIXPRI               __REG(0X11000B1C)
#define        EXT_INT24_FIXPRI               __REG(0X11000B20)
#define        EXT_INT25_FIXPRI               __REG(0X11000B24)
#define        EXT_INT26_FIXPRI               __REG(0X11000B28)
#define        EXT_INT27_FIXPRI               __REG(0X11000B2C)
#define        EXT_INT28_FIXPRI               __REG(0X11000B30)
#define        EXT_INT29_FIXPRI               __REG(0X11000B34)
#define        EXT_INT30_FIXPRI               __REG(0X106E0B14)
#define        EXT_INT31_FIXPRI               __REG(0X106E0B18)
#define        EXT_INT32_FIXPRI               __REG(0X106E0B1C)
#define        EXT_INT33_FIXPRI               __REG(0X106E0B20)
#define        EXT_INT34_FIXPRI               __REG(0X106E0B24)
#define        EXT_INT50_FIXPRI               __REG(0X03860B14)


/*******************************************************************************
 *                        Clock Management Unit
 ******************************************************************************/
#define        CLK_SRC_LEFTBUS                    __REG(0X10034200)
#define        CLK_MUX_STAT_LEFTBUS               __REG(0X10034400)
#define        CLK_DIV_LEFTBUS                    __REG(0X10034500)
#define        CLK_DIV_STAT_LEFTBUS               __REG(0X10034600)
#define        CLK_GATE_IP_LEFTBUS                __REG(0X10034800)
#define        CLK_GATE_IP_IMAGE                  __REG(0X10034930)
#define        CLKOUT_CMU_LEFTBUS                 __REG(0X10034A00)
#define        CLKOUT_CMU_LEFTBUS_DIV_STAT        __REG(0X10034A04)

#define        CLK_SRC_RIGHTBUS                   __REG(0X10038200)
#define        CLK_MUX_STAT_RIGHTBUS              __REG(0X10038400)
#define        CLK_DIV_RIGHTBUS                   __REG(0X10038500)
#define        CLK_DIV_STAT_RIGHTBUS              __REG(0X10038600)
#define        CLK_GATE_IP_RIGHTBUS               __REG(0X10038800)
#define        CLK_GATE_IP_PERIR                  __REG(0X10038960)
#define        CLKOUT_CMU_RIGHTBUS                __REG(0X10038A00)
#define        CLKOUT_CMU_RIGHTBUS_DIV_STAT       __REG(0X10038A04)

#define        EPLL_LOCK                          __REG(0X1003C010)
#define        VPLL_LOCK                          __REG(0X1003C020)
#define        EPLL_CON0                          __REG(0X1003C110)
#define        EPLL_CON1                          __REG(0X1003C114)
#define        EPLL_CON2                          __REG(0X1003C118)
#define        VPLL_CON0                          __REG(0X1003C120)
#define        VPLL_CON1                          __REG(0X1003C124)
#define        VPLL_CON2                          __REG(0X1003C128)

#define        CLK_SRC_TOP0                       __REG(0X1003C210)
#define        CLK_SRC_TOP1                       __REG(0X1003C214)
#define        CLK_SRC_CAM0                       __REG(0X1003C220)
#define        CLK_SRC_TV                         __REG(0X1003C224)
#define        CLK_SRC_MFC                        __REG(0X1003C228)
#define        CLK_SRC_G3D                        __REG(0X1003C22C)
#define        CLK_SRC_LCD                        __REG(0X1003C234)
#define        CLK_SRC_ISP                        __REG(0X1003C238)
#define        CLK_SRC_MAUDIO                     __REG(0X1003C23C)
#define        CLK_SRC_FSYS                       __REG(0X1003C240)
#define        CLK_SRC_PERIL0                     __REG(0X1003C250)
#define        CLK_SRC_PERIL1                     __REG(0X1003C254)
#define        CLK_SRC_CAM1                       __REG(0X1003C258)
#define        CLK_SRC_MASK_CAM0                  __REG(0X1003C320)
#define        CLK_SRC_MASK_TV                    __REG(0X1003C324)
#define        CLK_SRC_MASK_LCD                   __REG(0X1003C334)
#define        CLK_SRC_MASK_ISP                   __REG(0X1003C338)
#define        CLK_SRC_MASK_MAUDIO                __REG(0X1003C33C)
#define        CLK_SRC_MASK_FSYS                  __REG(0X1003C340)
#define        CLK_SRC_MASK_PERIL0                __REG(0X1003C350)
#define        CLK_SRC_MASK_PERIL1                __REG(0X1003C354)

#define        CLK_MUX_STAT_TOP0                  __REG(0X1003C410)
#define        CLK_MUX_STAT_TOP1                  __REG(0X1003C414)
#define        CLK_MUX_STAT_MFC                   __REG(0X1003C428)
#define        CLK_MUX_STAT_G3D                   __REG(0X1003C42C)
#define        CLK_MUX_STAT_CAM1                  __REG(0X1003C458)

#define        CLK_DIV_TOP                        __REG(0X1003C510)
#define        CLK_DIV_CAM0                       __REG(0X1003C520)
#define        CLK_DIV_TV                         __REG(0X1003C524)
#define        CLK_DIV_MFC                        __REG(0X1003C528)
#define        CLK_DIV_G3D                        __REG(0X1003C52C)
#define        CLK_DIV_LCD                        __REG(0X1003C534)
#define        CLK_DIV_ISP                        __REG(0X1003C538)
#define        CLK_DIV_MAUDIO                     __REG(0X1003C53C)
#define        CLK_DIV_FSYS0                      __REG(0X1003C540)
#define        CLK_DIV_FSYS1                      __REG(0X1003C544)
#define        CLK_DIV_FSYS2                      __REG(0X1003C548)
#define        CLK_DIV_FSYS3                      __REG(0X1003C54C)
#define        CLK_DIV_PERIL0                     __REG(0X1003C550)
#define        CLK_DIV_PERIL1                     __REG(0X1003C554)
#define        CLK_DIV_PERIL2                     __REG(0X1003C558)
#define        CLK_DIV_PERIL3                     __REG(0X1003C55C)
#define        CLK_DIV_PERIL4                     __REG(0X1003C560)
#define        CLK_DIV_PERIL5                     __REG(0X1003C564)
#define        CLK_DIV_CAM1                       __REG(0X1003C568)
#define        CLKDIV2_RATIO                      __REG(0X1003C580)
#define        CLK_DIV_STAT_TOP                   __REG(0X1003C610)
#define        CLK_DIV_STAT_CAM0                  __REG(0X1003C620)
#define        CLK_DIV_STAT_TV                    __REG(0X1003C624)
#define        CLK_DIV_STAT_MFC                   __REG(0X1003C628)
#define        CLK_DIV_STAT_G3D                   __REG(0X1003C62C)
#define        CLK_DIV_STAT_LCD                   __REG(0X1003C634)
#define        CLK_DIV_STAT_ISP                   __REG(0X1003C638)
#define        CLK_DIV_STAT_MAUDIO                __REG(0X1003C63c)
#define        CLK_DIV_STAT_FSYS0                 __REG(0X1003C640)
#define        CLK_DIV_STAT_FSYS1                 __REG(0X1003C644)
#define        CLK_DIV_STAT_FSYS2                 __REG(0X1003C648)
#define        CLK_DIV_STAT_FSYS3                 __REG(0X1003C64C)
#define        CLK_DIV_STAT_PERIL0                __REG(0X1003C650)
#define        CLK_DIV_STAT_PERIL1                __REG(0X1003C654)
#define        CLK_DIV_STAT_PERIL2                __REG(0X1003C658)
#define        CLK_DIV_STAT_PERIL3                __REG(0X1003C65C)
#define        CLK_DIV_STAT_PERIL4                __REG(0X1003C660)
#define        CLK_DIV_STAT_PERIL5                __REG(0X1003C664)
#define        CLK_DIV_STAT_CAM1                  __REG(0X1003C668)
#define        CLKDIV2_STAT                       __REG(0X1003C680)

#define        CLK_GATE_BUS_FSYS1                 __REG(0X1003C744)
#define        CLK_GATE_IP_CAM                    __REG(0X1003C920)
#define        CLK_GATE_IP_TV                     __REG(0X1003C924)
#define        CLK_GATE_IP_MFC                    __REG(0X1003C928)
#define        CLK_GATE_IP_G3D                    __REG(0X1003C92C)
#define        CLK_GATE_IP_LCD                    __REG(0X1003C934)
#define        CLK_GATE_IP_ISP                    __REG(0X1003C938)
#define        CLK_GATE_IP_FSYS                   __REG(0X1003C940)
#define        CLK_GATE_IP_GPS                    __REG(0X1003C94C)
#define        CLK_GATE_IP_PERIL                  __REG(0X1003C950)
#define        CLK_GATE_BLOCK                     __REG(0X1003C970)

#define        CLKOUT_CMU_TOP                     __REG(0X1003CA00)
#define        CLKOUT_CMU_TOP_DIV_STAT            __REG(0X1003CA04)

#define        MPLL_LOCK                          __REG(0X10040008)
#define        MPLL_CON0                          __REG(0X10040108)
#define        MPLL_CON1                          __REG(0X1004010C)
#define        CLK_SRC_DMC                        __REG(0X10040200)
#define        CLK_SRC_MASK_DMC                   __REG(0X10040300)
#define        CLK_MUX_STAT_DMC                   __REG(0X10040400)
#define        CLK_DIV_DMC0                       __REG(0X10040500)
#define        CLK_DIV_DMC1                       __REG(0X10040504)
#define        CLK_DIV_STAT_DMC0                  __REG(0X10040600)
#define        CLK_DIV_STAT_DMC1                  __REG(0X10040604)
#define        CLK_GATE_BUS_DMC0                  __REG(0X10040700)
#define        CLK_GATE_BUS_DMC1                  __REG(0X10040704)
#define        CLK_GATE_IP_DMC0                   __REG(0X10040900)
#define        CLK_GATE_IP_DMC1                   __REG(0X10040904)
#define        CLKOUT_CMU_DMC                     __REG(0X10040A00)
#define        CLKOUT_CMU_DMC_DIV_STAT            __REG(0X10040A04)
#define        DCGIDX_MAP0                        __REG(0X10041000)
#define        DCGIDX_MAP1                        __REG(0X10041004)
#define        DCGIDX_MAP2                        __REG(0X10041008)
#define        DCGPERF_MAP0                       __REG(0X10041020)
#define        DCGPERF_MAP1                       __REG(0X10041024)
#define        DVCIDX_MAP                         __REG(0X10041040)
#define        FREQ_CPU                           __REG(0X10041060)
#define        FREQ_DPM                           __REG(0X10041064)
#define        DVSEMCLK_EN                        __REG(0X10041080)
#define        MAXPERF                            __REG(0X10041084)
#define        DMC_PAUSE_CTRL                     __REG(0X10041094)
#define        DDRPHY_LOCK_CTRL                   __REG(0X10041098)
#define        C2C_STAT                           __REG(0X1004109C)
#define        APLL_LOCK                          __REG(0X10044000)
#define        APLL_CON0                          __REG(0X10044100)
#define        APLL_CON1                          __REG(0X10044104)
#define        CLK_SRC_CPU                        __REG(0X10044200)
#define        CLK_MUX_STAT_CPU                   __REG(0X10044400)
#define        CLK_DIV_CPU0                       __REG(0X10044500)
#define        CLK_DIV_CPU1                       __REG(0X10044504)
#define        CLK_DIV_STAT_CPU0                  __REG(0X10044600)
#define        CLK_DIV_STAT_CPU1                  __REG(0X10044604)
#define        CLK_GATE_IP_CPU                    __REG(0X10044900)
#define        CLKOUT_CMU_CPU                     __REG(0X10044A00)
#define        CLKOUT_CMU_CPU_DIV_STAT            __REG(0X10044A04)
#define        ARMCLK_STOPCTRL                    __REG(0X10045000)
#define        ATCLK_STOPCTRL                     __REG(0X10045004)
#define        PWR_CTRL                           __REG(0X10045020)
#define        PWR_CTRL2                          __REG(0X10045024)
#define        L2_STATUS                          __REG(0X10045400)
#define        CPU_STATUS                         __REG(0X10045410)
#define        PTM_STATUS                         __REG(0X10045420)
#define        CLK_DIV_ISP0                       __REG(0X10048300)
#define        CLK_DIV_ISP1                       __REG(0X10048304)
#define        CLK_DIV_STAT_ISP0                  __REG(0X10048400)
#define        CLK_DIV_STAT_ISP1                  __REG(0X10048404)
#define        CLK_GATE_IP_ISP0                   __REG(0X10048800)
#define        CLK_GATE_IP_ISP1                   __REG(0X10048804)
#define        CLKOUT_CMU_ISP                     __REG(0X10048A00)
#define        CLKOUT_CMU_ISP_DIV                 __REG(0X10048A04)
#define        CMU_ISP_SPARE0                     __REG(0X10048B00)
#define        CMU_ISP_SPARE1                     __REG(0X10048B04)
#define        CMU_ISP_SPARE2                     __REG(0X10048B08)
#define        CMU_ISP_SPARE3                     __REG(0X10048B0C)


/*******************************************************************************
 *                        Power Management Unit
 ******************************************************************************/
#define        OM_STAT                                  __REG(0X10020000)
#define        LPI_MASK0                                __REG(0X10020004)
#define        LPI_MASK1                                __REG(0X10020008)
#define        LPI_MASK2                                __REG(0X1002000C)
#define        RTC_CLKO_SEL                             __REG(0X10020010)
#define        GNSS_RTC_OUT_CTRL                        __REG(0X10020014)
#define        LPI_DENIAL_MASK0                         __REG(0X10020018)
#define        LPI_DENIAL_MASK1                         __REG(0X1002001C)
#define        LPI_DENIAL_MASK2                         __REG(0X10020020)
#define        C2C_CTRL                                 __REG(0X10020024)
#define        INTR_SSPREAD_ENABLE                      __REG(0X10020100)
#define        INTR_SSPREAD_USE_STANDBYWFI              __REG(0X10020104)
#define        INTR_SSPREAD_BLOCKING_DURATION           __REG(0X10020108)
#define        CENTRAL_SEQ_CONFIGURATION                __REG(0X10020200)
#define        CENTRAL_SEQ_OPTION                       __REG(0X10020208)
#define        CENTRAL_SEQ_CONFIGURATION_COREBLK        __REG(0X10020240)
#define        SWRESET                                  __REG(0X10020400)
#define        RST_STAT                                 __REG(0X10020404)
#define        AUTOMATIC_WDT_RESET_DISABLE              __REG(0X10020408)
#define        MASK_WDT_RESET_REQUEST                   __REG(0X1002040C)
#define        WAKEUP_STAT                              __REG(0X10020600)
#define        EINT_WAKEUP_MASK                         __REG(0X10020604)
#define        WAKEUP_MASK                              __REG(0X10020608)
#define        WAKEUP_STAT_COREBLK                      __REG(0X10020620)
#define        WAKEUP_MASK_COREBLK                      __REG(0X10020628)
#define        HDMI_PHY_CONTROL                         __REG(0X10020700)
#define        USB_PHY_CONTROL                          __REG(0X10020704)
#define        HSIC_1_PHY_CONTROL                       __REG(0X10020708)
#define        HSIC_2_PHY_CONTROL                       __REG(0X1002070C)
#define        MIPI_PHY0_CONTROL                        __REG(0X10020710)
#define        MIPI_PHY1_CONTROL                        __REG(0X10020714)
#define        ADC_PHY_CONTROL                          __REG(0X10020718)
#define        BODY_BIAS_CON0                           __REG(0X10020780)
#define        BODY_BIAS_CON1                           __REG(0X10020784)
#define        BODY_BIAS_CON2                           __REG(0X10020788)
#define        BODY_BIAS_CON3                           __REG(0X1002078C)
#define        INFORM0                                  __REG(0X10020800)
#define        INFORM1                                  __REG(0X10020804)
#define        INFORM2                                  __REG(0X10020808)
#define        INFORM3                                  __REG(0X1002080C)
#define        INFORM4                                  __REG(0X10020810)
#define        INFORM5                                  __REG(0X10020814)
#define        INFORM6                                  __REG(0X10020818)
#define        INFORM7                                  __REG(0X1002081C)
#define        IROM_DATA_REG0                           __REG(0X10020980)
#define        IROM_DATA_REG1                           __REG(0X10020984)
#define        IROM_DATA_REG2                           __REG(0X10020988)
#define        IROM_DATA_REG3                           __REG(0X1002098C)
#define        PMU_DEBUG                                __REG(0X10020A00)
#define        ARM_CORE0_SYS_PWR_REG                    __REG(0X10021000)
#define        DIS_IRQ_ARM_CORE0_LOCAL_SYS_PWR_REG      __REG(0X10021004)
#define        DIS_IRQ_ARM_CORE0_CENTRAL_SYS_PWR_REG    __REG(0X10021008)
#define        ARM_CORE1_SYS_PWR_REG                    __REG(0X10021010)
#define        DIS_IRQ_ARM_CORE1_LOCAL_SYS_PWR_REG      __REG(0X10021014)
#define        DIS_IRQ_ARM_CORE1_CENTRAL_SYS_PWR_REG    __REG(0X10021018)
#define        ISP_ARM_SYS_PWR_REG                      __REG(0X10021050)
#define        DIS_IRQ_ISP_ARM_LOCAL_SYS_PWR_REG        __REG(0X10021054)
#define        DIS_IRQ_ISP_ARM_CENTRAL_SYS_PWR_REG      __REG(0X10021058)
#define        ARM_COMMON_SYS_PWR_REG                   __REG(0X10021080)
#define        ARM_L2_0_SYS_PWR_REG                     __REG(0X100210C0)
#define        ARM_L2_1_SYS_PWR_REG                     __REG(0X100210C4)
#define        CMU_ACLKSTOP_SYS_PWR_REG                 __REG(0X10021100)
#define        CMU_SCLKSTOP_SYS_PWR_REG                 __REG(0X10021104)
#define        CMU_RESET_SYS_PWR_REG                    __REG(0X1002110C)
#define        CMU_ACLKSTOP_COREBLK_SYS_PWR_REG         __REG(0X10021110)
#define        CMU_SCLKSTOP_COREBLK_SYS_PWR_REG         __REG(0X10021114)
#define        CMU_RESET_COREBLK_SYS_PWR_REG            __REG(0X1002111C)
#define        APLL_SYSCLK_SYS_PWR_REG                  __REG(0X10021120)
#define        MPLL_SYSCLK_SYS_PWR_REG                  __REG(0X10021124)
#define        VPLL_SYSCLK_SYS_PWR_REG                  __REG(0X10021128)
#define        EPLL_SYSCLK_SYS_PWR_REG                  __REG(0X1002112C)
#define        MPLLUSER_SYSCLK_SYS_PWR_REG              __REG(0X10021130)
#define        CMU_CLKSTOP_GPS_ALIVE_SYS_PWR_REG        __REG(0X10021138)
#define        CMU_RESET_GPS_ALIVE_SYS_PWR_REG          __REG(0X1002113C)
#define        CMU_CLKSTOP_CAM_SYS_PWR_REG              __REG(0X10021140)
#define        CMU_CLKSTOP_TV_SYS_PWR_REG               __REG(0X10021144)
#define        CMU_CLKSTOP_MFC_SYS_PWR_REG              __REG(0X10021148)
#define        CMU_CLKSTOP_G3D_SYS_PWR_REG              __REG(0X1002114C)
#define        CMU_CLKSTOP_LCD0_SYS_PWR_REG             __REG(0X10021150)
#define        CMU_CLKSTOP_ISP_SYS_PWR_REG              __REG(0X10021154)
#define        CMU_CLKSTOP_MAUDIO_SYS_PWR_REG           __REG(0X10021158)
#define        CMU_CLKSTOP_GPS_SYS_PWR_REG              __REG(0X1002115C)
#define        CMU_RESET_CAM_SYS_PWR_REG                __REG(0X10021160)
#define        CMU_RESET_TV_SYS_PWR_REG                 __REG(0X10021164)
#define        CMU_RESET_MFC_SYS_PWR_REG                __REG(0X10021168)
#define        CMU_RESET_G3D_SYS_PWR_REG                __REG(0X1002116C)
#define        CMU_RESET_LCD0_SYS_PWR_REG               __REG(0X10021170)
#define        CMU_RESET_ISP_SYS_PWR_REG                __REG(0X10021174)
#define        CMU_RESET_MAUDIO_SYS_PWR_REG             __REG(0X10021178)
#define        CMU_RESET_GPS_SYS_PWR_REG                __REG(0X1002117C)
#define        TOP_BUS_SYS_PWR_REG                      __REG(0X10021180)
#define        TOP_RETENTION_SYS_PWR_REG                __REG(0X10021184)
#define        TOP_PWR_SYS_PWR_REG                      __REG(0X10021188)
#define        TOP_BUS_COREBLK_SYS_PWR_REG              __REG(0X10021190)
#define        TOP_RETENTION_COREBLK_SYS_PWR_REG        __REG(0X10021194)
#define        TOP_PWR_COREBLK_SYS_PWR_REG              __REG(0X10021198)
#define        LOGIC_RESET_SYS_PWR_REG                  __REG(0X100211A0)
#define        OSCCLK_GATE_SYS_PWR_REG                  __REG(0X100211A4)
#define        LOGIC_RESET_COREBLK_SYS_PWR_REG          __REG(0X100211B0)
#define        OSCCLK_GATE_COREBLK_SYS_PWR_REG          __REG(0X100211B4)
#define        ONENANDXL_MEM_SYS_PWR_REG                __REG(0X100211C0)
#define        HSI_MEM_SYS_PWR_REG                      __REG(0X100211C4)
#define        G2D_ACP_MEM_SYS_PWR_REG                  __REG(0X100211C8)
#define        USBOTG_MEM_SYS_PWR_REG                   __REG(0X100211CC)
#define        SDMMC_MEM_SYS_PWR_REG                    __REG(0X100211D0)
#define        CSSYS_MEM_SYS_PWR_REG                    __REG(0X100211D4)
#define        SECSS_MEM_SYS_PWR_REG                    __REG(0X100211D8)
#define        ROTATOR_MEM_SYS_PWR_REG                  __REG(0X100211DC)
#define        PAD_RETENTION_DRAM_SYS_PWR_REG           __REG(0X10021200)
#define        PAD_RETENTION_MAUDIO_SYS_PWR_REG         __REG(0X10021204)
#define        PAD_RETENTION_GPIO_SYS_PWR_REG           __REG(0X10021220)
#define        PAD_RETENTION_UART_SYS_PWR_REG           __REG(0X10021224)
#define        PAD_RETENTION_MMCA_SYS_PWR_REG           __REG(0X10021228)
#define        PAD_RETENTION_MMCB_SYS_PWR_REG           __REG(0X1002122C)
#define        PAD_RETENTION_EBIA_SYS_PWR_REG           __REG(0X10021230)
#define        PAD_RETENTION_EBIB_SYS_PWR_REG           __REG(0X10021234)
#define        PAD_RETENTION_GPIO_COREBLK_SYS_PWR_REG   __REG(0X1002123C)
#define        PAD_ISOLATION_SYS_PWR_REG                __REG(0X10021240)
#define        PAD_ISOLATION_COREBLK_SYS_PWR_REG        __REG(0X10021250)
#define        PAD_ALV_SEL_SYS_PWR_REG                  __REG(0X10021260)
#define        XUSBXTI_SYS_PWR_REG                      __REG(0X10021280)
#define        XXTI_SYS_PWR_REG                         __REG(0X10021284)
#define        EXT_REGULATOR_SYS_PWR_REG                __REG(0X100212C0)
#define        GPIO_MODE_SYS_PWR_REG                    __REG(0X10021300)
#define        GPIO_MODE_COREBLK_SYS_PWR_REG            __REG(0X10021320)
#define        GPIO_MODE_MAUDIO_SYS_PWR_REG             __REG(0X10021340)
#define        TOP_ASB_RESET_SYS_PWR_REG                __REG(0X10021344)
#define        TOP_ASB_ISOLATION_SYS_PWR_REG            __REG(0X10021348)
#define        CAM_SYS_PWR_REG                          __REG(0X10021380)
#define        TV_SYS_PWR_REG                           __REG(0X10021384)
#define        MFC_SYS_PWR_REG                          __REG(0X10021388)
#define        G3D_SYS_PWR_REG                          __REG(0X1002138C)
#define        LCD0_SYS_PWR_REG                         __REG(0X10021390)
#define        ISP_SYS_PWR_REG                          __REG(0X10021394)
#define        MAUDIO_SYS_PWR_REG                       __REG(0X10021398)
#define        GPS_SYS_PWR_REG                          __REG(0X1002139C)
#define        GPS_ALIVE_SYS_PWR_REG                    __REG(0X100213A0)
#define        DRAM_FREQ_DOWN_SYS_PWR_REG               __REG(0X100213B0)
#define        DDRPHY_DLLOFF_SYS_PWR_REG                __REG(0X100213B4)
#define        CMU_SYSCLK_ISP_SYS_PWR_REG               __REG(0X100213B8)
#define        CMU_SYSCLK_GPS_SYS_PWR_REG               __REG(0X100213BC)
#define        LPDDR_PHY_DLL_LOCK_SYS_PWR_REG           __REG(0X100213C0)
#define        ARM_CORE0_CONFIGURATION                  __REG(0X10022000)
#define        ARM_CORE0_STATUS                         __REG(0X10022004)
#define        ARM_CORE0_OPTION                         __REG(0X10022008)
#define        ARM_CORE1_CONFIGURATION                  __REG(0X10022080)
#define        ARM_CORE1_STATUS                         __REG(0X10022084)
#define        ARM_CORE1_OPTION                         __REG(0X10022088)
#define        ISP_ARM_OPTION                           __REG(0X10022288)
#define        ISP_ARM_CONFIGURATION                    __REG(0X10022280)
#define        ISP_ARM_STATUS                           __REG(0X10022284)
#define        ARM_COMMON_OPTION                        __REG(0X10022408)
#define        ARM_L2_0_CONFIGURATION                   __REG(0X10022600)
#define        ARM_L2_0_STATUS                          __REG(0X10022604)
#define        ARM_L2_0_OPTION                          __REG(0X10021608)
#define        ARM_L2_1_CONFIGURATION                   __REG(0X10022620)
#define        ARM_L2_1_STATUS                          __REG(0X10022624)
#define        ARM_L2_1_OPTION                          __REG(0X10022628)
#define        DRAM_FREQ_DOWN_OPTION                    __REG(0X100229A8)
#define        DDRPHY_DLLOFF_OPTION                     __REG(0X10022DC8)
#define        ONENANDXL_MEM_OPTION                     __REG(0X10022E08)
#define        HSI_MEM_OPTION                           __REG(0X10022E28)
#define        G2D_ACP_MEM_OPTION                       __REG(0X10022E48)
#define        USBOTG_MEM_OPTION                        __REG(0X10022E68)
#define        SDMMC_MEM_OPTION                         __REG(0X10022E88)
#define        CSSYS_MEM_OPTION                         __REG(0X10022EA8)
#define        SECSS_MEM_OPTION                         __REG(0X10022EC8)
#define        ROTATOR_MEM_OPTION                       __REG(0X10022F48)
#define        PAD_RETENTION_MAUDIO_OPTION              __REG(0X10023028)
#define        PAD_RETENTION_GPIO_OPTION                __REG(0X10023108)
#define        PAD_RETENTION_UART_OPTION                __REG(0X10023128)
#define        PAD_RETENTION_MMCA_OPTION                __REG(0X10023148)
#define        PAD_RETENTION_MMCB_OPTION                __REG(0X10023168)
#define        PAD_RETENTION_EBIA_OPTION                __REG(0X10023188)
#define        PAD_RETENTION_EBIB_OPTION                __REG(0X100231A8)
#define        PAD_RETENTION_GPIO_COREBLK_OPTION        __REG(0X100231E8)
#define        PS_HOLD_CONTROL                          __REG(0X1002330C)
#define        XUSBXTI_CONFIGURATION                    __REG(0X10023400)
#define        XUSBXTI_STATUS                           __REG(0X10023404)
#define        XUSBXTI_DURATION                         __REG(0X1002341C)
#define        XXTI_CONFIGURATION                       __REG(0X10023420)
#define        XXTI_STATUS                              __REG(0X10023424)
#define        XXTI_DURATION                            __REG(0X1002343C)
#define        EXT_REGULATOR_DURATION                   __REG(0X1002361C)
#define        CAM_CONFIGURATION                        __REG(0X10023C00)
#define        CAM_STATUS                               __REG(0X10023C04)
#define        CAM_OPTION                               __REG(0X10023C08)
#define        TV_CONFIGURATION                         __REG(0X10023C20)
#define        TV_STATUS                                __REG(0X10023C24)
#define        TV_OPTION                                __REG(0X10023C28)
#define        MFC_CONFIGURATION                        __REG(0X10023C40)
#define        MFC_STATUS                               __REG(0X10023C44)
#define        MFC_OPTION                               __REG(0X10023C48)
#define        G3D_CONFIGURATION                        __REG(0X10023C60)
#define        G3D_STATUS                               __REG(0X10023C64)
#define        G3D_OPTION                               __REG(0X10023C68)
#define        LCD0_CONFIGURATION                       __REG(0X10023C80)
#define        LCD0_STATUS                              __REG(0X10023C84)
#define        LCD0_OPTION                              __REG(0X10023C88)
#define        ISP_CONFIGURATION                        __REG(0X10023CA0)
#define        ISP_STATUS                               __REG(0X10023CA4)
#define        ISP_OPTION                               __REG(0X10023CA8)
#define        ISP_DURATION0                            __REG(0X10023CB8)
#define        ISP_DURATION2                            __REG(0X10023CB8)
#define        MAUDIO_CONFIGURATION                     __REG(0X10023CC0)
#define        MAUDIO_STATUS                            __REG(0X10023CC4)
#define        MAUDIO_OPTION                            __REG(0X10023CC8)
#define        GPS_CONFIGURATION                        __REG(0X10023CE0)
#define        GPS_STATUS                               __REG(0X10023CE4)
#define        GPS_OPTION                               __REG(0X10023CE8)
#define        GPS_ALIVE_CONFIGURATION                  __REG(0X10023D00)
#define        GPS_ALIVE_STATUS                         __REG(0X10023D04)
#define        GPS_ALIVE_OPTION                         __REG(0X10023D08)


/*******************************************************************************
 *                          Interrupt Controller
 ******************************************************************************/
typedef struct {
    unsigned long ICCICR;           // CPU interface control register
    unsigned long ICCPMR;           // Interupt priority mask register
    unsigned long ICCBPR;           // Binary point register
    unsigned long ICCIAR;           // Interrupt acknowledge register
    unsigned long ICCEOIR;          // End of interrupt register
    unsigned long ICCRPR;           // Running priority register
    unsigned long ICCHPIR;          // Highest pending interrupt register
    unsigned long ICCABPR;          // Aliased binary point register
    unsigned long RSVD[35];
    unsigned long INTEG_EN_C;       // Integration test enable register
    unsigned long INTERRUPT_OUT;    // Interrupt output register
} cpu_t;

#define        CPU0           (*((volatile cpu_t *)0x10480000))
#define        CPU1           (*((volatile cpu_t *)0x10484000))
#define        CPU2           (*((volatile cpu_t *)0x10488000))
#define        CPU3           (*((volatile cpu_t *)0x1048C000))

#define        ICCIIDR        __REG(0x104800FC)
#define        ICDDCR         __REG(0X10490000)
#define        ICDICTR        __REG(0X10490004)
#define        ICDIIDR        __REG(0X10490008)

/* Interrupt security registers */
typedef struct {
    unsigned    long    ICDISR0_CPU0;
    unsigned    long    ICDISR1;            // SPI[31:0]
    unsigned    long    ICDISR2;            // SPI[63:32]
    unsigned    long    ICDISR3;            // SPI[95:64]
    unsigned    long    ICDISR4;            // SPI[127:96]
} icdisr_t;

#define        ICDISR         (*((volatile icdisr_t *)0x10490080))

/* Interrupt set-enable register */
typedef struct {
    unsigned    long    ICDISER0_CPU0;
    unsigned    long    ICDISER1;           // SPI[31:0]
    unsigned    long    ICDISER2;           // SPI[63:32]
    unsigned    long    ICDISER3;
    unsigned    long    ICDISER4;
} icdiser_t;

#define        ICDISER        (*((volatile icdiser_t *)0x10490100))

/* Interrupt clear-enable register */
typedef struct {
    unsigned    long    ICDICER0_CPU0;
    unsigned    long    ICDICER1;
    unsigned    long    ICDICER2;
    unsigned    long    ICDICER3;
    unsigned    long    ICDICER4;
} icdicer_t;

#define        ICDICER        (*((volatile icdicer_t *)0x10490180))

/* Interrupt pending-set register */
typedef struct {
    unsigned    long    ICDISPR0_CPU0;
    unsigned    long    ICDISPR1;             // SPI[31:0]
    unsigned    long    ICDISPR2;             // SPI[63:32]
    unsigned    long    ICDISPR3;
    unsigned    long    ICDISPR4;
} icdispr_t;

#define        ICDISPR        (*((volatile icdispr_t *)0x10490200))

/* Interrupt pending-clear register */
typedef struct {
    unsigned    long    ICDICPR0_CPU0;
    unsigned    long    ICDICPR1;
    unsigned    long    ICDICPR2;
    unsigned    long    ICDICPR3;
    unsigned    long    ICDICPR4;
} icdicpr_t;

#define        ICDICPR        (*((volatile icdicpr_t *)0x10490280))

/* Active bit register */
typedef struct {
    unsigned    long    ICDABR0_CPU0;
    unsigned    long    ICDABR1;
    unsigned    long    ICDABR2;
    unsigned    long    ICDABR3;
    unsigned    long    ICDABR4;
} icdabr_t;

#define        ICDABR        (*((volatile icdabr_t *)0x10490300))

/* Priority level register */
typedef struct {
    unsigned    long    ICDIPR0_CPU0;
    unsigned    long    ICDIPR1_CPU0;
    unsigned    long    ICDIPR2_CPU0;
    unsigned    long    ICDIPR3_CPU0;
    unsigned    long    ICDIPR4_CPU0;
    unsigned    long    ICDIPR5_CPU0;
    unsigned    long    ICDIPR6_CPU0;
    unsigned    long    ICDIPR7_CPU0;
    unsigned    long    ICDIPR8;
    unsigned    long    ICDIPR9;
    unsigned    long    ICDIPR10;
    unsigned    long    ICDIPR11;
    unsigned    long    ICDIPR12;
    unsigned    long    ICDIPR13;
    unsigned    long    ICDIPR14;
    unsigned    long    ICDIPR15;
    unsigned    long    ICDIPR16;
    unsigned    long    ICDIPR17;
    unsigned    long    ICDIPR18;
    unsigned    long    ICDIPR19;
    unsigned    long    ICDIPR20;
    unsigned    long    ICDIPR21;
    unsigned    long    ICDIPR22;
    unsigned    long    ICDIPR23;
    unsigned    long    ICDIPR24;
    unsigned    long    ICDIPR25;
    unsigned    long    ICDIPR26;
    unsigned    long    ICDIPR27;
    unsigned    long    ICDIPR28;
    unsigned    long    ICDIPR29;
    unsigned    long    ICDIPR30;
    unsigned    long    ICDIPR31;
    unsigned    long    ICDIPR32;
    unsigned    long    ICDIPR33;
    unsigned    long    ICDIPR34;
    unsigned    long    ICDIPR35;
    unsigned    long    ICDIPR36;
    unsigned    long    ICDIPR37;
    unsigned    long    ICDIPR38;
    unsigned    long    ICDIPR39;
} icdipr_t;

#define    ICDIPR        (*((volatile icdipr_t *)0x10490400))

/* Processor targets register */
typedef struct {
    unsigned    long    ICDIPTR0_CPU0;
    unsigned    long    ICDIPTR1_CPU0;
    unsigned    long    ICDIPTR2_CPU0;
    unsigned    long    ICDIPTR3_CPU0;
    unsigned    long    ICDIPTR4_CPU0;
    unsigned    long    ICDIPTR5_CPU0;
    unsigned    long    ICDIPTR6_CPU0;
    unsigned    long    ICDIPTR7_CPU0;
    unsigned    long    ICDIPTR8;
    unsigned    long    ICDIPTR9;
    unsigned    long    ICDIPTR10;
    unsigned    long    ICDIPTR11;
    unsigned    long    ICDIPTR12;
    unsigned    long    ICDIPTR13;
    unsigned    long    ICDIPTR14;
    unsigned    long    ICDIPTR15;
    unsigned    long    ICDIPTR16;
    unsigned    long    ICDIPTR17;
    unsigned    long    ICDIPTR18;
    unsigned    long    ICDIPTR19;
    unsigned    long    ICDIPTR20;
    unsigned    long    ICDIPTR21;
    unsigned    long    ICDIPTR22;
    unsigned    long    ICDIPTR23;
    unsigned    long    ICDIPTR24;
    unsigned    long    ICDIPTR25;
    unsigned    long    ICDIPTR26;
    unsigned    long    ICDIPTR27;
    unsigned    long    ICDIPTR28;
    unsigned    long    ICDIPTR29;
    unsigned    long    ICDIPTR30;
    unsigned    long    ICDIPTR31;
    unsigned    long    ICDIPTR32;
    unsigned    long    ICDIPTR33;
    unsigned    long    ICDIPTR34;
    unsigned    long    ICDIPTR35;
    unsigned    long    ICDIPTR36;
    unsigned    long    ICDIPTR37;
    unsigned    long    ICDIPTR38;
    unsigned    long    ICDIPTR39;
} icdiptr_t;

#define        ICDIPTR        (*((volatile icdiptr_t *)0x10490800))

/* Interrupt configuration register */
typedef struct {
    unsigned    long    ICDICFR0_CPU0;
    unsigned    long    ICDICFR1_CPU0;
    unsigned    long    ICDICFR2;
    unsigned    long    ICDICFR3;
    unsigned    long    ICDICFR4;
    unsigned    long    ICDICFR5;
    unsigned    long    ICDICFR6;
    unsigned    long    ICDICFR7;
    unsigned    long    ICDICFR8;
    unsigned    long    ICDICFR9;
} icdicfr_t;

#define        ICDICFR        (*((volatile icdicfr_t *)0X10490C00))

/* SPI status register */
typedef struct {
    unsigned    long    STATUS0;
    unsigned    long    STATUS1;
    unsigned    long    STATUS2;
    unsigned    long    STATUS3;
} icdspi_status_t;

#define        ICDSPI_STATUS        (*((volatile icdspi_status_t *)0X10490D04))

/* Software generated interrupt register */
#define        ICDSGIR              __REG(0X10490F00)

/* CPU1 registers */
typedef struct {
    unsigned    long    ICDIPR0;
    unsigned    long    ICDIPR1;
    unsigned    long    ICDIPR2;
    unsigned    long    ICDIPR3;
    unsigned    long    ICDIPR4;
    unsigned    long    ICDIPR5;
    unsigned    long    ICDIPR6;
    unsigned    long    ICDIPR7;
} icdipr_cpun_t;

typedef struct {
    unsigned    long    ICDIPTR0;
    unsigned    long    ICDIPTR1;
    unsigned    long    ICDIPTR2;
    unsigned    long    ICDIPTR3;
    unsigned    long    ICDIPTR4;
    unsigned    long    ICDIPTR5;
    unsigned    long    ICDIPTR6;
    unsigned    long    ICDIPTR7;
} icdiptr_cpun_t;

#define        ICDISR0_CPU1           __REG(0X10494080)
#define        ICDISER0_CPU1          __REG(0X10494100)
#define        ICDICER0_CPU1          __REG(0X10494180)
#define        ICDISPR0_CPU1          __REG(0X10494200)
#define        ICDICPR0_CPU1          __REG(0X10494280)
#define        ICDABR0_CPU1           __REG(0X10494300)
#define        ICDIPR_CPU1            (*((volatile icdipr_cpun_t *)0X10494400))
#define        ICDIPTR_CPU1           (*((volatile icdiptr_cpun_t *))0X10494800)

/* CPU2 registers */
#define        ICDISR0_CPU2           __REG(0X10498080)
#define        ICDISER0_CPU2          __REG(0X10498100)
#define        ICDICER0_CPU2          __REG(0X10498180)
#define        ICDISPR0_CPU2          __REG(0X10498200)
#define        ICDICPR0_CPU2          __REG(0X10498280)
#define        ICDABR0_CPU2           __REG(0X10498300)
#define        ICDIPR_CPU2            (*((volatile icdipr_cpun_t *)0X10498400))
#define        ICDIPTR_CPU2           (*((volatile icdiptr_cpun_t *))0X10498800)

/* CPU3 registers */
#define        ICDISR0_CPU3           __REG(0X1049C080)
#define        ICDISER0_CPU3          __REG(0X1049C100)
#define        ICDICER0_CPU3          __REG(0X1049C180)
#define        ICDISPR0_CPU3          __REG(0X1049C200)
#define        ICDICPR0_CPU3          __REG(0X1049C280)
#define        ICDABR0_CPU3           __REG(0X1049C300)
#define        ICDIPR_CPU3            (*((volatile icdipr_cpun_t *)0X1049C400))
#define        ICDIPTR_CPU3           (*((volatile icdiptr_cpun_t *))0X1049C800)

/* PPI status register */
#define        PPI_STATUS_CPU0        __REG(0X10490D00)
#define        PPI_STATUS_CPU1        __REG(0X10494D00)
#define        PPI_STATUS_CPU2        __REG(0X10498D00)
#define        PPI_STATUS_CPU3        __REG(0X1049CD00)


/*******************************************************************************
 *                          Interrupt Combiner
 ******************************************************************************/
typedef struct {
    unsigned    long    IESR0;
    unsigned    long    IECR0;
    unsigned    long    ISTR0;
    unsigned    long    IMSR0;
    unsigned    long    IESR1;
    unsigned    long    IECR1;
    unsigned    long    ISTR1;
    unsigned    long    IMSR1;
    unsigned    long    IESR2;
    unsigned    long    IECR2;
    unsigned    long    ISTR2;
    unsigned    long    IMSR2;
    unsigned    long    IESR3;
    unsigned    long    IECR3;
    unsigned    long    ISTR3;
    unsigned    long    IMSR3;
    unsigned    long    IESR4;
    unsigned    long    IECR4;
    unsigned    long    ISTR4;
    unsigned    long    IMSR4;
} interrupt_combiner_t;

#define    INTERRUPT_COMBINER    (*((volatile interrupt_combiner_t *)0X10440000))
#define    CIPSR0                __REG(0X10440100)


/*******************************************************************************
 *                                    UART
 ******************************************************************************/
typedef struct {
    unsigned    long    ULCON;
    unsigned    long    UCON;
    unsigned    long    UFCON;
    unsigned    long    UMCON;
    unsigned    long    UTRSTAT;
    unsigned    long    UERSTAT;
    unsigned    long    UFSTAT;
    unsigned    long    UMSTAT;
    unsigned    long    UTXH;
    unsigned    long    URXH;
    unsigned    long    UBRDIV;
    unsigned    long    UFRACVAL;
    unsigned    long    UINTP;
    unsigned    long    UINTSP;
    unsigned    long    UINTM;
} uart_t;

#define        UART0        (*((volatile uart_t *)0X13800000))
#define        UART1        (*((volatile uart_t *)0X13810000))
#define        UART2        (*((volatile uart_t *)0X13820000))
#define        UART3        (*((volatile uart_t *)0X13830000))
#define        UART4        (*((volatile uart_t *)0X13840000))


/*******************************************************************************
 *                                    I2C
 ******************************************************************************/
typedef struct {
    unsigned    long    CON;
    unsigned    long    STAT;
    unsigned    long    ADD;    // address register
    unsigned    long    DS;     // transmit/receive data shift register
    unsigned    long    LC;     // multi-master line control register
} i2c_t;

#define        I2C0        (*((volatile i2c_t *)0X13860000))
#define        I2C1        (*((volatile i2c_t *)0X13870000))
#define        I2C2        (*((volatile i2c_t *)0X13880000))
#define        I2C3        (*((volatile i2c_t *)0X13890000))
#define        I2C4        (*((volatile i2c_t *)0X138A0000))
#define        I2C5        (*((volatile i2c_t *)0X138B0000))
#define        I2C6        (*((volatile i2c_t *)0X138C0000))
#define        I2C7        (*((volatile i2c_t *)0X138D0000))
#define        I2C8        (*((volatile i2c_t *)0X138E0000))

/*******************************************************************************
 *                              Audio Subsystem
 ******************************************************************************/
#define        ASS_CLK_SRC        __REG(0X03810000)
#define        ASS_CLK_DIV        __REG(0X03810004)
#define        ASS_CLK_GATE       __REG(0X03810008)

/*******************************************************************************
 *                          IIS Multi Audio Interface
 ******************************************************************************/
typedef struct {
    unsigned    long    CON;
    unsigned    long    MOD;
    unsigned    long    FIC;
    unsigned    long    PSR;
    unsigned    long    TXD;
    unsigned    long    RXD;
    unsigned    long    FICS;
    unsigned    long    TXDS;
    unsigned    long    AHB;
    unsigned    long    STR0;
    unsigned    long    SIZE;
    unsigned    long    TRNCNT;
    unsigned    long    LVL0ADDR;
    unsigned    long    LVL1ADDR;
    unsigned    long    LVL2ADDR;
    unsigned    long    LVL3ADDR;
    unsigned    long    STR1;
} i2s0_t;

#define        I2S0        (*((volatile i2s0_t *)0X03830000))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* AI_EXYNOS_4412_H_ */
