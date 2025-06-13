# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 19:00:03 by rafasant          #+#    #+#              #
#    Updated: 2025/06/13 17:25:22 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME 	= philo
OBJS_DIR= objs/
SRCS 	= philosophers.c static_structs.c check_params.c parse_philos.c start_philos.c
OBJS	= ${SRCS:%.c=${OBJS_DIR}%.o}
RM	= /bin/rm -f

${OBJS_DIR}%.o: %.c
	@mkdir -p objs
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}
${NAME} : ${OBJS}
	@${CC} ${CFLAGS} -pthread ${OBJS} -o ${NAME}
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