SHELL = /bin/sh

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter

SRC_DIR = remove_dup_sorted_arr
SRC = $(wildcard $(SRC_DIR)/*.c)

NAME = $(SRC_DIR)/a.out

RM = rm -f

.PHONY: all clean fclean re bonus c

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: re
	./$(NAME)

t:
	$(CC) $(CFLAGS) $(SRC_DIR)/test.c -L $(SRC_DIR)/ -lft -o $(NAME) && ./$(NAME)
