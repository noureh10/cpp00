# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 23:42:33 by nechaara          #+#    #+#              #
#    Updated: 2024/07/08 14:28:49 by nechaara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

OBJ_DIR = objects
SRCS = PhoneBook.cpp main.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))
FLAGS = -std=c++98 -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "megaphone created successfully !"
	@echo "use it this way : ./megaphone (message) "
	

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files." 
fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executable."

re: fclean all

.PHONY: all clean fclean re