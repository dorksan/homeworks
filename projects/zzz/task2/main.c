#include "matrix.h"
#include <stdio.h>

#define SIZE 100

int main()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        return 1;
    }
    int length = 0;
    fscanf(file, "%d", &length);
    int height = 0;
    fscanf(file, "%d", &height);
    int matrix[SIZE] = { 0 };
    int pointer = 0;
    while (!feof(file))
    {
        fscanf_s(file, "%d", &matrix[pointer]);
        pointer++;
    }
    fclose(file);
    int elements[SIZE] = { 0 };
    spiralMatrix(matrix, elements, length, height, pointer);
    FILE* output = fopen("out.txt", "w");
    if (output == NULL)
    {
        return 1;
    }
    for (int i = 0; i < pointer; i++)
    {
        fprintf(output, "%d ", elements[i]);
    }
    printf("Обход завершен.");
}