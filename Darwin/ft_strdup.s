section .text
extern _malloc
extern _ft_strlen
extern _ft_strcpy
global _ft_strdup

_ft_strdup:
	push	rdi			; save argument
	call	_ft_strlen	; rax = ft_strlen(rdi)
	inc		rax			; (rax++)
	mov		rdi, rax	; rdi = rax
	call	_malloc		; malloc(rdi) <--------------
	pop		rsi			; rdi is restored           |
	mov		rdi, rax	; arg1 = allocated_memory ---
	call	_ft_strcpy	; strcpy(arg1, arg2)
	ret
