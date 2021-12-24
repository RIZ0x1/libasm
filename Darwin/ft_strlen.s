section .text
global _ft_strlen

_ft_strlen:
	mov		rcx, 0				; n = 0;
loop:
	cmp BYTE	[rdi + rcx], 0	; if (rdi[rcx] == 0)
	je			return			; {	goto return; }
	inc			rcx				; (rcx++)
	jmp			loop			; goto loop;
return:
	mov			rax, rcx		; ret = rcx
	ret							; return (ret);
