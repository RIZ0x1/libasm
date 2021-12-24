section .text
global _ft_strcpy

_ft_strcpy:
	cmp		rdi, 0
	je		null_ret
	cmp		rsi, 0
	je		null_ret
	mov		rcx, 0
loop:
	cmp		BYTE [rsi + rcx], 0
	je		return
	mov		al, [rsi + rcx]
	mov		BYTE [rdi + rcx], al
	inc		rcx
	jmp		loop
null_ret:
	mov		rdi, 0
return:
	mov		rax, rdi
	ret