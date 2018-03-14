struct {
	char index[9][9]
}board;

void board_fill();
int swap(char*);
void get_move(void);
void convert(char *);
void showboard(void);

/* = {
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
*/