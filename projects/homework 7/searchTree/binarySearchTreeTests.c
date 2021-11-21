#include "binarySearchTreeTests.h"
#include "binarySearchTree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isTestOnePassed(void)
{
    Node* treeTest = createTree(10, "aaaaa");
    treeTest = addElement(treeTest, 10, "bbbbb");
    Node* temp = searchInTree(treeTest, 10);
    int result = strcmp(getValueInTree(temp), "bbbbb");
    return result == 0;
}

bool isTestTwoPassed(void)
{
    Node* treeTest = createTree(10, "aaaaa");
    treeTest = addElement(treeTest, 12, "bbbbb");
    deleteElement(treeTest, 12);
    return searchInTree(treeTest, 10) != NULL && searchInTree(treeTest, 12) == NULL
        && searchInTree(treeTest, 8) == NULL;
}

bool isTestThreePassed(void)
{
    Node* treeTest = createTree(10, "aaaaa");
    treeTest = addElement(treeTest, 12, ":)");
    treeTest = addElement(treeTest, 8, ":(");
    deleteElement(treeTest, 10);
    treeTest = addElement(treeTest, 15, "nya");
    treeTest = addElement(treeTest, 25, "25");
    deleteElement(treeTest, 8);
    int count = countElements(treeTest);
    return count == 3;
}

bool areTestsPassed(void)
{
    return isTestOnePassed() && isTestTwoPassed() && isTestThreePassed();
}