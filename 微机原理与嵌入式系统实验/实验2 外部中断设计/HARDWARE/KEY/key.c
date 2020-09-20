#include "key.h"
#include "exti.h"


//������IO�ڳ�ʼ������
void KEY_Init(void)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;   //�����ʽΪGPIO_InitTypeDef�Ľṹ�������ΪGPIO_InitStructure 

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	 //ʹ��PC�˿�ʱ��

  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //����IO�ڵĹ���ģʽΪ�������루��io���ڲ���ӵ��赽��Դ��
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //����IO����ߵ��������Ϊ50M
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;  //���ñ�ѡ�еĹܽţ�|��ʾͬʱ��ѡ��
  GPIO_Init(GPIOE, &GPIO_InitStructure);			        //��ʼ��GPIOC����ӦIO��Ϊ�������ã����ڰ������
	
	//ʧ��STM32 JTAG��д���ܣ�ֻ����SWDģʽ��д����ų�PA15��PB3��PB4�в���IO��
	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);	
}
 

//����KEY1״̬
//����0: E0�͵�ƽ��KEY1������

int KEY1_STATUS(void)
{
	u8 status;
	status=GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_0);
	return(status);//��ȡE0״̬������
}
