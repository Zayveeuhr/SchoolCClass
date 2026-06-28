#include  <stdio.h>
#include <stdbool.h>
#include <ctype.h>

char* StringEncoder(char* cEncodedString);

int main()
{
	char cInput[101] = { '\0' };
	bool bQuit = false;
	int iChoice = 0;

	do
	{
		printf("\n\t****MENU****\n");
		printf("\t1) Encode string\n");
		printf("\t2) Quit\n");
		printf("\tEnter Choice: ");
		scanf_s("%d", &iChoice);

		if (iChoice != 1 && iChoice != 2 && iChoice != 3)
		{
			while (getchar() != '\n'); // clear bad input
			printf("\nInvalid choice! (Please enter 1 or 2)");
			continue;
		}

		switch (iChoice)
		{
		case 1:
			printf("\nEnter string to encode: ");
			scanf_s(" %100[^\n]", cInput, 101); // using regex to allow for spacing

			printf("\nOriginal word: \"%s\"", cInput);
			printf("\nEncoded string: \"%s\"\n", StringEncoder(cInput));
			break;
		case 2:
			bQuit = true;
			break;
		}

	} while (bQuit != true);
}

char* StringEncoder( char* cEncodedString)
{
	// Change all input to uppper case
	for (int i = 0; cEncodedString[i] != '\0'; i++)
	{
		cEncodedString[i] = toupper(cEncodedString[i]);
	}

	for (int i = 0; cEncodedString[i] != '\0'; i++)
	{
		switch (cEncodedString[i])
		{
		case 'A':
			cEncodedString[i] = 'H';
			break;
		case 'B':
			cEncodedString[i] = 'I';
			break;
		case 'C':
			cEncodedString[i] = 'V';
			break;
		case 'D':
			cEncodedString[i] = 'J';
			break;
		case 'E':
			cEncodedString[i] = 'K';
			break;
		case 'F':
			cEncodedString[i] = 'W';
			break;
		case 'G':
			cEncodedString[i] = 'L';
			break;
		case 'H':
			cEncodedString[i] = 'A';
			break;
		case 'I':
			cEncodedString[i] = 'M';
			break;
		case 'J':
			cEncodedString[i] = 'Y';
			break;
		case 'K':
			cEncodedString[i] = 'N';
			break;
		case 'L':
			cEncodedString[i] = 'B';
			break;
		case 'M':
			cEncodedString[i] = 'X';
			break;
		case 'N':
			cEncodedString[i] = 'O';
			break;
		case 'O':
			cEncodedString[i] = 'Z';
			break;
		case 'P':
			cEncodedString[i] = 'C';
			break;
		case 'Q':
			cEncodedString[i] = 'T';
			break;
		case 'R':
			cEncodedString[i] = 'P';
			break;
		case 'S':
			cEncodedString[i] = 'U';
			break;
		case 'T':
			cEncodedString[i] = 'D';
			break;
		case 'U':
			cEncodedString[i] = 'Q';
			break;
		case 'V':
			cEncodedString[i] = 'S';
			break;
		case 'W':
			cEncodedString[i] = 'R';
			break;
		case 'X':
			cEncodedString[i] = 'E';
			break;
		case 'Y':
			cEncodedString[i] = 'G';
			break;
		case 'Z':
			cEncodedString[i] = 'F';
			break;
		default: // In the event there is a sapce just skip or unhandled expression
			break;
		}
	}

	return cEncodedString;
}