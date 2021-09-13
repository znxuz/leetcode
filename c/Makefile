SHELL = /bin/sh

NAME = a.out

CC = gcc
CFLAGS= -g -Wall -Wextra -Werror -Iinclude -Wno-unused-function \
		-Wno-unused-parameter -Wno-unused-variable

SRC_DIR = binary_tree_postorder
SRC = $(wildcard $(SRC_DIR)/*.c)

UTILS_DIR = utils
UTILS = $(wildcard $(UTILS_DIR)/*.c)

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o) # $(patsubst %.c,%.o,$(SRC))

RM = rm -f

.PHONY: all fclean re c leak

all: $(NAME) c

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: $(NAME)
	./$(NAME)

leak: $(NAME)
	valgrind --leak-check=full $(NAME)
