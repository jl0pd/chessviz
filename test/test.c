#include <stdio.h>
#include <ctest.h>
#include "commands.h"
#include "checks.h"

CTEST(move_suite, move_pawn) // Ход пешки 
{	
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"pppppppp",
		"........",
		"........",
		"........",
		"........",
		"PPPPPPPP",
		"RHBQKBHR" 
	};
	
	//WHEN
	int check[4];
	////////Проверка хода вперёд (b2b3)////////////

	int move1[4] = {1,1,1,2}; //b2b3

	check[0] = check_move_possible(move1, board); 

	///////Проверка хода по диагонали (c2d3)//////////
	
	int move2[4] = {2,1,3,2}; //c2d3

	check[1] = check_move_possible(move2, board);

	/////////Проверка хода назад (e2e4 -> e4e3)////////

	int move3[4] = {4,1,4,3}; //e2e4

	kill(move3, board);

	int move4[4] = {4,3,4,2}; //e4e3
	
	check[2] = check_move_possible(move4, board);
	
	//////проверка на возможность рубить пешкой////

	int move5[4] = {5,1,5,3}; //f2f4

	kill (move5, board); 

	int move6[4] = {6,6,6,4}; //g7g5

	kill (move6, board); 

	int move7[4] = {5,3,6,4}; //f4g5

	check[3] = check_move_possible(move7, board); 
//////
	int expected[] = {1, 0, 0, 1};

	for(int i = 0; i < 4; i++){
		ASSERT_EQUAL(expected[i], check[i]);
	}
}

CTEST(move_suite,_rook) // Ход Ладьи
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"........",
		".....P..",
		"........",
		"........",
		"........",
		"PPPPP.PP",
		"RHBQKBHR" 
	};
	
	
	//WHEN
	int check[10];

	//Ход вперёд 
	
	int move1[] = {7,0,7,3}; //h1h4

	check[0] = check_move_possible(move1, board); 
	kill(move1, board); 	

	//Ход назад

	int move2[] = {7,3,7,2}; //h4h3

	check[1] = check_move_possible(move2, board); 
	kill(move2, board); 	

	//Ход влево

	int move3[] = {7,2,6,2}; //h3g3

	check[2] = check_move_possible(move3, board); 
	kill(move3, board); 	

	//Атака

	int move4[] = {6,2,5,2}; //g3f3

	check[3] = check_move_possible(move4, board);
	kill(move4, board);

  //Ход по диагонали
	int move5[] = {5,2,4,3}; //f3e4

	check[4] = check_move_possible(move5, board); 

	//THEN

	int expected[] = {1,1,1,1,0};

	for (int i = 0; i < 5; i++){
		ASSERT_EQUAL(expected[i], check[i]);
}

}

CTEST(move_suite, move_horse) // Ход коня
{
	//GIVEN
	char board[8][8] = {
		"rnbqkbnr",
		"pppppppp",
		"........",
		"........",
		"....P...",
		"........",
		"PPPP.PPP",
		"RHBQKBHR" 
	};
	
	//WHEN

	int check[5];

	//ход Г(перевернутой)

	int move1[] = {6,0,5,2}; //g1f3

	check[0] = check_move_possible(move1, board); 
	kill(move1, board);

	//ход Г

	int move2[] = {1,0,2,2}; //b1c3

	check[1] = check_move_possible(move2, board); 
	kill(move2, board);

	//Атака

	int move3[] = {5,2,4,4}; //f3e5
	check[2] = check_move_possible(move3, board); 
	kill(move3, board);

	//ложный ход #1

	int move4[] = {4,4,4,5}; //e5e6
	check[3] = check_move_possible(move4, board); 

	//ложный ход #2
	int move5[] = {4,4,4,3}; //e5e3
	check[4] = check_move_possible(move5, board); 

	//THEN

	int expected[] = {1,1,1,0,0};
	for (int i = 0; i < 5; i++){
		ASSERT_EQUAL(expected[i], check[i]);
	}
}

CTEST(move_suite, move_bishop) // Ход Cлона
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"........",
		"......P.",
		"........",
		"....P...",
		"........",
		"PPPP.P.P",
		"RHBQKBHR" 
	};
	
	//WHEN
	int check[10];

	//ход по диаголи  

	int move1[] = {2,0,5,3}; //c1f4
	check[0] = check_move_possible(move1, board); 
	kill(move1, board);

	//атака 

	int move2[] = {5,3,6,2}; //f4g3
	check[1] = check_move_possible(move2, board);
	kill(move2, board); 

	//атака

	int move3[] = {6,2,4,4}; //g3e5
	check[2] = check_move_possible(move3, board); 
	kill(move3, board); 

	//ложный ход

	int move4[] = {4,4,5,4}; //e5f5
	check[3] = check_move_possible(move4, board); 

	//ложный ход

	int move5[] = {4,4,2,4}; //e5c5
	check[4] = check_move_possible(move5, board); 
	

	//THEN

	int expected[] = {1,1,1,0,0};
	for (int i = 0; i < 5; i++){
		ASSERT_EQUAL(expected[i], check[i]);
	}
}

CTEST(move_suite, move_king) // Ход короля
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"........",
		"........",
		"........",
		"...PP...",
		"........",
		"PPP..PPP",
		"RHBQKBHR" 
	};
	
	//WHEN
	
	int check[10];
	
	//ход вперёд

	int move1[] = {4,0,4,1}; //e1e2
	check[0] = check_move_possible(move1, board); 
	kill(move1, board); 

	//по диагонали

	int move2[] = {4,1,5,2}; //e2f3
	check[1] = check_move_possible(move2, board);  
	kill(move2, board);

	//по диагонали

	int move3[] = {5,2,4,3}; //f3e4
	check[2] = check_move_possible(move3, board);
	kill(move3, board); 

	//атака прямо

	int move4[] = {4,3,4,4}; //e4e5
	check[3] = check_move_possible(move4, board); 
	kill(move4, board);

	//атака влево

	int move5[] = {4,4,3,4}; //e5d5
	check[4] = check_move_possible(move5, board); 
	kill(move5, board);

	//ложный ход

	int move6[] = {3,4,3,2}; //d5d3
	check[5] = check_move_possible(move6, board); 
		
	//THEN
	int expected[] = {1,1,1,1,1,0};
	for (int i = 0; i < 5; i++){
		ASSERT_EQUAL(expected[i], check[i]);
	}
}


CTEST(move_suite, move_queen) // Ход королева
{
	//GIVEN
	char board[8][8] = {
		"r.bqkbhr",
		".h......",
		"........",
		".PP.....",
		"........",
		"........",
		"P..PPPPP",
		"RHBQKBHR" 
	};
	
	//WHEN

	int check[5];

	//ход вперёд

	int move1[] = {3,0,3,1}; //d1d2

	check[0] = check_move_possible(move1, board); 
	kill(move1, board);

	//по диагонали

	int move2[] = {3,1,2,2}; //d2c3
	check[1] = check_move_possible(move2, board);
	kill(move2, board);

	//атака вперед

	int move3[] = {2,2,2,3}; //c3c4
	check[2] = check_move_possible(move3, board); 
	kill(move3, board);

	//атака влево

	int move4[] = {2,3,1,3}; //c4b4
	check[3] = check_move_possible(move4, board); 
	kill(move4, board);

	//проверка на ложный ход

	int move5[] = {1,3,1,0}; //b4b1

	check[4] = check_move_possible(move5, board); 

	//THEN

	int expected[] = {1,1,1,1,0};
	for (int i = 0; i < 5; i++){
		ASSERT_EQUAL(expected[i], check[i]);
	}
}
