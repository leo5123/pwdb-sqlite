# Define the compiler
CC = gcc

# Define the directories
INCLUDE_DIR = include
SRC_DIR = src
DATABASE_DIR = $(SRC_DIR)/database
MENU_DIR =  $(SRC_DIR)/menu
OBJ_DIR = obj

# Define the source files
SRC_FILES = $(SRC_DIR)/init/main.c $(DATABASE_DIR)/database.c $(MENU_DIR)/menu.c

# Define the output executable
OUTPUT = exec

# Define the libraries to link against
LIBS = -lsqlite3

# Define the compiler flags
CFLAGS = -I$(INCLUDE_DIR)

# Define object files
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default target
all: $(OUTPUT)

# Rule to build the executable
$(OUTPUT): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $@ $(LIBS)

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(OUTPUT)

# Phony targets
.PHONY: all clean