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

 ;AREA RESET, CODE, READONLY
 EXPORT RESULT [WEAK];声明一个可以全局引用的标号RESULT
RESULT;输出结果
 ENTRY
 MOV R0, #100;循环数，即累加个数100
 MOV R1, #0;初始化数据
LOOP ADD R1, R1, R0;将数据进行相加，获得最后的数据
 SUBS R0, R0, #1;R0=R0-1
 CMP R0, #0;将R0与0比较判断循环是否结束
 BNE LOOP;判断循环是否结束，结束则进行下面的步骤
 LDR R2, =RESULT;RESULT为数据段存储结果单元，将RESULT地址赋给R2
 STR R1, [R2]
 ;END

;程序结束

    NOP
	B Reset_Handler
    ENDP

    END
