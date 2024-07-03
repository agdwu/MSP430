/*
 * gray.h
 *
 *  Created on: 2023年7月19日
 *      Author: 1
 */

#ifndef GRAY_H_
#define GRAY_H_

#include "driverlib.h"

#define     L4        GPIO_getInputPinValue(GPIO_PORT_P7, GPIO_PIN0)
#define     L3        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN4)
#define     L2        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN6)
#define     L1        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN3)
#define     R1        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN2)
#define     R2        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN1)
#define     R3        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN0)
#define     R4        GPIO_getInputPinValue(GPIO_PORT_P6, GPIO_PIN5)



void Gray_Init(void);
int8_t Get_GrayNumber();

#endif /* GRAY_H_ */
