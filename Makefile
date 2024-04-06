CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I minitalk.h
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = server client

SRC = 	server.c \
		client.c

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		$(CC) $(CFLAGS) server.o $(LIBFT) -o server
		$(CC) $(CFLAGS) client.o $(LIBFT) -o client

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean