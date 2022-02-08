# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 15:17:14 by gneri             #+#    #+#              #
#    Updated: 2021/12/20 11:42:54 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = amateria

SRCS =	main.cpp \
		AMateria.cpp \
		Character.cpp \
		Cure.cpp \
		Ice.cpp \
		MateriaSource.cpp

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