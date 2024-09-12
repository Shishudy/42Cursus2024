# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 21:24:26 by rafasant          #+#    #+#              #
#    Updated: 2024/09/11 21:41:11 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= push_swap
INCLUDE	= srcs/push_swap.h
SRCS	= push_swap.c check_args.c error.c moves.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJS)
	@make -C ft_printf --no-print-directory
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) srcs/push_swap.h ft_printf/libftprintf.a

val:
	valgrind ./push_swap 5 1 3 9 7 6 4 2 8

clean: 
	@$(RM) $(OBJS)
	@make clean -C ft_printf --no-print-directory
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C ft_printf --no-print-directory
re: fclean all

.PHONY: clean, fclean, all, re