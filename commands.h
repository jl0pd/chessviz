#include "board.h"

int make_move(void);
int check_move_possible(int* move);
int* get_move(void);
int* convert(char *string);
void showboard(char *board);
void swap(int* from_to);