#include "stm32f4xx.h"
#include "delay.h"//延时函数所在的头文件
#include "dip.h"
#include "led.h"

void LED_Init(void); 		

#define ON   Bit_SET     //GPIO的布尔变量，用于GPIO_WriteBit函数
#define OFF  Bit_RESET   //GPIO的布尔变量，用于GPIO_WriteBit函数

/**#define LED0(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_11, x)//写IO口状态，0/1
#define LED1(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_10, x)
#define LED2(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_9, x)
#define LED3(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_7, x)
#define LED4(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_3, x)
#define LED5(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_2, x)
#define LED6(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_13, x)
#define LED7(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_12, x)**/

int main(void)
{ 
	LED_Init();		       //初始化LED端口
	DIP_Init();
	delay_init(168);     //初始化延时函数

	while(1)
	{
		/*流水灯显示*/
		if(DIP0) LED0=1;else LED0=0;
		if(DIP1) LED1=1;else LED1=0;
		if(DIP2) LED2=1;else LED2=0;
		if(DIP3) LED3=1;else LED3=0;
		if(DIP4) LED4=1;else LED4=0;
		if(DIP5) LED5=1;else LED5=0;
		if(DIP6) LED6=1;else LED6=0;
		if(DIP7) LED7=1;else LED7=0;
 	}
}
/**void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;   //GPIO初始化结构体
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG|
								RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOG、GPIOD时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOG,GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3);//LED1,LED2,LED3,LED4,LED5

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_12 | GPIO_Pin_13;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7 |GPIO_Pin_12|GPIO_Pin_13);  //LED6,LED7		 
}**/

