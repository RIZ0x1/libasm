section .text
global _ft_write
extern ___error

_ft_write:
	mov		rax, 0x2000004	; move system call number (write) to RAX
	syscall					; Knock-knock, Kernel. fd, buf and flags are in RDI, RSI, RDX registers respectively
	jc		error			; if (syscall() < 0) { goto error; } Carry flag - checks the first left bit (10000000 & x)
	ret						; else { goto return; }
error:
	push	rax				; 
	call	___error
	pop		qword rax
	mov		rax, -1
	ret
