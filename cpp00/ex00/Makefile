# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:17:02 by wxuerui           #+#    #+#              #
#    Updated: 2023/04/12 15:26:05 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
SRC		=	megaphone.cpp
OBJ		=	$(SRC:.cpp=.o)

#.cpp.o:
#	$(CXX) $(CXXFLAGS) -c $< -o $(<:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
