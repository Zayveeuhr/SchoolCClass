#include <stdio.h>
#include <stdlib.h>
#define SIZE 13

int bianarySearch(int[], int, int);

int main()
{
	int iGrades[SIZE] = { 75,77,80,82,85,86,87,89,90,93,95,96,99 };
	int iKey = 89;
	int iResult = 0;

	iResult = bianarySearch(iGrades, SIZE, iKey);

	printf("%d was found at location: %d\n", iKey, iResult);

	system("Pause");

	return 0;
}

int bianarySearch(int iArray[], int iSize, int iKey)
{
	int iLow = 0, iHigh = iSize - 1, iMiddle;

	while (iLow <= iHigh)
	{
		iMiddle = (iLow + iHigh) / 2;

		if (iKey == iArray[iMiddle])
		{
			return iMiddle;
		}
		else if (iArray[iMiddle] > iKey)
		{
			iHigh = iMiddle - 1;
		}
		else
		{
			iLow = iMiddle + 1;
		}
	}

	return -1;
}