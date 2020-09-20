#include "key.h"
#include "exti.h"


//按键的IO口初始化程序
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;   //定义格式为GPIO_InitTypeDef的结构体的名字为GPIO_InitStructure 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	 //使能PC端口时钟

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //配置IO口的工作模式为上拉输入（该io口内部外接电阻到电源）
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //配置IO口最高的输出速率为50M
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;  //配置被选中的管脚，|表示同时被选中
  GPIO_Init(GPIOE, &GPIO_InitStructure);			        //初始化GPIOC的相应IO口为上述配置，用于按键检测
	
	//失能STM32 JTAG烧写功能，只能用SWD模式烧写，解放出PA15和PB3、PB4中部分IO口
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	
}
 

//返回KEY1状态
//返回0: E0低电平，KEY1被按下

int KEY1_STATUS(void)
{
	u8 status;
	status=GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0);
	return(status);//读取E0状态并返回
}
