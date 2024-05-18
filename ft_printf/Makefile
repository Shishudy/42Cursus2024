CC = cc
C_FLAGS = -Wall -Wextra -Werror
AR	= ar -rcs
RM = rm -rf
NAME = libftprintf.a
INCLUDE = ft_printf.h
SRCS = ft_printf.c helper_functions.c helper_functions2.c
OBJS =  $(SRCS:.c=.o)

%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@

all: ${NAME}

${NAME}:	${OBJS} ${INCLUDE}
			${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

.phony: all clean fclean re