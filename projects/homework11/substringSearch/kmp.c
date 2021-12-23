#include "kmp.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE_OF_SUBSTRING 100
#define SIZE 100000

void prefixFunction(const char* string, int* prefix, const int sizeOfSubstring, const int sizeOfText)
{
    int i = 0;
    for (i = 1; i < sizeOfSubstring + sizeOfText; i++)
    {
        int j = prefix[i - 1];
        while (j > 0 && string[i] != string[j])
        {
            j = prefix[j - 1];
        }
        if (string[i] == string[j])
        {
            j++;
        }
        if (i == sizeOfSubstring || j == sizeOfSubstring + 1)
        {
            j = (string[i] != string[0]) ? 0 : 1;
        }
        prefix[i] = j;
    }
}

void kmp(const char* substring, const char* text, int* positionOfEntry)
{
    const int lengthOfSubstring = strlen(substring);
    const int lengthOfText = strlen(text);
    if (lengthOfSubstring > lengthOfText)
    {
        return;
    }
    char* string = calloc(SIZE + SIZE_OF_SUBSTRING, sizeof(char));
    if (string == NULL)
    {
        return;
    }
    snprintf(string, SIZE + SIZE_OF_SUBSTRING, "%s%s", substring, text);
    int* prefix = calloc(SIZE, sizeof(int));
    if (prefix == NULL)
    {
        return;
    }
    prefixFunction(string, prefix, lengthOfSubstring, lengthOfText);
    int count = 0;
    for (int i = 0; i < lengthOfSubstring + lengthOfText; i++)
    {
        if (prefix[lengthOfSubstring + i] == lengthOfSubstring)
        {
            positionOfEntry[count++] = i - lengthOfSubstring + 1;
        }
    }
    free(string);
    free(prefix);
}