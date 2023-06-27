
SRCS = ft_printf.c \
ft_print_char.c \
ft_is_hex_l.c \
ft_is_int.c \
ft_is_char.c \
ft_unsigned.c \
ft_convert.c \
ft_is_hex_u.c \
ft_is_str.c \
ft_pointer.c
OBJS = ${SRCS:.c=.o}
		
NAME = libftprintf.a

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re


