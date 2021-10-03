#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int fibonacciRecursive(int number)
{
    if (number < 0)
    {
        return 0;
    }
    if (number == 1 || number == 2)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
    }
}

int fibonacciIterative(int number)
{
    if (number < 0)
    {
        return 0;
    }
    if (number == 1 || number == 2)
    {
        return 1;
    }
    int element1 = 1;
    int element2 = 1;
    int result = 0;
    if (number > 2)
    {
        for (int i = 0; i < number - 2; i++)
        {
            result = element1 + element2;
            element1 = element2;
            element2 = result;
        }
    }
    return result;
}

bool testFR(void)
{
    return fibonacciRecursive(1) == 1 && fibonacciRecursive(-1) == 0 && fibonacciRecursive(10) == 55;
}

bool testFI(void)
{
    return fibonacciIterative(1) == 1 && fibonacciIterative(-1) == 0 && fibonacciIterative(10) == 55;
}

double main()
{
    if (!testFR() || !testFI())
    {
        printf("Ошибка\n");
        return -1;
    }

    printf("Введите номер элемента последовательности: ");
    int number = 0;
    scanf_s("%d", &number);
    const int result1 = fibonacciRecursive(number);
    printf("%d-ое число Фибоначчи равно %d    ", number, result1);
    const int result2 = fibonacciIterative(number);
    printf("(%d)    \n", result2);
    for (int i = 1; i < number; i++)
    {
        const clock_t start = clock();
        int res1 = fibonacciRecursive(i);
        const clock_t end = clock();
        const double seconds = (const double)(end - start) / CLOCKS_PER_SEC;
        printf("%d-ый элемент    Время: %lf    ", i, seconds);
        const clock_t start2 = clock();
        int res2 = fibonacciIterative(i);
        const clock_t end2 = clock();
        const double seconds2 = (const double)(end2 - start2) / CLOCKS_PER_SEC;
        printf("%lf\n", seconds2);
    }
}