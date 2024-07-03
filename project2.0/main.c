#include    "driverlib.h"//基于库函数开发
#include    "Sys.h"
#include    "Motor.h"
#include    "Bsp_usart.h"
#include    "Bsp_gpio.h"
#include    "HC_SR04.h"
#include    "Oled.h"
#include    "gray.h"



int main(void)
{
    WDT_A_hold(WDT_A_BASE);
    System_Confing();

    Usart_Init(USCI_A0_BASE);
    Motor_Init();
    while(1)
    {

//        Motor_Set_Speed(1,700);
//        Motor_Set_Speed(2,700);
        Motor_PID_Move(1);
        Motor_PID_Move(2);
    }
}




