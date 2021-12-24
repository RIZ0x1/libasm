section .text
global _ft_read

_ft_read:
	mov		rax, 2000003	; move system call number (read) to RAX
	syscall					; Knock-knock, Kernel. fd, buf and flags are in RDI, RSI, RDX registers respectively
	jc		return
return:
	ret
