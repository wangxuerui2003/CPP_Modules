# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 14:41:00 by wxuerui           #+#    #+#              #
#    Updated: 2023/07/26 15:27:58 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	aform
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
SRCS	=	$(wildcard *.cpp)
OBJS	=	$(SRCS:.cpp=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)
	rm -f *_shrubbery

re:	fclean all

.PHONY: all clean fclean re
