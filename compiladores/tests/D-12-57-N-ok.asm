segment	.bss
align	4
y:
	resb	4
segment	.bss
align	4
x:
	resb	4
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	push	dword 1
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
_L2:
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L3
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
_L4:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 50
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L5
segment	.rodata
align	4
_L6:
	db	"x", 32, 61, 32, 0
segment	.text
	push	dword $_L6
	call	prints
	add	esp, 4
	push	dword $x
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
segment	.rodata
align	4
_L7:
	db	32, "y", 32, 61, 32, 0
segment	.text
	push	dword $_L7
	call	prints
	add	esp, 4
	push	dword $y
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
segment	.rodata
align	4
_L8:
	db	0
segment	.text
	push	dword $_L8
	call	prints
	add	esp, 4
	call	println
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 2
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L9
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L4
_L9:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 10
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	pop	eax
	cmp	eax, byte 0
	je	near _L10
	jmp	dword _L5
_L10:
	push	dword $x
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $x
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L4
_L5:
	push	dword $x
	pop	eax
	push	dword [eax]
	call	printi
	add	esp, 4
	call	println
	push	dword $y
	pop	eax
	push	dword [eax]
	push	dword 1
	pop	eax
	add	dword [esp], eax
	push	dword [esp]
	push	dword $y
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
	jmp	dword _L2
_L3:
        ;; after body 
_L1:
	leave
	ret
extern	printi
extern	println
extern	prints
extern	readi
