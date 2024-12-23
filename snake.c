#include <stdio.h>

char board[3][3]; // 3x3 Tic-Tac-Toe board
char currentPlayer = 'X'; // 'X' starts the game

// Function to initialize the board with empty spaces
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the current state of the board
void printBoard() {
    printf("  0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d", i);
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf(" ---+---+---\n");
    }
}

// Function to check if a player has won
int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return 1;
    }
    // Check diagonals
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return 1;

    return 0;
}

// Function to check if the game is a draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // If there's an empty space, the game is not a draw
            }
        }
    }
    return 1; // If no empty spaces, it's a draw
}

// Function to switch between players
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to make a move
int makeMove(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;
        return 1; // Valid move
    } else {
        printf("Invalid move! Try again.\n");
        return 0; // Invalid move
    }
}

int main() {
    int row, col;
    initializeBoard();

    while (1) {
        printBoard();

        printf("Player %c, enter your move (row and column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (makeMove(row, col)) {
            if (checkWin()) {
                printBoard();
                printf("Player %c wins!\n", currentPlayer);
                break;
            } else if (checkDraw()) {
                printBoard();
                printf("It's a draw!\n");
                break;
            }

            switchPlayer(); // Switch to the other player
        }
    }

    return 0;
}
