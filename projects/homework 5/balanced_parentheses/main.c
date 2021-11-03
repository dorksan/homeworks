#include "balance.h"
#include "testBalance.h"
#include <stdio.h>

#define SIZE 100

int main()
{
    if (!testBalance())
    {
        return -1;
    }
    printf("Введите выражение: ");
    char string[SIZE] = { 0 };
    scanf_s("%s", &string, SIZE);
    if (balance(string, SIZE))
    {
        printf("Скобки сбалансированы.");
    }
    else
    {
        printf("Скобки не сбалансированы.");
    }
}