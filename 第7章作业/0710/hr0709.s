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
    AREA     hr0710, DATA, READONLY
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

 ;N EQU 10;����N��ֵΪ10
 ;AREA RESET, CODE, READONLY;���������
 ENTRY;��ʶ�������
 EXPORT my_strlen;
my_strlen
 MOV R1, #0;��ʼ��R3
LOOP LDRB R2, [R0], #1;R0ָ��Դ�ַ�����ַ��ȡ���ַ����ݴ���R2
 ADD R1, R1, #1;R1=R1+1
 CMP R2, #0;�ж�R2�Ƿ�Ϊ0
 BNE LOOP;�ж�ѭ���Ƿ�������������������Ĳ���
 BLX LR;����ָ��
 ;END

;�������

    NOP
	B Reset_Handler
    ENDP

    END
