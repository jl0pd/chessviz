//стандартный прототип функции
//int (int* move, char board[8][8]);


int make_move(char board[8][8]);

int check_move_possible(int* move, char board[8][8]);

int check_pawn(int* move, char board[8][8]);
int check_pawn_kill(int* move, char board[8][8]);
int check_bishop(int* move, char board[8][8]);
int check_rook(int* move, char board[8][8]);
int check_queen(int* move, char board[8][8]);
int check_knight(int* move, char board[8][8]);
int check_king(int* move, char board[8][8]);

int check_row(int* move, char board[8][8]);
int check_column(int* move, int can_back, char board[8][8]);
int check_diag(int* move, char board[8][8]);

int* get_move(void);
int* convert(char* string);

void showboard(char board[8][8]);

void swap(int* from_to, char board[8][8]);
void kill(int* move, char board[8][8]);