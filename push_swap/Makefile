# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/06/25 16:24:47 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	= \
	src/index.c \
	src/main.c \
	src/moves.c \
	src/options.c \
	src/push.c \
	src/reverse_rotate.c \
	src/rotate.c \
	src/short.c \
	src/sort.c \
	src/steps.c \
	src/swap.c \
	src/tempft.c \
	src/utils.c \
	src/validation.c \
	src/wtc.c	

OBJS	= $(SRC:.c=.o)
HEAD	= inc
NAME	= push_swap
AR	= ar rcs
RM	= rm -rf
LIB	= ranlib
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -I $(HEAD)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(OBJS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
