#include "kmp.h"
#include "testKMP.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE_OF_SUBSTRING 100
#define SIZE 100000

int main()
{
    if (!isTestPassed())
    {
        return 111;
    }
    FILE* file = fopen("text.txt", "r");
    if (file == NULL)
    {
        return 1;
    }
    char* text = calloc(SIZE, sizeof(char));
    if (text == NULL)
    {
        return -1;
    }
    int pointer = 0;
    while (!feof(file))
    {
        fscanf_s(file, "%c", &text[pointer], SIZE);
        pointer++;
    }
    fclose(file);
    char substring[SIZE_OF_SUBSTRING] = { 0 };
    printf("Введите строку: ");
    scanf_s("%s", &substring, SIZE_OF_SUBSTRING);
    int* positionOfEntry = calloc(SIZE, sizeof(int));
    if (positionOfEntry == NULL)
    {
        return -1;
    }
    kmp(substring, text, positionOfEntry);
    int lengthOfSubstring = strlen(substring);
    for (int i = 0; i < SIZE; i++)
    {
        if ((positionOfEntry[0] == 0 && lengthOfSubstring > 1) || (lengthOfSubstring == 1 && text[0] != substring[0] && positionOfEntry[0] == 0))
        {
            printf("\nСлово не содержится в тексте.");
            return 10;
        }
        else if (positionOfEntry[i] == 0 && i > 0)
        {
            break;
        }
        else
        {
            printf("\nПозиция %d-ого вхождения: %d ", i + 1, positionOfEntry[i]);
        }
    }
    free(positionOfEntry);
    free(text);
}