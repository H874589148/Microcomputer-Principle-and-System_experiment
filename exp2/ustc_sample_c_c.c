// 中国科学技术大学，信息科学技术学院，微机原理与嵌入式系统
// C代码示例，2020-05-14

#include <stdio.h>

#include "ARMCM3.h"                     // Device header
//#include "core_cmInstr.h"

//需要调用的汇编函数原型并加extern关键字
extern void strcopy (char * d , char * s ) ; 
extern int MY_C_FUNCTION(int a, int b);
extern void call_C (void) ; 
extern void swap_param (void) ; 
extern char ui_global_defined_in_c = 1;
extern unsigned int ui_glocal_defined_in_asm = 9;

int MY_C_FUNCTION(int a, int b);

int main (void) {
	//观察PC，观察printf()输入参数存放位置
	printf("Hello USTCer\n");

	//观察C程序调用汇编函数的效果，strcopy定义在*.s中
	//观察memery窗口显示的存储器数据
	//观察Call Stack - Local窗口显示的变量
	char * srcstr = "0123456" ;
	char  dststr [ ] = "abcdefg" ;
	//根据ATPCS规则，子程序间通过寄存器R0～R3来传递参数
	//dststr地址存放在R0，srcstr地址存放在R1
	strcopy(dststr,srcstr);	
	
	//观察子程序调用时候输入参数的传递方式，R0,R1
	//注意观察LR寄存器
	//call_C();
	
	printf("Hello USTCer\n");
	//在C程式中嵌入汇编可以有两种方法：内联汇编和内嵌汇编
	//如下为内嵌汇编示例，Embedded assembler syntax in C and C++
	__asm
	(
		"NOP"
	);

	//使用CMSIS-core函数
	unsigned int uiTmp = 0;
	uiTmp = __REV16(1);			//Reverse byte order (16 bit)
	uiTmp = __get_xPSR();		//Get xPSR Register
	uiTmp = __get_MSP();		//Get Main Stack Pointer
	//使用CMSIS预定义的寄存器（已命名寄存器变量）
	uiTmp = SCB->VTOR;			//Get Vector Table Offset Register
	

	//以下利用全局变量进行数据传递的代码，调试结果不正确！！！
	//全局变量的C程序和汇编程序中的传递
	ui_global_defined_in_c = 8;
	uiTmp = ui_glocal_defined_in_asm;
	//调用汇编程序修改 ui_glocal_defined_in_asm
	swap_param();
	uiTmp = ui_glocal_defined_in_asm;
	
	
	
}


//MY_C_FUNCTION()函数由汇编代码调用，注意观察LR寄存器
int MY_C_FUNCTION(int a, int b){
		return (a+b);
}
//思考：为什么main()-->call_C()-->MY_C_FUNCTION()后陷入了死循环？

//在C程式中嵌入汇编可以有两种方法：内联汇编和内嵌汇编
//如下为内嵌汇编示例，Embedded assembler syntax in C and C++
__asm void Test()
{
    nop
    BX lr
}
