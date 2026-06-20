#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX_GAMES 20
#define TEAMS 2

void GetGameResults(int iScores[][TEAMS], int* pEffectiveSize);
void CalculateCurrentRecord(int iScores[][TEAMS], int iTeamWins[], int iTeamLoses[], int* pEffectiveSize, int* pTies);
void DisplayWonGames(int iScores[][TEAMS], int* pEffectiveSize);
void SortScores(int iScores[][TEAMS], int* pEffectiveSize);

int main()
{
	bool bQuit = false;
	char cResponse = ' ';
	int iScores[MAX_GAMES][TEAMS] = { 0 };
	int iEffectiveSize = 0;
	int iTeamWins[TEAMS] = { 0 };
	int iTeamLoses[TEAMS] = { 0 };
	int iTies = 0;
	int ch;



	do
	{
		printf("\n***********************************************\n");
		printf("**                MAIN MENU                  **\n");
		printf("***********************************************\n");

		printf("\nA) Enter game results\n");
		printf("B) Current Record\n");
		printf("C) Display ALL results from all games WON\n");
		printf("D) Display ALL results ordered by opponent score from low to high.\n");
		printf("E) Quit\n");

		printf("\nEnter choice: ");
		scanf_s(" %c", &cResponse, 1);

		while ((ch = getchar()) != '\n' && ch != EOF) {} /*Prevent extra characters from entering a loop switch*/

		if (isdigit(cResponse))
		{
			printf("\nThat was not a valid input. Please try again!!!\n");
			continue;
		}

		// Convert response to lower case to lowercase
		char clowerResponse = tolower(cResponse);

		switch (clowerResponse)
		{
		case 'a':
			GetGameResults(iScores, &iEffectiveSize);
			break;
		case 'b':
			CalculateCurrentRecord(iScores, iTeamWins, iTeamLoses, &iEffectiveSize, &iTies);
			printf("\nCurrent Record: ");
			printf("\nTeam 1 - WINS: %d  LOSES: %d\n", iTeamWins[TEAMS - 2], iTeamLoses[TEAMS - 2]);
			printf("Team 2 - WINS: %d  LOSES: %d\n", iTeamWins[TEAMS - 1], iTeamLoses[TEAMS - 1]);
			printf("Total ties: %d\n", iTies);
			break;
		case 'c':
			DisplayWonGames(iScores, &iEffectiveSize);
			break;
		case 'd':
			SortScores(iScores, &iEffectiveSize);
			break;
		case 'e':
			bQuit = true;
			break;
		default:
			printf("Sorry that was not a valid input! Please try again.\n");
			break;
		}

	} while (bQuit != true);

	return 0;
}

void GetGameResults(int iScores[][TEAMS], int* pEffectiveSize)
{
	int iReponse = 0;

	if (*pEffectiveSize >= MAX_GAMES)
	{
		printf("\nGame has ended.\n");
		return;
	}

	system("cls");

	printf("\nEnter Team1 score: ");
	scanf_s(" %d", &iReponse);

	iScores[*pEffectiveSize][TEAMS - 2] = iReponse;

	printf("\nEnter Team2 score: ");
	scanf_s(" %d", &iReponse);

	iScores[*pEffectiveSize][TEAMS - 1] = iReponse;

	(*pEffectiveSize)++;

	system("cls");
}

void CalculateCurrentRecord(int iScores[][TEAMS], int iTeamWins[], int iTeamLoses[], int* pEffectiveSize, int* pTies)
{
	iTeamWins[TEAMS - 2] = 0;
	iTeamLoses[TEAMS - 1] = 0;
	iTeamWins[TEAMS - 1] = 0;
	iTeamLoses[TEAMS - 2] = 0;
	*pTies = 0;

	for (int i = 0; i < *pEffectiveSize; i++)
	{
		if (iScores[i][TEAMS - 2] > iScores[i][TEAMS - 1])
		{
			iTeamWins[TEAMS - 2] += 1;
			iTeamLoses[TEAMS - 1] += 1;
		}
		else if (iScores[i][TEAMS - 2] < iScores[i][TEAMS - 1])
		{
			iTeamWins[TEAMS - 1] += 1;
			iTeamLoses[TEAMS - 2] += 1;
		}
		else
		{
			(*pTies)++;
		}
	}
}

void DisplayWonGames(int iScores[][TEAMS], int* pEffectiveSize)
{
	printf("\nTeam 1 win record: \n");
	for (int i = 0; i < *pEffectiveSize; i++)
	{
		if (iScores[i][TEAMS - 2] > iScores[i][TEAMS - 1])
		{
			printf("Win %d: T1: %d vs T2: %d\n", i + 1, iScores[i][TEAMS - 2], iScores[i][TEAMS - 1]);
		}
	}

	printf("\nTeam 2 win record: \n");
	for (int i = 0; i < *pEffectiveSize; i++)
	{
		if (iScores[i][TEAMS - 2] < iScores[i][TEAMS - 1])
		{
			printf("Win %d: T2:  %d vs T1: %d\n", i + 1, iScores[i][TEAMS - 1], iScores[i][TEAMS - 2]);
		}
	}
}

void SortScores(int iScores[][TEAMS], int* pEffectiveSize)
{
	int tempTeam1 = 0;
	int tempTeam2 = 0;

	// Bubble sort by opponent score (Team 2) low to high
	for (int pass = 0; pass < *pEffectiveSize - 1; pass++)
	{
		for (int row = 0; row < *pEffectiveSize - 1 - pass; row++)
		{
			if (iScores[row][1] > iScores[row + 1][1])
			{
				tempTeam1 = iScores[row][0];
				tempTeam2 = iScores[row][1];

				iScores[row][0] = iScores[row + 1][0];
				iScores[row][1] = iScores[row + 1][1];

				iScores[row + 1][0] = tempTeam1;
				iScores[row + 1][1] = tempTeam2;
			}
		}
	}

	printf("\nResults ordered by opponent score from low to high:\n");

	for (int i = 0; i < *pEffectiveSize; i++)
	{
		printf("Game %d: Team1 %d Team2 %d\n",
			i + 1,
			iScores[i][0],
			iScores[i][1]);
	}
}