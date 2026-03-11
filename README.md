# C Fundamentals 

A hands-on learning repository for C programming fundamentals.
## About

This repository documents learning C programming. Each file focuses on core concepts with working code examples and explanations.


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
- Multi-file projects 
- Growing arrays pattern 
- Interactive program

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

### Linked List
**Location**: `linked-list/`

Singly and doubly linked list implementations:
- Node structure with data and next pointers
- Insert, append, and delete 
- Forward and backward traversal (doubly linked)
- Memory management for dynamic nodes

**Run singly linked list**:
```bash
cd linked-list
make run-singly
```

**Run doubly linked list**:
```bash
cd linked-list
make run-doubly
```

### Hash Table
**Location**: `hash-table/`

Hash table with chaining for collision resolution:
- Hash function (ASCII summation)
- Collision handling with linked lists
- Insert and lookup operations
- Multi-level pointer indirection
- Memory cleanup

**Run the hash table**:
```bash
cd hash-table
make run
```

## Key Concepts Learned

- **Pointers**: Understanding memory addresses and indirection
- **Dynamic Memory**: Allocating and freeing memory at runtime
- **Arrays**: Static and dynamic array management
- **Structs**: Creating custom data types
- **Linked Lists**: Building chains with pointers
- **Hash Tables**: Key-value storage with hashing and collision resolution
- **Multi-file Projects**: Separating interface from implementation
- **Build Automation**: Using Makefiles for compilation
- **Memory Management**: Preventing leaks, cleanup

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
├── linked-list/           # Singly and doubly linked lists
├── hash-table/            # Hash table with chaining
└── README.md             
```

