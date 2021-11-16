#include <stdio.h>
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

Node* createTreeRecursive(char* string, int* index)
{
    while (string[*index] != '\0')
    {
        int sign = 1;
        switch (string[*index])
        {
        case '(':
        case ')':
        case ' ':
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
            while (48 <= string[*index] <= 57)
            {
                invertedNumber += (string[*index] - '0') * powerOfTen;
                powerOfTen *= 10;
                counter++;
            }
            int result = 0;
            powerOfTen = 1;
            for (int i = 0; i < counter; i++)
            {
                result += invertedNumber;
            }
            break;
        }
        }
    }
}

int main()
{
    
}