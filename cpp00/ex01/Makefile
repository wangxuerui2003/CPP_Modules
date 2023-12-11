# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 18:39:22 by wxuerui           #+#    #+#              #
#    Updated: 2023/04/13 20:49:45 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME	=	phonebook
CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I $(INC_DIR)
SRCS_DIR	=	srcs/
INC_DIR		=	includes/
OBJS_DIR	=	objs/

# Sources
SRCS	=	$(wildcard $(SRCS_DIR)*.cpp)
OBJS	=	$(addprefix $(OBJS_DIR), $(notdir $(SRCS:.cpp=.o)))

# Rules
all:
	@make make_objs_dir
	@make $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

make_objs_dir:
	@mkdir -p $(OBJS_DIR)

clean:
	rm -rf $(OBJS_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	$(OBJS_DIR) all clean fclean re


