# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 17:08:05 by gneri             #+#    #+#              #
#    Updated: 2021/11/17 12:23:45 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Claptrap

SRCS =	main.cpp \
		ClapTrap.cpp \

CXX = clang++

CXXFLAGS= -Wall -Wextra -Werror

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