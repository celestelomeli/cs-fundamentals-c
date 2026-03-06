// TicTacToe Game

#include <stdio.h>

// 3x3 board represented as 2D array of chars
char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the board
void print_board() {
    printf("\n");
    for (int i = 0; i < 3; i++) {  // Loop through each row 
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);  // Print row
        if (i < 2) {  // no dashes
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Place a mark (X or O) at a position (1-9)
void place_mark(int position, char mark) {
    int row = (position - 1) / 3; // calculate row with division
    int col = (position - 1) % 3; // calculate column with modulus
    
    // Update the board at position
    board[row][col] = mark;
}

// Check if someone won (returns 'X', 'O', or ' ' for no winner)
char check_winner() {
    // Check all 3 rows: does row have XXX or OOO?
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];  // Return winner ('X' or 'O')
        }
    }
    
    // Check all 3 columns: does column have XXX or OOO?
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    
    // Check diagonal: top-left to bottom-right 
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    // Check diagonal: top-right to bottom-left 
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    
    return ' ';  // No winner 
}

int main(void) {
    printf("TicTacToe Game\n");
    
    char current_player = 'X';  // X always goes first
    int moves = 0;              // Track number of moves 
    
    // Game loop, keep playing until board is full
    while (moves < 9) {
        // STEP 1: Show the board
        print_board();
        
        // STEP 2: Ask current player what position they want to mark 
        int position;
        printf("Player %c, enter position (1-9): ", current_player);
        scanf("%d", &position);
        
        // STEP 3: Place mark on the board
        place_mark(position, current_player);
        moves++;
        
        // STEP 4: Check if they won
        char winner = check_winner();
        if (winner != ' ') {
            // STEP 5a: If yes show board, announce winner, and stop game
            print_board();
            printf("Player %c wins!\n", winner);
            return 0;
        }
        // STEP 5b: If no keep going
        
        // STEP 6: Switch players 
        if (current_player == 'X') {
            current_player = 'O';
        } else {
            current_player = 'X';
        }
        // STEP 7: Repeat
    }
    
    // STEP 8: Board is full with no winner
    print_board();
    printf("It's a tie!\n");
    
    return 0;
}
