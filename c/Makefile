SHELL = /bin/sh

NAME = $(SRC_DIR)/a.out

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Iinclude -Wno-unused-function \
		-Wno-unused-parameter -Wno-unused-variable

SRC_DIR = squares_of_sorted_array
SRC = $(wildcard $(SRC_DIR)/*.c)

UTILS_DIR = utils
UTILS = $(wildcard $(UTILS_DIR)/*.c)

RM = rm -f

.PHONY: all fclean re c leak

all: $(NAME) c

$(NAME): $(SRC) $(UTILS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: $(NAME)
	./$(NAME)

leak: $(NAME)
	valgrind --leak-check=full $(NAME)
