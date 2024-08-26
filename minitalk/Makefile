# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 15:47:32 by eala-lah          #+#    #+#              #
#    Updated: 2024/08/26 14:02:54 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

INCS        = -I ./inc/
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_PATH    = src/
SERVER_SRC  = server.c
CLIENT_SRC  = client.c

BONUS_SERVER_SRC = server_bonus.c
BONUS_CLIENT_SRC = client_bonus.c

OBJ_PATH    = obj/
SERVER_OBJS = $(OBJ_PATH)server.o
CLIENT_OBJS = $(OBJ_PATH)client.o
BONUS_SERVER_OBJS = $(OBJ_PATH)server_bonus.o
BONUS_CLIENT_OBJS = $(OBJ_PATH)client_bonus.o

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

all: $(OBJ_PATH) $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_PATH)server.o: $(SRC_PATH)$(SERVER_SRC)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_PATH)client.o: $(SRC_PATH)$(CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_PATH)server_bonus.o: $(SRC_PATH)$(BONUS_SERVER_SRC)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_PATH)client_bonus.o: $(SRC_PATH)$(BONUS_CLIENT_SRC)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME_SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(NAME_SERVER) -L $(LIBFT_DIR) -lft

$(NAME_CLIENT): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(NAME_CLIENT) -L $(LIBFT_DIR) -lft

$(BONUS_SERVER): $(BONUS_SERVER_OBJS)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJS) -o $(BONUS_SERVER) -L $(LIBFT_DIR) -lft

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJS)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) -o $(BONUS_CLIENT) -L $(LIBFT_DIR) -lft

bonus: $(OBJ_PATH) $(LIBFT) $(BONUS_SERVER) $(BONUS_CLIENT)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	rm -f $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus
