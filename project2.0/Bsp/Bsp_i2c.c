/*
 * Bsp_i2c.c
 *
 *  Created on: 2023年7月12日
 *      Author: Brando
 */

#include"Bsp_i2c.h"
//写模式
void IIC_Write(void)
{
    GPIO_setAsOutputPin(IIC_SDA_PORT, IIC_SDA_PIN);
}
//读模式
void IIC_Read(void)
{
    GPIO_setAsInputPin(IIC_SDA_PORT, IIC_SDA_PIN);
    GPIO_setAsInputPinWithPullUpResistor(IIC_SDA_PORT, IIC_SDA_PIN);

}

//IIC数据线写字节
void IIC_Write_SDA(uint8_t x)
{
    if (x != LOW)
    {
        GPIO_setOutputHighOnPin(IIC_SDA_PORT, IIC_SDA_PIN);
    }
    else
    {
        GPIO_setOutputLowOnPin(IIC_SDA_PORT, IIC_SDA_PIN);
    }

}
//IIC时钟线电平的高低电平交互
void IIC_Write_SCL(uint8_t x)
{
    if (x != LOW)
    {
        GPIO_setOutputHighOnPin(IIC_SCL_PORT, IIC_SCL_PIN);
    }
    else
    {
        GPIO_setOutputLowOnPin(IIC_SCL_PORT, IIC_SCL_PIN);
    }

}

//IIC初始化
void IIC_Init(void)
{
    GPIO_setAsOutputPin(IIC_SCL_PORT|IIC_SDA_PORT, IIC_SDA_PIN | IIC_SCL_PIN);
    GPIO_setOutputHighOnPin(IIC_SCL_PORT|IIC_SDA_PORT, IIC_SDA_PIN | IIC_SCL_PIN);
}
//IIC开始信号
void IIC_Start(void)
{
    IIC_Write_SCL(HIGH);
    IIC_Write_SDA(HIGH);
    IIC_Write_SDA(LOW);
    IIC_Write_SCL(LOW);
}
//IIC 停止信号
void IIC_Stop(void)
{
    IIC_Write_SCL(HIGH);
    IIC_Write_SDA(LOW);
    IIC_Write_SDA(HIGH);
}
//主机应答
void IIC_Ack(void)
{
    IIC_Write();
    IIC_Write_SDA(LOW);
    IIC_Write_SCL(HIGH);
    IIC_Write_SCL(LOW);
}
//主机非应答
void IIC_NAck(void)
{
    IIC_Write();
    IIC_Write_SDA(HIGH);
    IIC_Write_SCL(HIGH);
    IIC_Write_SCL(LOW);
}
//等待从机应答
uint8_t Wait_Ack(void)
{
    uint8_t ucErrTime=0;
    IIC_Read();
    IIC_Write_SDA(HIGH);
    delay_ms(5);
    while(IIC_SDA_READDATA)
    {
        ucErrTime++;
        if(ucErrTime>50)
        {
            IIC_Stop();
            return 1;
        }
        delay_ms(5);
    }
    IIC_Write_SCL(HIGH);
    delay_ms(5);
    IIC_Write_SCL(HIGH);
    return 0;
}
//发送字节
void IIC_SendByte(uint8_t Byte)
{
    uint8_t i;
    IIC_Write();
    IIC_Write_SCL(LOW);
    for (i=0;i < 8;i++)
    {
        IIC_Write_SDA(Byte&(0x80>>i));
        IIC_Write_SCL(HIGH);
        IIC_Write_SCL(LOW);
    }
    delay_us(5);
    IIC_Write_SCL(HIGH);
    IIC_Write_SCL(LOW);
}

uint8_t IIC_ReadByte(unsigned char ack)
{
    uint8_t i,Receive;
    IIC_Read();
//    IIC_Write_SCL(LOW);
    for (i = 0; i < 8; i++)
    {
        IIC_Write_SCL(LOW);
        delay_us(5);
        IIC_Write_SCL(HIGH);
        Receive<<=1;
        if(IIC_SDA_READDATA)Receive++;
        delay_us(5);
    }
    if(ack){
        IIC_Ack();
    }else{
        IIC_NAck();
    }
    return Receive;
}



