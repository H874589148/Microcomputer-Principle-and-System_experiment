#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "12864.h"
#include "stm32f4xx.h"

int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
  pcb_Init();
  delay_ms(20);
  lcd_clear();
  delay_ms(10);
	
	while(1)
	{
			 	lcd_wstr(1,1,"ST STM32F407");
				lcd_wstr(2,1," Cortex-M4");
				lcd_wstr(3,1," ARMʵ����");
				lcd_wstr(4,0,"Ƥ��12�������޹�˾");
	}
}
