#include "AVLTree.h"
#include <stdlib.h>
#include <string.h>

#define SIZE 30

typedef struct Node
{
    char* key;
    char* value;
    int balanceFactor;
    struct Node* leftChild;
    struct Node* rightChild;
    struct Node* parent;
} Node;

char* addString(char* value)
{
    const int length = strlen(value) + 1;
    char* temp = calloc(length, sizeof(value));
    if (temp == NULL)
    {
        return NULL;
    }
    strcpy_s(temp, length, value);
    return temp;
}

Node* createTree(char* key, char* value)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->value = addString(value);
        node->key = addString(key);
    }
    return node;
}

int heightSearch(Node* node)
{
    int height = 0;
    int leftHeight = 0;
    int rightHeight = 0;
    if (node == NULL)
    {
        height = 0;
    }
    else
    {
        leftHeight = heightSearch(node->leftChild);
        rightHeight = heightSearch(node->rightChild);
        height = 1 + max(leftHeight, rightHeight);
    }
    return height;
   /* int height = 0;
    if (node->leftChild == NULL && node->rightChild == NULL)
    {
        height = 0;
    }
    int leftHeight = 1;
    int rightHeight = 1;
    if (node->leftChild != NULL && node->rightChild == NULL)
    {
        leftHeight += heightSearch(node->leftChild);
        height = max(leftHeight, rightHeight);
    }
    if (node->leftChild == NULL && node->rightChild != NULL)
    {
        rightHeight += heightSearch(node->rightChild);
        height = max(leftHeight, rightHeight);
    }
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        leftHeight += heightSearch(node->leftChild);
        rightHeight += heightSearch(node->rightChild);
        height = max(leftHeight, rightHeight);
    }
    return height;*/
}

int balanceSearch(Node* node)
{
    //if (node->leftChild == NULL && node->rightChild == NULL)
    //{
    //    node->balanceFactor = 0;
    //}
    //else if (node->leftChild != NULL && node->rightChild == NULL)
    //{
    //    node->balanceFactor = -1 - heightSearch(node->leftChild);
    //}
    //else if (node->leftChild == NULL && node->rightChild != NULL)
    //{
    //    node->balanceFactor = 1 + heightSearch(node->rightChild);
    //}
    //else if (node->leftChild != NULL && node->rightChild != NULL)
    //{
    //    node->balanceFactor = heightSearch(node->rightChild) - heightSearch(node->leftChild);
    //}
    int leftBalance = heightSearch(node->leftChild);
    int rightBalance = heightSearch(node->rightChild);
    return node->balanceFactor = rightBalance - leftBalance;
}

Node* rotateLeft(Node* node)
{
    Node* newNode = node->rightChild;
    Node* movingNode = newNode->leftChild;
    newNode->leftChild = node;
    node->rightChild = movingNode;
    newNode->parent = node->parent;
    if (movingNode != NULL)
    {
        movingNode->parent = node;
    }
    node->parent = newNode;
    node->balanceFactor = balanceSearch(node);
    newNode->balanceFactor = balanceSearch(newNode);
    return newNode;
}

Node* rotateRight(Node* node)
{
    Node* newNode = node->leftChild;
    Node* movingNode = newNode->rightChild;
    newNode->rightChild = node;
    node->leftChild = movingNode;
    newNode->parent = node->parent;
    if (movingNode != NULL)
    {
        movingNode->parent = node;
    }
    node->parent = newNode;
    node->balanceFactor = balanceSearch(node);
    newNode->balanceFactor = balanceSearch(newNode);
    return newNode;
}

Node* bigRotateLeft(Node* node)
{
    Node* temp = rotateRight(node->rightChild);
    node->rightChild = temp;
    Node* newNode = rotateLeft(node);
    return newNode;
}

Node* bigRotateRight(Node* node)
{
    Node* temp = rotateLeft(node->leftChild);
    node->leftChild = temp;
    Node* newNode = rotateRight(node);
    return newNode;
}

