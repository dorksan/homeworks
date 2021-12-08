#include "parseTree.h"
#include "testParseTree.h"
#include <stdbool.h>
#include <string.h>

#define SIZE 50

bool testAddAndGetStringFunction(void)
{
    char inputString[SIZE] = "( * ( + ( - ( / 16 -2 ) 7 ) 1 ) 2 ) ";
    Node* node = createTree(inputString);
    char outputString[SIZE] = { '\0' };
    getString(node, outputString, SIZE);
    deleteTreeRecursive(node);
    return strcmp(inputString, outputString) == 0;
}

bool testGetResultFunction(void)
{
    char inputStringOne[SIZE] = "( * ( + ( - ( / 16 -2 ) 7 ) 1 ) 2 ) ";
    char inputStringTwo[SIZE] = "( * ( + ( - ( / 16 2 ) 7 ) 1 ) 2 ) ";
    char inputStringThree[SIZE] = "( * ( + 1 1 ) 2 ) ";
    Node* nodeOne = createTree(inputStringOne);
    Node* nodeTwo = createTree(inputStringTwo);
    Node* nodeThree = createTree(inputStringThree);
    int resultOne = getResult(nodeOne);
    int resultTwo = getResult(nodeTwo);
    int resultThree = getResult(nodeThree);
    deleteTreeRecursive(nodeOne);
    deleteTreeRecursive(nodeTwo);
    deleteTreeRecursive(nodeThree);
    return resultOne == -28 && resultTwo == 4
        && resultThree == 4;
}

bool areTestsPassed(void)
{
    return testAddAndGetStringFunction() && testGetResultFunction();
}