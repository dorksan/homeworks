#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct Node
{
    int key;
    char* value;
    struct Node* leftChild;
    struct Node* rightChild;
    struct Node* parent;
} Node;

Node* createTree(int key, char* value)
{
    Node* tree = calloc(1, sizeof(Node));
    if (tree != NULL)
    {
        //tree->value = strdup(value);
        tree->value = value;
        tree->key = key;
        tree->leftChild = NULL;
        tree->rightChild = NULL;
    }
    return tree;
}

Node* addElement(Node* tree, int key, char* value)
{
    //const int temp = strcmp(value, tree->value);
    Node* parent = tree;
    if (tree == NULL)
    {
        return NULL;
        //createTree(key, value);
    }
    while (tree != NULL)
    {
        parent = tree;
        if (key < tree->key)
        {
            tree = tree->leftChild;
        }
        else if (key > tree->key)
        {
            tree = tree->rightChild;
        }
        else
        {
            return NULL;
        }
    }
    Node* newTree = createTree(key, value);
    if (key < parent->key)
    {
        parent->leftChild = newTree;
    }
    else
    {
        parent->rightChild = newTree;
    }
    return newTree;
    //else if (temp == 0)
    //{
    //    return tree;
    //}
    //else if (temp < 0)
    //{
    //    tree->leftChild = addNode(tree->leftChild, key, value);
    //}
    //else
    //{
    //    tree->rightChild = addNode(tree->rightChild, key, value);
    //}
    //return tree;
}

Node* searchInTree(Node* tree, int key)
{
    while (tree != NULL)
    {
        if (key == tree->key)
        {
            return tree;
        }
        else if (key < tree->key)
        {
            tree = tree->leftChild;
        }
        else
        {
            tree = tree->rightChild;
        }
    }
    return tree;
}

Node* leftmostChilde(Node* tree)
{
    if (tree == NULL)
    {
        return NULL;
    }
    while (tree->leftChild != NULL)
    {
        tree = tree->leftChild;
    }
    return tree;
}

void deleteElement(Node* tree, int key)
{
    if (tree == NULL)
    {
        return;
    }
    tree = searchInTree(tree, key);
    Node* parent = tree;
    if (tree->leftChild == NULL && tree->rightChild == NULL)
    {
        if (parent->key > tree->key)
        {
            free(tree);
            parent->leftChild = NULL;
        }
        else
        {
            free(tree);
            parent->rightChild = NULL;
        }
    }
    else if (tree->leftChild == NULL && tree->rightChild != NULL)
    {
        parent->rightChild = tree->rightChild;
        free(tree);
    }
    else if (tree->rightChild == NULL && tree->leftChild != NULL)
    {
        parent->leftChild = tree->leftChild;
        free(tree);
    }
    //else
    //{
    //    Node* newTree = leftmostChilde(tree);

    //}
}

//void treePrint(Node* tree)
//{
//    if (tree == NULL)
//    {
//        return;
//    }
//    treePrint(tree->leftChild);
//    printf("%d %s\n", tree->key, tree->value);
//    treePrint(tree->rightChild);
//}

int main()
{
    Node* tree = NULL;
    printf("\n0 – выйти\n1 – добавить значение по ключу");
    printf("\n2 – получить значение по ключу");
    printf("\n3 – проверить наличие ключа");
    printf("\n4 - удалить ключ и связанное с ним значение\n");
    int pointer = 0;
    while (1)
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
            //deleteTree(tree);
            return -1;
            break;
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

            break;
        case 3:

            break;
        case 4:
            printf("Введите ключ: ");
            scanf_s("%d", &key);
            deleteElement(tree, key);
            pointer--;
            break;
        default:
            printf("\nНеправильный ввод команды.\n");
            break;
        }
    }
}