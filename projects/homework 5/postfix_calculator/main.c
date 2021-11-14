#include "calculate.h"
#include "calculateTests.h"
#include <stdio.h>

#define SIZE 100

int main()
{
    if (!testCalculate())
    {
        return -1;
    }
    int errorCode = -1;
    printf("Введите выражение в постфиксной форме: ");
    char string[SIZE] = "";
    scanf_s("%s", &string, SIZE);
    const int result = calculate(string, &errorCode);
    if (errorCode == 0)
    {
        printf("Результат выражения: %d", result);
    }
    else
    {
        printf("Код ошибки: %d", errorCode);
    }
}