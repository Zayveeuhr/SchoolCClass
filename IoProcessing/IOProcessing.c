#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void LoadWords(char words[][MAX_WORD_LENGTH], int* count);
void SaveWords(char words[][MAX_WORD_LENGTH], int count);
void AddWord(char words[][MAX_WORD_LENGTH], int* count);
void CreateTextFile(char words[][MAX_WORD_LENGTH], int count);
void DumpWords(char words[][MAX_WORD_LENGTH], int* count);

int main()
{
    char words[MAX_WORDS][MAX_WORD_LENGTH] = { '\0' };
    int count = 0;
    int choice = 0;
    bool quit = false;

    LoadWords(words, &count);

    do
    {
        printf("\n*** WORD MENU ***\n");
        printf("1) Add word\n");
        printf("2) Create text document\n");
        printf("3) Dump all words\n");
        printf("4) Quit\n");
        printf("Enter choice: ");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            AddWord(words, &count);
            break;

        case 2:
            CreateTextFile(words, count);
            break;

        case 3:
            DumpWords(words, &count);
            break;

        case 4:
            SaveWords(words, count);
            quit = true;
            break;

        default:
            printf("\nInvalid choice.\n");
            break;
        }

    } while (!quit);

    return 0;
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

void AddWord(char words[][MAX_WORD_LENGTH], int* count)
{
    if (*count >= MAX_WORDS)
    {
        printf("\nMaximum word limit reached.\n");
        return;
    }

    printf("\nEnter word: ");
    scanf_s("%50s", words[*count], (unsigned)MAX_WORD_LENGTH);

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