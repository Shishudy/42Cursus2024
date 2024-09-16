# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 21:24:26 by rafasant          #+#    #+#              #
#    Updated: 2024/09/16 20:39:18 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
C_FLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= push_swap
INCLUDE	= ./libft/libft.a
SRCS	= push_swap.c check_args.c error.c moves.c sort_big.c
OBJS	= ${SRCS:.c=.o}

%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@

all: ${NAME}
$(NAME) : $(OBJS)
	@make -C libft
	@${CC} ${C_FLAGS} ${SRCS} ${INCLUDE} -o ${NAME}

val: re
	valgrind --leak-check=full ./push_swap 5 1 3 9 7 6 4 2 8

clean:
	@make clean -C libft
	@${RM} ${OBJS}

fclean: clean
	@make fclean -C libft
	@${RM} ${NAME}

re: fclean all

.PHONY: val, clean, fclean, all, re