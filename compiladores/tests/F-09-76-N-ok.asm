extern	readi
extern	printi
extern	prints
extern	println
segment	.text
align	4
f:
	push	dword 10
	push	dword [esp]
segment	.data
align	4
f:
	dd	0
segment	.text
	push	dword $f
	pop	ecx
	pop	eax
	mov	[ecx], eax
	add	esp, 4
extern	readi
extern	printi
extern	prints
extern	println
segment	.text
align	4
g:
extern	readi
extern	printi
extern	prints
extern	println
segment	.text
align	4
fir:
