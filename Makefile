CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I minitalk.h
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = server client

SRC = server.c client.c

OBJS = $(SRC:%.c=.o)

all: $(NAME)

$(all): $(OBJS)
		$(MAKE) -C ./libft $(CC) $ (CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
		$(MAKE) clean -C ./libft
		$(RM) $(OBJS)

fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re: fclean all

run: all clean

.PHONY: all clean