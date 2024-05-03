CC = cc
C_FLAGS = -Wall -Wextra -Werror
AR	= ar -rcs
RM = rm -rf
NAME = libftprintf.a
INCLUDE = ft_printf.h
SRCS = ft_printf.c
OBJS =  $(SRCS:.c=.o)

%.o: %.c
	${CC} ${C_FLAGS} -c $< -o $@

all: ${NAME}

${NAME}:	make -C ./libft --no-print-directory
			${OBJS} ${INCLUDE}
			${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS} ${BONUS_OBJS}
	make clean -C ./libft --no-print-directory

fclean:	clean
	${RM} ${NAME}
	make fclean -C ./libft --no-print-directory

re: fclean all

.phony: all clean fclean re