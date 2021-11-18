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

Node* addElement(Node* tree, int key, char* value)
{
    Node* root = tree;
    Node* parent = tree;
    if (tree == NULL)
    {
        return NULL;
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
            free(tree->value);
            tree->value = _strdup(value);
            tree->key = key;
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

char* getValueInTree(Node* tree)
{
    return tree->value;
}

Node* leftmostChild(Node* tree)
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

int findBalanceFactor(Node* node)
{
    if (node->leftChild == NULL && node->rightChild == NULL)
    {
        node->balanceFactor = 0;
        return node->balanceFactor;
    }
    if (node->leftChild != NULL && node->rightChild == NULL)
    {
        int rightHeight = 0;
        int leftHeight = 1 + findBalanceFactor(node->leftChild);
        node->balanceFactor = rightHeight - leftHeight;
        return node->balanceFactor;
    }
    if (node->leftChild == NULL && node->rightChild != NULL)
    {
        int leftHeight = 0;
        int rightHeight = 1 + findBalanceFactor(node->rightChild);
        node->balanceFactor = rightHeight - leftHeight;
        return node->balanceFactor;
    }
    if (node->leftChild != NULL && node->rightChild != NULL)
    {
        int leftHeight = findBalanceFactor(node->leftChild);
        int rightHeight = findBalanceFactor(node->rightChild);
        node->balanceFactor = rightHeight - leftHeight;
        return node->balanceFactor;
    }
    return node->balanceFactor;
}

Node* rotate()
{

}


void deleteElement(Node* tree, int key)
{
    if (tree == NULL)
    {
        return;
    }
    tree = searchInTree(tree, key);
    if (tree == NULL)
    {
        return;
    }
    Node* parent = tree->parent;
    if (tree->leftChild == NULL && tree->rightChild == NULL)
    {
        if (parent == NULL)
        {
            free(tree->value);
            free(tree);
            return;
        }
        if (parent->key > tree->key)
        {
            free(tree->value);
            free(tree);
            parent->leftChild = NULL;
        }
        else
        {
            free(tree->value);
            free(tree);
            parent->rightChild = NULL;
        }
    }
    else if (tree->leftChild == NULL && tree->rightChild != NULL)
    {
        parent->rightChild = tree->rightChild;
        parent->rightChild->parent = parent;
        free(tree->value);
        free(tree);
    }
    else if (tree->rightChild == NULL && tree->leftChild != NULL)
    {
        parent->leftChild = tree->leftChild;
        parent->leftChild->parent = parent;
        free(tree->value);
        free(tree);
    }
    else
    {
        Node* minNode = leftmostChild(tree->rightChild);
        tree->key = minNode->key;
        free(tree->value);
        tree->value = minNode->value;
        minNode->value = NULL;
        deleteElement(tree->rightChild, minNode->key);
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