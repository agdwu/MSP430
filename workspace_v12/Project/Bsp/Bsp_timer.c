/*
 * Bsp_timer.c
 *
 *  Created on: 2023年7月10日
 *      Author: Brando
 */
#include "Bsp_timer.h"

/***************************
 * Function: 定时器A PWM输出初始化
 * Input: 无
 * Output:无
 * data：2023.7  陈子松
 **************************/
void TimerA_Pwm_Init(void)
{
    Timer_A_outputPWMParam  PWM_param={0};
    //P1.2、P1.3复用输出
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P1, GPIO_PIN2+GPIO_PIN3);

    PWM_param.clockSource = TIMER_A_CLOCKSOURCE_SMCLK;//时钟源选为SMCLK = 25MHz
    PWM_param.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;    //分频系数
    PWM_param.timerPeriod = 1000 - 1; //装载值
    PWM_param.compareOutputMode = TIMER_A_OUTPUTMODE_RESET_SET;
    PWM_param.dutyCycle = 0; //初始比较值
    PWM_param.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_1;   //PWM通道1
    Timer_A_outputPWM(TIMER_A0_BASE, &PWM_param);
    PWM_param.compareRegister = TIMER_A_CAPTURECOMPARE_REGISTER_2;   //PWM通道2
    Timer_A_outputPWM(TIMER_A0_BASE, &PWM_param);
}


/***************************
 * Function: 定时器B中断初始化
 * Input: 无
 * Output:无
 * data：2023.7  陈子松
 **************************/
void TimerB_Interrupt_Init(void)
{
    Timer_B_initUpModeParam InitParam = {0};//向上计数模式结构体
    InitParam.clockSource=TIMER_B_CLOCKSOURCE_SMCLK;//SMCLK 25HMz
    //霍尔计数
    InitParam.clockSourceDivider=TIMER_B_CLOCKSOURCE_DIVIDER_20;//20倍分配
    InitParam.timerPeriod=62500-1;//25MHz/20/62500=10hz
    //超声波计数
//    InitParam.clockSourceDivider=TIMER_B_CLOCKSOURCE_DIVIDER_1;
//    InitParam.timerPeriod=250-1;
    InitParam.timerInterruptEnable_TBIE=TIMER_B_TBIE_INTERRUPT_DISABLE;
    InitParam.captureCompareInterruptEnable_CCR0_CCIE=TIMER_B_CCIE_CCR0_INTERRUPT_ENABLE;
    InitParam.timerClear=TIMER_B_DO_CLEAR;
    InitParam.startTimer=true;

    Timer_B_initUpMode(TIMER_B0_BASE,&InitParam);
    //启用可屏蔽中断(具有中断功能的片上外设产生)
    _BIS_SR(GIE);
}

//#pragma vector=TIMERB0_VECTOR
//__interrupt void TIMERB0_ISR (void)
//{
//    speed1=Get_Encoder_Speed(1);
//    speed2=Get_Encoder_Speed(2);
//}

















