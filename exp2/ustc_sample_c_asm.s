; �й���ѧ������ѧ����Ϣ��ѧ����ѧԺ��΢��ԭ����Ƕ��ʽϵͳ
; ���������д�Ӻ���ʾ����2020-05-14

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   �����붨����Ӻ���
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		AREA MyCode,CODE,READONLY
		EXPORT strcopy 
strcopy	PROC;������EXPORT������һ��
	
LOOP	LDRB	R2, [R1],#1	;R1ָ��Դ�ַ�����ַ��ȡ���ַ����ݴ���R2
							;����R1=R1+1����һ�ε���ʱR1ָ��Դ�ַ����׵�ַ
		STRB	R2, [R0],#1	;R0ָ��Ŀ���ַ�����ַ��R2�����ݴ���R0ָ���ڴ浥Ԫ��
							;����R0=R0+1����һ�ε���ʱR0ָ��Ŀ���ַ����׵�ַ
		CMP	R2, #0
		BNE	LOOP ;��ִ�к��жϣ�Դ�ַ�������ֹ����\0��Ҳ���Ƶ�Ŀ���ַ���
		
		MOV	PC, LR
		ENDP
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   ����е���C����
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		PRESERVE8	;����ATPCS,��ջ������Ҫ����Ϊ8�ֽڶ���
		THUMB
		EXPORT call_C 
		IMPORT MY_C_FUNCTION ;����MY_C_FUNCTIONΪ�ⲿ���÷���
		ALIGN
call_C	PROC;������EXPORT������һ��
		MOV  R0, #1 ;����1��R0
		MOV  R1, #2 ;����2��R1
		BL  MY_C_FUNCTION
		ENDP

;;;;;;;;;��������ȫ�ֱ����������ݴ��ݵĴ��룬���Խ������ȷ������;;;;;;;;;;;;;;;;;
		EXPORT swap_param 
		IMPORT  ui_global_defined_in_c	;��IMPORTα���������ñ���ʱ�������ļ��ж���ı���
		GBLA ui_glocal_defined_in_asm

swap_param	PROC;������EXPORT������һ��
		MOV32 R5,ui_global_defined_in_c
;		MOV  R6, ui_glocal_defined_in_asm
ui_glocal_defined_in_asm SETA 0xAA
		ENDP
			
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		NOP	;��ָ���Keil��д�������������δ���뵽�֣��������Զ��������棬��NOP����
		END 
