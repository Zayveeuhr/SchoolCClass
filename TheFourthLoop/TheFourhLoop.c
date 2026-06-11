#include <stdio.h>
#include <limits.h>

void CheckPrime(int, int, int);

int main()
{
	int iReposnse;

	printf("\nPlease enter a number be 2 and %d: ", INT_MAX);
	scanf_s("%d", &iReposnse);

	CheckPrime(iReposnse, iReposnse, 0);

	return 0;
}

void CheckPrime(int iStable, int iDevisor, int iCounter)
{
	if (iCounter == 3)
	{
		printf("\nThe number %d is NOT a prime number.\n", iStable);
		return;
	}
	else if (iDevisor == 1)
	{
		printf("\nThe number %d is a prime number.\n", iStable);
		return;
	}

	if (iStable % iDevisor == 0) { iCounter++; }

	CheckPrime(iStable, iDevisor - 1, iCounter);
}