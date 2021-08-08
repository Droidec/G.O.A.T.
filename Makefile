# Compiler
CC              = gcc
# Compilation flags
CFLAGS          = -Wall -Wextra -Werror -O3 -fPIC
# Header repository
INC_REP         = include
# Source repository
SRC_REP         = src
# Object repository
OBJ_REP         = obj
# Binary repository
BIN_REP         = bin
# Dynamic library name
TARGET_NAME     = G.O.A.T
# All header files from header repository
HEADERS         = $(wildcard $(INC_REP)/*.h)
# All source files from source repository
SOURCES         = $(wildcard $(SRC_REP)/*.c)
# All object files from object repository
OBJECTS         = $(patsubst $(SRC_REP)/%.c, $(OBJ_REP)/%.o, $(SOURCES))

.PHONY: all
all: $(OBJ_REP) $(BIN_REP) $(TARGET_NAME)

$(TARGET_NAME): $(OBJECTS)
	$(CC) -o $(BIN_REP)/$@ $^

$(OBJ_REP)/%.o : $(SRC_REP)/%.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INC_REP)

$(OBJ_REP):
	mkdir -p $(OBJ_REP)

$(BIN_REP):
	mkdir -p $(BIN_REP)

.PHONY: clean
clean:
	rm -f $(OBJ_REP)/*.o $(BIN_REP)/*
