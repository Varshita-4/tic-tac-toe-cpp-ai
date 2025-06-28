#ifndef GAME_H
#define GAME_H

void initializeBoard(char board[3][3]);
void drawBoard(char board[3][3]);
bool makeMove(char board[3][3], int move, char player);
bool isBoardFull(char board[3][3]);
char checkWinner(char board[3][3]);

#endif
