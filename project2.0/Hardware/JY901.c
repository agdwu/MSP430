/*
 * JY901.c
 *
 *  Created on: 2023年7月16日
 *      Author: Brando
 */

#include    "JY901.h"

int32_t IICreadBytes(uint8_t dev, uint8_t reg, uint8_t *data, uint32_t length)
{
    uint32_t count = 0;

    IIC_Start();
    IIC_SendByte(dev);
    if(IIC_Wait_Ack() == 1)return 0;
    IIC_SendByte(reg);
    if(IIC_Wait_Ack() == 1)return 0;
    IIC_Start();
    IIC_SendByte(dev+1);
    if(IIC_Wait_Ack() == 1)return 0;

    for(count=0; count<length; count++)
    {
        if(count!=length-1)data[count]=IIC_ReadByte(1);
        else  data[count]=IIC_ReadByte(0);
    }
    IIC_Stop();
    return 1;
}


int32_t IICwriteBytes(uint8_t dev, uint8_t reg, uint8_t* data, uint32_t length)
{
    uint32_t count = 0;
    IIC_Start();
    IIC_SendByte(dev);
    if(IIC_Wait_Ack() == 1)return 0;
    IIC_SendByte(reg);
    if(IIC_Wait_Ack() == 1)return 0;
    for(count=0; count<length; count++)
    {
        IIC_SendByte(data[count]);
        if(IIC_Wait_Ack() == 1)return 0;
    }
    IIC_Stop();

    return 1;
}




