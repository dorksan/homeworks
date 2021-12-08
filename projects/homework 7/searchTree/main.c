#include "binarySearchTree.h"
#include "binarySearchTreeTests.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 30

int main()
{
    if (!areTestsPassed())
    {
        return 111;
    }
    Node* tree = NULL;
    Node* temp = NULL;
    printf("\n0 – выйти\n1 – добавить значение по ключу");
    printf("\n2 – получить значение по ключу");
    printf("\n3 – проверить наличие ключа");
    printf("\n4 - удалить ключ и связанное с ним значение\n");
    int pointer = 0;
    while (true)
    {
        printf("\nВведите команду: ");
        int input = 0;
        scanf_s("%d", &input);
        int key = 0;
        char value[SIZE] = { 0 };
        switch (input)
        {
        case 0:
            printf("\nВы вышли из программы.\n");
            tree = deleteTree(tree);
            return -1;
        case 1:
            printf("Введите ключ: ");
            scanf_s("%d", &key);
            printf("Введите значение: ");
            scanf_s("%s", &value, SIZE);
            if (pointer == 0)
            {
                tree = createTree(key, value);
            }
            else
            {
                tree = addElement(tree, key, value);
            }
            pointer++;
            break;
        case 2:
            printf("Введите ключ: ");
            scanf_s("%d", &key);
            temp = searchInTree(tree, key);
            if (temp != NULL)
            {
                char* word = getValueInTree(temp);
                printf("Найденное значение: %s\n", word);
            }
            else
            {
                printf("Значение не найдено.\n");
            }
            break;
        case 3:
            printf("Введите ключ: ");
            scanf_s("%d", &key);
            temp = searchInTree(tree, key);
            if (temp == NULL)
            {
                printf("Ключ не содержится в словаре.\n");
            }
            else
            {
                printf("Ключ содержится в словаре.\n");
            }
            break;
        case 4:
            printf("Введите ключ: ");
            scanf_s("%d", &key);
            if (tree == NULL)
            {
                printf("Значение не содержится в дереве.\n");
            }
            else
            {
                tree = deleteElement(tree, key);
                printf("Значение удалено.\n");
                pointer--;
            }
            break;
        default:
            printf("\nНеправильный ввод команды.\n");
            break;
        }
    }
}