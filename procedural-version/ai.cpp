#include<bits/stdc++.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "ai.h"
#include "game.h"
using namespace std;

int getRandomMove(char board[3][3]) {
    srand(time(0));
    int move;
    do {
        move = rand() % 9 + 1;
    } while (board[(move - 1) / 3][(move - 1) % 3] != ' ');
    return move;
}

int minimax(char board[3][3], bool isMax, char aiPlayer, char humanPlayer) {
    char winner = checkWinner(board);
    if (winner == aiPlayer) return 10;
    if (winner == humanPlayer) return -10;
    if (isBoardFull(board)) return 0;

    int best = isMax ? numeric_limits<int>::min() : numeric_limits<int>::max();

    for (int i = 1; i <= 9; ++i) {
        int r = (i - 1) / 3, c = (i - 1) % 3;
        if (board[r][c] == ' ') {
            board[r][c] = isMax ? aiPlayer : humanPlayer;
            int score = minimax(board, !isMax, aiPlayer, humanPlayer);
            board[r][c] = ' ';
            best = isMax ? max(best, score) : min(best, score);
        }
    }
    return best;
}

int getBestMove(char board[3][3], char aiPlayer, char humanPlayer) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;

    for (int i = 1; i <= 9; ++i) {
        int r = (i - 1) / 3, c = (i - 1) % 3;
        if (board[r][c] == ' ') {
            board[r][c] = aiPlayer;
            int moveVal = minimax(board, false, aiPlayer, humanPlayer);
            board[r][c] = ' ';
            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    return bestMove;
}
