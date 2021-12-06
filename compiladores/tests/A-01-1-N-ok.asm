extern	readi
extern	printi
extern	prints
extern	println
segment	.text
align	4
fir:
	push	dword 10
	call	printi
	add	esp, 4
	call	println
