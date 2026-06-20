#include <stdio.h>
#include <stdbool.h>
#define MAX_DEPOSIT 50

//Prototypes
void Deposit(double[], int);
double DisplayDepositSum(double[]);
void DisplaySortedDeposits(double[]);
void DisplayAverageDeposit(double[], double);
void DisplayLowestDeposit(double[]);

int main()
{
	char cResponse = ' ';
	bool bQuit = false;
	double dDeposit[MAX_DEPOSIT] = { 0 };
	int iCount = 0;

	do
	{
		printf("\n\t*** BANKING MAIN MENU ***\n");
		printf("\n\t[G]et a new deposit\n");
		printf("\t[S]um of all deposit\n");
		printf("\t[D]eposits will be displayhed from the highest to lowest deposit\n");
		printf("\t[A]verage of all deposits\n");
		printf("\t[L]owest deposit will be displayed\n");
		printf("\t[Q]uit the program\n");

		printf("\nWhat would you like to do: ");
		scanf_s(" %c", &cResponse, 1);

		switch (cResponse)
		{
		case 'g':
		case 'G':
			Deposit(dDeposit, iCount);
			iCount++;
			break;
		case 's':
		case 'S':
			printf("\nThe total of your deposits is $%.2lf\n", DisplayDepositSum(dDeposit));
			break;
		case 'd':
		case 'D':
			DisplaySortedDeposits(dDeposit);
			break;
		case 'a':
		case 'A':
			DisplayAverageDeposit(dDeposit, DisplayDepositSum(dDeposit));
			break;
		case 'l':
		case 'L':
			DisplayLowestDeposit(dDeposit);
			break;
		case 'q':
		case 'Q':
			bQuit = true;
			break;
		}
	} while (bQuit != true);

	return 0;
}

void Deposit(double dDeposit[], int iCount)
{
	double iAmount = 0;

	if (iCount > MAX_DEPOSIT - 1)
	{
		printf("\nMax deposit limit reached.\n");
		return;
	}

	printf("\nEnter amount wanting to deposit: ");
	scanf_s("%lf", &iAmount);

	dDeposit[iCount] = iAmount;

}

double DisplayDepositSum(double dDeposit[])
{

	double dTotalSum = 0;

	for (int i = 0; i < MAX_DEPOSIT; i++)
	{
		dTotalSum += dDeposit[i];
	}

	return dTotalSum;
}

void DisplaySortedDeposits(double dDeposit[])
{
	double dTemp = 0;

	printf("\nDeposits highest to: \n");

	for (int i = 0; i < MAX_DEPOSIT - 1; i++)
	{
		for (int j = 0; j < MAX_DEPOSIT - 1; j++)
		{
			if (dDeposit[j] < dDeposit[j + 1])
			{
				dTemp = dDeposit[j];
				dDeposit[j] = dDeposit[j + 1];
				dDeposit[j + 1] = dTemp;
			}
		}
	}


	for (int i = 0; i <= MAX_DEPOSIT - 1; i++)
	{
		if (dDeposit[i] > 0)
		{
			printf("$%.2lf\n", dDeposit[i]);
		}
	}
}

void DisplayAverageDeposit(double dDeposit[], double dSum)
{
	int iCount = 0;

	for (int i = 0; i <= MAX_DEPOSIT - 1; i++)
	{
		if (dDeposit[i] > 0)
		{
			iCount++;
		}
	}

	printf("\nThe avrage deposit is $%.2lf\n", dSum / iCount);
}

void DisplayLowestDeposit(double dDeposit[])
{
	double dTemp = 0;

	for (int i = 0; i < MAX_DEPOSIT - 1; i++)
	{
		for (int j = 0; j < MAX_DEPOSIT - 1; j++)
		{
			if (dDeposit[j] > dDeposit[j + 1])
			{
				dTemp = dDeposit[j];
				dDeposit[j] = dDeposit[j + 1];
				dDeposit[j + 1] = dTemp;
			}
		}
	}

	for (int i = 0; i <= MAX_DEPOSIT - 1; i++)
	{
		if (dDeposit[i] > 0)
		{
			printf("\nThe lowest deposit was $%.2lf\n", dDeposit[i]);
			break;
		}
	}
}