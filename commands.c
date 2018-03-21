#include <stdio.h>
#include <ctype.h>
#include "commands.h"

int make_move(void)
{
    int *move = get_move();
    if (check_move_possible(move)){
        swap(move);
        return 1; //done
    }else{
        printf("Move not possible!");
        return 0;
    }
}

int check_move_possible(int* move)
{
    int possible = -1;

    return possible;
}

int* get_move(void)
{
    char move_from_to[4];
    for (int i = 0; i < 4; i++ )
        move_from_to[i] = getchar();
    return convert(move_from_to);
}

int* convert(char *string)
{
    static int res[4];
    for (int i = 1; i <= 3; i+=2){
        switch (tolower(string[i])){
            case 'a':
                res[i]=1;
                break;
            case 'b':
                res[i]=2;
                break;
            case 'c':
                res[i]=3;
                break;
            case 'd':
                res[i]=4;
                break;
            case 'e':
                res[i]=5;
                break;
            case 'f':
                res[i]=6;
                break;
            case 'g':
                res[i]=7;
                break;
            case 'h':
                res[i]=8;
                break;
        }
    }
    return res;
}

void showboard(char *board)
{
    for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf(" %c", board[i][j]);
            }
            printf("\n");
        }
}

void swap(int* from_to)
{
    char tmp = board[from_to[0]][from_to[1]];
    board[from_to[0]][from_to[1]] = board[from_to[2]][from_to[3]];
    board[from_to[2]][from_to[3]] = tmp;
}