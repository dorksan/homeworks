#include <stdio.h>
#define length 10

int main()
{
    int sum = 0;
    int array[length] = { 5, 6, 45, 0, 98, 0, 5465, 1, 0, 0 };
    for (int i = 0; i < length; i++)
    {
        if (array[i] == 0)
        {
            sum++;
        }
    }
    printf("%s %d\n", "Количество нулевых элементов массива:", sum);
}