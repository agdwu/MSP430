/*
 * Sys.h
 *
 *  Created on: 2023年7月9日
 *      Author: Brando
 */

#ifndef SYSTEM_SYS_H_
#define SYSTEM_SYS_H_

#include <msp430.h>
#include  "driverlib.h"//基于库函数开发

#define MCLK_IN_HZ      25000000

#define delay_us(x)     __delay_cycles((MCLK_IN_HZ/1000000*(x)))
#define delay_ms(x)     __delay_cycles((MCLK_IN_HZ/1000*(x)))

void System_Confing(void);

#endif /* SYSTEM_SYS_H_ */
