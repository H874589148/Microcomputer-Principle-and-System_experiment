// �й���ѧ������ѧ����Ϣ��ѧ����ѧԺ��΢��ԭ����Ƕ��ʽϵͳ
// C����ʾ����2020-05-14

#include <stdio.h>

#include "ARMCM3.h"                     // Device header
//#include "core_cmInstr.h"

//��Ҫ���õĻ�ຯ��ԭ�Ͳ���extern�ؼ���
extern void strcopy (char * d , char * s ) ; 
extern int MY_C_FUNCTION(int a, int b);
extern void call_C (void) ; 
extern void swap_param (void) ; 
extern char ui_global_defined_in_c = 1;
extern unsigned int ui_glocal_defined_in_asm = 9;

int MY_C_FUNCTION(int a, int b);

int main (void) {
	//�۲�PC���۲�printf()����������λ��
	printf("Hello USTCer\n");

	//�۲�C������û�ຯ����Ч����strcopy������*.s��
	//�۲�memery������ʾ�Ĵ洢������
	//�۲�Call Stack - Local������ʾ�ı���
	char * srcstr = "0123456" ;
	char  dststr [ ] = "abcdefg" ;
	//����ATPCS�����ӳ����ͨ���Ĵ���R0��R3�����ݲ���
	//dststr��ַ�����R0��srcstr��ַ�����R1
	strcopy(dststr,srcstr);	
	
	//�۲��ӳ������ʱ����������Ĵ��ݷ�ʽ��R0,R1
	//ע��۲�LR�Ĵ���
	//call_C();
	
	printf("Hello USTCer\n");
	//��C��ʽ��Ƕ������������ַ���������������Ƕ���
	//����Ϊ��Ƕ���ʾ����Embedded assembler syntax in C and C++
	__asm
	(
		"NOP"
	);

	//ʹ��CMSIS-core����
	unsigned int uiTmp = 0;
	uiTmp = __REV16(1);			//Reverse byte order (16 bit)
	uiTmp = __get_xPSR();		//Get xPSR Register
	uiTmp = __get_MSP();		//Get Main Stack Pointer
	//ʹ��CMSISԤ����ļĴ������������Ĵ���������
	uiTmp = SCB->VTOR;			//Get Vector Table Offset Register
	

	//��������ȫ�ֱ����������ݴ��ݵĴ��룬���Խ������ȷ������
	//ȫ�ֱ�����C����ͻ������еĴ���
	ui_global_defined_in_c = 8;
	uiTmp = ui_glocal_defined_in_asm;
	//���û������޸� ui_glocal_defined_in_asm
	swap_param();
	uiTmp = ui_glocal_defined_in_asm;
	
	
	
}


//MY_C_FUNCTION()�����ɻ�������ã�ע��۲�LR�Ĵ���
int MY_C_FUNCTION(int a, int b){
		return (a+b);
}
//˼����Ϊʲômain()-->call_C()-->MY_C_FUNCTION()����������ѭ����

//��C��ʽ��Ƕ������������ַ���������������Ƕ���
//����Ϊ��Ƕ���ʾ����Embedded assembler syntax in C and C++
__asm void Test()
{
    nop
    BX lr
}
