///*
//   Function : HC_SR04超声波测距，单位毫米
//   DATE   :2023/7/14
//   Creator  :陈洛康
//
//*/
//#include "HC_SR04.h"
//
//uint32_t Time_Star,Time_End;
//float Speed, TIM_MS, Temp;
//uint32_t Distance_mm;
//
//
////HC_SR04初始化
//void HC_SR04_Init(void)
//{
//           GPIO_setAsInputPin(HC_SR04_Echo_PORT, HC_SR04_Echo_PIN);
//           GPIO_setAsInputPinWithPullDownResistor(HC_SR04_Echo_PORT,HC_SR04_Echo_PIN);
//           GPIO_setAsOutputPin(HC_SR04_Trig_PORT, HC_SR04_Trig_PIN);
//           GPIO_setOutputLowOnPin(HC_SR04_Trig_PORT, HC_SR04_Trig_PIN);
//}
//
///*
//  Function:HC_SR04收到返回的超声波并通过定时器中断计算所用时间
//  Value   :Time_End
//*/
//uint32_t HC_SR04_Receive(void)
//{
//    while(GPIO_getInputPinValue(HC_SR04_Echo_PORT,HC_SR04_Echo_PIN)==0);
//    Time_Star =0;
//    while(GPIO_getInputPinValue(HC_SR04_Echo_PORT,HC_SR04_Echo_PIN)==1);
//    Time_End =Time_Star;
////  if (Time_End / 100 < 38)
////  {
//        return Time_End;
//        /*Distance = (Time_End * 346) / 2;
//        Distance_mm = Distance / 100;
//        Distance_cm = Distance_mm / 100;*/
////  }
//}
//
////HC_SR04发送一个超声波
//void HC_SR04_Send(void)
//{
//    GPIO_setOutputHighOnPin(HC_SR04_Trig_PORT, HC_SR04_Trig_PIN);
//    delay_us(15);
//    GPIO_setOutputLowOnPin(HC_SR04_Trig_PORT, HC_SR04_Trig_PIN);
//
//}
//
///*
//function：计算超声波和物体间的距离
//value   : Distance_mm
//*/
//uint32_t Get_Distance(void)
//{
//    Temp = 28.4;
//    HC_SR04_Send();
//    TIM_MS = (float)HC_SR04_Receive() / 100;
//    Speed = (331.5 + 0.6 * Temp);
//    Distance_mm = (TIM_MS * Speed) / 2;
//
//    delay_ms(210);
//    return Distance_mm;
//}
//
//#pragma vector=TIMERB0_VECTOR
//__interrupt void TIMERB0_ISR (void)
//{
//    Time_Star++;
//}
