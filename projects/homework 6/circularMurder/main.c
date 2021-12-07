#include "circularListAndSearchFunctionTests.h"
#include "searchLastWarrior.h"
#include <stdio.h>

int main()
{
    if (!areTestsPassed())
    {
        return 1;
    }
    int numberOfWarriors = 0;
    printf("В отряде n воинов.\nВведите n: ");
    scanf_s("%d", &numberOfWarriors);
    int murderedWarrior = 0;
    printf("Убивают каждого m-го воина.\nВведите m: ");
    scanf_s("%d", &murderedWarrior);
    printf("Номер начальной позиции оставшегося воина: %d ", searchLastWarrior(numberOfWarriors, murderedWarrior));
}