Node* balance(Node* node)
{
    if (node->balanceFactor == 2)
    {
        if (node->rightChild->balanceFactor >= 0)
        {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    if (node->balanceFactor == -2)
    {
        if (node->leftChild->balanceFactor <= 0)
        {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    return node;
}

Node* balanceAllTree(Node* node, char* key)
{
    int matchString = strcmp(key, node->key);
    if (matchString != 0)
    {
        if (matchString < 0)
        {
            node->leftChild = balanceAllTree(node->leftChild, key);
        }
        else
        {
            node->rightChild = balanceAllTree(node->rightChild, key);
        }
    }
    node->balanceFactor = balanceSearch(node);
    return balance(node);
}

Node* addElement(Node* node, char* key, char* value)
{
    Node* root = node;
    Node* parent = node;
    if (node == NULL)
    {
        return NULL;
    }
    while (node != NULL)
    {
        int matchString = strcmp(key, node->key);
        parent = node;
        if (matchString < 0)
        {
            node = node->leftChild;
        }
        else if (matchString > 0)
        {
            node = node->rightChild;
        }
        else
        {
            free(node->value);
            node->value = addString(value);
            node->key = addString(key);
            break;
        }
    }
    Node* newNode = createTree(key, value);
    if (strcmp(key, parent->key) < 0)
    {
        parent->leftChild = newNode;
    }
    else
    {
        parent->rightChild = newNode;
    }
    newNode->parent = parent;
    return balanceAllTree(root, parent->key);
}

Node* searchInTree(Node* node, char* key)
{
    if (node == NULL)
    {
        return NULL;
    }
    while (node != NULL)
    {
        int matchString = strcmp(key, node->key);
        if (matchString == 0)
        {
            return node;
        }
        else if (matchString < 0)
        {
            node = node->leftChild;
        }
        else
        {
            node = node->rightChild;
        }
    }
    return node;
}

char* getValueInTree(Node* node)
{
    return node->value;
}

Node* leftmostChild(Node* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    while (node->leftChild != NULL)
    {
        node = node->leftChild;
    }
    return node;
}

Node* deleteElement(Node* node, char* key)
{
    if (node == NULL)
    {
        return NULL;
    }
    Node* root = node;
    node = searchInTree(node, key);
    if (node == NULL)
    {
        return root;
    }
    Node* parent = node->parent;
    if (node->leftChild == NULL && node->rightChild == NULL)
    {
        if (parent == NULL)
        {
            free(node->value);
            free(node);
            return NULL;
        }
        int matchString = strcmp(parent->key, node->key);
        if (matchString > 0)
        {
            free(node->value);
            free(node);
            parent->leftChild = NULL;
            return balanceAllTree(root, parent->key);
        }
        else
        {
            free(node->value);
            free(node);
            parent->rightChild = NULL;
            return balanceAllTree(root, parent->key);
        }
    }
    else if (node->leftChild == NULL && node->rightChild != NULL)
    {
        if (parent != NULL)
        {
            int matchString = strcmp(parent->key, node->key);
            if (matchString < 0)
            {
                parent->rightChild = node->rightChild;
                parent->rightChild->parent = parent;
            }
            else
            {
                parent->leftChild = node->rightChild;
                parent->leftChild->parent = parent;
            }
            free(node->value);
            free(node);
            return balanceAllTree(root, parent->key);
        }
        else
        {
            root = balance(node->rightChild);
            free(node->value);
            free(node);
            return root;
        }
    }
    else if (node->leftChild != NULL && node->rightChild == NULL)
    {
        if (parent != NULL)
        {
            int matchString = strcmp(parent->key, node->key);
            if (matchString < 0)
            {
                parent->rightChild = node->leftChild;
                parent->rightChild->parent = parent;
            }
            else
            {
                parent->leftChild = node->leftChild;
                parent->leftChild->parent = parent;
            }
            free(node->value);
            free(node);
            return balanceAllTree(root, parent->key);
        }
        else
        {
            root = balance(node->leftChild);
            free(node->value);
            free(node);
            return root;
        }
    }
    Node* minNode = leftmostChild(node->rightChild);
    char* temp = calloc(SIZE, sizeof(char));
    if (temp == NULL)
    {
        return root;
    }
    strcpy_s(temp, SIZE, minNode->key);
    free(node->value);
    node->value = minNode->value;
    minNode->value = NULL;
    root = deleteElement(root, minNode->key);
    node->key = temp;
    return root;
}

Node* deleteTree(Node* node)
{
    if (node == NULL)
    {
        return NULL;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    free(node->value);
    free(node);
    return NULL;
}

int countElements(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return 1 + countElements(node->leftChild) + countElements(node->rightChild);
}