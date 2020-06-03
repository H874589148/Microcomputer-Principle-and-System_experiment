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

N EQU 10;����N��ֵΪ10
 ;AREA RESET, CODE, READONLY;���������
 ENTRY;��ʶ�������
START LDR R0, =N;��R0��R1����ֵR0=10,R1=1
 MOV R1, #1;��ʼ��R1
 BL FUNC;�����ӳ���MAX
 MOV R2, R1;R2=R1
HALT B HALT;
FUNC;�����ӳ̳���FUNC
LOOP MUL R2, R2, R1;R2=R2*R1
 ADD R1, R1, #1;R1++
 CMP R1, R0;��R1��R0�ȽϿ�ѭ���Ƿ����
 BNE LOOP;�ж�ѭ���Ƿ�������������������Ĳ���
 MOV PC, LR;�������
 ;END

;�������

    NOP
	B Reset_Handler
    ENDP

    END
