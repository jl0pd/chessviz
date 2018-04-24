#include <ctype.h>
#include <stdio.h>
#include "checks.h"

int check_pawn(int* move, char board[8][8])
{
    if(board[move[1]][move[0]] == 'p' && (board[move[3]][move[2]] == '.')) {
        if(((move[0] - move[2]) == 0) && ((move[3] - move[1]) < 0)) {
            return 0;
        }
        if(((move[0] - move[2]) == 0) && ((move[3] - move[1]) > 2)) {
            return 0;
        }
        if(((move[2] - move[0]) != 0) && ((move[3] - move[1]) > 0)) {
            return 0;
        }
    }

    if(board[move[1]][move[0]] == 'P' && (board[move[3]][move[2]] == '.')) {
       	if(((move[0] - move[2]) == 0) && ((move[1] - move[3]) < 0)) {
       		return 0;
       	}
       	if(((move[0] - move[2]) == 0) && ((move[1] - move[3]) > 2)) {
       		return 0;
       	}
       	if(((move[2] - move[0]) != 0) && ((move[3] - move[1]) < 0)) {
        	return 0;
        }
    }
    if (board[move[1]][move[0]] == 'p' 
    || board[move[1]][move[0]] == 'P') {

    	if((board[move[1]][move[0]] == 'p' 
            && board[move[3]][move[2]] == 'P')
        || (board[move[1]][move[0]] == 'P' 
            && board[move[3]][move[2]] == 'p')) { 
	   
	    	if (((move[0] + 1) == move[2]) 
            && ((move[1] - 1) == move[3]))
	        	return 1;
	
        	if (((move[0] + 1) == move[2]) 
            && ((move[1] + 1) == move[3]))
	        	return 1;
	
        	if (((move[0] - 1) == move[2]) 
            && ((move[1] - 1) == move[3]))
	        	return 1;
	
        	if (((move[0] - 1) == move[2]) 
            && ((move[1] + 1) == move[3]))
	        	return 1;
        }


        if (board[move[3]][move[2]] == '.') {
            if (move[1] == 1
            && move[3] < 4
            && move[3] > 1
            && move[0] == move[2]
            && board[move[1]+1][move[0]] == '.')
                return 1;

            if (move[1] == 6
            && move[3] > 3
            && move[3] < 6
            && move[0] == move[2]
            && board[move[1]-1][move[0]] == '.')
                return 1;

            if (board[move[1]][move[0]] == 'p'
            && move[1] != 6
            && move[3] == (move[1] - 1)
            && move[0] == move[2]) 
                return 1;

            if (board[move[1]][move[0]] == 'P'
            && move[1] != 1
            && move[3] == (move[1] + 1)
            && move[0] == move[2])
                return 1;
        }
        return 0;
    }    
    return 0;
}

int check_bishop(int* move, char board[8][8])
{
    return check_diag(move, board);
}

int check_rook(int* move, char board[8][8])
{
    return check_row_and_col(move, board);
}

int check_queen(int* move, char board[8][8])
{
    return check_row_and_col(move, board) 
        + check_diag(move, board);
}

int check_knight(int* move, char board[8][8])
{
    if(((move[3] == (move[1] + 1)) 
        || (move[3] == (move[1] - 1)))
    && (move[2] == (move[0] + 2) 
    || (move[2] == (move[0] - 2))))
        return 1;
    
    if(((move[3] == (move[1] + 2)) 
        || (move[3] == (move[1] - 2)))
    && ((move[2] == (move[0] + 1))
    || (move[2] == (move[0] - 1))))
        return 1;
    
    return 0;
}

int check_king(int* move, char board[8][8])
{
    if (((move[3] - move[1] == 1) || (move[1] - move[3] == 1))
    && (move[2] == move[0]))
        return 1;
    
    if ((move[1] == move[3]) && ((move[0] - move[2] == 1)
    || (move[2] - move[0]) == 1))
        return 1;
    
    if ((move[3] - move[1] == 1) && ((move[2] - move[0] == 1)
    || (move[0] - move[2] == 1)))
        return 1;
    
    if ((move[1] - move[3] == 1) && ((move[2] - move[0] == 1)
    || (move[0] - move[2] == 1)))
        return 1;
    
    return 0;
}

int check_row_and_col(int* move, char board[8][8])
{
    int i;
    if(((move[0] - move[2]) != 0) && ((move[1] - move[3]) != 0)) {
        return 1;
    }    
    if (move[0] == move[2] && move[1] < move[3]) { 
        for (i = move[1] + 1; i < move[3]; i++)
            if (board[i][move[0]] != '.')
                return 1;
        return 0;
    }
    if (move[0] == move[2] && move[1] > move[3]) { 
        for (i = move[3] + 1; i < move[1]; i++)
            if (board[i][move[0]] != '.')
                return 1;
        return 0;
    }
    if (move[0] < move[2] && move[1] == move[3]) {
        for (i = move[0] + 1; i < move[2]; i++)
            if (board[move[1]][i] != '.')
                return 1;
        return 0;
    }
    if (move[0] > move[2] && move[1] == move[3]) {
        for (i = move[2] + 1; i < move[0]; i++)
            if (board[move[1]][i] != '.')
                return 1;
        return 0;
    }
    return 0;
}

int check_diag(int* move, char board[8][8])
{
    int i, j;
    if((move[1] - move[3]) == 0 && (move[0] - move[2]) != 0) {
        return 0;
    }
    if ((move[1] - move[3]) == (move[0] - move[2])) {
        i = move[1] - 1;
        j = move[0] - 1;
        while (i > move[3] && j > move[2]) {
            if(board[i][j] != '.')
                return 0;
            i--;
            j--;
        }
        return 1;
    }    
    if ((move[1] - move[3]) == (move[2] - move[0])) {
        i = move[1] - 1;
        j = move[0] + 1;
        while (i > move[3] && j < move[2]) {
            if(board[i][j] != '.')
                return 0;
            i--;
            j++;
        }
        return 1;
    }
    if ((move[3] - move[1]) == (move[0] - move[2])) {
        i = move[1] + 1;
        j = move[0] - 1;
        while (i < move[3] && j > move[2]) {
            if(board[i][j] != '.')
                return 0;
            i++;
            j--;
        }
        return 1;
    }  
    if ((move[3] - move[1]) == (move[2] - move[0])) {
        i = move[1] + 1;
        j = move[0] + 1;
        while (i < move[3] && j < move[2]) {
            if(board[i][j] != '.')
                return 0;
            i++;
            j++;
        }
        return 1;
    }  
    return 0;
}

int check_move_possible(int* move, char board[8][8])
{
    switch(tolower(board[move[1]][move[0]])){   
    case 'r':
        return check_rook(move, board);
        break;
    case 'n':
        return check_knight(move, board);
        break;
    case 'b':
        return check_bishop(move, board);
        break;
    case 'q':
        return check_queen(move, board);
        break;
    case 'k':
        return check_king(move, board);
        break;
    case 'p':
        return check_pawn(move, board);
        break;
    default:
        return 0;
        break;
    }
}
