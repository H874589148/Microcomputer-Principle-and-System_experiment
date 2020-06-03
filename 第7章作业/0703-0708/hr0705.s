; 中国科学技术大学，信息科学技术学院，微机原理与嵌入式系统
; 纯汇编的代码示例，2020-05-11

; Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; 定义栈大小
Stack_Size      EQU      0x00000400

    AREA     STACK, NOINIT, READWRITE, ALIGN=3
__stack_limit
Stack_Mem       SPACE    Stack_Size
__initial_sp

    EXPORT   __stack_limit
    EXPORT   __initial_sp
    THUMB

; Vector Table Mapped to Address 0 at Reset
    AREA     RESET, DATA, READONLY
    EXPORT   __Vectors
    EXPORT   __Vectors_End
    EXPORT   __Vectors_Size
__Vectors       DCD      __initial_sp            ; Top of Stack
				DCD      Reset_Handler           ; Reset Handler
				SPACE    (254 * 4)               ; 为方便演示，其他异常向量没有指定
__Vectors_End
__Vectors_Size  EQU      __Vectors_End - __Vectors


    AREA     |.text|, CODE, READONLY
; Reset Handler
Reset_Handler   PROC
    EXPORT   Reset_Handler             [WEAK]

;程序开始

 ;AREA BUF, DATA, READWRITE;定义数据段Buf
Array DCB 0x11,0x22,0x33,0x44
 DCB 0x55,0x66,0x77,0x88
 DCB 0x00,0x00,0x00,0x00;定义12个字节的数组Array

 ;AREA RESET, CODE, READONLY
 ENTRY
 LDR R0,=Array;取得数组Array的首地址
 MOV R1,#0;R1为循环计数器
 MOV R2,#0;R2为偶数计数器
LOOP CMP R1,#10;判断R1<10?
 BCS FOR_E;若条件失败(R2>=10)则退出循环
 LDR R3,[R0];从数组读取字到R3
 ANDS R3,R3,#0x80;取出符号位
 CMP R3,#1;判断R3>1?
 ADDNE R2,R2,#1;如果R3不等于1则R2++
 ADDS R1,R1,#1;低32位相加，影响标志位，保存进位，结果放入循环计数器R1
 ADDS R0,R0,#1;低32位相加，影响标志位，保存进位，结果放入数组地址R0
 B LOOP
FOR_E MOV R0, R2;退出循环R0=R2
 END

;程序结束

    NOP
	B Reset_Handler
    ENDP

    END
