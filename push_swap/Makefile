# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/07/11 13:44:40 by eala-lah         ###   ########.fr        #
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

BONUS_SRC   = \
    bonus_checker.c \
    push.c \
    swap.c \
    rotate.c \
    reverse_rotate.c \
    stack.c \
    utils.c

OBJ_PATH    = obj/
OBJS        = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_PATH), $(BONUS_SRC:.c=.o))

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Default target
all: $(OBJ_PATH) $(LIBFT) $(NAME)

# Rule to compile regular source files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Create obj directory
$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

# Build the library
$(LIBFT):
	make -C $(LIBFT_DIR)

# Build push_swap executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

# Bonus target rule
bonus: $(BONUS_NAME)

# Compile bonus source files
$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Build checker executable
$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -L$(LIBFT_DIR) -lft

# Clean object files and libraries
clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean

# Clean everything including executables
fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re bonus
