# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Directories
SRC_DIR = src
INCLUDE_DIR = include
OUT_DIR = out

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Object files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OUT_DIR)/%.o,$(SRC_FILES))

# Executable
EXECUTABLE = $(OUT_DIR)/Arabica

# Build rule
all: $(EXECUTABLE)

# Linking rule
$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $^ -o $@

# Compilation rule
$(OUT_DIR)/%.o: $(SRC_DIR)/%.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create output directory if it doesn't exist
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# Clean rule
clean:
	rm -rf $(OUT_DIR)

.PHONY: all clean
