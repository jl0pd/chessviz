#include <stdio.h>
#include "commands.h"
//#include "board.h"

int main()
{
	
	static char board[8][8] = {
		"rnbqkbnr", // 1 
		"pppppppp", // 2
		"........", // 3
		"........", // 4
		"........", // 5
		"........", // 6
		"PPPPPPPP", // 7
		"RNBQKBNR"  // 8
       //ABCDEFGH
	};

	showboard(board);
}
