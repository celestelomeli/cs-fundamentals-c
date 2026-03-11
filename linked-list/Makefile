# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

# Target executables
SINGLY = list_basics
DOUBLY = doubly_linked

# Source files
SINGLY_SRC = list_basics.c
DOUBLY_SRC = doubly_linked.c

# Build both programs
all: $(SINGLY) $(DOUBLY)

# Build singly linked list
$(SINGLY): $(SINGLY_SRC)
	$(CC) $(CFLAGS) $(SINGLY_SRC) -o $(SINGLY)

# Build doubly linked list
$(DOUBLY): $(DOUBLY_SRC)
	$(CC) $(CFLAGS) $(DOUBLY_SRC) -o $(DOUBLY)

# Clean compiled files
clean:
	rm -f $(SINGLY) $(DOUBLY)

# Run singly linked list
run-singly: $(SINGLY)
	./$(SINGLY)

# Run doubly linked list
run-doubly: $(DOUBLY)
	./$(DOUBLY)


.PHONY: all clean run-singly run-doubly
