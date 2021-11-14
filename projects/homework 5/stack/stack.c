#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int value;
    struct Stack* next;
} Stack;

Stack* push(Stack* stack, int element, int* errorCode)
{
    Stack* newStack = calloc(1, sizeof(Stack));
    if (newStack == NULL)
    {
        *errorCode = 1;
        return stack;
    }
    newStack->value = element;
    newStack->next = stack;
    *errorCode = 0;
    return newStack;
}

Stack* pop(Stack* stack, int* errorCode)
{
    if (stack == NULL)
    {
        *errorCode = 1;
        return NULL;
    }
    Stack* newStack = stack->next;
    *errorCode = 0;
    free(stack);
    return newStack;
}

int top(Stack* stack, int* errorCode)
{
    if (stack != NULL)
    {
        *errorCode = 0;
        return stack->value;
    }
    *errorCode = 1;
    return 0;
}

void deleteStack(Stack* stack)
{
    while (stack != NULL)
    {
        Stack* newStack = stack->next;
        free(stack);
        stack = newStack;
    }
}