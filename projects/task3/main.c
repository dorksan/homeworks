#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

int main()
{
    FILE* fileG = fopen("g.txt", "r");
    if (fileG == NULL)
    {
        printf("Файл не найден");
        return -1;
    }
    int maxNumber = 0;
    fscanf_s(fileG, "%d ", &maxNumber);
    fclose(fileG);
    FILE* fileF = fopen("f.txt", "r");
    if (fileF == NULL)
    {
        printf("Файл не найден");
        return -1;
    }
    FILE* fileH = fopen("h.txt", "w");
    if (fileH == NULL)
    {
        printf("Файл не найден");
        return -1;
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
    printf("Запись в файл прошла успешно (наверное)");
    fclose(fileF);
    fclose(fileH);
}