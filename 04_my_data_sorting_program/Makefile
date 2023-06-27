# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/21 20:43:16 by mcoelho-          #+#    #+#              #
#    Updated: 2023/01/24 18:48:46 by mcoelho-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = push_swap.c \
lst_handle.c \
index.c \
utils.c \
validation.c \
push.c \
swaps.c \
rotates.c \
reverses.c \
short_order.c \
long_sort.c \
multivalue.c \
ft_strjoin.c

OBJS = ${SRCS:.c=.o}

NAME = push_swap

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
#-fsanitize=address

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all

val: 
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(NAME) 1

.PHONY:	all clean fclean re
