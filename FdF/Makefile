# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:04:26 by rafasant          #+#    #+#              #
#    Updated: 2024/10/14 20:23:24 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
C_FLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f
NAME		= fdf
# BONUS_NAME	= 
INCLUDE		= ./libft/libft.a ./minilibx-linux/libmlx.a
SRCS		= srcs/fdf.c srcs/proc_map.c srcs/error.c srcs/init_bag.c \
				srcs/hooks.c
# BONUS_SRCS	= 

all: ${NAME}
# $(NAME) :
# 	make -C libft
# 	${CC} ${C_FLAGS} ${SRCS} ${INCLUDE} -o ${NAME}
$(NAME):
	make -C libft
	make -C minilibx-linux
	$(CC) ${C_FLAGS} ${SRCS} ${INCLUDE} -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

# bonus: all ${BONUS_NAME}
# ${BONUS_NAME} :
# 	${CC} ${C_FLAGS} ${BONUS_SRCS} ${INCLUDE} -o ${BONUS_NAME}

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	${RM} ${NAME}
	# ${RM} ${BONUS_NAME}

re: fclean all

# rebonus: fclean bonus

.PHONY: all, bonus, clean, fclean, re, rebonus