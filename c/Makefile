SHELL = /bin/sh

NAME = a.out

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter \
		-Wno-unused-variable

SRC_DIR = balanced_tree
SRC = $(wildcard $(SRC_DIR)/*.c)

UTILS_DIR = include
UTILS = $(wildcard $(UTILS_DIR)/*.c)

RM = rm -f

.PHONY: all fclean re c

all: $(NAME) c

$(NAME): $(SRC) $(UTILS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c:
	./$(NAME)
