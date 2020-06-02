//�й���ѧ������ѧ����Ϣ��ѧ����ѧԺ��΢��ԭ����Ƕ��ʽϵͳ
//2020-05-20

/*
��ʾ�����ڽ����8�¡�
����GPIO��TIM�ļĴ���������ϸ��Ϣ�����STM32F103��оƬ�ֲᡣ

STM32F103��оƬ�ֲ��������ӣ�
RM0008 - STM32F10x�ο��ֲ�
https://www.stmcu.org.cn/document/detail/index/id-200272
*/

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"

GPIO_InitTypeDef GPIO_InitStructure;


/*��ʱ����
ʵ��ԭ��μ����� 8.6.7 С��ʾ������
��ؼĴ��������STM32F103��оƬ�ֲ�
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

//������
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
    GPIOD->BSRR = 0x00000005;		//����PD0��PD2
		TIM2_Delay250MS();					//��ʱ250ms
		
		if ( GPIO_ReadInputDataBit (GPIOA,GPIO_Pin_0))	//ȱʡIO�˿ڱ�����Ϊ����
			TIM2_Delay250MS();				//���PA0����1������Ӷ������ʱ
		
    GPIOD->BRR  = 0x00000005;		//PD0��PD2����
		TIM2_Delay250MS();
  }
}



