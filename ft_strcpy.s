; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 22:57:07 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:05:36 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global ft_strcpy
ft_strcpy:
    xor rax, rax
    mov rcx, -1
while:
    inc rcx
    mov al, [rsi + rcx]
    mov [rdi + rcx], al
	cmp [rdi + rcx], byte 0
	je return
    jmp while
return:
	mov rax, rdi    
    ret