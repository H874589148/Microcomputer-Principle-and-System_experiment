#ifndef __KEY_H
#define __KEY_H
#include "sys.h" 
#define SW0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0)
#define DIP0  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)
#define DIP1  GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)
#define DIP2  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_14)
#define DIP3  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)
#define DIP4  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_0)
#define DIP5  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1)
#define DIP6  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_2)
#define DIP7  GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_3)
void KEY_Init(void);//
#endif
