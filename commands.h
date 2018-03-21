static char board[9][9] = {
		" ABCDEFGH",
		"1rnbqkbnr",
		"2pppppppp",
		"3........",
		"4........",
		"5........",
		"6........",
		"7PPPPPPPP",
		"8RNBQKBNR"
	};

int make_move(void);
int check_move_possible(int* move);
int* get_move(void);
int* convert(char *string);
void showboard(char *board);
void swap(int* from_to);