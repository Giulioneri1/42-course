# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:30:20 by gneri             #+#    #+#              #
#    Updated: 2022/02/08 11:11:38 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mutantstack

SRCS =	main.cpp 

CXX = clang++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

RM	=	rm -f

%.o	:	%.cpp
	@$(CXX) $(CXXFLAGS) -c $<
				
$(NAME)	:	$(OBJS)
	@$(CXX) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean 
	@$(RM) $(NAME)

re:	fclean all