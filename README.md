# C Fundamentals 

A hands-on learning repository for C programming fundamentals.
## About

This repository documents learning C programming. Each file focuses on core concepts with working code examples and explanations.

## Labs

### Memory Experiments
**Location**: `memory-experiments/`

Pointer fundamentals and memory management:
- Address-of (`&`) and dereference (`*`) operators
- Pass-by-value vs pass-by-pointer
- Arrays as pointers
- Structs and memory layout

**Run examples**:
```bash
cd memory-experiments
gcc pointers_basics.c -o pointers_basics
./pointers_basics
```

### TicTacToe
**Location**: `tictactoe/`

Building a command-line TicTacToe game:
- 2D arrays for game board
- Game loops and user input with `scanf`
- Win condition checking
- Converting user positions to array indices

**Play the game**:
```bash
cd tictactoe
make run
```

### MiniDB
**Location**: `minidb/`

In-memory student database with dynamic memory:
- Dynamic memory allocation with `malloc()` and `free()`
- Multi-file projects (header + implementation)
- Growing arrays pattern (doubling capacity)
- Interactive menu-driven program

**Run the database**:
```bash
cd minidb
make run
```

**Run the malloc demo**:
```bash
cd minidb
make run-demo
```

## Key Concepts Learned

- **Pointers**: Understanding memory addresses and indirection
- **Dynamic Memory**: Allocating and freeing memory at runtime
- **Arrays**: Static and dynamic array management
- **Structs**: Creating custom data types
- **Multi-file Projects**: Separating interface from implementation
- **Build Automation**: Using Makefiles for compilation
- **Memory Management**: Preventing leaks and proper cleanup

## Build Tools

Each includes a Makefile for easy compilation:
- `make` - Build the program
- `make run` - Build and run
- `make clean` - Remove compiled files


## Repository Structure

```
cs-fundamentals-c/
├── memory-experiments/    # Pointers and memory
├── tictactoe/             # Game with 2D arrays
├── minidb/                # Dynamic memory database
└── README.md             
```

