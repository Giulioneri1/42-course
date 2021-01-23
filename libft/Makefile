# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 15:19:15 by gneri             #+#    #+#              #
#    Updated: 2021/01/23 10:47:41 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalnum.c	ft_isprint.c	ft_isdigit.c	ft_isascii.c \
			ft_tolower.c	ft_isalpha.c	ft_memmove.c	ft_memccpy.c \
			ft_memchr.c		ft_memset.c		ft_memcmp.c		ft_memcpy.c \
			ft_bzero.c		ft_toupper.c\
			ft_putstr_fd.c	ft_strjoin.c	ft_strmapi.c	ft_strtrim.c \
			ft_strlcat.c	ft_strncmp.c	ft_atoi.c		ft_substr.c \
			ft_strchr.c		ft_strlcpy.c	ft_itoa.c		ft_split.c	\
			ft_strnstr.c	ft_strlen.c		ft_strrchr.c	ft_strdup.c \
			ft_calloc.c		ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c

BSRCS	=	ft_lstiter.c	ft_lstsize.c	ft_lstadd_front.c ft_lstlast.c \
			ft_lstdelone.c	ft_lstmap.c		ft_lstclear.c	ft_lstnew.c \
			ft_lstadd_back.c

OBJS	=	${SRCS:.c=.o}

BOBJS	=	${BSRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

NAME	=	libft.a

AR		=	ar -rcs		

$(NAME)	:	${OBJS}		
			${AR} $(NAME) $(OBJS)

bonus	:	${OBJS} ${BOBJS}
			${AR} $(NAME) $(OBJS) $(BOBJS)

all		:	$(NAME)

clean	:
			rm -f ${OBJS} ${BOBJS}
	
fclean	:	clean
			rm -f ${NAME}

re		:	fclean all	

.PHONY	:	all clean fclean re   
