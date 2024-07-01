# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/07/01 15:53:29 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

INCS	= -I ./inc/

SRC_PATH = src/
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
SRC	= \
	index.c \
	main.c \
	moves.c \
	options.c \
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

OBJ_PATH = obj/
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
OBJ	= $(SRC:.c=.o)

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

all: $(OBJ_PATH) $(NAME) 

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re