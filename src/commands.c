#include <stdio.h>
#include <ctype.h>
#include "commands.h"

int make_move(char board[8][8])
{
    int *move = get_move();
    if (check_move_possible(move, board)){
        swap(move, board);
        return 1; //done
    }else{
        printf("Move not possible!");
        return 0;
    }
}
int check_pawn(int* move, char board[8][8])
{
    int can_back = 0;
    int possible = 0;
    if (   check_column(move, can_back, board) 
        || check_pawn_kill(move, board)){
        possible = 1;
        }
    return possible;
}

int check_pawn_kill(int* move, char board[8][8])
{
    int possible = 0;
    return possible;
}

int check_bishop(int* move, char board[8][8])
{
    int possible = 0;
    if (check_diag(move, board)){
        possible = 1;
    }
    return possible;
}

int check_rook(int* move, char board[8][8])
{
    int possible = 0;
    int can_back = 1;
    if (check_row(move, board) || check_column(move, can_back, board)){
        possible = 1;
    }
    return possible;
}

int check_queen(int* move, char board[8][8])
{
    int possible = 0;
    int can_back = 1;
    if (   check_column(move, can_back, board) 
        || check_diag(move, board) 
        || check_row(move, board)){
        possible = 1;
    }
    return possible;
}

int check_knight(int* move, char board[8][8])
{
    int possible = 0;
    if ((move, board)){
        possible = 1;
    }
    return possible;
}

int check_king(int* move, char board[8][8])
{
    int possible = 0;
    if ((move, board)){
        possible = 1;
    }
    return possible;
}

int check_column(int *move, int can_back, char board[8][8])
{
    int possible = 0;
    int i;
    if (move[0] == move[3]){
        if (!can_back){
            if (tolower(board[move[0]][move[1]]) == board[move[0]][move[1]]){ //проверка цвета 1- белый, 0- чёрный
                for (i = move[1]; i <= move[3]; i++){
                    
                }
            }else{
                for (i = move[3]; i >= move[1]; i--){
                    
                }
            }
        }else{
            for (i = move[1]; i <= move[3]; i++){
                
            }
        }
    }
    return possible;
}

int check_move_possible(int *move, char board[8][8])
{
    int possible = -1;
    switch(tolower(board[move[0]][move[1]])){
/*    
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
*/
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