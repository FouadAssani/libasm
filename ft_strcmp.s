; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 23:02:32 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:05:17 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_strcmp
ft_strcmp:
	mov rcx, -1
while:
	inc rcx
	cmp byte [rdi + rcx], 0
	je equal
	mov dl, byte [rsi + rcx]
	cmp byte [rdi + rcx], dl
	jl minus
	jg plus
	jmp while
equal:
	cmp byte [rsi + rcx], 0
	je return
	jmp minus	
plus:
	mov rax, 1
	ret
minus:
	mov rax, -1
	ret
return:
	mov rax, 0
	ret