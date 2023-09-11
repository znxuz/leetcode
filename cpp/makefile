SRC_DIR := groupThePeopleGivenTheGroupSizeTheyBelongTo

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
CFLAGS := -x $(LANG) -std=$(STD) $(WARNINGS) $(DEBUG) -I$(UTILS_DIR)

SAN := -fsanitize=address,undefined
LIB := -lfmt

ARGS :=

all: compile

run: compile
	./$(NAME) $(ARGS)

compile: $(NAME)

debug: CFLAGS += -g -DDEBUG=1 -O0

debug: fclean compile

$(NAME): $(utils_obj) $(obj)
	$(CC) $(utils_obj) $(obj) $(SAN) $(LIB) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

leak: $(NAME)
	valgrind --leak-check=full $(NAME)

clean:
	$(RM) $(obj)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(utils_obj)
