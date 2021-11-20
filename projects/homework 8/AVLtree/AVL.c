#include "AVL.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int key;
    char* value;
    int balanceFactor;
    struct Node* leftChild;
    struct Node* rightChild;
    struct Node* parent;
} Node;

Node* createTree(int key, char* value)
{
    Node* tree = calloc(1, sizeof(Node));
    if (tree != NULL)
    {
        tree->value = _strdup(value);
        tree->key = key;
    }
    return tree;
}

int heightSearch(Node* node)
{
    if (node->leftChild == NULL && node->rightChild == NULL)
    {
        node->balanceFactor = 0;
        return node->balanceFactor;
    }
    int leftHeight = 1;
    int rightHeight = 1;
    if (node->leftChild != NULL && node->rightChild == NULL)
    {
        leftHeight += heightSearch(node->leftChild);
        node->balanceFactor = max(leftHeight, rightHeight);
    }
    if (node->leftChild == NULL && node->rightChild != NULL)
    {
        rightHeight += heightSearch(node->rightChild);
        node->balanceFactor = max(leftHeight, rightHeight);
    }
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        leftHeight += heightSearch(node->leftChild);
        rightHeight += heightSearch(node->rightChild);
        node->balanceFactor = max(leftHeight, rightHeight);
    }
    return node->balanceFactor;
}

int balanceSearch(Node* node)
{
    if (node->leftChild == NULL && node->rightChild == NULL)
    {
        node->balanceFactor = 0;
    }
    if (node->leftChild != NULL && node->rightChild == NULL)
    {
        node->balanceFactor = 1 + heightSearch(node->leftChild);
    }
    if (node->leftChild == NULL && node->rightChild != NULL)
    {
        node->balanceFactor = 1 + heightSearch(node->rightChild);
    }
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        node->balanceFactor = heightSearch(node->rightChild) - heightSearch(node->leftChild);
    }
    return node->balanceFactor;
}

Node* rotateLeft(Node* node)
{
    Node* newNode = node->rightChild;
    Node* movingNode = newNode->leftChild;
    newNode->leftChild = node;
    node->rightChild = movingNode;
    newNode->parent = node->parent;
    node->parent = newNode;
    movingNode->parent = node;
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
    node->parent = newNode;
    movingNode->parent = node;
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
        if (node->rightChild->balanceFactor <= 0)
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

Node* balanceAllTree(Node* node, int key)
{
    if (node->key != key)
    {
        if (key < node->key)
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

Node* addElement(Node* node, int key, char* value)
{
    Node* root = node;
    Node* parent = node;
    if (node == NULL)
    {
        return NULL;
    }
    while (node != NULL)
    {
        parent = node;
        if (key < node->key)
        {
            node = node->leftChild;
        }
        else if (key > node->key)
        {
            node = node->rightChild;
        }
        else
        {
            free(node->value);
            node->value = _strdup(value);
            node->key = key;
            break;
        }
    }
    Node* newNode = createTree(key, value);
    if (key < parent->key)
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

Node* searchInTree(Node* node, int key)
{
    while (node != NULL)
    {
        if (key == node->key)
        {
            return node;
        }
        else if (key < node->key)
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

Node* deleteElement(Node* node, int key)
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
        if (parent->key > node->key)
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
            parent->rightChild = node->rightChild;
            parent->rightChild->parent = parent;
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
            parent->leftChild = node->leftChild;
            parent->leftChild->parent = parent;
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
    else
    {
        Node* minNode = leftmostChild(node->rightChild);
        int temp = minNode->key;
        free(node->value);
        node->value = minNode->value;
        minNode->value = NULL;
        root = deleteElement(root, minNode->key);
        node->key = temp;
        return root;
    }
}

void deleteTree(Node* node)
{
    if (node != NULL)
    {
        if (node->leftChild != NULL)
        {
            deleteTree(node->leftChild);
        }
        if (node->rightChild != NULL)
        {
            deleteTree(node->rightChild);
        }
        free(node->value);
        free(node);
    }
}