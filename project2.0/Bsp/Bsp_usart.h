/*
 * Bsp_usart.h
 *
 *  Created on: 2023年7月11日
 *      Author: Brando
 */

#ifndef BSP_BSP_USART_H_
#define BSP_BSP_USART_H_

#include  "driverlib.h"//基于库函数开发

bool Usart_Init(uint16_t baseAddress);
void USART_PrintDatas(uint16_t baseAddress,uint8_t* data,uint8_t length);
void Vofa_PrintDatas(uint8_t* data,uint8_t length);

#endif /* BSP_BSP_USART_H_ */
