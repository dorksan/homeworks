#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    int divisor = 2;
    while (divisor * divisor <= n)
    {
        if (n % divisor == 0)
        {
            return false;
        }
        divisor++;
    }
    return true;
}

int main()
{
    int enteredNumber = 0;
    printf("Введите число: ");
    scanf_s("%d", &enteredNumber);
    printf("%s", "Простые числа:\n");
    for (int number = 1; number <= enteredNumber; number++)
    {
        if (isPrime(number))
        {
            printf("%d\n", number);
        }
    }
}