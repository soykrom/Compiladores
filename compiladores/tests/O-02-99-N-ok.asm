segment	.text
align	4
global	main:function
main:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
        ;; after body 
_L1:
	leave
	ret
segment	.text
align	4
global	_main:function
_main:
	push	ebp
	mov	ebp, esp
	sub	esp, 0
        ;; before body 
