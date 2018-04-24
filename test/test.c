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
	int coordinates[4];
	////////Проверка хода вперёд (b2b3)////////////
	//b2b3
	coordinates[0] = 1;
	coordinates[1] = 1;
	coordinates[2] = 1;
	coordinates[3] = 2;

	int check1 = check_move_possible(coordinates, board); 

	///////Проверка хода по диагонали (c2d3)//////////
	coordinates[0] = 2;
	coordinates[1] = 1;     //c2d3
	coordinates[2] = 3;
	coordinates[3] = 2;
	
	int check3 = check_move_possible(coordinates, board);

	/////////Проверка хода назад (e2e4 -> e4e3)////////
	coordinates[0] = 4;
	coordinates[1] = 1;     //e2e4
	coordinates[2] = 4;
	coordinates[3] = 3;

	kill(coordinates, board);

	coordinates[0] = 4;
	coordinates[1] = 3;     //e4e3
	coordinates[2] = 4;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board);
	
	//////проверка на возможность рубить пешкой////
	coordinates[0] = 5;
	coordinates[1] = 1;    //f2f4
	coordinates[2] = 5;
	coordinates[3] = 3;

	kill (coordinates, board); 

	coordinates[0] = 6;
	coordinates[1] = 6;    //g7g5
	coordinates[2] = 6;
	coordinates[3] = 4;

	kill (coordinates, board); 

	coordinates[0] = 5;
	coordinates[1] = 3;   //f4g5
	coordinates[2] = 6;
	coordinates[3] = 4;

	int check4 = check_move_possible(coordinates, board); 

	//THEN
	const int expected1 = 0;
	const int expected2 = 1;
	const int expected3 = 1;
	const int expected4 = 0;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
}

CTEST(move_suite, move_rook) // Ход Ладьи
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
	int coordinates[4];

	//Ход вперёд 
	coordinates[0] = 7;
	coordinates[1] = 0;     //h1h4
	coordinates[2] = 7;
	coordinates[3] = 3;
	
	int check1 = check_move_possible(coordinates, board); 
	kill(coordinates, board); 	

	//Ход назад
	coordinates[0] = 7;
	coordinates[1] = 3;     //h4h3
	coordinates[2] = 7;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board); 
	kill(coordinates, board); 	

	//Ход влево
	coordinates[0] = 7;
	coordinates[1] = 2;     //h3g3
	coordinates[2] = 6;
	coordinates[3] = 2;

	int check3 = check_move_possible(coordinates, board); 
	kill(coordinates, board); 	

	//Атака
	coordinates[0] = 6;
	coordinates[1] = 2;     //g3f3
	coordinates[2] = 5;
	coordinates[3] = 2;

	int check4 = check_move_possible(coordinates, board);
	kill(coordinates, board);

	//Ход по диагонале 
	coordinates[0] = 5;
	coordinates[1] = 2;     //f3e4
	coordinates[2] = 4;
	coordinates[3] = 3;

	int check5 = check_move_possible(coordinates, board); 

	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 0;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}

