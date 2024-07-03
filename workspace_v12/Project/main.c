#include    "driverlib.h"//基于库函数开发
#include    "Sys.h"
#include    "Motor.h"
#include    "Bsp_usart.h"
#include    "Bsp_gpio.h"
#include    "Oled.h"
#include    "mpu6050.h"



//static uint8_t Serial_RxPacket[2]={0,0};



float pitch,roll,yow ;


int main( void )
{
    WDT_A_hold(WDT_A_BASE);
    System_Confing();

    OLED_Init();
    MPU_Init();
    mpu_dmp_init();
//    Usart_Init(USCI_A0_BASE);
    while(1)
    {
        mpu_dmp_get_data(&pitch,&roll,&yow);
        OLED_ShowSignedNum(1,1,yow,4);
    //    delay_ms(5);
     //   UART_printf(USCI_A0_BASE,"Pitch=%f\n",pitch);
    //    UART_printf(USCI_A0_BASE,"roll=%f\n",roll);
     //   UART_printf(USCI_A0_BASE,"yow=%f\n",yow);
    }
}

/******************************************************************************

This is the USCI_A1 interrupt vector service routine.

******************************************************************************/
//#pragma vector=USCI_A0_VECTOR
//__interrupt void USCI_A0_ISR (void)
//{
//    static uint8_t RxState = 0;
//    static uint8_t count = 0;
//    static uint8_t RxData;
//    switch (__even_in_range(UCA0IV,4))
//    {
//        //Vector 2 - RXIFG
//        case 2:
//            RxData = USCI_A_UART_receiveData(USCI_A0_BASE);
//            if(RxState==0){
//                if(RxData==0xAA){
//                    RxState=1;
//                    count=0;
//                }
//            }
//            else if(RxState == 1){
//                Serial_RxPacket[count] = RxData;
//                count ++;
//                if(count>=2){
//                    RxState = 2;
//                }
//            }
//            else if(RxState == 2){
//                if(RxData == 0x5B){
//                    RxState = 0;
//                }
//            }
//            break;
//        default:
//            break;
//    }
//}



