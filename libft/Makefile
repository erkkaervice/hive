# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 17:41:41 by eala-lah          #+#    #+#              #
#    Updated: 2024/05/02 16:36:54 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC         = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_striteri.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SRC_BONUS   = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

OBJS        = $(SRC:.c=.o)
OBJS_BONUS  = $(SRC_BONUS:.c=.o)

HEAD        = .

NAME        = libft.a
AR          = ar rcs
RM          = rm -f
LIB         = ranlib
GCC         = gcc
CFLAGS      = -Wall -Wextra -Werror

all: $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	@$(AR) $(NAME) $(OBJS_BONUS)
	@$(LIB) $(NAME)

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM)

fclean: 
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
