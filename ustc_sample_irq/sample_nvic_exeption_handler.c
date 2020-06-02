//�й���ѧ������ѧ����Ϣ��ѧ����ѧԺ��΢��ԭ����Ƕ��ʽϵͳ
//2020-05-20

/*
��ʾ�����ڽ����8�¡�
����NVIC�ļĴ���������ϸ��Ϣ�����STM32F103��оƬ�ֲᡣ

STM32F103��оƬ�ֲ��������ӣ�
RM0008 - STM32F10x�ο��ֲ�
https://www.stmcu.org.cn/document/detail/index/id-200272
*/

#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_tim.h"
//# include "stm32f10x_it.h"

void LED0_On (void) ;
void LED0_Off (void) ;
unsigned char LED0_IsOn (void) ;

void EXTI9_5_IRQHandler (void)
{
	unsigned char temp=LED0_IsOn () ;
	if (EXTI_GetITStatus (EXTI_Line5) != RESET) 
		{
			if (temp)
				LED0_Off ();
			else
			LED0_On();
			EXTI_ClearITPendingBit (EXTI_Line5) ;
		}
}

void LED0_On (void)
{
	GPIO_ResetBits (GPIOA, GPIO_Pin_8) ;
}

void LED0_Off (void)
{
	GPIO_SetBits (GPIOA, GPIO_Pin_8) ;
}

unsigned char LED0_IsOn (void)
{
	return !GPIO_ReadOutputDataBit (GPIOA, GPIO_Pin_8) ;
}    
