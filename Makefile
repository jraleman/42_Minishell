# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaleman <jraleman@student.42.us.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/15 18:18:00 by jaleman           #+#    #+#              #
#    Updated: 2019/02/15 18:18:01 by jaleman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
SRC			= src/main.c \
			  src/minishell.c \
			  src/builtins/builtins.c \
			  src/builtins/get_total.c \
			  src/builtins/cmd/baguette.c \
			  src/builtins/cmd/cd.c \
			  src/builtins/cmd/echo.c \
			  src/builtins/cmd/env.c \
			  src/builtins/cmd/exit.c \
			  src/builtins/cmd/help.c \
			  src/builtins/cmd/konami.c \
			  src/builtins/cmd/setenv.c \
			  src/utils/ft_error.c
INC			= includes/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I $(INC)
OBJ			= $(SRC:.c=.o)
DEBUG		= -g3 -fsanitize=address

all: $(NAME)
%.o: %.c
	@printf "[minishell] Compiling [.:]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "[minishell] Compiling [:.]\r"
$(NAME): $(OBJ)
	@printf "[minishell] Compiled successfuly! [OK]\n"
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
	@printf "[minishell] Removed object files!\n"
fclean: clean
	@/bin/rm -f $(NAME)
	@printf "[ft_ls] Removed ft_ls binary!\n"
re: fclean all

.PHONY: all clean fclean re
