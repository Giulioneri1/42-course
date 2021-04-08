# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fulloa-s <fulloa-s@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/27 12:13:43 by fulloa-s          #+#    #+#              #
#    Updated: 2021/03/27 13:06:32 by fulloa-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	check_map.c \
			check_var.c \
			cub3d_utils.c \
			cub3d.c \
			get_next_line.c \
			get_next_line_utils.c \
			mlx.c \
			parsing_map.c \
			parsing_res_4var.c \
			parsing_s_f_c.c \
			raycasting.c \
			error.c

MLX_F	=	-Lmlx -lmlx -framework OpenGL -framework AppKit

NAME	=	cub3D

CFLAGS	=	-Wall -Werror -Wextra

CC		=	gcc

OBJCS	=	$(SRCS:.c=.o)

.c.o		:
				@printf "\r\033[33m[CONVERTING FILES ...]"
				@$(CC) $(CFLAGS) -c $<

all:		$(NAME)
			
$(NAME):	$(OBJCS)
			@echo "\n\033[33m[COMPILING MLX ...]" "\x1b[0m"
			@$(MAKE) -C ./mlx > /dev/null
			@cp ./mlx/libmlx.dylib ./
			@echo "\033[33m[COMPILING CUB3D ...]"
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJCS) $(MLX_F)
			@echo "\x1b[32;01m[DONE!]"

run:		$(NAME)
			./cub3d "./map.cub"

save:		$(NAME)
			./cub3d "./map.cub" "--save"

clean:
			@$(MAKE) clean -C ./mlx > /dev/null
			@rm -f libmlx.dylib
			@rm -f $(OBJCS)
			@rm -f ./screenshot.bmp


fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re run