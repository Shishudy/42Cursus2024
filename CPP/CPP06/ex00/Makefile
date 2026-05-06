# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/19 15:52:21 by rafasant          #+#    #+#              #
#    Updated: 2026/05/06 18:04:42 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME 	= ex00
RM		= rm -rf
SRCS 	= main.cpp ScalarConverter.cpp
DEPS	= ScalarConverter.hpp
OBJS	= ${SRCS:%.cpp=%.o}

%.o: %.cpp ${DEPS}
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}
	@echo "Compiled $(NAME)."

clean: 
	${RM} ${OBJS}
	@echo "Cleaned object files!"

fclean: clean
	${RM} ${NAME}
	@echo "Cleaned executables!"

re: fclean all

.PHONY: clean fclean all re