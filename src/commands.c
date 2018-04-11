#include <stdio.h>
#include <ctype.h>
#include "commands.h"
#include "checks.h"

int make_move(char board[8][8])
{
    int *move = get_move();
    if (move == NULL){
        printf("Incorrect input\n");
        return 0;
    }
    if (check_move_possible(move, board)){
        kill(move, board);
       return 1; //done
   }
   printf("Move not possible!");
    return 0;
}

int* get_move(void)
{
    char move_from_to[4];
    printf("Enter move: ");	
    for (int i = 0; i < 4; i++ )
        move_from_to[i] = tolower(getchar());
    while(getchar() != '\n'); //очистка потока ввода
    return convert(move_from_to);
}

int* convert(char* string)
{
    static int res[4];  
    
    res[0] = string[0] - 'a';
    res[2] = string[2] - 'a';
    
    res[1] = string[1] - '1';
    res[3] = string[3] - '1';

    int count = 1;
    for (int i = 0; i < 4; i++){
        count *= res[i] < 8;
    }

    if (count == 0)
        return NULL;

    return res;
}

void showboard(char board[8][8])
{
    printf("\033[1J"); //очистка консоли
    printf("\033[J");
	printf("\n");
    for (int i = 7; i >= 0; i--)
    {
        printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
        {
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
	printf("   _______________\n");
	printf("   A B C D E F G H\n");
}

void swap(int* move, char board[8][8])
{
    char tmp = board[move[1]][move[0]];
    board[move[1]][move[0]] = board[move[3]][move[2]];
    board[move[3]][move[2]] = tmp;
    showboard(board);
}

void kill(int* move, char board[8][8])
{
    board[move[3]][move[2]] = '.';
    swap(move, board);
}

int update_status(char board[8][8])
{
    int king = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j <8; j++){
            if (tolower(board[i][j]) == 'k'){
                king++;
                if (king == 2)
                return 1;
            } 
        }
    }
    return 0;
}
