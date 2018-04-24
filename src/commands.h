//стандартный прототип функции
//int (int* move, char board[8][8]);

#ifndef COMMANDS_H
#define COMMANDS_H

int make_move(char board[8][8]);

int* get_move(void);
int* convert(char* string);

void showboard(char board[8][8]);

void swap(int* from_to, char board[8][8]);
void kill(int* move, char board[8][8]);

int update_status(char board[8][8]);
#endif
