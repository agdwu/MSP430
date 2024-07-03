/*
 * gray.c
 *
 *  Created on: 2023年7月19日
 *      Author: 1
 */
/*                           十二路灰度传感器标注（只使用了中间八路）
 *
 *             |空闲| |空闲| |P7.0| |P6.4| |P6.6| |P6.3| |P6.2| |P6.1| |P6.0| |P6.5| |空闲| |空闲|
 *
 *                                              面向车头
 */

#include"gray.h"



void Gray_Init(void)
{
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN0);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN1);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN2);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN3);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN4);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN5);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P6, GPIO_PIN6);
    GPIO_setAsInputPinWithPullDownResistor(GPIO_PORT_P7, GPIO_PIN0);
}


int8_t Get_GrayNumber()
{
    static int8_t GrayNumber;
    if((L2==1)&&(L1==1)&&(R2==1)&&(L4==0)){
        GrayNumber=10;
    }
//    if((L2==1||L3==1||L4==1)&&(R4==1)){
//        GrayNumber=11;
//    }
    if((L4==1)&&(L3==0)&&(L2==0)&&(L1==0)&&(R1==0)&&(R2==0)&&(R3==0)&&(R4==0)){
        GrayNumber=-3;
    }
    else if((L4==0)&&(L3==1)&&(L2==0)&&(L1==0)&&(R1==0)&&(R2==0)&&(R3==0)&&(R4==0)){
        GrayNumber=-2;
    }
    else if((L4==0)&&(L3==0)&&(L2==1)&&(L1==0)&&(R1==0)&&(R2==0)&&(R3==0)&&(R4==0)){
        GrayNumber=-1;
    }
    else if((L4==0)&&(L3==0)&&(L2==0)&&(L1==1)&&(R1==0)&&(R2==0)&&(R3==0)&&(R4==0)){
        GrayNumber=0;
    }
    else if((L4==0)&&(L3==0)&&(L2==0)&&(L1==0)&&(R1==1)&&(R2==0)&&(R3==0)&&(R4==0)){
        GrayNumber=0;
    }
    else if((L4==0)&&(L3==0)&&(L2==0)&&(L1==0)&&(R1==0)&&(R2==1)&&(R3==0)&&(R4==0)){
        GrayNumber=1;
    }
    else if((L4==0)&&(L3==0)&&(L2==0)&&(L1==0)&&(R1==0)&&(R2==0)&&(R3==1)&&(R4==0)){
        GrayNumber=2;
    }
    else if((L4==0)&&(L3==0)&&(L2==0)&&(L1==0)&&(R1==0)&&(R2==0)&&(R3==0)&&(R4==1)){
        GrayNumber=3;
    }
    return GrayNumber;
}



















