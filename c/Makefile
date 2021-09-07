SHELL = /bin/sh

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter \
		-Wno-unused-variable

SRC_DIR = balanced_tree
SRC = $(wildcard $(SRC_DIR)/*.c)

UTILS_DIR = utils
UTILS = $(wildcard $(UTILS_DIR)/*.c)

NAME = $(SRC_DIR)/a.out

RM = rm -f

.PHONY: all fclean re c t

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(UTILS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

c: re
	./$(NAME)
