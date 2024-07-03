/*
 * Bsp_gpio.h
 *
 *  Created on: 2023年7月21日
 *      Author: Brando
 */

#ifndef BSP_BSP_GPIO_H_
#define BSP_BSP_GPIO_H_

#include "driverlib.h"
#include "Sys.h"


void Key_init(void);
uint8_t Key_Scanf(void);
void Beep_solo(uint8_t n);

#endif /* BSP_BSP_GPIO_H_ */