CTEST(move_suite, move_horse) // Ход коня
{
	//GIVEN
	char board[8][8] = {
		"rhbqkbhr",
		"pppppppp",
		"........",
		"........",
		"....P...",
		"........",
		"PPPP.PPP",
		"RHBQKBHR" 
	};
	
	//WHEN

	int coordinates[4];

	//ход Г(перевернутой)
	coordinates[0] = 6;
	coordinates[1] = 0;     //g1f3
	coordinates[2] = 5;
	coordinates[3] = 2;

	int check1 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//ход Г
	coordinates[0] = 1;
	coordinates[1] = 0;     //b1c3
	coordinates[2] = 2;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//Атака
	coordinates[0] = 5;
	coordinates[1] = 2;     //f3e5
	coordinates[2] = 4;
	coordinates[3] = 4;

	int check3 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//ложный ход #1
	coordinates[0] = 4;
	coordinates[1] = 4;     //e5e6
	coordinates[2] = 4;
	coordinates[3] = 5;

	int check4 = check_move_possible(coordinates, board); 

	//ложный ход #2
	coordinates[0] = 4;
	coordinates[1] = 4;     //e5e4
	coordinates[2] = 4;
	coordinates[3] = 3;

	int check5 = check_move_possible(coordinates, board); 
	
	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 1;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
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
	int coordinates[4];

	//ход по диаголи  
	coordinates[0] = 2;
	coordinates[1] = 0;     //c1f4
	coordinates[2] = 5;
	coordinates[3] = 3;

	int check1 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//атака 
	coordinates[0] = 5;
	coordinates[1] = 3;     //f4g3
	coordinates[2] = 6;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board);
	kill(coordinates, board); 

	//атака
	coordinates[0] = 6;
	coordinates[1] = 2;     //g3e5
	coordinates[2] = 4;
	coordinates[3] = 4;

	int check3 = check_move_possible(coordinates, board); 
	kill(coordinates, board); 

	//ложный ход
	coordinates[0] = 4;
	coordinates[1] = 4;     //e5f5
	coordinates[2] = 5;
	coordinates[3] = 4;

	int check4 = check_move_possible(coordinates, board); 

	//ложный ход
	coordinates[0] = 4;
	coordinates[1] = 4;     //e5c5
	coordinates[2] = 2;
	coordinates[3] = 4;

	int check5 = check_move_possible(coordinates, board); 
	

	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 1;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
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
	int coordinates[4];
	//ход вперёд 
	coordinates[0] = 4;
	coordinates[1] = 0;     //e1e2
	coordinates[2] = 4;
	coordinates[3] = 1;

	int check1 = check_move_possible(coordinates, board); 
	kill(coordinates, board); 

	//по диагонали
	coordinates[0] = 4;
	coordinates[1] = 1;     //e2f3
	coordinates[2] = 5;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board);  
	kill(coordinates, board);

	//по диагонали

	coordinates[0] = 5;
	coordinates[1] = 2;     //f3e4
	coordinates[2] = 4;
	coordinates[3] = 3;

	int check3 = check_move_possible(coordinates, board);
	kill(coordinates, board); 

	//атака прямо

	coordinates[0] = 4;
	coordinates[1] = 3;     //e4e5
	coordinates[2] = 4;
	coordinates[3] = 4;

	int check4 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//атака влево

	coordinates[0] = 4;
	coordinates[1] = 4;     //e5d5
	coordinates[2] = 3;
	coordinates[3] = 4;

	int check5 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//ложный ход

	coordinates[0] = 3;
	coordinates[1] = 4;     //d5d3
	coordinates[2] = 3;
	coordinates[3] = 2;

	int check6 = check_move_possible(coordinates, board); 
		
	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 0;
	const int expected5 = 0;
	const int expected6 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
	ASSERT_EQUAL(expected6, check6);
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
	int coordinates[4];

	//ход вперёд 
	coordinates[0] = 3;
	coordinates[1] = 0;     //d1d2
	coordinates[2] = 3;
	coordinates[3] = 1;

	int check1 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//по диагонали 
	coordinates[0] = 3;
	coordinates[1] = 1;     //d2c3
	coordinates[2] = 2;
	coordinates[3] = 2;

	int check2 = check_move_possible(coordinates, board);
	kill(coordinates, board);

	//атака вперед
	coordinates[0] = 2;
	coordinates[1] = 2;     //c3с4
	coordinates[2] = 2;
	coordinates[3] = 3; 

	int check3 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//атака влево
	coordinates[0] = 2;
	coordinates[1] = 3;     //c4b4
	coordinates[2] = 1;
	coordinates[3] = 3; 

	int check4 = check_move_possible(coordinates, board); 
	kill(coordinates, board);

	//проверка на ложный ход
	coordinates[0] = 1;
	coordinates[1] = 3;     //b4b1
	coordinates[2] = 1;
	coordinates[3] = 0; 

	
	int check5 = check_move_possible(coordinates, board); 

	//THEN
	const int expected1 = 0;
	const int expected2 = 0;
	const int expected3 = 0;
	const int expected4 = 0;
	const int expected5 = 1;

	ASSERT_EQUAL(expected1, check1);
	ASSERT_EQUAL(expected2, check2);
	ASSERT_EQUAL(expected3, check3);
	ASSERT_EQUAL(expected4, check4);
	ASSERT_EQUAL(expected5, check5);
}

