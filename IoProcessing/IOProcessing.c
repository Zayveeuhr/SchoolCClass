#include <stdio.h>
#include <stdbool.h>


#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 51

void LoadWords(char words[][MAX_WORD_LENGTH], int* count);
void SaveWords(char words[][MAX_WORD_LENGTH], int count);
void AddWord(char words[][MAX_WORD_LENGTH], int* count);
void CreateTextFile(char words[][MAX_WORD_LENGTH], int count);
void DumpWords(char words[][MAX_WORD_LENGTH], int* count);

int main()
{
    char cWords[MAX_WORDS][MAX_WORD_LENGTH] = { '\0' };
    int iCount = 0;
    int iChoice = 0;
    bool bQuit = false;

    LoadWords(cWords, &iCount);

    do
    {
        printf("\n\t*** WORD MENU ***\n");
        printf("\t1) Add word\n");
        printf("\t2) Create text document\n");
        printf("\t3) Dump all words\n");
        printf("\t4) Quit\n");
        printf("Enter choice: ");
        scanf_s("%d", &iChoice);

        while (getchar() != '\n');

        if (iChoice != 1 && iChoice != 2 && iChoice != 3 && iChoice != 4)
        {
            printf("\nInvalid choice.\n");

            while (getchar() != '\n'); // clear bad input
        }

        switch (iChoice)
        {
        case 1:
            AddWord(cWords, &iCount);
            break;

        case 2:
            CreateTextFile(cWords, iCount);
            break;

        case 3:
            DumpWords(cWords, &iCount);
            break;

        case 4:
            SaveWords(cWords, iCount);
            bQuit = true;
            break;
        }

    } while (bQuit != true);

    return 0;
}

void AddWord(char words[][MAX_WORD_LENGTH], int* count)
{
    // As long as count is less than max words allowed keep allowing user to add words
    if (*count >= MAX_WORDS)
    {
        printf("\nMaximum word limit reached.\n");
        return;
    }

    printf("\nEnter word: ");
    scanf_s("%50[^\n]", words[*count], MAX_WORD_LENGTH); // only allow up to a 50 char string 

    (*count)++;
}

void CreateTextFile(char words[][MAX_WORD_LENGTH], int count)
{
    FILE* file = fopen("words.txt", "w");

    if (file == NULL)
    {
        printf("\nError creating text file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s\n", words[i]);
    }

    fclose(file);

    printf("\nText file created successfully.\n");
}

void DumpWords(char words[][MAX_WORD_LENGTH], int* count)
{
    for (int i = 0; i < MAX_WORDS; i++)
    {
        words[i][0] = '\0';
    }

    *count = 0;

    printf("\nAll words have been dumped from the program.\n");
}

void SaveWords(char words[][MAX_WORD_LENGTH], int count)
{
    FILE* file = fopen("words.bin", "wb");

    if (file == NULL)
    {
        printf("\nError saving binary file.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, file);
    fwrite(words, sizeof(char), MAX_WORDS * MAX_WORD_LENGTH, file);

    fclose(file);

    printf("\nWords saved to binary file.\n");
}

void LoadWords(char words[][MAX_WORD_LENGTH], int* count)
{
    FILE* file = fopen("words.bin", "rb");

    if (file == NULL)
    {
        printf("\nNo saved binary file found.\n");
        return;
    }

    fread(count, sizeof(int), 1, file);
    fread(words, sizeof(char), MAX_WORDS * MAX_WORD_LENGTH, file);

    fclose(file);

    printf("\nLoaded %d words from binary file.\n", *count);
}