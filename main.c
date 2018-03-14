#include <stdio.h>
#include "commands.h"

int main()
{
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
	showboard();
}
