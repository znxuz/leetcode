SRC_DIR := countOperationsToObtainZero
src := $(wildcard $(SRC_DIR)/*.java)
utils := $(wildcard utils/*.java)
BIN_DIR := bin
.class := $(patsubst %.java,$(BIN_DIR)/%.class,$(src))
MAIN := Main
ARGS = 

J := java
JOPT := -cp $(BIN_DIR)
JC := javac
JCOPT := -g -cp $(SRC_DIR) -d $(BIN_DIR)

all: run

run: $(.class)
	$J $(JOPT) $(patsubst src/%,%,$(SRC_DIR)).$(MAIN) $(ARGS)

$(.class): $(src) $(utils)
	$(JC) $(JCOPT) $(src) $(utils)

compile: $(src) $(utils)
	$(JC) $(JCOPT) $(src) $(utils)

clean:
	$(RM) -rf $(.class)

clean_all:
	$(RM) -rf $(BIN_DIR)/*
