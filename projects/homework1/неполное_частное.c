#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dividend = 0;
    printf("Введите делимое: ");
    scanf_s("%d", &dividend);
    int divisor = 0;
    printf("\nВведите делитель: ");
    scanf_s("%d", &divisor);
    int incompleteQuotient = 0;
    while (divisor == 0)
    {
        printf("\nВведите другой делитель: ");
        scanf_s("%d", &divisor);
    }
    int dividendModule = abs(dividend);
    int divisorModule = abs(divisor);
    while (dividendModule >= divisorModule)
    {
        incompleteQuotient++;
        dividendModule -= divisorModule;
    }
    if ((dividend < 0) || (divisor < 0))
    {
        incompleteQuotient = -incompleteQuotient;
        if ((dividend < 0) && (dividend != -divisor))
        {
            incompleteQuotient--;
        }
    }
    if ((dividend < 0) && (divisor < 0))
    {
        incompleteQuotient = -incompleteQuotient;
    }
    printf("\nНеполное частное: %d\n", incompleteQuotient);
}