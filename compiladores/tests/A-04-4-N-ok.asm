segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
segment	.rodata
align	4
_L2:
	db	"xYz", 0
segment	.text
	push	dword $_L2
	call	prints
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
