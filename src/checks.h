//стандартный прототип функции
//int (int* move, char board[8][8]);

#ifndef CHECKS_H
#define CHECKS_H

int check_move_possible(int* move, char board[8][8]);

int check_pawn(int* move, char board[8][8]);
int check_bishop(int* move, char board[8][8]);
int check_rook(int* move, char board[8][8]);
int check_queen(int* move, char board[8][8]);
int check_knight(int* move, char board[8][8]);
int check_king(int* move, char board[8][8]);

int check_row_and_col(int* move, char board[8][8]);
int check_diag(int* move, char board[8][8]);

#endif
