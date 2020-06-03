; �й���ѧ������ѧ����Ϣ��ѧ����ѧԺ��΢��ԭ����Ƕ��ʽϵͳ
; �����Ĵ���ʾ����2020-05-11

; Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; ����ջ��С
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
				SPACE    (254 * 4)               ; Ϊ������ʾ�������쳣����û��ָ��
__Vectors_End
__Vectors_Size  EQU      __Vectors_End - __Vectors


    AREA     |.text|, CODE, READONLY
; Reset Handler
Reset_Handler   PROC
    EXPORT   Reset_Handler             [WEAK]

;����ʼ

 ;AREA RESET, CODE, READONLY
 ENTRY
 MOV R2, #76;��ʼ��R2��ֵ
 MOV R3, #88;��ʼ��R3��ֵ
 CMP R3, R2;�ж�R3>R2?
 ADDHI R3, R2, #10;R3>R2ʱ��R3=R2+10
 ADDLS R3, R2, #100;R3<=R2ʱ��R3=R2+100
 ;END

;�������

    NOP
	B Reset_Handler
    ENDP

    END
