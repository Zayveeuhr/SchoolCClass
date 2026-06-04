#include <stdio.h>

int main()
{
	int fFirstNum = 0, fSecondNum = 0,fThirdNum = 0, fFourthNum = 0;
	int result;

	printf("\nEnter your first number: ");
	scanf_s("%d", &fFirstNum);
	printf("Enter your first number: ");
	scanf_s("%d", &fSecondNum);
	printf("Enter your first number: ");
	scanf_s("%d", &fThirdNum);
	printf("Enter your first number: ");
	scanf_s("%d", &fFourthNum);

	printf("\nThe total is %d", (fFirstNum - fSecondNum) * (fThirdNum - fFourthNum));
}