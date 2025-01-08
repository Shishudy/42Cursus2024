# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 19:04:26 by rafasant          #+#    #+#              #
#    Updated: 2025/01/08 16:33:09 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -O3
NAME		= fdf
INCLUDES	= ./libft/libft.a ./minilibx-linux/libmlx.a
SRCS		= srcs/fdf.c srcs/proc_map.c srcs/error.c srcs/init_bag.c \
				srcs/hooks.c srcs/coords.c srcs/draw.c srcs/rotations.c \
				srcs/hooks_helper.c srcs/proc_map_helper.c \
				srcs/init_bag_helper.c
OBJS		= $(SRCS:.c=.o)
RM			= /bin/rm -f

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(INCLUDES) $(NAME)
$(INCLUDES) :
	@echo "Compiling libft..."
	@make -C libft --silent
	@echo "Libft compiled!"
	@echo "Compiling MLX..."
	@make -C minilibx-linux --silent
	@echo "MLX compiled!"
$(NAME) : $(OBJS)
	@echo "Compiled $(NAME)."
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -Lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

clean: 
	@$(RM) $(OBJS)
	@make clean -C libft --silent
	@echo "Cleaned object files!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft --silent
	@make clean -C minilibx-linux --silent
	@echo "Cleaned executables!"

re: fclean all

.PHONY: clean, fclean, all, re