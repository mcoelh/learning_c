# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcoelho- <mcoelho-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 15:25:24 by mcoelho-          #+#    #+#              #
#    Updated: 2022/09/13 20:15:58 by mcoelho-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
LIBFT = libft/libft.a
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
LOCAL_LIBFT = "libft"
CLEAN_LIBFT = @cd $(LOCAL_LIBFT) && make clean
FCLEAN_LIBFT = @cd $(LOCAL_LIBFT) && make fclean

SRCS = client.c \
server.c \
client_bonus.c \
server_bonus.c

OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):	$(LIBFT) $(SERVER) $(CLIENT) 

$(CLIENT):	$(LIBFT)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client

$(SERVER):	$(LIBFT)
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

$(LIBFT):
	make -C ./libft

all:	$(NAME)

bonus: $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):	$(LIBFT)
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus
	
$(SERVER_BONUS):	$(LIBFT)
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus
	
clean:
	rm -rf $(OBJS)
	$(CLEAN_LIBFT)
fclean: clean
	rm -rf $(NAME)
	rm -rf $(CLIENT)
	rm -rf $(SERVER)
	$(FCLEAN_LIBFT)
re:	fclean all

clean_bonus:
	rm -rf client_bonus.o
	rm -rf server_bonus.o
	$(CLEAN_LIBFT)

fclean_bonus: clean_bonus
	rm -rf $(CLIENT_BONUS)
	rm -rf	$(SERVER_BONUS)
	$(FCLEAN_LIBFT)

re_bonus: clean_bonus fclean_bonus


.PHONY:	all clean fclean re bonus clean_bonus fclean_bonus re_bonus 
