#include "lexer.h"
#include "testLexer.h"
#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

int main()
{
    if (!areTestsPassed())
    {
        return 111;
    }
    char realNumber[SIZE] = { 0 };
    printf("Введите вещественное число:\n");
    scanf_s("%s", &realNumber, SIZE);
    bool isEmail = analyze(realNumber);
    if (isEmail)
    {
        printf("Это вещественное число");
    }
    else
    {
        printf("Это не вещественное число");
    }
}