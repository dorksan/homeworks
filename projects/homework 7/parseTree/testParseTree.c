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
    return getResult(nodeOne) == -28 && getResult(nodeTwo) == 4
        && getResult(nodeThree) == 4;
}

bool areTestsPassed(void)
{
    return testAddAndGetStringFunction() && testGetResultFunction();
}