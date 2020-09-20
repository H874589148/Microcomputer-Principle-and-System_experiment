#include "sys.h"
#include "delay.h"
#include "led.h"
#include "key.h"
#include "exti.h"
//#define sw0 KEY1_STATUS()

int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);    
	LED_Init();				
	KEY_Init(); 
	
	EXTIX_Init();       
	LED0=0;
	LED1=1;
	while(1)
	{
		if(KEY1_STATUS()){
			EXTI0_IRQHandler();
		}
	}

}
