global _main

section .data
	var	db "I am vengeance"
	len equ $ - var

section .text

_main:
	mov rax, 4
	mov rbx, 1
	mov rcx, var
	mov rdx, len

	int 0x80

	mov rax, 1
	mov rbx, 0

	int 0x80

