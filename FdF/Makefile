# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:04:26 by rafasant          #+#    #+#              #
#    Updated: 2024/10/08 19:04:56 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
C_FLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= push_swap
BONUS_NAME	= checker
INCLUDE		= ./libft/libft.a
SRCS		= 
BONUS_SRCS	= 

all: ${NAME}
$(NAME) :
	make -C libft
	${CC} ${C_FLAGS} ${SRCS} ${INCLUDE} -o ${NAME}

bonus: all ${BONUS_NAME}
${BONUS_NAME} :
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