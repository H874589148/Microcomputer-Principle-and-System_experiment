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

	;�۲쳣��Ĵ���R0��R1��PC
	MOV R1, #0xAB		;��������Ҫ�����ض��Ĺ���
	MOV R0, R1 			;�Ĵ���R1�е���ֵװ�ص��Ĵ���R0
	MOVS R0, R1 		;�Ĵ���R1�е���ֵװ�ص��Ĵ���R0������APSR

	;�۲�PSR
	ITT EQ 	;��������ָ��������ִ�е�
	MOVEQ R0, R1		;��APSR�б�־λ��Z == 1��ʱִ�У�����ִ��
	MOVEQ R2, R1		;��APSR�б�־λ��Z == 1��ʱִ�У�����ִ��

	;�۲�PSR
	MOV R3, #0xFF		;��������Ҫ�����ض��Ĺ���
	LSL R3, #24
	LSL R3, #1
	LSLS R3, #1

	MOV R1,#0x34
	MOV R3,#0xEF
	ITE CS 	;��������ָ��������ִ�е�
	MOVCS R0, R1		;��APSR�б�־λ��C == 1��ʱִ�У�����ִ��
	MOVCC R2, R3		;��APSR�б�־λ��C == 0��ʱִ�У�����ִ��
	
	;�۲�SP
	MOV R1, #0x1
	MOV R3, #0x3
	PUSH {R1}				;��R1ѹ���ջ
	PUSH {R3}				;��R3ѹ���ջ
	POP {R2}				;�Ӷ�ջ������R2
	POP {R4}				;�Ӷ�ջ������R4

	LDR R0, =0x20000800		;��0x12345678װ�ص�R0
	MOV R1, #0xABABABAB		;��������Ҫ�����ض��Ĺ���
	STR R1, [R0]
	LDR R2, [R0]
	
    NOP
	B Reset_Handler
    ENDP

    END
