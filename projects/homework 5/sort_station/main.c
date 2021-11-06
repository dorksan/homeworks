#include "sortStation.h"
#include "sortStationTests.h"
#include <stdio.h>

#define SIZE 100

int main()
{
    if (!sortStationTest())
    {
        return -1;
    }
    int* errorCode = -1;
    printf("Введите выражение в инфиксной форме: ");
    char infixString[SIZE] = "";
    scanf_s("%[^\n]", &infixString, SIZE);
    char postfixString[SIZE] = "";
    sortStation(infixString, postfixString, &errorCode);
    printf("\nВыражение в постфиксной форме: ");
    if (errorCode == 0)
    {
        for (int i = 0; i < strlen(postfixString); i++)
        printf("%c", postfixString[i]);
    }
    else
    {
        printf("Код ошибки: %d", errorCode);
    }
}