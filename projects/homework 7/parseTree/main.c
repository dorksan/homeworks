#include "parseTree.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main()
{
    FILE* file = fopen("file.txt", "r");
    if (file == NULL)
    {
        return -1;
    }
    char inputString[SIZE] = { 0 };
    fgets(inputString, SIZE, file);
    fclose(file);
    Node* node = createTree(inputString);
    char outputString[SIZE] = { '\0' };
    getString(node, outputString, SIZE);
    printf("Исходное выражение: %s\n", outputString);
    printf("Результат выражения: %d\n", getResult(node));
    deleteTreeRecursive(node);
}