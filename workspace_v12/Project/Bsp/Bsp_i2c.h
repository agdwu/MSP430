#ifndef __BSP_I2C_H__
#define __BSP_I2C_H__

#include "driverlib.h"
#include "Sys.h"

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

#define SDA_PIN GPIO_PIN1
#define SDA_PORT GPIO_PORT_P4

#define SCL_PORT GPIO_PORT_P4
#define SCL_PIN GPIO_PIN2


#define IIC_SDA_High()  GPIO_setOutputHighOnPin(SDA_PORT,SDA_PIN)
#define IIC_SDA_Low()   GPIO_setOutputLowOnPin(SDA_PORT,SDA_PIN)

#define IIC_SCL_High()  GPIO_setOutputHighOnPin(SCL_PORT,SCL_PIN)
#define IIC_SCL_Low()   GPIO_setOutputLowOnPin(SCL_PORT,SCL_PIN)

#define SDA_OUT()       GPIO_setAsOutputPin(SDA_PORT,SDA_PIN)
#define SDA_IN()        GPIO_setAsInputPin(SDA_PORT,SDA_PIN)

#define READ_SDA    GPIO_getInputPinValue(SDA_PORT,SDA_PIN)  //输入SDA


//IIC有操作函�?
void IIC_Init(void);                //初始化IIC的IO�?
void IIC_Start(void);               //发�?�IIC�?始信�?
void IIC_Stop(void);                //发�?�IIC停止信号
void IIC_Send_Byte(u8 txd);         //IIC发�?�一个字�?
uint8_t IIC_Read_Byte(unsigned char ack);//IIC读取�?个字�?
uint8_t IIC_Wait_Ack_R(void);               //IIC等待ACK信号
void IIC_Wait_Ack_NO_R(void);
void IIC_Ack(void);                 //IIC发�?�ACK信号
void IIC_NAck(void);                //IIC不发送ACK信号


int32_t I2cRead(uint8_t ucAddr, uint8_t ucReg, uint8_t *p_ucVal, uint32_t uiLen);
int32_t I2cWrite(uint8_t ucAddr, uint8_t ucReg, uint8_t *p_ucVal, uint32_t uiLen);


#endif
