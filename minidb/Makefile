# MiniDB Makefile

# Compiler and flags
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra
# -Wall: Enable all common warnings 
# -Wextra: Enable extra warnings 

# Target executables
TARGET = minidb
DEMO = malloc_demo

# Source files
SRC = main.c db.c
DEMO_SRC = malloc_demo.c

# Object files are compiled machine code to link
OBJ = main.o db.o

# Build main program
all: $(TARGET)

# Build main database program
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# Build object file for main.c
# -c flag = recompile what changed
main.o: main.c db.h
	$(CC) $(CFLAGS) -c main.c

# Build object file for db.c
db.o: db.c db.h
	$(CC) $(CFLAGS) -c db.c

# Build the malloc demo
demo: $(DEMO)

$(DEMO): $(DEMO_SRC)
	$(CC) $(CFLAGS) $(DEMO_SRC) -o $(DEMO)

# Clean up compiled files
clean:
	rm -f $(TARGET) $(DEMO) $(OBJ)

# Run the main program
run: $(TARGET)
	./$(TARGET)

# Run the demo
run-demo: $(DEMO)
	./$(DEMO)

# Phony targets 
.PHONY: all demo clean run run-demo
