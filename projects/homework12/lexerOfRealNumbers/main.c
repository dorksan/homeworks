#include "lexer.h"
#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    char realNumber[SIZE] = { 0 };
    printf("Введите вещественное число:\n");
    scanf_s("%s", &realNumber, SIZE);
    bool isEmail = lexer(realNumber);
    if (isEmail)
    {
        printf("Это вещественное число");
    }
    else
    {
        printf("Это не вещественное число");
    }
}