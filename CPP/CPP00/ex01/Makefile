# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafasant <rafasant@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 00:33:10 by rafasant          #+#    #+#              #
#    Updated: 2025/12/23 13:11:16 by rafasant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
NAME 		= PhoneBook
RM			= rm -rf
SRCS 		= main.cpp PhoneBook.cpp Contact.cpp
DEPS		= PhoneBook.hpp Contact.hpp
OBJS		= ${SRCS:%.cpp=%.o}

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

.PHONY: clean, fclean, all, re