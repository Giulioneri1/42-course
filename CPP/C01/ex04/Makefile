# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneri <gneri@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 10:42:33 by gneri             #+#    #+#              #
#    Updated: 2021/11/11 17:59:42 by gneri            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	replace

SRCS	=	main.cpp 

CXX	=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

OBJS	=	$(SRCS:.cpp=.o)

RM	=	rm -f

%.o	:	%.cpp
	@$(CXX) $(CXXFLAGS) -c $<
				
$(NAME)	:	$(OBJS)
	@$(CXX) -o $(NAME) $(OBJS)
						
all	:	$(NAME)

clean	:
	@$(RM) $(OBJCS)
						
fclean	:	clean
	@$(RM) $(NAME)
						
re	:	fclean all
.PHONY	:	all clean fclean re