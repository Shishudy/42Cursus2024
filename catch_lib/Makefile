# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 18:41:12 by rafasant          #+#    #+#              #
#    Updated: 2025/08/07 19:45:11 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Wextra -Werror
AR	= ar -rcs
RM = rm -rf
NAME = catch.a
HEADERS = $(addprefix headers, catch.h)
SRCS = $(addprefix sources/, catch.c create_msg.c converter.c \
		converter_functions.c utils.c list_functions.c)
OBJS	= ${SRCS:%.c=${OBJS_DIR}%.o}
RM	= /bin/rm -f

${OBJS_DIR}%.o: %.c
	@mkdir -p objs
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}
${NAME} : ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo "Compiled $(NAME)."

clean: 
	@${RM} ${OBJS}
	@rm -rf objs
	@echo "Cleaned object files!"

fclean: clean
	@${RM} ${NAME}
	@echo "Cleaned executables!"

re: fclean all

.PHONY: clean, fclean, all, re