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

X EQU 19;定义X的值为19
N EQU 20;定义N的值为20
 ;AREA RESET, CODE, READONLY;声明代码段
 ENTRY;标识程序入口
START LDR R0, =X ;给R0、R1赋初值
 LDR R1 , =N;将N读取到R1
 BL MAX;调用子程序MAX
HALT B HALT;
MAX;声明子程序MAX
 CMP R0, R1;判断R0>R1?
 MOVHI R2, R0;R0>R1时R2=R0,R2等于R0,R1中的最大值
 MOVLS R2, R1;R0<=R1时R2=R1,R2等于R0,R1中的最大值
 MOV PC, LR;返回语句
 ;END

;程序结束

    NOP
	B Reset_Handler
    ENDP

    END
