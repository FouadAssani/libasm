; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 22:57:07 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:05:45 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location
ft_strdup:
	push rdi
	call ft_strlen
	mov rdi, rax
	inc rdi
	call malloc
	cmp rax, 0
	je error
	pop rsi
	mov rdi, rax
	call ft_strcpy
	jmp return
error:
    xor     rcx, rcx
    mov     ecx, eax
    neg     rcx
    call    __errno_location
    mov     [rax], rcx
    mov     rax, -1
return:
    ret