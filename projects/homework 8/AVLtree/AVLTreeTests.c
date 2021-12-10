#include "AVLTreeTests.h"
#include "AVLTree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isTestOnePassed(void)
{
    Node* treeTest = createTree("10", "aaaaa");
    treeTest = addElement(treeTest, "10", "bbbbb");
    Node* temp = searchInTree(treeTest, "10");
    int result = strcmp(getValueInTree(temp), "bbbbb");
    return result == 0;
}

bool isTestTwoPassed(void)
{
    Node* treeTest = createTree("10", "aaaaa");
    treeTest = addElement(treeTest, "12", "bbbbb");
    treeTest = deleteElement(treeTest, "10");
    return searchInTree(treeTest, "10") == NULL && searchInTree(treeTest, "12") != NULL
        && searchInTree(treeTest, "8") == NULL;
}

bool isTestThreePassed(void)
{
    Node* treeTest = createTree("10", "aaaaa");
    treeTest = addElement(treeTest, "12", ":)");
    treeTest = addElement(treeTest, "8", ":(");
    treeTest = deleteElement(treeTest, "10");
    treeTest = addElement(treeTest, "15", "nya");
    treeTest = addElement(treeTest, "25", "25");
    treeTest = deleteElement(treeTest, "8");
    int count = countElements(treeTest);
    return count == 3;
}

int isTestFourPassed(void)
{
    Node* treeTest = createTree("10", "aaaaa");
    treeTest = addElement(treeTest, "12", ":)");
    treeTest = addElement(treeTest, "8", ":(");
    treeTest = addElement(treeTest, "15", "nya");
    treeTest = addElement(treeTest, "25", "25");
    treeTest = deleteElement(treeTest, "10");
    treeTest = addElement(treeTest, "11", "pamagiti");
    treeTest = addElement(treeTest, "14", "-----");
    treeTest = deleteElement(treeTest, "25");
    treeTest = deleteElement(treeTest, "14");
    int height = heightSearch(treeTest);
    return height == 2;
}

int isTestFivePassed(void)
{
    Node* treeTestOne = createTree("10", "aaaaa");
    treeTestOne = addElement(treeTestOne, "12", "bbbbb");
    treeTestOne = addElement(treeTestOne, "8", "ccccc");
    Node* treeTestTwo = createTree("5", "meow");
    treeTestTwo = addElement(treeTestTwo, "8", "meowmeow");
    Node* treeTestThree = createTree("5", "woof");
    treeTestThree = addElement(treeTestThree, "3", "woofwoof");
    return balanceSearch(treeTestOne) == 0 && balanceSearch(treeTestTwo) == 1
        && balanceSearch(treeTestThree) == -1;
}

bool areTestsPassed(void)
{
    return isTestOnePassed() && isTestTwoPassed() && isTestThreePassed()
        && isTestFourPassed() && isTestFivePassed();
}