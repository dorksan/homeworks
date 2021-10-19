#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 20
#define TEST_SIZE 11

int file()
{
    FILE* fileG = fopen("g.txt", "r");
    if (fileG == NULL)
    {
        return -1;
    }
    int maxNumber = 0;
    fscanf_s(fileG, "%d ", &maxNumber);
    fclose(fileG);
    FILE* fileF = fopen("f.txt", "r");
    if (fileF == NULL)
    {
        return -2;
    }
    FILE* fileH = fopen("h.txt", "w");
    if (fileH == NULL)
    {
        return -3;
    }
    int* array = calloc(SIZE, sizeof(int));
    for (int i = 0; i < SIZE; i++)
    {
        fscanf_s(fileF, "%d ", &array[i]);
        if (array[i] < maxNumber)
        {
            fprintf(fileH, "%d ", array[i]);
        }
    }
    fclose(fileF);
    fclose(fileH);
}

bool test(void)
{
    int testArray[TEST_SIZE] = { 15, 23, 4, 12, 26, 17, 34, 45, 11, 8, 47 };
    FILE* fileH = fopen("h.txt", "r");
    int array[TEST_SIZE] = { 0 };
    for (int i = 0; i < TEST_SIZE; i++)
    {
        fscanf_s(fileH, "%d ", &array[i]);
        if (array[i] != testArray[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!test())
    {
        printf("Ошибка");
        return -10;
    }
    printf(file);
    printf("Запись в файл прошла успешно (наверное)");
}