#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    string[99] = "\0";
    gets(&string);
    char string1[100];
    string1[99] = "\0";
    gets(&string1);
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0;; j++)
        {
            if (string1[j] == '\0')
            {
                count++;
            }
            if (string[i + j] != string1[j])
            {
                break;
            }
        }
    }
    printf("Подстрока содержится %d раз.\n ", count);
}