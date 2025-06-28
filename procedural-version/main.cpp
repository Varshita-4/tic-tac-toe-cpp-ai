#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "ai.h"

using namespace std;

int main() {
    char board[3][3];
    initializeBoard(board);
    int mode, difficulty;
    cout << "Tic-Tac-Toe Game\n";
    cout << "1. Player vs Player\n2. Player vs Computer\nChoose mode: ";
    cin >> mode;

    if (mode == 2) {
        cout << "Select difficulty: 1. Easy  2. Hard: ";
        cin >> difficulty;
    }

    char currentPlayer = 'X';  
    bool gameOver = false;

    while (!gameOver) {
        drawBoard(board);
        int move;

        if (mode == 1 || currentPlayer == 'X') {
            
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
        } else {
            
            cout << "Computer is making a move...\n";
            if (difficulty == 1)
                move = getRandomMove(board);
            else
                move = getBestMove(board, 'O', 'X');
            currentPlayer = 'O';  
        }

        if (!makeMove(board, move, currentPlayer)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        char winner = checkWinner(board);
        if (winner != ' ') {
            drawBoard(board);
            cout << "Player " << winner << " wins!\n";
            gameOver = true;
        } else if (isBoardFull(board)) {
            drawBoard(board);
            cout << "It's a draw!\n";
            gameOver = true;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}
