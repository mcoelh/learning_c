
NAME = philo
SRCS = main.c \
utils.c \
validation.c \
start_dinner.c \
forks.c \
time.c \
actions.c \
starvation.c \
print.c \
checker.c \
end_dinner.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -pthread
RM = rm -rf

$(NAME):	${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o philo 

all: 	$(NAME)

clean:
	@${RM} ${OBJS}

fclean:	clean
	@${RM} $(NAME)

re:	fclean all

.PHONY: all clean fclean re
