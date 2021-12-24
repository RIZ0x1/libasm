section .text
global _ft_read
extern ___error

_ft_read:
	mov		rax, 0x2000003	; move system call number (read) to RAX
	syscall					; Knock-knock, Kernel. fd, buf and flags are in RDI, RSI, RDX registers respectively
	jc		error			; if (syscall() < 0) { goto error; } Carry flag - checks the first left bit (10000000 & x)
	ret						; else { goto return; }

error:
	push	rax				; save syscall return
	call	___error		; get *int errno
	pop		r9				; r9 = saved syscall
	mov		[rax], r9		; *int errno = r9
	mov		rax, -1			; return (-1)
	ret						;
