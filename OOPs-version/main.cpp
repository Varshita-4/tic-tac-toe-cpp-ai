#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int mode;
    int difficulty;

public:
    TicTacToe() {
        resetBoard();
        currentPlayer = 'X';
        mode = 1;
        difficulty = 1;
    }

    void resetBoard() {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = ' ';
    }

    void drawBoard() {
        cout << "\n";
        for (int i = 0; i < 3; ++i) {
            cout << " ";
            for (int j = 0; j < 3; ++j) {
                char symbol = board[i][j];
                if (symbol == ' ') {
                    cout << (char)('1' + i * 3 + j);
                } else {
                    cout << symbol;
                }
                if (j < 2) cout << " | ";
            }
            if (i < 2) cout << "\n-----------\n";
        }
        cout << "\n";
    }

    bool makeMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        if (move < 1 || move > 9 || board[row][col] != ' ')
            return false;
        board[row][col] = currentPlayer;
        return true;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    char checkWinner() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' &&
                board[i][0] == board[i][1] &&
                board[i][1] == board[i][2])
                return board[i][0];
            if (board[0][i] != ' ' &&
                board[0][i] == board[1][i] &&
                board[1][i] == board[2][i])
                return board[0][i];
        }

        if (board[0][0] != ' ' &&
            board[0][0] == board[1][1] &&
            board[1][1] == board[2][2])
            return board[0][0];

        if (board[0][2] != ' ' &&
            board[0][2] == board[1][1] &&
            board[1][1] == board[2][0])
            return board[0][2];

        return ' ';
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    int getRandomMove() {
        srand(time(0));
        int move;
        do {
            move = rand() % 9 + 1;
        } while (!isValidMove(move));
        return move;
    }

    bool isValidMove(int move) {
        int row = (move - 1) / 3;
        int col = (move - 1) % 3;
        return (move >= 1 && move <= 9 && board[row][col] == ' ');
    }

    int minimax(bool isMaximizing) {
        char winner = checkWinner();
        if (winner == 'O') return 10;
        if (winner == 'X') return -10;
        if (isBoardFull()) return 0;

        int best = isMaximizing ? numeric_limits<int>::min() : numeric_limits<int>::max();

        for (int i = 1; i <= 9; ++i) {
            if (isValidMove(i)) {
                int r = (i - 1) / 3;
                int c = (i - 1) % 3;
                board[r][c] = isMaximizing ? 'O' : 'X';
                int score = minimax(!isMaximizing);
                board[r][c] = ' ';
                best = isMaximizing ? max(best, score) : min(best, score);
            }
        }

        return best;
    }

    int getBestMove() {
        int bestVal = numeric_limits<int>::min();
        int bestMove = -1;

        for (int i = 1; i <= 9; ++i) {
            if (isValidMove(i)) {
                int r = (i - 1) / 3;
                int c = (i - 1) % 3;
                board[r][c] = 'O';
                int moveVal = minimax(false);
                board[r][c] = ' ';
                if (moveVal > bestVal) {
                    bestMove = i;
                    bestVal = moveVal;
                }
            }
        }

        return bestMove;
    }

    void playGame() {
        cout << "Tic-Tac-Toe Game (OOP Version)\n";
        cout << "1. Player vs Player\n2. Player vs Computer\nChoose mode: ";
        cin >> mode;

        if (mode == 2) {
            cout << "Select difficulty: 1. Easy  2. Hard: ";
            cin >> difficulty;
        }

        bool gameOver = false;

        while (!gameOver) {
            drawBoard();
            int move;

            if (mode == 1 || currentPlayer == 'X') {
                cout << "Player " << currentPlayer << ", enter your move (1-9): ";
                cin >> move;
            } else {
                cout << "Computer is making a move...\n";
                move = (difficulty == 1) ? getRandomMove() : getBestMove();
            }

            if (!makeMove(move)) {
                cout << "Invalid move. Try again.\n";
                continue;
            }

            char winner = checkWinner();
            if (winner != ' ') {
                drawBoard();
                cout << "Player " << winner << " wins!\n";
                gameOver = true;
            } else if (isBoardFull()) {
                drawBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}
