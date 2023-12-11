# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 16:50:52 by wxuerui           #+#    #+#              #
#    Updated: 2023/04/19 17:30:23 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	attack
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
SRC		=	$(wildcard *.cpp)
OBJ		=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	$(OBJS_DIR) all clean fclean re

