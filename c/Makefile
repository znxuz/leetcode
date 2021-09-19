SHELL = /bin/sh

NAME := a.out

CC := gcc
ERR_FLAGS := -Wall -Wextra -Werror
ERR_FLAGS =
CFLAGS = -g $(ERR_FLAGS) -lm -Iinclude -Wno-unused-function \
		-Wno-unused-parameter -Wno-unused-variable

RM = rm -f

src_dir = contain_duplicate_int_array
src = $(wildcard $(src_dir)/*.c)

utils_dir = utils
utils = $(wildcard $(utils_dir)/*.c)

obj = $(src:.c=.o) $(utils:.c=.o) # $(patsubst %.c,%.o,$(src))

.PHONY: all fclean re c leak reset

all: $(NAME) c

$(NAME): $(obj)
	$(CC) $(CFLAGS) $(obj) -o $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)

re: fclean all

c: $(NAME)
	./$(NAME)

leak: $(NAME)
	valgrind --leak-check=full ./$(NAME)

reset: fclean
	@read -rep "new path: " var && sed -i "0,/\(src_dir = \).*/ s//\1$$var/" Makefile \
		&& echo "src_dir => $$var"
