# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 19:00:03 by rafasant          #+#    #+#              #
#    Updated: 2025/08/08 17:09:17 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread ${HEADERS}
NAME 		= philo
RM			= rm -rf
HEADERS 	= $(addprefix -I, . catch_lib)
INCLUDE 	= catch_lib/catch.a
SRCS 		= $(addprefix ${SRCS_DIR}, philosophers.c check_params.c \
				static_structs.c parse_philos.c start_philos.c)
OBJS		= ${SRCS:${SRCS_DIR}%.c=${OBJS_DIR}%.o}
SRCS_DIR	= srcs/
OBJS_DIR	= objs/

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p objs
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}
${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${INCLUDE} -o ${NAME}
	@echo "Compiled $(NAME)."

clean: 
	@${RM} ${OBJS_DIR}
	@echo "Cleaned object files!"

fclean: clean
	@${RM} ${NAME}
	@echo "Cleaned executables!"

re: fclean all

.PHONY: clean, fclean, all, re