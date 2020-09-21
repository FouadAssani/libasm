; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 22:57:06 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:05:00 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global ft_read
    extern __errno_location
ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jl error
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