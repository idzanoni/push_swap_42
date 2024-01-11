# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izanoni <izanoni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 12:23:17 by izanoni           #+#    #+#              #
#    Updated: 2024/01/11 19:26:06 by izanoni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I$(FT_PRINTF)
RM = rm -f

FT_PRINTF = ./libs/ft_printf

FILES = checking.c  create.c  move_push.c  move_rotate.c\
		move_rotate_r.c  move_swap.c  push_swap.c  radix.c  sort.c

OBJ = $(FILES:%.c=%.o)

all: libs $(NAME)

libs:
	@make -C $(FT_PRINTF)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(FT_PRINTF)/libftprintf.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(FT_PRINTF)
	@$(RM)  $(OBJ)

fclean: clean
	@make fclean -C $(FT_PRINTF)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libs
