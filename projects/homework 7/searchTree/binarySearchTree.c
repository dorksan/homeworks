#include "binarySearchTree.h"
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

char* addValue(char* value)
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

Node* createTree(int key, char* value)
{
    Node* node = calloc(1, sizeof(Node));
    if (node != NULL)
    {
        node->value = addValue(value);
        node->key = key;
    }
    return node;
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
            node->value = addValue(value);
            node->key = key;
            node->key = key;
            break;
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
    newTree->parent = parent;
    return root;
}

Node* searchInTree(Node* node, int key)
{
    if (node == NULL)
    {
        return NULL;
    }
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
        }
        else
        {
            free(node->value);
            free(node);
            parent->rightChild = NULL;
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
        }
        else
        {
            free(node->value);
            free(node);
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
        }
        else
        {
            free(node->value);
            free(node);
        }
    }
    else
    {
        Node* minNode = leftmostChild(node->rightChild);
        int temp = minNode->key;
        free(node->value);
        node->value = minNode->value;
        minNode->value = NULL;
        deleteElement(root, minNode->key);
        node->key = temp;
    }
    return root;
}

Node* deleteTree(Node* node)
{
    if (node == NULL)
    {
        return NULL;
    }
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