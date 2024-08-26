# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 23:42:33 by nechaara          #+#    #+#              #
#    Updated: 2024/08/26 17:11:06 by nechaara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Account

OBJ_DIR = objects
SRCS = tests.cpp Account.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))
FLAGS = -std=c++98 -Wall -Wextra -Werror

# CAN BE CHANGED BY THE CORRECTOR

LOG_FILE_NAME = test.log

all : $(NAME)

$(NAME) : $(OBJS)
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "Account created successfully !"
	@echo "use it this way : ./Account "
	

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@c++ $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Cleaned object files." 
fclean: clean
	@rm -f $(NAME)
	@echo "Cleaned executable."

diff: all
	@awk -F '] ' '{print $$2}' $(LOG_FILE_NAME) > l1
	@./$(NAME) | awk -F "] " '{print $$2}' > l2
	@echo "Checking differences between files"
	@if diff l1 l2; then \
		echo "Test passed: No differences found."; \
	else \
		echo "Test failed: Differences found (might be destructor order)."; \
	fi
	@rm l1 l2
	
re: fclean all

.PHONY: all clean fclean re