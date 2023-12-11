# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 13:12:40 by wxuerui           #+#    #+#              #
#    Updated: 2023/05/31 11:33:38 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	diamondtrap
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -Wshadow -std=c++98
SRCS	=	$(wildcard *.cpp)
OBJS	=	$(SRCS:.cpp=.o)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re