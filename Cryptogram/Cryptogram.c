#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// fuction prototypes 

void encrypt(char[], int);
void decrypt(char[], int);

int main()
{
	char myString[21] = { 0 };
	int iSelection = 0;
	int iRand;
	srand(time(NULL));
	iRand = (rand() % 4) + 1; // random #, 1-4

	while (iSelection != 4)
	{
		printf("\n\n1\tEncrypt Clear Test\n");
		printf("2\tDecrypt Cipher Text\n");
		printf("3\tGenerate New Key\n");
		printf("4\tQuit\n");
		
		printf("\nSelect a Cryptography Option: ");
		scanf_s("%d", &iSelection, 20);

		switch (iSelection)
		{
		case 1:
			printf("Enter one word as clear text to encrypt: ");
			scanf_s("%s", myString, 20);
			encrypt(myString, iRand);
			break;
		case 2:
			printf("\nEnter cipher text to decrypt: ");
			scanf_s("%s", myString, 20);
			decrypt(myString, iRand);
			break;
		case 3:
			iRand = (rand() % 4) + 1; // random #, 1-4
			printf("\nNew Key Generated\n");
			break;
		}
	}

	
}

void encrypt(char sMessage[], int random)
{
	int x = 0;

	//encrypt the massage by shifting each charater's ASCII value
	while (sMessage[x])
	{
		sMessage[x] += random;
		x++;
	}
	
	x = 0;

	printf("\nEncrypted Message is: ");
	//print the encrypted meaage 
	while (sMessage[x])
	{
		printf("%c", sMessage[x]);
		x++;
	}
}

void decrypt(char sMessage[], int random)
{
	int x = 0; x = 0;

	//decrypt the message by shifting each charater's ASCII value 
	while (sMessage[x])
	{
		sMessage[x] = sMessage[x] - random;
		x++;
	}
	x = 0;

	printf("\nDecrypted message is: ");

	// Print the decrypted message
	while (sMessage[x])
	{
		printf("%c", sMessage[x]);
		x++;
	}
}