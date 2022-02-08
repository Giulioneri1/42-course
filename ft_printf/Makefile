# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/23 10:57:31 by gneri             #+#    #+#              #
#    Updated: 2021/02/23 10:57:36 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c \
			utils7.c

OBJS	= ${SRCS:.c=.o}

CC 		= gcc

CFLAGS	= -Wall -Wextra -Werror -c

NAME	= libftprintf.a

RM		= /bin/rm -f

%.o: %.c
	${CC} ${CFLAGS} $<

${NAME} :	${OBJS}
			ar -rc ${NAME} ${OBJS}
			ranlib ${NAME}

all :		${NAME}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}
			
re :		fclean all
	
.PHONY :	all clean fclean re
