CC = cc
C_FLAGS = -Wall -Wextra -Werror
AR	= ar -rcs
RM = rm -rf
NAME = libft.a
INCLUDE = libft.h
SRCS = ft_atoi.c ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c \
		ft_strmapi.c ft_substr.c ft_bzero.c ft_isdigit.c ft_memmove.c \
		ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_calloc.c \
		ft_isprint.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c \
		ft_toupper.c ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c \
		ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_isalpha.c ft_memcmp.c \
		ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstadd_front.c ft_lstmap.c ft_lstclear.c \
		ft_lstnew.c ft_lstdelone.c ft_lstsize.c ft_lstiter.c \
		ft_printf.c helper_functions.c helper_functions2.c \
		get_next_line_bonus.c get_next_line_utils_bonus.c
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

.PHONY: all clean fclean re