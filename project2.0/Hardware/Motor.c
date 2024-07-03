/*
 * Motor.c
 *
 *  Created on: 2023年7月11日
 *      Author: Brando
 */
#include    "Motor.h"



//pid结构体变量：P I D 比例缩放
PID_Handle  Left_Motor_PID={35.55,6.55,0,1};
PID_Handle  Right_Motor_PID={36.55,6.55,0,1};

/*
 Motor_Init() 电机初始化
 */
void Motor_Init(void)
{
    TimerA_Pwm_Init();
    TimerB_Interrupt_Init();
    Bsp_Exti_init();
}

/*
 *Pid_Init: PID数值初始化
 */
void Pid_Init(void)
{
    Left_Motor_PID.Target=7;
    Left_Motor_PID.OutputMin=-1000;
    Left_Motor_PID.OutputMax=1000;

    Right_Motor_PID.Target=7;
    Right_Motor_PID.OutputMin=-1000;
    Right_Motor_PID.OutputMax=1000;

}
/***************************
 * Function:PID电机控制
 * Input: Motor_Num:电机编号
 * Output:无
 * data：2023.7  陈子松
 **************************/
void Motor_PID_Move(uint8_t Motor_Num)
{
    if(Motor_Num==1){
       Motor_Set_Speed(1,Left_Speed);
    }
    if(Motor_Num==2){
       Motor_Set_Speed(2,Right_Speed);
    }
}


/***************************
 * Function:定时器PID运算
 * Input:无
 * Output:无
 * data：2023.7  陈子松
 **************************/
#pragma vector=TIMERB0_VECTOR
__interrupt void TIMERB0_ISR (void)
{

    Pid_Init();
    encoder_speed1=Get_Encoder_Speed(1);
    encoder_speed2=Get_Encoder_Speed(2);
   Left_Speed=PID_PosOperation(&Left_Motor_PID,encoder_speed1);
    Right_Speed=PID_PosOperation(&Right_Motor_PID,encoder_speed2);
    Vofa_Input(encoder_speed1,0);
    Vofa_Input(encoder_speed2,2);
//    Vofa_Input(Left_Speed,1);
    Vofa_Input(Right_Motor_PID.Target,1);
    Vofa_Input(Left_Motor_PID.Target,3);
    Vofa_Send();
}



/***************************
 * Function: 读取霍尔编码器转速
 * Input: Num：霍尔编码器编号
 * Output:霍尔编码器转速
 * data：2023.7  陈子松
 **************************/
int16_t Get_Encoder_Speed(uint8_t Num)
{
    static int16_t temp;
    switch(Num){
        case 1:temp=encoder_count1;encoder_count1=0;break;
        case 2:temp=encoder_count2;encoder_count2=0;break;
    }
    return temp;
}

/***************************
 * Function: 电机速度、方向控制
 * Input: Motor_Num:电机编号 Motor_Speed:电机速度（符号代表正反转）
 * Output:无
 * data：2023.7  陈子松
 **************************/
void Motor_Set_Speed(uint8_t Motor_Num,int16_t Motor_Speed)
{
    GPIO_setAsOutputPin (GPIO_PORT_P2,GPIO_PIN7 );
    GPIO_setAsOutputPin (GPIO_PORT_P3,GPIO_PIN2 );
    GPIO_setAsOutputPin (GPIO_PORT_P4,GPIO_PIN0 +GPIO_PIN3 );//初始化GPIO输出
    if(Motor_Num==1){
      if(Motor_Speed>=0){
          GPIO_setOutputLowOnPin(GPIO_PORT_P2,GPIO_PIN7);
          GPIO_setOutputHighOnPin(GPIO_PORT_P3,GPIO_PIN2);
          Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1, Motor_Speed);
      }
      else{
          GPIO_setOutputHighOnPin(GPIO_PORT_P2,GPIO_PIN7);
          GPIO_setOutputLowOnPin(GPIO_PORT_P3,GPIO_PIN2);
          Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_1, -Motor_Speed);
      }
    }
    if(Motor_Num==2){
      if (Motor_Speed >= 0){
        GPIO_setOutputLowOnPin (GPIO_PORT_P4, GPIO_PIN0);  //高电位输出
        GPIO_setOutputHighOnPin (GPIO_PORT_P4, GPIO_PIN3);  //低电位输出
        Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2, Motor_Speed);
      }
      else{
        GPIO_setOutputHighOnPin (GPIO_PORT_P4, GPIO_PIN0);  //高电位输出
        GPIO_setOutputLowOnPin (GPIO_PORT_P4, GPIO_PIN3);  //低电位输出
        Timer_A_setCompareValue(TIMER_A0_BASE, TIMER_A_CAPTURECOMPARE_REGISTER_2, -Motor_Speed);
      }
    }
}


/***************************
 * Function:编码器中断计数
 * Input:无
 * Output:无
 * data：2023.7  陈子松
 **************************/
#pragma vector=PORT2_VECTOR
__interrupt void Port_2 (void)
{
    if(GPIO_getInterruptStatus(GPIO_PORT_P2, GPIO_PIN0)){
        if(GPIO_getInputPinValue(GPIO_PORT_P2, GPIO_PIN2)==GPIO_INPUT_PIN_HIGH){
            encoder_count1--;
        }else{
            encoder_count1++;
        }
    }
    if(GPIO_getInterruptStatus(GPIO_PORT_P2, GPIO_PIN3)){
        if(GPIO_getInputPinValue(GPIO_PORT_P2, GPIO_PIN6)==GPIO_INPUT_PIN_HIGH){
            encoder_count2++;
        }else{
            encoder_count2--;
        }
    }
    GPIO_clearInterrupt(GPIO_PORT_P2,GPIO_PIN0);
    GPIO_clearInterrupt(GPIO_PORT_P2,GPIO_PIN3);
}


