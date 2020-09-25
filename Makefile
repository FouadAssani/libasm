# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fassani <fassani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 22:57:07 by fassani           #+#    #+#              #
#    Updated: 2020/09/21 23:04:04 by fassani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libasm.a
SRCS	= \
ft_strlen.s \
ft_write.s \
ft_read.s \
ft_strcpy.s \
ft_strcmp.s \
ft_strdup.s \

OBJS	= ${SRCS:.s=.o}
INCS	= libasm.h
LIBR	= ranlib
RM		= rm -f
NASM	= nasm -f elf64
LIBC	= ar rcs

.s.o:
	${NASM} $< -o ${<:.s=.o} -I${INCS}

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all


.PHONY: all clean fclean re .s.o
