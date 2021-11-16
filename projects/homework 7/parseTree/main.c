#include "parseTree.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int main()
{
    Node* node = createTree("(* (+ 1 1) 2)");
    printf("%d\n", getResult(node));
    char string[SIZE] = { '\0' };
    getString(node, string, SIZE);
    printf("%s", string);
}