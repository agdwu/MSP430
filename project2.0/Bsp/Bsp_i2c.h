/*
 * Bsp_i2c.h
 *
 *  Created on: 2023年7月12日
 *      Author: Brando
 */

#ifndef BSP_BSP_I2C_H_
#define BSP_BSP_I2C_H_

#include <driverlib.h>
#include "Sys.h"



#define HIGH     1
#define LOW      0
#define EIGHT    8
#define ACK      0
#define NACK     1
//库函数开发
#define IIC_SDA_PORT                          GPIO_PORT_P4
#define IIC_SCL_PORT                          GPIO_PORT_P4
#define IIC_SDA_PIN                           GPIO_PIN1
#define IIC_SCL_PIN                           GPIO_PIN2
#define IIC_SDA_READDATA                      GPIO_getInputPinValue(IIC_SDA_PORT,IIC_SDA_PIN)

void IIC_Init(void);

void IIC_NAck(void);
void IIC_Ack(void);
uint8_t IIC_Wait_Ack(void);

uint8_t IIC_ReadByte(unsigned char ack);
void IIC_SendByte(uint8_t Byte);
void IIC_Start(void);
void IIC_Stop(void);

void IIC_Write_SDA(uint8_t x);
void IIC_Write_SCL(uint8_t x);

#endif /* BSP_BSP_I2C_H_ */
