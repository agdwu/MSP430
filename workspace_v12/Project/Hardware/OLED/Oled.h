/*
 * Oled.h
 *
 *  Created on: 2023年7月12日
 *      Author: Brando
 */

#ifndef HARDWARE_OLED_H_
#define HARDWARE_OLED_H_


#include    "driverlib.h"//基于库函数开发
#include    "Sys.h"


#define HIGH     1
#define LOW      0

//库函数开发
#define IIC_SDA_PORT                          GPIO_PORT_P4
#define IIC_SCL_PORT                          GPIO_PORT_P4
#define IIC_SDA_PIN                           GPIO_PIN1
#define IIC_SCL_PIN                           GPIO_PIN2
#define IIC_SDA_READDATA                      GPIO_getInputPinValue(IIC_SDA_PORT,IIC_SDA_PIN)


void OLED_IIC_Init(void);
void OLED_IIC_SendByte(uint8_t Byte);
void OLED_IIC_Start(void);
void OLED_IIC_Stop(void);
void IIC_Write_SDA(uint8_t x);
void IIC_Write_SCL(uint8_t x);


void OlED_WriteData(uint8_t Data);
void OLED_Set_Cursor(uint8_t Y, uint8_t X);
void OLED_WriteCommand(uint8_t Command);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char* String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint64_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
uint32_t OLED_Pow(uint32_t X, uint32_t Y);
void OLED_Init(void);

#endif /* HARDWARE_OLED_H_ */
