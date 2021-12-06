segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
	push	dword 10
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
	push	dword [esp]
	pop	eax
	cmp	eax, byte 0
	je	near _L2
	push	dword 10
	push	dword 3
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
	pop	eax
	and	dword [esp], eax
align	4
_L2:
	call	printi
	add	esp, 4
	call	println
        ;; after body 
_L1:
	leave
	ret
extern	printi
extern	println
extern	prints
extern	readi
