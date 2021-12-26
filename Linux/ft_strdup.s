section .text
extern malloc
extern ft_strlen
extern ft_strcpy
global ft_strdup

ft_strdup:
	push	rdi			; save argument
	call	ft_strlen	; rax = ft_strlen(rdi)
	inc		rax			; (rax++)
	mov		rdi, rax	; rdi = rax
	call	malloc		; malloc(rdi) <--------------
	pop		rsi			; rdi is restored           |
	mov		rdi, rax	; arg1 = allocated_memory ---
	call	ft_strcpy	; strcpy(arg1, arg2)
	ret
