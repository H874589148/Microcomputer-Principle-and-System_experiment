; 中国科学技术大学，信息科学技术学院，微机原理与嵌入式系统
; 纯汇编代码编写子函数示例，2020-05-14

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   汇编代码定义的子函数
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		AREA MyCode,CODE,READONLY
		EXPORT strcopy 
strcopy	PROC;必须与EXPORT后面标号一致
	
LOOP	LDRB	R2, [R1],#1	;R1指向源字符串地址，取出字符内容存入R2
							;更新R1=R1+1，第一次调用时R1指向源字符串首地址
		STRB	R2, [R0],#1	;R0指向目的字符串地址，R2中内容存入R0指向内存单元，
							;更新R0=R0+1，第一次调用时R0指向目的字符串首地址
		CMP	R2, #0
		BNE	LOOP ;先执行后判断，源字符串的终止符‘\0’也复制到目的字符串
		
		MOV	PC, LR
		ENDP
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   汇编中调用C函数
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		PRESERVE8	;根据ATPCS,堆栈数据需要设置为8字节对齐
		THUMB
		EXPORT call_C 
		IMPORT MY_C_FUNCTION ;声明MY_C_FUNCTION为外部引用符号
		ALIGN
call_C	PROC;必须与EXPORT后面标号一致
		MOV  R0, #1 ;参数1赋R0
		MOV  R1, #2 ;参数2赋R1
		BL  MY_C_FUNCTION
		ENDP

;;;;;;;;;以下利用全局变量进行数据传递的代码，调试结果不正确！！！;;;;;;;;;;;;;;;;;
		EXPORT swap_param 
		IMPORT  ui_global_defined_in_c	;用IMPORT伪操作声明该变量时在其他文件中定义的变量
		GBLA ui_glocal_defined_in_asm

swap_param	PROC;必须与EXPORT后面标号一致
		MOV32 R5,ui_global_defined_in_c
;		MOV  R6, ui_glocal_defined_in_asm
ui_glocal_defined_in_asm SETA 0xAA
		ENDP
			
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
		NOP	;空指令，在Keil里写汇编代码如果代码未对齐到字，编译器自动补补警告，加NOP对齐
		END 
