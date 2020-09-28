#ifndef __12864_H
#define __12864_H

#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"

#define CLK_1 GPIO_SetBits(GPIOF, GPIO_Pin_14);  
#define CLK_0 GPIO_ResetBits(GPIOF, GPIO_Pin_14); 

#define SID_1 GPIO_SetBits(GPIOF, GPIO_Pin_15);  
#define SID_0 GPIO_ResetBits(GPIOF, GPIO_Pin_15); 

#define CS_1 GPIO_SetBits(GPIOG, GPIO_Pin_1);  
#define CS_0 GPIO_ResetBits(GPIOG, GPIO_Pin_1);


void Delay(__IO uint32_t nCount);
unsigned char get_byte(void);
void check_busy(void);
void send_cmd(unsigned char cmd);
void write_char(unsigned char dat);
void lcd_clear(void);        //�����ʾ
void lcd_pos(unsigned char y_add , unsigned char x_add);
void lcd_wstr(unsigned char y_add , unsigned char x_add , unsigned char *str) ;
void write_figer(unsigned char y_add , unsigned char x_add , unsigned int figer);//���κ�λ��д����
void lcd_init(void);     //
void Delay(__IO uint32_t nCount);
void pcb_Init(void);
void pcb_GPIO_Init(void);
void lcd_wstr2(unsigned char y_add , unsigned char x_add , unsigned char *str) ;
 
#endif 
