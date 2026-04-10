# Compiler
CC = gcc

# Folders
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj

# Include paths
CFLAGS = -I$(INC_DIR) \
         -I$(INC_DIR)/common \
         -I$(INC_DIR)/physics \
         -I$(INC_DIR)/sandbox \
         -Wall -Wextra -O2

LIBS = -lm

# Source files (explicit, matches your tree)
SRC = \
    main.c \
    $(SRC_DIR)/common/data_structures/array.c \
    $(SRC_DIR)/common/math/pow.c \
    $(SRC_DIR)/physics/relativity.c \
    $(SRC_DIR)/sandbox/array_tests.c \
    $(SRC_DIR)/sandbox/relativity_tests.c

# Object files (mirror src/ structure inside obj/)
OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

# Target binary
TARGET = main

# Default
all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Compile rule (preserve directory structure)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

# Cleanup
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
    