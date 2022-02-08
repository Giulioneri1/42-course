# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 14:45:58 by gneri             #+#    #+#              #
#    Updated: 2021/11/30 12:11:52 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp
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