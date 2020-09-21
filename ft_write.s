; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2020/09/21 22:57:07 by fassani           #+#    #+#              ;
;    Updated: 2020/09/21 23:06:09 by fassani          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global ft_write
    extern __errno_location
ft_write:
    mov rax, 1
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