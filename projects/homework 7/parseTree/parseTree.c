#include "parseTree.h"
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* createNode()
{
    return calloc(1, sizeof(Node));
}

Node* createTreeRecursive(const char* string, int* index)
{
    while (string[*index] != '\0')
    {
        int sign = 1;
        switch (string[*index])
        {
        case '(':
        case ')':
        case ' ':
            (*index)++;
            break;
        case '*':
        case '/':
        case '+':
        case '-':
        {
            if (string[*index] == '-' && string[*index + 1] != ' ')
            {
                sign = -1;
                (*index)++;
            }
            else
            {
                Node* node = createNode();
                node->value = string[*index];
                (*index)++;
                node->leftChild = createTreeRecursive(string, index);
                node->rightChild = createTreeRecursive(string, index);
                return node;
            }
        }
        default:
        {
            // я не знаю, как сделать это без powerOfTen
            int temp = *index;
            int counter = 0;
            int powerOfTen = 1;
            int result = 0;
            while ('0' <= string[temp] && string[temp] <= '9')
            {
                counter++;
                powerOfTen *= 10;
                temp++;
            }
            powerOfTen /= 10;
            for (int i = 0; i < counter; i++)
            {
                result += (string[*index] - '0') * powerOfTen;
                powerOfTen /= 10;
                (*index)++;
            }
            result *= sign;
            Node* node = createNode();
            node->value = result;
            return node;
        }
        }
    }
    return NULL;
}

Node* createTree(const char* string)
{
    int index = 0;
    Node* node = createTreeRecursive(string, &index);
    return node;
}

int getResult(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    if (node->leftChild == NULL || node->rightChild == NULL)
    {
        return node->value;
    }
    int leftValue = getResult(node->leftChild);
    int rightValue = getResult(node->rightChild);
    switch (node->value)
    {
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    }
    return 0;
}

void getStringRecursive(Node* node, char* string, int size, int* index)
{
    if (node->leftChild == NULL || node->rightChild == NULL)
    {
        char* buffer = calloc(size, sizeof(char));
        itoa(node->value, buffer, 10);
        int counter = 0;
        while (buffer[counter] != '\0' && (*index < size))
        {
            string[*index] = buffer[counter];
            (*index)++;
            counter++;
        }
        free(buffer);
        string[*index] = ' ';
        (*index)++;
    }
    else
    {
        string[*index] = '(';
        (*index)++;
        string[*index] = ' ';
        (*index)++;
        string[*index] = node->value;
        (*index)++;
        string[*index] = ' ';
        (*index)++;
        getStringRecursive(node->leftChild, string, size, index);
        getStringRecursive(node->rightChild, string, size, index);
        string[*index] = ')';
        (*index)++;
        string[*index] = ' ';
        (*index)++;
    }
}

void getString(Node* node, char* string, int size)
{
    int index = 0;
    getStringRecursive(node, string, size, &index);
    string[index] = '\0';
}

void deleteTreeRecursive(Node* node)
{
    if (node == NULL)
    {
        return;
    }
    if (node->leftChild != NULL)
    {
        deleteTreeRecursive(node->leftChild);
    }
    if (node->rightChild != NULL)
    {
        deleteTreeRecursive(node->rightChild);
    }
    free(node);
}