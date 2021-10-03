#include <stdio.h>
#define length 8

void shift(int start, int count, int array[])
{
    for (int i = start; i < count; i++)
    {
        int temp = array[i];
        array[i] = array[count - 1];
        array[count - 1] = temp;
        count--;
    }
}

int main()
{
    const int m = 5;
    const int n = 3;
    int array[length] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    printf("Исходный массив: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
    }
    shift(length - m - n, m, array);
    shift(length - n, length, array);
    shift(0, length, array);
    printf("\nНовый массив: ");
    for (int i = 0; i < length; i++)
    {
        printf("%d", array[i]);
    }
}