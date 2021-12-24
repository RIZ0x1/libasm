section .text
global _ft_strcpy

_ft_strcpy:
	cmp		rdi, 0					; if (!s1)
	je		null_ret				; { goto null_ret; }
	cmp		rsi, 0					; if (!s2)
	je		null_ret				; { goto null_ret; }
	mov		rcx, 0					; rcx = 0
loop:
	cmp		BYTE [rsi + rcx], 0		; if (!s2[rcx])
	je		return					; { goto return }
	mov		al, [rsi + rcx]			; char al = s2[rcx]
	mov		BYTE [rdi + rcx], al	; s1[rcx] = al
	inc		rcx						; (rcx++)
	jmp		loop					; goto loop
null_ret:
	mov		rdi, 0					; s1 = 0
return:
	mov		rax, rdi				; return (s1)
	ret								;