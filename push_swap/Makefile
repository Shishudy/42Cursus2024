# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 21:24:26 by rafasant          #+#    #+#              #
#    Updated: 2024/10/03 21:43:07 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= push_swap
BONUS_NAME	= checker
INCLUDE		= ./libft/libft.a
SRCS		= srcs/init_group.c srcs/check_args.c \
				srcs/sort_small.c srcs/sort_big.c srcs/sort_utils1.c \
				srcs/sort_utils2.c srcs/sort_utils3.c srcs/moves.c \
				srcs/error.c srcs/push_swap.c
BONUS_SRCS	= bonus/check_args_bonus.c bonus/error_bonus.c \
				bonus/moves_bonus.c bonus/checker.c

all: ${NAME}
$(NAME) :
	make -C libft
	${CC} ${C_FLAGS} ${SRCS} ${INCLUDE} -o ${NAME}

bonus: all
	${CC} ${C_FLAGS} ${BONUS_SRCS} ${INCLUDE} -o ${BONUS_NAME}

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	${RM} ${NAME}
	${RM} ${BONUS_NAME}

re: fclean all

rebonus: fclean bonus

.PHONY: all, bonus, clean, fclean, re, rebonus