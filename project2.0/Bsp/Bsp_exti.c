/*
 * Bsp_exti.c
 *
 *  Created on: 2023年7月9日
 *      Author: Brando
 */
#include    "Bsp_exti.h"



/***************************
 * Function:编码器AB相中断初始化
 * Input:无
 * Output:无
 * data：2023.7  陈子松
 **************************/
void   Bsp_Exti_init(void)
{
    GPIO_setAsInputPin (GPIO_PORT_P2,GPIO_PIN2+GPIO_PIN6);
    //GPIO带电上拉电阻输入使能
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2,GPIO_PIN0);
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2,GPIO_PIN3);
    //GPIO中断使能
    GPIO_enableInterrupt(GPIO_PORT_P2,GPIO_PIN0);
    GPIO_enableInterrupt(GPIO_PORT_P2,GPIO_PIN3);
    //上升沿触发
    GPIO_selectInterruptEdge(GPIO_PORT_P2,GPIO_PIN0,GPIO_LOW_TO_HIGH_TRANSITION);
    GPIO_selectInterruptEdge(GPIO_PORT_P2,GPIO_PIN3,GPIO_LOW_TO_HIGH_TRANSITION);
    //清除中断标志位 IFG cleared
    GPIO_clearInterrupt(GPIO_PORT_P2,GPIO_PIN0);
    GPIO_clearInterrupt(GPIO_PORT_P2,GPIO_PIN3);
    //启用可屏蔽中断(具有中断功能的片上外设产生)
    __bis_SR_register(GIE);
}
















