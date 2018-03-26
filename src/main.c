#include <stdio.h>
//#include "commands.h"
//#include "board.h"
void showboard(char board[8][8])
{
    char character = 'H';

	printf("\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("%c|", character--);
        for (int j = 0; j < 8; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
	printf("   _______________\n");
	printf("   1 2 3 4 5 6 7 8\n");

}

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
