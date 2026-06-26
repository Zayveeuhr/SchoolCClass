#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// prototypes 
void DisplayFoward(char*);
void DisplayBackwards(char*);
void DisplayVertical(char*);
int DisplayTotalLetters(char*);
void DisplayTriangle(char*);

int main()
{
	char cResponse[101] = {'\0'};
	int iResponse = 0;
	bool bQuit = false;

	do
	{
		printf("\nEnter a string up to 100 characters: ");
		scanf_s("%[^\n]", cResponse, 101); // Use regex to allow all characters even whitespaces

		DisplayFoward(cResponse);
		DisplayBackwards(cResponse);
		DisplayVertical(cResponse);
		DisplayTriangle(cResponse);
		printf("\nThe number of letters is %d\n", DisplayTotalLetters(cResponse));
		

		// Loop till reponse is one of two choices
		do
		{
			printf("\n\t1)Enter another string\n");
			printf("\n\t2)Quit\n");
			printf("Enter choice: ");
			scanf_s("%d", &iResponse);

			if (iResponse != 1 && iResponse != 2)
			{
				printf("Invalid input. Please enter a number.\n");

				while (getchar() != '\n'); // clear bad input
			}

			switch (iResponse)
			{
			case 1:
				break;
			case 2:
				bQuit = true;
				break;
			default:
				break;
			}

		} while (iResponse != 1 && iResponse != 2); // If string does not = 1 or 2 keep asking for input 

		
	} while (bQuit != true);

	return 0;
}

void DisplayFoward(char* sFoward)
{
	printf("\nString printed foward: ");
	printf("\n%s\n", sFoward);
}

void DisplayBackwards(char* sBackward)
{
	printf("\nString printed backwards: \n");

	for (int i = strlen(sBackward); i >= 0; i--)
	{
		printf("%c", sBackward[i]);
	}
	printf("\n");
}

void DisplayVertical(char* sVertical)
{
	printf("\nString printed vertical: ");

	for (int i = 0; i <= strlen(sVertical); i++)
	{
		printf("\n%c", sVertical[i]);
	}
}

int DisplayTotalLetters(char* sLetters)
{
	int iCount = 0;
	
	for (int i = 0; i < strlen(sLetters); i++)
	{
		if (isspace(sLetters[i])) // Remove whitespaces 
		{
			continue;
		}
		iCount++;
	}

	return iCount;
}

void DisplayTriangle(char* sTriangle)
{
	printf("\nString printed in triangle: \n");
	for (int i = 0; sTriangle[i] != '\0'; i++) // display string by adding 1 to every loop
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%c", sTriangle[j]);
		}
		printf("\n");
	}
}