# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 17:41:41 by eala-lah          #+#    #+#              #
#    Updated: 2024/06/06 12:30:08 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC         = \
	src/checks/ft_isalnum.c \
	src/checks/ft_isalpha.c \
	src/checks/ft_isascii.c \
	src/checks/ft_isdigit.c \
	src/checks/ft_isprint.c \
	src/checks/ft_isspace.c \
	src/checks/ft_pole.c \
	src/converters/ft_atoi.c \
	src/converters/ft_itoa.c \
	src/converters/ft_tolower.c \
	src/converters/ft_toupper.c \
	src/getnextline/get_next_line.c \
	src/lists/ft_lstadd_back_bonus.c \
	src/lists/ft_lstadd_front_bonus.c \
	src/lists/ft_lstclear_bonus.c \
	src/lists/ft_lstdelone_bonus.c \
	src/lists/ft_lstiter_bonus.c \
	src/lists/ft_lstlast_bonus.c \
	src/lists/ft_lstmap_bonus.c \
	src/lists/ft_lstnew_bonus.c \
	src/lists/ft_lstsize_bonus.c \
	src/memories/ft_bzero.c \
	src/memories/ft_calloc.c \
	src/memories/ft_free.c \
	src/memories/ft_memchr.c \
	src/memories/ft_memcmp.c \
	src/memories/ft_memcpy.c \
	src/memories/ft_memmove.c \
	src/memories/ft_memset.c \
	src/printf/ft_printchar.c \
	src/printf/ft_printf.c \
	src/printf/ft_printhexa.c \
	src/printf/ft_printmah.c \
	src/printf/ft_printnbr.c \
	src/printf/ft_printstr.c \
	src/printf/ft_printulo.c \
	src/puts/ft_putchar_fd.c \
	src/puts/ft_putendl_fd.c \
	src/puts/ft_putnbr_fd.c \
	src/puts/ft_putstr_fd.c \
	src/strings/ft_nbrlen.c \
	src/strings/ft_newstr.c \
	src/strings/ft_split.c \
	src/strings/ft_strchr.c \
	src/strings/ft_strdup.c \
	src/strings/ft_striteri.c \
	src/strings/ft_strjoin.c \
	src/strings/ft_strlcat.c \
	src/strings/ft_strlcpy.c \
	src/strings/ft_strlen.c \
	src/strings/ft_strmapi.c \
	src/strings/ft_strncmp.c \
	src/strings/ft_strnstr.c \
	src/strings/ft_strrchr.c \
	src/strings/ft_strtrim.c \
	src/strings/ft_substr.c \

SRC_BONUS   = \
	src/lists/ft_lstadd_back_bonus.c \
	src/lists/ft_lstadd_front_bonus.c \
	src/lists/ft_lstclear_bonus.c \
	src/lists/ft_lstdelone_bonus.c \
	src/lists/ft_lstiter_bonus.c \
	src/lists/ft_lstlast_bonus.c \
	src/lists/ft_lstmap_bonus.c \
	src/lists/ft_lstnew_bonus.c \
	src/lists/ft_lstsize_bonus.c \

OBJS        = $(SRC:.c=.o)
OBJS_BONUS  = $(SRC_BONUS:.c=.o)

HEAD        = include

NAME        = libft.a
AR          = ar rcs
RM          = rm -f
LIB         = ranlib
GCC         = gcc
CFLAGS      = -Wall -Wextra -Werror -I $(HEAD)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@$(LIB) $(NAME)

bonus: $(OBJS_BONUS) $(OBJS)
	@$(AR) $(NAME) $(OBJS_BONUS)
	@$(LIB) $(NAME)
	
clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: 
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
