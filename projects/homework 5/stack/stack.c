#include "stack.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Stack
{
    char* value;
    struct Stack* next;
} Stack;

Stack* createStack(char element)
{
    Stack* stack = calloc(1, sizeof(Stack));
    if (stack == NULL)
    {
        return;
    }
    stack->value = element;
    stack->next = NULL;
    return stack;
}

void push(Stack** head, char element)
{
    Stack* newStack = createStack(element);
    newStack->next = *head;
    *head = newStack;
}

void pop(Stack** head)
{
    if (*head == NULL || head == NULL)
    {
        return;
    }
    Stack* temp = *head;
    *head = temp->next;
    free(temp);
}

void* peek(Stack* head)
{
    return head->value;
}

bool isEmpty(Stack* head)
{
    return head == NULL;
}

void deleteStack(Stack** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}