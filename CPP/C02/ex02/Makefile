# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:34:55 by gneri             #+#    #+#              #
#    Updated: 2021/11/16 16:38:47 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixedpoint

SRCS =	main.cpp \
		Fixed.cpp \

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