section .text
global ft_write
extern __errno_location

ft_write:
	mov		rax, 1			; move system call number (write) to RAX
	syscall					; Knock-knock, Kernel. fd, buf and flags are in RDI, RSI, RDX registers respectively
	jc		error			; if (syscall() < 0) { goto error; } Carry flag - checks the first left bit (10000000 & x)
	ret						; else { goto return; }
error:
	push	rax				; save syscall return
	call	__errno_location		; get *int errno
	pop		r9				; r9 = saved syscall
	mov		[rax], r9		; *int errno = r9
	mov		rax, -1			; return (-1)
	ret						;
