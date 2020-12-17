/*
 * =============================================================================
 *
 *       Filename:  aii2c.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/17/2020 10:18:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  takeno (takeno2020), takeno2020@163.com
 *   Organization:  
 *
 * =============================================================================
 */
#ifndef AI_I2C_H_
#define AI_I2C_H_
#include "aitypes.h"

/*******************************************************************************
 *    Function: aii2c_init
 * Description: wm8960使用的i2c初始化
 *              I2C_4_SCL/GPB_1
 *              I2C_4_SDA/GPB_0
 *       Input: void
 *      Output: None
 *      Return: void
 *      Others:
 ******************************************************************************/
void aii2c_init(void);

/*******************************************************************************
 *    Function: aii2c_write
 * Description: I2C向寄存器地址写数据.
 *       Input:  reg - wm8960芯片内部寄存器地址;
 *               val - 要写入的数据.
 *      Output: None
 *      Return: void
 *      Others:
 ******************************************************************************/
void aii2c_write(u8 reg, u16 val);

/*******************************************************************************
 *    Function: aii2c_read
 * Description: I2C从wm8960特定地址读取数据
 *       Input: reg - wm8960芯片内部寄存器地址.
 *      Output: None
 *      Return: u16 - 寄存器值
 *      Others:
 ******************************************************************************/
u16 aii2c_read(u8 reg);

#endif /* AI_I2C_H_ */
