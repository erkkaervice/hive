# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/20 15:47:32 by eala-lah          #+#    #+#              #
#    Updated: 2024/10/03 15:17:15 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
BONUS_SERVER = server_bonus
BONUS_CLIENT = client_bonus

INCS        = -I ./inc/
LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR    = src/
SERVER_SRC  = server.c
CLIENT_SRC  = client.c
UTILS_SRC   = utils.c

BONUS_SERVER_SRC = server_bonus.c
BONUS_CLIENT_SRC = client_bonus.c
BONUS_UTILS_SRC  = utils_bonus.c

OBJ_DIR    = obj/
SERVER_OBJS = $(OBJ_DIR)server.o
CLIENT_OBJS = $(OBJ_DIR)client.o
UTILS_OBJS  = $(OBJ_DIR)utils.o

BONUS_SERVER_OBJS = $(OBJ_DIR)server_bonus.o
BONUS_CLIENT_OBJS = $(OBJ_DIR)client_bonus.o
BONUS_UTILS_OBJS  = $(OBJ_DIR)utils_bonus.o

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

all: $(OBJ_DIR) $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC"

$(OBJ_DIR)server.o: $(SRC_DIR)$(SERVER_SRC) inc/minitalk.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)client.o: $(SRC_DIR)$(CLIENT_SRC) inc/minitalk.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)utils.o: $(SRC_DIR)$(UTILS_SRC) inc/minitalk.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)server_bonus.o: $(SRC_DIR)$(BONUS_SERVER_SRC) inc/minitalk_bonus.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)client_bonus.o: $(SRC_DIR)$(BONUS_CLIENT_SRC) inc/minitalk_bonus.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR)utils_bonus.o: $(SRC_DIR)$(BONUS_UTILS_SRC) inc/minitalk_bonus.h
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME_SERVER): $(SERVER_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(UTILS_OBJS) -o $(NAME_SERVER) -L $(LIBFT_DIR) -lft

$(NAME_CLIENT): $(CLIENT_OBJS) $(UTILS_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(UTILS_OBJS) -o $(NAME_CLIENT) -L $(LIBFT_DIR) -lft

$(BONUS_SERVER): $(BONUS_SERVER_OBJS) $(BONUS_UTILS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJS) $(BONUS_UTILS_OBJS) -o $(BONUS_SERVER) -L $(LIBFT_DIR) -lft

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJS) $(BONUS_UTILS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) $(BONUS_UTILS_OBJS) -o $(BONUS_CLIENT) -L $(LIBFT_DIR) -lft

bonus: $(OBJ_DIR) $(LIBFT) $(BONUS_SERVER) $(BONUS_CLIENT)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	rm -f $(BONUS_SERVER) $(BONUS_CLIENT)

re: fclean all

.PHONY: all clean fclean re bonus