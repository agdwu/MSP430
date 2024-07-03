/*
 * Motor.h
 *
 *  Created on: 2023年7月11日
 *      Author: Brando
 */


#ifndef HARDWARE_MOTOR_H_
#define HARDWARE_MOTOR_H_

#include    "driverlib.h"//基于库函数开发
#include    "Bsp_timer.h"
#include    "Bsp_exti.h"
#include    "pid.h"
#include    "Vofa.h"



static  int16_t Left_Speed;
static  int16_t Right_Speed;

static  int16_t encoder_speed1;
static  int16_t encoder_speed2;

static  int16_t encoder_count1;
static  int16_t encoder_count2;

void Motor_Init(void);
void Motor_PID_Move(uint8_t Motor_Num);
void Motor_Set_Speed(uint8_t Motor_Num,int16_t Motor_Speed);
void Pid_Init(void);
int16_t Get_Encoder_Speed(uint8_t Num);
__interrupt void Port_2 (void);

#endif /* HARDWARE_MOTOR_H_ */
