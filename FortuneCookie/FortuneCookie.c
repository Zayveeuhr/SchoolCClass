#include <stdio.h>
#include <ctype.h>

int main()
{
	int iBirthDaY = 0;
	int iBirthMonth = 0;

	int iJanuary = 1;
	int iFeburay = 2;
	int iMarch = 3;
	int iApril = 4;
	int iMay = 5;
	int iJune = 6;
	int iJuly = 7;
	int iAugust = 8;
	int iSeptember = 9;
	int iOctober = 10;
	int iNovember = 11;
	int iDecember = 12;

	printf("\n\tFortune Cookie\n");

	printf("\nEnter your day of birth: ");
	scanf_s("%d", &iBirthDaY);
	printf("Enter your month of birth: ");
	scanf_s("%d", &iBirthMonth);

	if (isdigit(iBirthDaY) == 0 && isdigit(iBirthMonth) == 0)
	{
		if ((iBirthMonth == iMarch && iBirthDaY >= 21) || (iBirthMonth == iApril && iBirthDaY <= 19))
		{
			printf("\nYour zodiac is: Aries\n");
			printf("Your courage will open a new door today.\n");
		}
		else if ((iBirthMonth == iApril && iBirthDaY >= 20) || (iBirthMonth == iMay && iBirthDaY <= 20))
		{
			printf("\nYour zodiac is: Taurus\n");
			printf("Stay patient—steady progress beats rushing.\n");
		}
		else if ((iBirthMonth == iMay && iBirthDaY >= 21) || (iBirthMonth == iJune && iBirthDaY <= 20))
		{
			printf("\nYour zodiac is: Gemini\n");
			printf("A good conversation may spark a great idea.\n");
		}
		else if ((iBirthMonth == iJune && iBirthDaY >= 21) || (iBirthMonth == iJuly && iBirthDaY <= 22))
		{
			printf("\nYour zodiac is: Cancer\n");
			printf("Trust your instincts; they won't lead you astray.\n");
		}
		else if ((iBirthMonth == iJuly && iBirthDaY >= 23) || (iBirthMonth == iAugust && iBirthDaY <= 22))
		{
			printf("\nYour zodiac is: Leo\n");
			printf("Your confidence inspires those around you.\n");
		}
		else if ((iBirthMonth == iAugust && iBirthDaY >= 23) || (iBirthMonth == iSeptember && iBirthDaY <= 22))
		{
			printf("\nYour zodiac is: Virgo\n");
			printf("Small details handled today bring big rewards later.\n");
		}
		else if ((iBirthMonth == iSeptember && iBirthDaY >= 23) || (iBirthMonth == iOctober && iBirthDaY <= 22))
		{
			printf("\nYour zodiac is: Libra\n");
			printf("Seek balance and avoid unnecessary stress.\n");
		}
		else if ((iBirthMonth == iOctober && iBirthDaY >= 23) || (iBirthMonth == iNovember && iBirthDaY <= 21))
		{
			printf("\nyour zodiac is: Scorpio\n");
			printf("Your determination can overcome any obstacle.\n");
		}
		else if ((iBirthMonth == iNovember && iBirthDaY >= 22) || (iBirthMonth == iDecember && iBirthDaY <= 21))
		{
			printf("\nYOur zodiac is: Sagittarius\n");
			printf("Be open to adventure and new opportunities.\n");
		}
		else if ((iBirthMonth == iDecember && iBirthDaY >= 22) || (iBirthMonth == iJanuary && iBirthDaY <= 19))
		{
			printf("\nYour zodiac is: Capricorn\n");
			printf("Hard work today moves you closer to your goals.\n");
		}
		else if ((iBirthMonth == iJanuary && iBirthDaY >= 20) || (iBirthMonth == iFeburay && iBirthDaY <= 18))
		{
			printf("\nYour zodiac is: Aquarius\n");
			printf("Your unique perspective is your greatest strength.\n");
		}
		else if ((iBirthMonth == iFeburay && iBirthDaY >= 19) || (iBirthMonth == iMarch && iBirthDaY <= 20))
		{
			printf("\nYOur zodiac is: Pisces\n");
			printf("Let creativity guide you toward something meaningful.\n");
		}
	}
	else
	{
		printf("\nThat was not a vaild reponse.\n");
	}
}