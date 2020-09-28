#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define LED0 PGout(11)
#define LED1 PGout(10)	 
#define LED2 PGout(9)
#define LED3 PDout(7)	 
#define LED4 PGout(3)
#define LED5 PGout(2)	 
#define LED6 PDout(13)
#define LED7 PDout(12)	 	 
//#define PGout(n)   BIT_ADDR(GPIOG_ODR_Addr,n)  //
//#define PGin(n)    BIT_ADDR(GPIOG_IDR_Addr,n)  //
void LED_Init(void);	 				    
#endif
