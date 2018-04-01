#include <stdio.h>
#include "commands.h"
//#include "board.h"

int main()
{
	char input[8][8] = {
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
	char board[8][8];

	for (int i = 0; i < 8; i ++){
		for(int j = 0; j < 8; j++){
			board[i][j] = input[i][j];
		}
	}

	int game_status = 1;

	showboard(board);

	while(game_status)
	{
		switch(game_status)
		{
		case 0:
			printf("Game was ended\n");
			return 0;
		default:
			make_move(board);
			game_status = update_status(board);
		}
	}
	printf("Game was ended\n");
	return 0;
}