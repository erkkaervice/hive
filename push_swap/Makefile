# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/07/10 16:57:27 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

INCS        = -I ./inc/
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_PATH    = src/
SRCS        = $(addprefix $(SRC_PATH), $(SRC))
SRC         = \
    index.c \
    main.c \
    moves.c \
    push.c \
    reverse_rotate.c \
    rotate.c \
    short.c \
    sort.c \
    steps.c \
    swap.c \
    utils.c \
    validation.c \
    stack.c

BONUS_SRC   = src/bonus_checker.c

OBJ_PATH    = obj/
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))
OBJ         = $(SRC:.c=.o)
BONUS_OBJS  = $(addprefix $(OBJ_PATH), $(notdir $(BONUS_SRC:.c=.o)))

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

all: $(OBJ_PATH) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft

$(BONUS_OBJS): $(BONUS_SRC)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -L $(LIBFT_DIR) -lft

bonus: $(BONUS_NAME)

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus