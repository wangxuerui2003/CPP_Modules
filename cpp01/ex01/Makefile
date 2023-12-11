# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/19 15:51:36 by wxuerui           #+#    #+#              #
#    Updated: 2023/04/19 15:53:52 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	zombiehorde
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

