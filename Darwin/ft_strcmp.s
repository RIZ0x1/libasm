section .text
global _ft_strcmp

_ft_strcmp:
	mov		rcx, 0				; rcx = 0
loop:
	cmp	BYTE	[rdi + rcx], 0	; if (s1[rcx] == 0)
	je			return			; { goto return }
	cmp BYTE	[rsi + rcx], 0	; if (s2[rcx] == 0)
	je			return			; { goto return }
	mov			al, [rdi + rcx]	; char al = s1[rcx]
	mov			bl, [rsi + rcx]	; char bl = s2[rcx]
	cmp			al, bl			; if (al != bl)
	jne			return			; { goto return }
	inc			rcx				; (rcx++)
	jmp			loop			; goto loop
return:
	movzx	rax, BYTE [rdi + rcx]	; (int)s1[rcx]
	movzx	rbx, BYTE [rsi + rcx]	; (int)s2[rcx]
	sub		rax, rbx				; return ((int)s1[rcx] - (int)s2[rcx])
	ret								;
