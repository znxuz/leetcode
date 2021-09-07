SHELL = /bin/sh

NAME = a.out

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter \
		-Wno-unused-variable

SRC_DIR = balanced_tree
SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR = $(SRC_DIR)
OBJ = $(SRC:.c=.o)

UTILS_DIR = include
UTILS = $(wildcard $(UTILS_DIR)/*.c)

RM = rm -f

.PHONY: all fclean re c

all: $(NAME) c

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ): $(SRC) $(UTILS)
	// FIXME
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c:
	./$(NAME)
