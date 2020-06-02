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
//#include "stm32f10x_rcc.h"
//#include "stm32f10x_tim.h"


void LED0_Config (void) ;
void KEY0_Config(void) ;
void EXTI_Config (void) ;
void NVIC_Config (void) ;

int main (void)
{
	LED0_Config ( ) ;
	KEY0_Config ( ) ;
	EXTI_Config ( ) ;
	NVIC_Config ( ) ;
	while (1) ;
}

void EXTI_Config (void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO, ENABLE) ;
	GPIO_EXTILineConfig (GPIO_PortSourceGPIOC, GPIO_PinSource5);
	EXTI_InitStructure.EXTI_Line= EXTI_Line5;
	EXTI_InitStructure.EXTI_Mode= EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_InitStructure.EXTI_LineCmd= ENABLE;
	EXTI_Init (&EXTI_InitStructure) ;
}

void NVIC_Config (void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_PriorityGroupConfig (NVIC_PriorityGroup_1) ;
	NVIC_InitStructure.NVIC_IRQChannel= EXTI9_5_IRQn;	//9_5��Ӧ9-5�ߣ�15_10��Ӧ15-10
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority= 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority= 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd= ENABLE;
	NVIC_Init ( &NVIC_InitStructure) ;
}

//PA8ΪLED��������ź�
void LED0_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// Enable GPIO_LED0 clock                                         
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA, ENABLE) ;
	//GPIO_LED0 Pin (PA8) Configuration 
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_2MHz ;
	GPIO_Init (GPIOA, &GPIO_InitStructure) ;
}

//PC5Ϊ�ⲿ�ж��ź�
void KEY0_Config (void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	// Enable GPIO_KEY0 clock 
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOC, ENABLE ) ;
	// Configure KEY0 Button 
	GPIO_InitStructure.GPIO_Mode= GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_5;
	GPIO_Init (GPIOC, &GPIO_InitStructure) ;
}
