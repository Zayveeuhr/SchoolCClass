#include <stdio.h>
#include <stdlib.h>

/*Fuction prototypes*/
void DisplayBoard();
int VerifySelection(int, int);
void CheckForWin();

/*Global veriables*/
char cBoard[8];
char cWhoWon = ' ';
int iCurrentPlayer = 0;


int Main()
{
	int x;
	int iSquareNum = 0;

	for (x = 0; x < 9; x++)
		cBoard[x] = ' ';
	DisplayBoard();
}

/*Fuction definitions begin*/

void DisplayBoard()
{
	system("clear");
	printf("\n\t|\t|\n");
	printf("\t|\t|\n");
	printf("");
}

int VerifySelection(int iSquare, int iPlayer)
{

}

void CheckForWin()
{

}