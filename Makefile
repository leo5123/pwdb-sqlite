# Define the compiler
CC = gcc

# Define the directories
INCLUDE_DIR = include
SRC_DIR = src
LIB_DIR = lib
DATABASE_DIR = $(SRC_DIR)/database
CLI_DIR = $(SRC_DIR)/cli
OBJ_DIR = obj

# Define the source files
SRC_FILES = $(SRC_DIR)/init/main.c $(DATABASE_DIR)/database.c $(CLI_DIR)/commands.c $(CLI_DIR)/handler/handler.c $(LIB_DIR)/utils/messages.c $(LIB_DIR)/utils/input.c

# Define the output executable
OUTPUT = pwdb

# Define the libraries to link against
LIBS = -lsqlite3

# Define the compiler flags
CFLAGS = -I$(INCLUDE_DIR)

# Define object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c/%.c=$(OBJ_DIR)/%.o/%.o)

# Default target
all: $(OUTPUT)

# Rule to build the executable
$(OUTPUT): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@ $(LIBS)

# Rule to build object files
$(OBJ_DIR)/%.o/%.o: $(SRC_DIR)/%.c/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(OUTPUT)

# Phony targets
.PHONY: all clean
