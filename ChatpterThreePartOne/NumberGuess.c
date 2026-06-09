#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
 
int main()
{
	int iGuess = 0;
	int iRandomNum = 0;
	srand(time(NULL));
	iRandomNum = (rand() % 10) + 1;

	printf("\nGuess the number betweeen (1 - 10): ");
	scanf_s("%d", &iGuess);

	if (isdigit(iGuess) == 0)
	{
		if (iGuess == iRandomNum)
		{
			printf("\nYou guessed the correct number!\n");
		}
		else
		{
			printf("You guess wrong! Number was %d\n", iRandomNum);
		}
	}
	else
	{
		printf("\nThat was not a number\n");
	}
}