SRC_DIR := countBinarySubstrings
BIN_DIR := bin
NAME := $(BIN_DIR)/a.out

src := $(shell find $(SRC_DIR) -type f -name "*cpp")
obj := $(src:.cpp=.o)

UTILS_DIR := utils
utils_src := $(shell find $(UTILS_DIR) -type f -name "*cpp")
utils_obj := $(utils_src:.cpp=.o)

CC := clang++
LANG := c++
STD := c++20
WARNINGS := -Wall -Wextra -Wpedantic -Weffc++ -Wconversion \
			-Wno-unused-parameter -Wno-unused-function
SAN := -fsanitize=address,undefined
CFLAGS := -x $(LANG) -std=$(STD) $(WARNINGS) $(DEBUG) -I$(UTILS_DIR)

ARGS :=

all: run

run: $(NAME)
	./$(NAME) $(ARGS)

rerun: fclean run

debug: CFLAGS += -g -DDEBUG=1 -O0

debug: fclean run

$(NAME): $(utils_obj) $(obj)
	$(CC) $(utils_obj) $(SAN) $(obj) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

leak: $(NAME)
	valgrind --leak-check=full $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(utils_obj)

generate_cc:
	@echo $(CFLAGS) | sed 's/\s/\n/g' > compile_flags.txt
