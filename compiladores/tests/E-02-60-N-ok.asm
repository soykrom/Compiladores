; TEXT
segment	.text
; ALIGN
align	4
; LABEL f
f:
; ENTER 4
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; INT 2
	push	dword 2
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
; LABEL _L2
_L2:
        ;; after body 
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; LDINT
	pop	eax
	push	dword [eax]
; DUP32
	push	dword [esp]
; STFVAL32
	pop	eax
; LABEL _L1
_L1:
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBAL _main, :function
global	_main:function
; LABEL _main
_main:
; ENTER 4
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; INT 0
	push	dword 0
; LOCAL -4
	lea	eax, [ebp+-4]
	push	eax
; STINT
	pop	ecx
	pop	eax
	mov	[ecx], eax
        ;; before body 
; CALL f
	call	f
; LDFVAL32
	push	eax
; EXTERN printi
extern	printi
; CALL printi
	call	printi
; TRASH 4
	add	esp, 4
; LABEL _L4
_L4:
        ;; after body 
; INT 0
	push	dword 0
; STFVAL32
	pop	eax
; LABEL _L3
_L3:
; LEAVE
	leave
; RET
	ret
