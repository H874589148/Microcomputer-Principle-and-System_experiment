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

 ;N EQU 10;定义N的值为10
 ;AREA RESET, CODE, READONLY;声明代码段
 ENTRY;标识程序入口
 IMPORT FACT;
 MOV R0, #10;初始化R0
 BL FACT
 LDR R1,=0x20000000;结果R0存入内存单元R1
 STR R0,[R1]
 
 ;END

;程序结束

    NOP
	B Reset_Handler
    ENDP

    END
