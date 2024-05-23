# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 17:41:41 by eala-lah          #+#    #+#              #
#    Updated: 2024/05/23 15:29:36 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC         = \
	ft_nbrlen.c \
	ft_printchar.c \
	ft_printf.c \
	ft_printhexa.c \
	ft_printmah.c \
	ft_printnbr.c \
	ft_printstr.c \
	ft_printulo.c \
	ft_strchr.c \
	ft_strlen.c \

OBJS        = $(SRC:.c=.o)

HEAD        = .

NAME        = libftprintf.a
AR          = ar rcs
RM          = rm -f
LIB         = ranlib
GCC         = gcc
CFLAGS      = -Wall -Wextra -Werror

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

.PHONY: all clean fclean re bonus
