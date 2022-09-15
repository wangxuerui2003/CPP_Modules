# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wxuerui <wxuerui@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 11:07:35 by wxuerui           #+#    #+#              #
#    Updated: 2022/09/15 09:07:14 by wxuerui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables

NAME	= tests
CXX		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic $(HEADER)
HEADER	= -I$(INCLUDE_DIR)
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
INCLUDE_DIR	= includes/

#colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
RESET = \033[0m

#sources

SRC_FILES	= tests Account

SRCS	= $(addprefix $(SRCS_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

#######

all:
		@mkdir -p $(OBJS_DIR)
		@make $(NAME)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
				@$(CXX) $(CXXFLAGS) -c $< -o $@
				@echo ".\c"

$(NAME):	$(OBJS)
			@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "\n$(GREEN)$(NAME) was created$(RESET)"

clean:
		@rm -rf $(OBJS_DIR)
		@echo "$(BLUE)$(NAME): $(YELLOW)object files are cleaned$(RESET)"

fclean:	clean
		@rm -f $(NAME)
		@echo "$(BLUE)$(NAME): $(MAGENTA)$(NAME) was deleted$(RESET)"

re:	fclean all

.PHONY:	all $(NAME) fclean clean re
