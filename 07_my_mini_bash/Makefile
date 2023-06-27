
NAME = minishell

LOCAL_LIB = ./includes/libft
LIBFT = ./includes/libft/libft.a
CLEAN_LIBFT = @cd $(LOCAL_LIB) && make clean
FCLEAN_LIBFT = @cd $(LOCAL_LIB) && make fclean

LREAD = -L ~/.brew/Cellar/readline/8.2.1/lib -lreadline
LINCLUDE = -I ~/.brew/Cellar/readline/8.2.1/include

SRCS = ./sources/main.c \
./sources/init.c \
./sources/built_ins/exit.c \
./sources/executor.c \
./sources/executor_aux.c \
./sources/checks.c \
./sources/expand.c \
./sources/split_words.c \
./sources/checks_lexer.c \
./sources/exec_utils.c \
./sources/parse.c \
./sources/parse_aux.c \
./sources/cleaner_data.c \
./sources/built_ins/echo.c \
./sources/built_ins/env.c \
./sources/built_ins/pwd.c \
./sources/built_ins/cd.c \
./sources/built_ins/export_utils.c \
./sources/built_ins/export.c \
./sources/built_ins/unset.c \
./sources/quotes_aux.c \
./sources/expand_utils.c


OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra $(LINCLUDE) -g

all: ${NAME}

$(NAME): ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} $(LREAD) $(LINCLUDE)

$(LIBFT):
	make -C ./includes/libft all
clean:
	rm -rf ${OBJS}
	$(CLEAN_LIBFT)

fclean: clean
	rm -rf ${NAME}
	${FCLEAN_LIBFT}
re: fclean all

.Phony: all clean fclean re
