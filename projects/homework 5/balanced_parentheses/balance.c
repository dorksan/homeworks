#include "balance.h"
#include "../stack/stack.h"
#include <stdlib.h>
#include <stdbool.h>

bool balance(char* string, int size)
{
    Stack* stack = NULL;
    for (int i = 0; i < size; i++)
    {
        switch (string[i])
        {
        case '(':
            stack = push(stack, ')');
            break;
        case '{':
            stack = push(stack, '}');
            break;
        case '[':
            stack = push(stack, ']');
            break;
        case ')':
        case '}':
        case ']':
            if (top(stack) != string[i])
            {
                stack = deleteStack(stack);
                return false;
            }
            int element = 0;
            stack = pop(stack, &element);
            break;
        default:
            break;
        }
    }
    bool isEmpty = stack == NULL;
    stack = deleteStack(stack);
    return isEmpty;
}