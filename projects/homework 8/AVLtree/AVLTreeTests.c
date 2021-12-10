#include "AVLTreeTests.h"
#include "AVLTree.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool testAddAndGetValueFunction(void)
{
    Node* tree = createTree("10", "aaaaa");
    tree = addElement(tree, "10", "bbbbb");
    Node* temp = searchInTree(tree, "10");
    int resultOne = strcmp(getValueInTree(temp), "bbbbb");
    int resultTwo = strcmp(getValueInTree(temp), "aaaaa");
    tree = deleteTree(tree);
    return resultOne == 0 && resultTwo != 0;
}

bool testDeleteAndSearchFunction(void)
{
    Node* tree = createTree("10", "aaaaa");
    tree = addElement(tree, "12", "bbbbb");
    tree = addElement(tree, "8", "ccccc");
    tree = deleteElement(tree, "10");
    tree = deleteElement(tree, "20");
    bool isTenInTree = searchInTree(tree, "10") == NULL;
    bool isTwelveInTree = searchInTree(tree, "12") == NULL;
    bool isEightInTree = searchInTree(tree, "8") == NULL;
    bool isSevenInTree = searchInTree(tree, "7") == NULL;
    bool isTwentyInTree = searchInTree(tree, "20") == NULL;
    tree = deleteTree(tree);
    return isTenInTree && !isTwelveInTree && !isEightInTree
        && isSevenInTree && isTwentyInTree;
}

bool checkNumberOfElements(void)
{
    Node* tree = createTree("10", "aaaaa");
    tree = addElement(tree, "12", ":)");
    tree = addElement(tree, "8", ":(");
    tree = deleteElement(tree, "10");
    tree = addElement(tree, "15", "nya");
    tree = addElement(tree, "25", "25");
    tree = deleteElement(tree, "8");
    int count = countElements(tree);
    tree = deleteTree(tree);
    return count == 3;
}

int checkHeight(void)
{
    Node* tree = createTree("J", "aaaaa");
    tree = addElement(tree, "L", ":)");
    tree = addElement(tree, "H", ":(");
    tree = addElement(tree, "O", "nya");
    tree = addElement(tree, "Y", "25");
    tree = deleteElement(tree, "J");
    tree = addElement(tree, "K", "pamagiti");
    tree = addElement(tree, "N", "-----");
    tree = deleteElement(tree, "Y");
    tree = deleteElement(tree, "N");
    int height = heightSearch(tree);
    tree = deleteTree(tree);
    return height == 3;
}

int testBalanceSearchFunction(void)
{
    Node* treeOne = createTree("10", "aaaaa");
    treeOne = addElement(treeOne, "12", "bbbbb");
    treeOne = addElement(treeOne, "8", "ccccc");
    Node* treeTwo = createTree("5", "meow");
    treeTwo = addElement(treeTwo, "8", "meowmeow");
    Node* treeThree = createTree("5", "woof");
    treeThree = addElement(treeThree, "3", "woofwoof");
    bool balanceOne = balanceSearch(treeOne) == 0;
    bool balanceTwo = balanceSearch(treeTwo) == 1;
    bool balanceThree = balanceSearch(treeThree) == -1;
    treeOne = deleteTree(treeOne);
    treeTwo = deleteTree(treeTwo);
    treeThree = deleteTree(treeThree);
    return balanceOne && balanceTwo && balanceThree;
}

bool areTestsPassed(void)
{
    return testAddAndGetValueFunction() && testDeleteAndSearchFunction()
        && checkNumberOfElements() && checkHeight()
        && testBalanceSearchFunction();
}