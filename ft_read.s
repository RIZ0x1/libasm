section .text
global _ft_read

_ft_read:
	mov	rax, 0	; move system call number (read) to RAX
	int	0x80	; Knock-knock, Kernel. fd, buf and flags are in RDI, RSI, RDX registers respectively
	cmp	rax, 0	; comparing returned value with 0
	jl	error	; if it less than 0 RIP jumps to error label
	jmp	return	; exit from func
error:
	push	rax
	call	___error
	pop	rax
	mov	rax, -1
return:
	ret
