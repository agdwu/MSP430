/*
 * Vofa.h
 *
 *  Created on: 2023年7月11日
 *      Author: Brando
 */

#ifndef SOFTWARE_VOFA_H_
#define SOFTWARE_VOFA_H_

#include  "Bsp_usart.h"

#define DataNum 10  //通道数量

#define write_data  Vofa_PrintDatas//数据传输到电脑

typedef struct Fdatas {
    float fdata[DataNum];
    unsigned char tail[4];
}Fdatas;


static Fdatas Vofa_Sbuffer = {{0},{0x00,0x00,0x80,0x7f}};

/*
    Vofa_Input
    Vofa数据存入Vofa_sbuffer
    @parm data      VOFA数据
    @parm channel   vofa数据通道
*/
void Vofa_Input(float data,unsigned char channel);


/*
    Vofa_send
    数据输出到电脑
*/
void Vofa_Send(void);

#endif /* SOFTWARE_VOFA_H_ */
