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
				checker_utils2.c \
				checker_utils3.c \
				get_next_line.c \
				moves.c \
				moves2.c \
				lastcheck.c \
				big_numbers.c \
				big_numbers2.c \
				big_numbers3.c \
				big_numbers4.c \
				push_swap_utils.c \
				three_numbers.c \
				five_numbers.c \
				lists_clean.c \
				lists_utils.c \
				lists_utils2.c \
				lists_utils3.c \
				init.c \
				subsequence.c \
				subsequence2.c \
				print_moves.c \
				print_moves2.c \
				
SRCS_P		=	checker_utils.c \
				checker_utils2.c \
				checker_utils3.c \
				get_next_line.c \
				moves.c \
				moves2.c \
				lastcheck.c \
				push_swap.c \
				push_swap_utils.c \
				three_numbers.c \
				five_numbers.c \
				big_numbers.c \
				big_numbers2.c \
				big_numbers3.c \
				big_numbers4.c \
				print_moves.c \
				print_moves2.c \
				init.c \
				subsequence.c \
				subsequence2.c \
				lists_clean.c \
				lists_utils.c \
				lists_utils2.c \
				lists_utils3.c \
				
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