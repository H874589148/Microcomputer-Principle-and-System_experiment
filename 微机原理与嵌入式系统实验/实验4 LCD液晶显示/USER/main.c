#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "12864.h"
#include "stm32f4xx.h"
#include "KEY.h"

int main(void)
{ 
 
	delay_init(168);		  //初始化延时函数
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
  pcb_Init();
  delay_ms(20);
  lcd_clear();
  delay_ms(10);
	KEY_Init();
	
	while(1)
	{
		if(DIP0==1){
			 	lcd_wstr(1,0,"信息科学技术学院");
				lcd_wstr(2,3,"胡睿");
				lcd_wstr(3,2,"PB17061124");
				lcd_wstr(4,1,"17级信院01班");
				//lcd_wstr(5,0,"17级信院01班");
		}
		else {
			lcd_clear();
			while(1){
				delay_ms(20);
					lcd_wstr(2,2,"微机原理");
					lcd_wstr(3,1,"与嵌入式系统");
				if(DIP0==1)
				{
					lcd_clear();					
				break; 
			}
		}
	}
}
}

