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

int check_column(int *move, int can_back)
{
    if (!can_back){
        if (tolower(board[move[0]][move[1]]) == board[move[0][move[1]]){ //проверка цвета

        }
    }
}

int check_move_possible(int *move)
{
    int possible = -1;
    switch(tolower(board[move[0]][move[1]])){
    case 'r':
        possible = check_rook(move);
        break;
    case 'n':
        possible = check_knight(move);
        break;
    case 'b':
        possible = check_bishop(move);
        break;
    case 'q':
        possible = check_queen(move);
        break;
    case 'k':
        possible = check_king(move);
        break;
    case 'p':
        possible = check_pawn(move);
        break;
    default:
        possible = 0;
        break;
    }
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
    
    for (int i = 0; i <= 2; i+=2)
        res[i] = string[i] - 'a';
    
    for (int i = 1; i <= 3; i+=2)
        res[i] = string[i] - '1';

    return res;
}

void showboard(char *board)
{
    char character = 'A';
    printf("12345678");
    for (int i = 0; i < 8; i++)
        {
            printf("%c", character++);
            for (int j = 0; j < 8; j++)
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