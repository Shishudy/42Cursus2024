# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 21:24:26 by rafasant          #+#    #+#              #
#    Updated: 2024/09/26 20:13:14 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= push_swap
INCLUDE		= ./libft/libft.a
SRCS		= srcs/push_swap.c srcs/init_group.c srcs/check_args.c \
				srcs/sort_small.c srcs/sort_big.c srcs/sort_utils1.c \
				srcs/sort_utils2.c srcs/moves.c srcs/error.c
OBJS		= ${SRCS:.c=.o}
BONUS_SRCS	= checker/checker.c
BONUS_OBJS	= ${BONUS_OBJS:.c=.o}

%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@

all: ${NAME}
$(NAME) : $(OBJS)
	@make -C libft
	@${CC} ${C_FLAGS} ${SRCS} ${INCLUDE} -o ${NAME}

bonus: 
	make OBJS="${OBJS} ${BONUS_OBJS}" all

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