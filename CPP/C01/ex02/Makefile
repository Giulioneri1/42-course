# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 11:55:02 by gneri             #+#    #+#              #
#    Updated: 2021/11/11 18:01:20 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

SRCS =	main.cpp 

CXX = clang++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

RM	=	rm -f

%.o	:	%.cpp
	@$(CXX) $(CXXFLAGS) -c $<

$(NAME)	: $(OBJS)
	@$(CXX) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME)

re:	fclean all