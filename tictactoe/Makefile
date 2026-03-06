# TicTacToe Makefile

# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

# Target executables
TARGET = tictactoe
TARGET_SIMPLE = tictactoe_simple

# Source files
SRC = tictactoe.c
SRC_SIMPLE = tictactoe_simple.c

# Default target: build both versions
all: $(TARGET) $(TARGET_SIMPLE)

# Build the main game
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

# Build the simple version
$(TARGET_SIMPLE): $(SRC_SIMPLE)
	$(CC) $(CFLAGS) $(SRC_SIMPLE) -o $(TARGET_SIMPLE)

# Clean up compiled files
clean:
	rm -f $(TARGET) $(TARGET_SIMPLE)

# Run the main game
run: $(TARGET)
	./$(TARGET)

# Run the simple version
run-simple: $(TARGET_SIMPLE)
	./$(TARGET_SIMPLE)

# Phony targets not actual files
.PHONY: all clean run run-simple
