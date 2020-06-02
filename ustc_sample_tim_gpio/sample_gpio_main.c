//中国科学技术大学，信息科学技术学院，微机原理与嵌入式系统
//2020-05-20

/*
本示例基于讲义第8章。
关于GPIO和TIM的寄存器配置详细信息请参阅STM32F103的芯片手册。

STM32F103的芯片手册下载链接：
RM0008 - STM32F10x参考手册
https://www.stmcu.org.cn/document/detail/index/id-200272
*/

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

GPIO_InitTypeDef GPIO_InitStructure;


/*延时函数
实现原理参见讲义 8.6.7 小节示例解析
相关寄存器请参阅STM32F103的芯片手册
*/
void TIM2_Delay250MS ( )
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure ;
	RCC_APB1PeriphClockCmd (RCC_APB1Periph_TIM2, ENABLE) ;	// Enable TIM2 clock
/*   TIM2 Time Base Configuration:*/
/*TIM2CLK /((TIM_Prescaler+1) * (TIM_Period+ 1))=TIM2 Frequency*/
/*TIM2CLK= 72MHz ,  TIM2 Frequency= 2Hz,*/
/*TIM_Prescaler= 36000-1,   TIM_Period= 1000-1               */
	
	TIM_TimeBaseStructure.TIM_Prescaler= 18000- 1 ;
	TIM_TimeBaseStructure.TIM_Period= 1000- 1 ;
	TIM_TimeBaseStructure.TIM_CounterMode= TIM_CounterMode_Up ;
	TIM_TimeBaseInit (TIM2, &TIM_TimeBaseStructure) ;
	TIM_ClearFlag ( TIM2 , TIM_FLAG_Update ) ;		// Clear TIM2 update pending flag
	TIM_Cmd (TIM2, ENABLE) ;					// Enable TIM2 counter
	while (TIM_GetFlagStatus (TIM2, TIM_FLAG_Update) ==RESET) ;
}

//主函数
int main(void)
{
  /* GPIOD Periph clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

  /* Configure PD0 and PD2 in output pushpull mode */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  while (1)
  {
    GPIOD->BSRR = 0x00000005;		//设置PD0和PD2
		TIM2_Delay250MS();					//延时250ms
		
		if ( GPIO_ReadInputDataBit (GPIOA,GPIO_Pin_0))	//缺省IO端口被配置为输入
			TIM2_Delay250MS();				//如果PA0输入1，则添加额外的延时
		
    GPIOD->BRR  = 0x00000005;		//PD0和PD2清零
		TIM2_Delay250MS();
  }
}



