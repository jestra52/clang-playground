COMMON_IDIR = common/include
PHYSICS_IDIR = physics/include

COMMON_DS_DIR = common/data_structures
COMMON_MATH_DIR = common/math
PHYSICS_DIR = physics

ODIR = obj

CC = gcc
CFLAGS = -I$(COMMON_IDIR) -I$(PHYSICS_IDIR) -Wall -Wextra -O2

LIBS = -lm

# All sources
SRC = \
    main.c \
    $(COMMON_DS_DIR)/array.c \
    $(COMMON_MATH_DIR)/pow.c \
    $(PHYSICS_DIR)/relativity.c

# Object files mapped into obj/
OBJ = $(patsubst %.c,$(ODIR)/%.o,$(SRC))

# Default target
all: main

# Link
main: $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

# Compile rule (generic)
$(ODIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ODIR) main
