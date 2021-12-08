#include "binarySearchTreeTests.h"
#include "binarySearchTree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool testAddAndGetValueFunction(void)
{
    Node* tree = createTree(10, "aaaaa");
    tree = addElement(tree, 10, "bbbbb");
    Node* temp = searchInTree(tree, 10);
    int resultOne = strcmp(getValueInTree(temp), "bbbbb");
    int resultTwo = strcmp(getValueInTree(temp), "ccccc");
    tree = deleteTree(tree);
    return resultOne == 0 && resultTwo != 0;
}

bool testDeleteAndSearchFunction(void)
{
    Node* tree = createTree(10, "aaaaa");
    tree = addElement(tree, 12, "bbbbb");
    tree = addElement(tree, 8, "ccccc");
    tree = deleteElement(tree, 10);
    tree = deleteElement(tree, 20);
    bool isTenInTree = searchInTree(tree, 10) == NULL;
    bool isTwelveInTree = searchInTree(tree, 12) == NULL;
    bool isEightInTree = searchInTree(tree, 8) == NULL;
    bool isSevenInTree = searchInTree(tree, 7) == NULL;
    bool isTwentyInTree = searchInTree(tree, 20) == NULL;
    tree = deleteTree(tree);
    return isTenInTree && !isTwelveInTree && !isEightInTree
        && isSevenInTree && isTwentyInTree;
}

bool checkNumberOfElements(void)
{
    Node* tree = createTree(10, "aaaaa");
    tree = addElement(tree, 12, ":)");
    tree = addElement(tree, 8, ":(");
    tree = deleteElement(tree, 10);
    tree = addElement(tree, 15, "nya");
    tree = addElement(tree, 25, "25");
    tree = deleteElement(tree, 8);
    int count = countElements(tree);
    deleteTree(tree);
    return count == 3;
}

bool areTestsPassed(void)
{
    return testAddAndGetValueFunction() && testDeleteAndSearchFunction() && checkNumberOfElements();
}