; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 22:57:07 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:05:56 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global ft_strlen
ft_strlen:
	xor 	rax, rax
while:
	cmp 	BYTE [rdi + rax], 0
	je 		return
	inc	 	rax
	jmp 	while
return:
	ret