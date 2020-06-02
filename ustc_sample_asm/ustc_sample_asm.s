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

	;观察常规寄存器R0，R1，PC
	MOV R1, #0xAB		;立即数需要满足特定的规则
	MOV R0, R1 			;寄存器R1中的数值装载到寄存器R0
	MOVS R0, R1 		;寄存器R1中的数值装载到寄存器R0，更新APSR

	;观察PSR
	ITT EQ 	;随后的两条指令是条件执行的
	MOVEQ R0, R1		;当APSR中标志位“Z == 1”时执行，否则不执行
	MOVEQ R2, R1		;当APSR中标志位“Z == 1”时执行，否则不执行

	;观察PSR
	MOV R3, #0xFF		;立即数需要满足特定的规则
	LSL R3, #24
	LSL R3, #1
	LSLS R3, #1

	MOV R1,#0x34
	MOV R3,#0xEF
	ITE CS 	;随后的两条指令是条件执行的
	MOVCS R0, R1		;当APSR中标志位“C == 1”时执行，否则不执行
	MOVCC R2, R3		;当APSR中标志位“C == 0”时执行，否则不执行
	
	;观察SP
	MOV R1, #0x1
	MOV R3, #0x3
	PUSH {R1}				;将R1压入堆栈
	PUSH {R3}				;将R3压入堆栈
	POP {R2}				;从堆栈弹出至R2
	POP {R4}				;从堆栈弹出至R4

	LDR R0, =0x20000800		;把0x12345678装载到R0
	MOV R1, #0xABABABAB		;立即数需要满足特定的规则
	STR R1, [R0]
	LDR R2, [R0]
	
    NOP
	B Reset_Handler
    ENDP

    END
