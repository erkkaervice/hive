# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 15:04:01 by eala-lah          #+#    #+#              #
#    Updated: 2024/10/03 16:06:25 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

INCS		= -I ./inc/
LIBFT_DIR	= libft/
LIBFT		= $(LIBFT_DIR)/libft.a
MLX_DIR		= minilibx-linux/
MLX		= $(MLX_DIR)/mlx.a

SRC_DIR		= src/
SRCS		= $(addprefix $(SRC_DIR), $(SRC))
SRC		= \


OBJ_PATH	= obj/
OBJ		= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(OBJ_DIR) $(MLX) $(LIBFT) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(MLX_DIR) $(LIBFT_DIR) -lm -lXext -lX11 -lft

bonus: all

clean:
	rm -rf $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus