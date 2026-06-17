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


int main()
{
	int x;
	int iSquareNum = 0;

	for (x = 0; x < 9; x++)
		cBoard[x] = ' ';
	DisplayBoard();

	while (cWhoWon == ' ')
	{
		printf("\n%c\n", cWhoWon);
		
		if (iCurrentPlayer == 1 || iCurrentPlayer == 0)
		{
			printf("\nPlayer X\n");
			printf("Enter an avaliable square number (1-9): ");
			scanf_s("%d", &iSquareNum);
			
			if (VerifySelection(iSquareNum, iCurrentPlayer) == 1)
			{
				iCurrentPlayer = 1;
			}
			else
			{
				iCurrentPlayer = 2;
			}
		}
		else
		{
			printf("\nPlayer O\n");
			printf("Enter an avaliable square number (1-9): ");
			scanf_s("%d", &iSquareNum);

			if (VerifySelection(iSquareNum, iCurrentPlayer) == 1)
			{
				iCurrentPlayer = 2;
			}
			else
			{
				iCurrentPlayer = 1;
			}
		}

		DisplayBoard();
		CheckForWin();
	}
}

/*Fuction definitions begin*/

void DisplayBoard()
{
	system("clear");
	printf("\n\t|\t|\n");
	printf("\t|\t|\n");
	printf("%c\t|%c\t|%c\n", cBoard[0], cBoard[1], cBoard[2]);
	printf("- - - - | - - - | - - - -\n");
	printf("\t|\t|\n");
	printf("%c\t|%c\t|%c\n", cBoard[3], cBoard[4], cBoard[5]);
	printf("- - - - | - - - | - - - -\n");
	printf("\t|\t|\n");
	printf("%c\t|%c\t|%c\n", cBoard[6], cBoard[7], cBoard[8]);
	printf("\t|\t|\n");
}

int VerifySelection(int iSquare, int iPlayer)
{
	if (cBoard[iSquare - 1] == ' ' && (iPlayer == 1 || iPlayer == 0))
	{
		cBoard[iSquare - 1] = 'X';
		return 0;
	}
	else if (cBoard[iSquare - 1] == ' ' && iPlayer == 2)
	{
		cBoard[iSquare - 1] = 'O';
		return 0;
	}
	else
		return 1;
}

void CheckForWin()
{
	int catTotal = 0;
	int x;

	if (cBoard[0] == 'X' && cBoard[1] == 'X' && cBoard[2] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[3] == 'X' && cBoard[4] == 'X' && cBoard[5] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[6] == 'X' && cBoard[7] == 'X' && cBoard[8] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[0] == 'X' && cBoard[3] == 'X' && cBoard[6] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[1] == 'X' && cBoard[4] == 'X' && cBoard[7] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[2] == 'X' && cBoard[5] == 'X' && cBoard[8] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[0] == 'X' && cBoard[4] == 'X' && cBoard[8] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[2] == 'X' && cBoard[4] == 'X' && cBoard[6] == 'X')
	{
		cWhoWon = 'X';
	}
	else if (cBoard[0] == 'O' && cBoard[1] == 'O' && cBoard[2] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[3] == 'O' && cBoard[4] == 'O' && cBoard[5] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[6] == 'O' && cBoard[7] == 'O' && cBoard[8] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[0] == 'O' && cBoard[3] == 'O' && cBoard[6] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[1] == 'O' && cBoard[4] == 'O' && cBoard[7] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[2] == 'O' && cBoard[5] == 'O' && cBoard[8] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[0] == 'O' && cBoard[4] == 'O' && cBoard[8] == 'O')
	{
		cWhoWon = 'O';
	}
	else if (cBoard[2] == 'O' && cBoard[4] == 'O' && cBoard[6] == 'O')
	{
		cWhoWon = 'O';
	}

	if (cWhoWon == 'X')
	{
		printf("\nX Wins!\n");
		return;
	}
	if (cWhoWon == 'O')
	{
		printf("\nO Wins!\n");
		return;
	}

	// check for cat /draw game
	for (x = 0; x < 9; x++)
	{
		if (cBoard[x] != ' ')
			catTotal += 1;
	}
	if (catTotal == 9)
	{
		cWhoWon == 'C';
		printf("\nCAT Game!\n");
		return;
	}
}