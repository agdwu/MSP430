/*
 * Bsp_usart.c
 *
 *  Created on: 2023年7月11日
 *      Author: Brando
 */

#include    "Bsp_usart.h"

/***************************
 * @Function: 串口初始化
 * @Input: baseAddress：串口号
 * @Output: STATUS_FAIL：初始化失败  STATUS_SUCCESS：初始化成功
 * @data：2023.7  陈子松
 * 波特率固定为9600bps
 **************************/
bool Usart_Init(uint16_t baseAddress)
{
    USCI_A_UART_initParam   Usart_str = {0};

    //将所用引脚复用为UART模式
    if(baseAddress == USCI_A0_BASE)         //P3.3, P3.4 = USCI_A0 TXD/RXD
    {
        GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P3, GPIO_PIN3);
        GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P3, GPIO_PIN4);
    }
    else if(baseAddress == USCI_A1_BASE)    //P4.4, P4.5 = USCI_A1 TXD/RXD
    {
        GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P4, GPIO_PIN4);
        GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P4, GPIO_PIN5);
    }

    Usart_str.selectClockSource=USCI_A_UART_CLOCKSOURCE_SMCLK;//时钟源选择
    Usart_str.clockPrescalar=162;
    Usart_str.firstModReg=12;
    Usart_str.secondModReg=0;
    Usart_str.overSampling=1;//波特率配置
    Usart_str.parity=USCI_A_UART_NO_PARITY;//设置奇校验位
    Usart_str.msborLsbFirst=USCI_A_UART_LSB_FIRST;
    Usart_str.numberofStopBits = USCI_A_UART_ONE_STOP_BIT;//设置停止位
    Usart_str.uartMode = USCI_A_UART_MODE;//选择模式


    if (USCI_A_UART_init(baseAddress, &Usart_str)==STATUS_FAIL)
      {   //初始化对应串口
          return STATUS_FAIL;
      }
      //使能串口
      USCI_A_UART_enable(baseAddress);

//      //Enable Receive Interrupt 启用串口中断
      USCI_A_UART_clearInterrupt(baseAddress, USCI_A_UART_RECEIVE_INTERRUPT);
      USCI_A_UART_enableInterrupt(baseAddress, USCI_A_UART_RECEIVE_INTERRUPT);
      _BIS_SR(GIE);//开启中断使能
      return STATUS_SUCCESS;
}


/***************************
 * @Function:  串口输出数据
 * @Input: baseAddress：串口号 data：数据 length 数据长度
 * @Output: 无
 * @data：2023.7  陈子松
 **************************/
void USART_PrintDatas(uint16_t baseAddress,uint8_t* data,uint8_t length)
{
    uint8_t i;
    for(i=0;i<length;i++)
    {
        USCI_A_UART_transmitData(baseAddress,data[i]);
    }
}

/***************************
 * @Function:  VOFA数据输出
 * @Input: data：数据 length 数据长度
 * @Output: 无
 * @data：2023.7  陈子松
 **************************/
void Vofa_PrintDatas(uint8_t* data,uint8_t length)
{
    uint8_t i;
    for(i=0;i<length;i++)
    {
        USCI_A_UART_transmitData(USCI_A0_BASE,data[i]);
    }
}


////******************************************************************************
////
////This is the USCI_A0 interrupt vector service routine.
////
////******************************************************************************
//#pragma vector=USCI_A0_VECTOR
//__interrupt void USCI_A0_ISR (void)
//{
//    uint8_t receivedData = 0;
//    switch (__even_in_range(UCA0IV,4))
//    {
//        //Vector 2 - RXIFG
//        case 2:
//            receivedData = USCI_A_UART_receiveData(USCI_A0_BASE);
//            USCI_A_UART_transmitData(USCI_A0_BASE,receivedData);
//            break;
//        default:
//            break;
//    }
//}
//
////******************************************************************************
////
////This is the USCI_A1 interrupt vector service routine.
////
////******************************************************************************
//#pragma vector=USCI_A1_VECTOR
//__interrupt void USCI_A1_ISR (void)
//{
//    uint8_t receivedData = 0;
//    switch (__even_in_range(UCA1IV,4))
//    {
//        //Vector 2 - RXIFG
//        case 2:
//            receivedData = USCI_A_UART_receiveData(USCI_A1_BASE);
//            USCI_A_UART_transmitData(USCI_A1_BASE,receivedData);
//            break;
//        default:
//            break;
//    }
//}


