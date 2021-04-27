#pragma once
#define ROW 3
#define COL 3
#include<stdlib.h>
#include<time.h>
void ClearBoard(char board[ROW][COL], int row, int col);
void DisplayBoard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMover(char board[ROW][COL], int row, int col);
char is_win(char board[ROW][COL], int row, int col);
int is_full(char board[ROW][COL], int row, int col);