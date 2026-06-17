#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

int main()
{
	int iTemp, iGrades[SIZE] = { 95, 75, 87, 68, 98, 88 };

	for (int i = 0; i < SIZE; i++)
	{
		printf(" %i", iGrades[i]);
	}
	printf("\n");
	
	for (int iPass = 1; iPass <= SIZE - 1; iPass++)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (iGrades[i] > iGrades[i + 1])
			{
				iTemp = iGrades[i];
				iGrades[i] = iGrades[i + 1];
				iGrades[i + 1] = iTemp;
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf(" %i", iGrades[i]);
	}
	printf("\n");

	system("Pause");

	return 0;
}