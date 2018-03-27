#include <stdio.h>
#include <ctype.h>
#include "commands.h"
#include "checks.h"

int make_move(char board[8][8])
{
    int *move = get_move();
    if (check_move_possible(move, board)){
        swap(move, board);
        return 1; //done
    }
    printf("Move not possible!");
    return 0;

}

int* get_move(void)
{
    char move_from_to[4];
    for (int i = 0; i < 4; i++ )
        move_from_to[i] = getchar();
    return convert(move_from_to);
}

int* convert(char* string)
{
    static int res[4];
    
    for (int i = 0; i <= 2; i+=2)
        res[i] = string[i] - 'a';
    
    for (int i = 1; i <= 3; i+=2)
        res[i] = string[i] - '1';

    return res;
}

void showboard(char board[8][8])
{
    printf("\033[2J"); //очистка консоли

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

void swap(int* from_to, char board[8][8])
{
    char tmp = board[from_to[0]][from_to[1]];
    board[from_to[0]][from_to[1]] = board[from_to[2]][from_to[3]];
    board[from_to[2]][from_to[3]] = tmp;
}

void kill(int* move, char board[8][8])
{
    board[move[2]][move[3]] = '.';
    swap(move, board);
}