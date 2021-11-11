# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 18:04:14 by gneri             #+#    #+#              #
#    Updated: 2021/11/11 18:04:35 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Karen

SRCS =	main.cpp \
		Karen.cpp \

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