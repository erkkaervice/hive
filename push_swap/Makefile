# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/06/27 15:05:41 by eala-lah         ###   ########.fr        #
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
	tempft.c \
	utils.c \
	validation.c \
	wtc.c	

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

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000