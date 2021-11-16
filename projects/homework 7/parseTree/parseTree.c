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
    Node* node = calloc(1, sizeof(Node));
    return node;
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
            int powerOfTen = 1;
            int counter = 0;
            int invertedNumber = 0;
            while (48 <= string[*index] && string[*index] <= 57)
            {
                invertedNumber += (string[*index] - '0') * powerOfTen;
                powerOfTen *= 10;
                counter++;
                (*index)++;
            }
            int result = 0;
            powerOfTen /= 10;
            int newPowerOfTen = 1;
            for (int i = 0; i < counter; i++)
            {
                result += invertedNumber / powerOfTen * newPowerOfTen;
                invertedNumber %= powerOfTen;
                newPowerOfTen *= 10;
                powerOfTen /= 10;
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
    else
    {
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
    }
    return 0;
}

void getStringRecursive(Node* node, char* string, int size, int* index)
{
    if (node->leftChild == NULL || node->rightChild == NULL)
    {
        char* buffer = calloc(size, sizeof(char));
        _itoa_s(node->value, buffer, size, 10);
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