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

 ;AREA BUF, DATA, READWRITE;�������ݶ�Buf
Array DCB 0x11,0x22,0x33,0x44
 DCB 0x55,0x66,0x77,0x88
 DCB 0x00,0x00,0x00,0x00;����12���ֽڵ�����Array

 ;AREA RESET, CODE, READONLY
 ENTRY
 LDR R0,=Array;ȡ������Array���׵�ַ
 MOV R1,#0;R1Ϊѭ��������
 MOV R2,#0;R2Ϊż��������
LOOP CMP R1,#10;�ж�R1<10?
 BCS FOR_E;������ʧ��(R2>=10)���˳�ѭ��
 LDR R3,[R0];�������ȡ�ֵ�R3
 ANDS R3,R3,#0x80;ȡ������λ
 CMP R3,#1;�ж�R3>1?
 ADDNE R2,R2,#1;���R3������1��R2++
 ADDS R1,R1,#1;��32λ��ӣ�Ӱ���־λ�������λ���������ѭ��������R1
 ADDS R0,R0,#1;��32λ��ӣ�Ӱ���־λ�������λ��������������ַR0
 B LOOP
FOR_E MOV R0, R2;�˳�ѭ��R0=R2
 END

;�������

    NOP
	B Reset_Handler
    ENDP

    END
