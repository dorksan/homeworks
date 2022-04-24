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
    char string[SIZE] = "";
    scanf_s("%s", &string, SIZE);
    int errorCode = -1;
    balance(string, &errorCode);
    if (errorCode == 0)
    {
        printf("Скобки сбалансированы.");
    }
    else
    {
        printf("Код ошибки: %d", errorCode);
    }
}