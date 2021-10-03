#include <stdio.h>
#include <string.h>

int main()
{
    printf("Введите строку: ");
    char string[100];
    string[99] = '\0';
    gets(&string);
    int length = strlen(string);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (string[i] == '(')
        {
            count++;
        }
        if (string[i] == ')')
        {
            count--;
        }
        if (count < 0)
        {
            break;
        }
    }
    if (count != 0)
    {
        printf("Скобки не сбалансированы.");
    }
    else
    {
        printf("Скобки сбалансированы.");
    }
}