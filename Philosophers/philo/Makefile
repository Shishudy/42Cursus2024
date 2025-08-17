# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 19:00:03 by rafasant          #+#    #+#              #
#    Updated: 2025/08/17 14:46:54 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread ${HEADERS}
NAME 		= philo
RM			= rm -rf
HEADERS 	= $(addprefix -I, . catch_lib)
INCLUDE 	= catch_lib/catch.a
SRCS 		= $(addprefix ${SRCS_DIR}, philosophers.c print_structs.c \
				static_structs.c parse_philos.c simulation.c eating.c \
				actions.c stop.c clear.c utils.c)
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