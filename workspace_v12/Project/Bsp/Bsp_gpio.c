/*
 * Bsp_gpio.c
 *
 *  Created on: 2023年7月21日
 *      Author: Brando
 */
#include "Bsp_gpio.h"

void Key_init(void)
{
    GPIO_setAsInputPin(GPIO_PORT_P3,GPIO_PIN7);
    GPIO_setAsInputPin(GPIO_PORT_P8,GPIO_PIN1+GPIO_PIN2);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3,GPIO_PIN7);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P8,GPIO_PIN1+GPIO_PIN2);
}

/***************************
 * Function: 按键扫描
 * Input: 无
 * Output:按键扫描值
 * data：2023.7  陈子松
 **************************/
uint8_t Key_Scanf(void)
{
    static uint8_t KeyNumber;

    if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN1)==GPIO_INPUT_PIN_LOW){
       delay_ms(20);
       while(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN1)==GPIO_INPUT_PIN_LOW);
       KeyNumber=1;
    }
    if(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN2)==GPIO_INPUT_PIN_LOW){
        delay_ms(20);
        while(GPIO_getInputPinValue(GPIO_PORT_P8,GPIO_PIN2)==GPIO_INPUT_PIN_LOW);
            KeyNumber=2;
    }
    if(GPIO_getInputPinValue(GPIO_PORT_P3,GPIO_PIN7)==GPIO_INPUT_PIN_LOW){
        delay_ms(20);
        while(GPIO_getInputPinValue(GPIO_PORT_P3,GPIO_PIN7)==GPIO_INPUT_PIN_LOW);
        KeyNumber=3;
    }
    return KeyNumber;
}

/***************************
 * Function: 蜂鸣器鸣叫
 * Input: 0：不响 1：响
 * Output:无
 * data：2023.7  陈子松
 **************************/
void Beep_solo(uint8_t n)
{
     GPIO_setAsOutputPin(GPIO_PORT_P1,GPIO_PIN6);
     if(n==1){
         GPIO_setOutputHighOnPin(GPIO_PORT_P1,GPIO_PIN6);
     }
     else if(n==0){
        GPIO_setOutputLowOnPin(GPIO_PORT_P1,GPIO_PIN6);
     }
}


