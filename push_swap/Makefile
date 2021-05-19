# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 12:13:43 by fulloa-s          #+#    #+#              #
#    Updated: 2021/05/13 16:53:48 by fulloa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_C		=	checker.c \
				checker_utils.c \
				get_next_line.c \
				moves.c \
				lastcheck.c \
				hundredmoves.c \
				push_swap_utils.c \
				threemoves.c \
				
SRCS_P		=	checker_utils.c \
				get_next_line.c \
				moves.c \
				lastcheck.c \
				push_swap.c \
				push_swap_utils.c \
				threemoves.c \
				hundredmoves.c \
				
NAME_C		=	checker

NAME_P		=	push_swap

CFLAGS		=	-Wall -Werror -Wextra

CC			=	gcc

OBJCS_C		=	$(SRCS_C:.c=.o)

OBJCS_P		=	$(SRCS_P:.c=.o)

.c.o		:
				@$(CC)  -c $<

all			:	$(NAME_C) $(NAME_P)
			
$(NAME_C)		:	$(OBJCS_C)
				@$(CC) $(CFLAGS) -o $(NAME_C) $(OBJCS_C)

$(NAME_P)		:	$(OBJCS_P)
				@$(CC) $(CFLAGS) -o $(NAME_P) $(OBJCS_P)
				
clean		:
				@rm -f $(OBJCS_C)
				@rm -f $(OBJCS_P)

fclean		:	clean
				@rm -f $(NAME_C)
				@rm -f $(NAME_P)

re			:	fclean all

.PHONY		:	all clean fclean re run