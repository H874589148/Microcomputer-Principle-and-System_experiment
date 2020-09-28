#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "12864.h"
#include "stm32f4xx.h"
#include "KEY.h"

int main(void)
{ 
 
	delay_init(168);		  //��ʼ����ʱ����
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
  pcb_Init();
  delay_ms(20);
  lcd_clear();
  delay_ms(10);
	KEY_Init();
	
	while(1)
	{
		if(DIP0==1){
			 	lcd_wstr(1,0,"��Ϣ��ѧ����ѧԺ");
				lcd_wstr(2,3,"���");
				lcd_wstr(3,2,"PB17061124");
				lcd_wstr(4,1,"17����Ժ01��");
				//lcd_wstr(5,0,"17����Ժ01��");
		}
		else {
			lcd_clear();
			while(1){
				delay_ms(20);
					lcd_wstr(2,2,"΢��ԭ��");
					lcd_wstr(3,1,"��Ƕ��ʽϵͳ");
				if(DIP0==1)
				{
					lcd_clear();					
				break; 
			}
		}
	}
}
}

