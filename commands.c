#include "commands.h"

void showboard(void){
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf(" %c", board[i][j]);
            }
            printf("\n");
        }
}

int swap(char* from_to)
{
    char tmp = board->index[from_to[0]][from_to[1]];
    board->index[from_to[0]][from_to[1]] = board->index[from_to[2]][from_to[3]];
    board->index[from_to[2]][from_to[3]] = tmp;
}

void get_move(void)
{
    char move_from_to[4];
    for (int i = 0; i < 4; i++ )
        move_from_to[i] = getc();
    convert(move_from_to);
    make_move(move_from_to);
}

void convert(char *string)
{
    for (int i = 1; i <= 3; i+=2){
        switch (tolower(string[i])){
            case 'a':
                string[i]=1;
                break;
            case 'b':
                string[i]=2;
                break;
            case 'c':
                string[i]=3;
                break;
            case 'd':
                string[i]=4;
                break;
            case 'e':
                string[i]=5;
                break;
            case 'f':
                string[i]=6;
                break;
            case 'g':
                string[i]=7;
                break;
            case 'h':
                string[i]=8;
                break;
        }
    }
}