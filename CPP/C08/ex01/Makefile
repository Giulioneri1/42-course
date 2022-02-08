# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 10:37:32 by gneri             #+#    #+#              #
#    Updated: 2022/01/14 15:25:04 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = span

SRCS =	main.cpp \
		span.cpp

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