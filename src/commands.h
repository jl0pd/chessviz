//стандартный прототип функции
//int (int* move, char board[8][8]);

int make_move(char board[8][8]);

int* get_move(void);
int* convert(char* string);

void showboard(char board[8][8]);

void swap(int* from_to, char board[8][8]);
void kill(int* move, char board[8][8]);