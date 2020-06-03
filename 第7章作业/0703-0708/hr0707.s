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

X EQU 19;����X��ֵΪ19
N EQU 20;����N��ֵΪ20
 ;AREA RESET, CODE, READONLY;���������
 ENTRY;��ʶ�������
START LDR R0, =X ;��R0��R1����ֵ
 LDR R1 , =N;��N��ȡ��R1
 BL MAX;�����ӳ���MAX
HALT B HALT;
MAX;�����ӳ���MAX
 CMP R0, R1;�ж�R0>R1?
 MOVHI R2, R0;R0>R1ʱR2=R0,R2����R0,R1�е����ֵ
 MOVLS R2, R1;R0<=R1ʱR2=R1,R2����R0,R1�е����ֵ
 MOV PC, LR;�������
 ;END

;�������

    NOP
	B Reset_Handler
    ENDP

    END
