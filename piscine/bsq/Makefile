CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = bsq.c
OBJS = $(SRCS:.c=.o)
NAME = bsq

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
