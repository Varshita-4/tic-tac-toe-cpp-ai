#include <iostream>
using namespace std;

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void drawBoard(char board[3][3]) {
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



bool makeMove(char board[3][3], int move, char player) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (move < 1 || move > 9 || board[row][col] != ' ')
        return false;
    board[row][col] = player;
    return true;
}

bool isBoardFull(char board[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

char checkWinner(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];
    return ' ';
}
