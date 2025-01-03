# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 16:08:59 by rafasant          #+#    #+#              #
#    Updated: 2025/01/03 20:28:05 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
LIBFT 		= libft/libft.a
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
RM			= /bin/rm -f

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)
$(LIBFT) :
	@echo "Compiling libft..."
	@make -C libft --silent
	@echo "Compilation successfull!"
$(NAME_CLIENT) : $(OBJS_CLIENT)
	@echo "Compiled $(NAME_CLIENT)."
	@$(CC) $(CFLAGS) $(SRCS_CLIENT) libft/libft.a -o $(NAME_CLIENT)
$(NAME_SERVER) : $(OBJS_SERVER)
	@$(CC) $(CFLAGS) $(SRCS_SERVER) libft/libft.a -o $(NAME_SERVER)
	@echo "Compiled $(NAME_SERVER)."

clean: 
	@$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	@make clean -C libft --silent
	@echo "Cleaned object files!"
fclean: clean
	@$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@make fclean -C libft --silent
	@echo "Cleaned executables!"
re: fclean all

.PHONY: clean, fclean, all, re