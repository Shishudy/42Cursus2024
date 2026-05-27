CC 		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME 	= Bureaucrat
RM		= rm -rf
SRCS 	= main.cpp Bureaucrat.cpp
DEPS	= Bureaucrat.hpp
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
