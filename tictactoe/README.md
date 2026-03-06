# TicTacToe

A playable TicTacToe game demonstrating 2D arrays, game loops, and user input.

---

## What I Learned

- 2D arrays for game boards
- Game loop pattern
- User input with `scanf`
- Win condition checking
- Control flow (`if/else`, `while`)

---

## Files

**`tictactoe.c`** - Main game  
**`tictactoe_simple.c`** - Simplified version

---

## How to Play

```bash
# Compile
gcc tictactoe.c -o tictactoe

# Run
./tictactoe
```

**Gameplay:**
- Board shows positions 1-9
- Players take turns entering a position
- First to get 3 in a row wins
- If board fills with no winner, it's a tie

---

## Code Structure

### The Board
```c
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
```
2D array storing the game state.

### Key Functions

**`print_board()`** - Displays the current board  
**`place_mark(position, mark)`** - Converts position 1-9 to row/col and places X or O  
**`check_winner()`** - Checks all rows, columns, and diagonals for a winner

### Game Loop

1. Show board
2. Get player input
3. Place mark
4. Check for winner
5. Switch players
6. Repeat until game over

---

## Key Concepts

**2D Arrays:** `board[row][col]` accesses a specific cell  
**Position Mapping:** Position 5 → row 1, col 1 (center)  
**Win Checking:** 8 possible wins (3 rows + 3 cols + 2 diagonals)  
**User Input:** `scanf("%d", &position)` reads from keyboard

---

## Example Game

```
 1 | 2 | 3
-----------
 4 | 5 | 6
-----------
 7 | 8 | 9

Player X, enter position (1-9): 5

 1 | 2 | 3
-----------
 4 | X | 6
-----------
 7 | 8 | 9

Player O, enter position (1-9): 1
...
```

---

## Next: Lab 3 (MiniDB)
Learn dynamic memory allocation with `malloc` and `free`!
