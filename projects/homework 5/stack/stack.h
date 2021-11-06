#pragma once

typedef struct Stack Stack;

// Добавляет элемент в стек
Stack* push(Stack* stack, int element);

// Удаляет элемент из стека
Stack* pop(Stack* stack, int* value);

// Возвращает верхний элемент стека
int top(Stack* stack, int* errorCode);

// Удаляет стек
Stack* deleteStack(Stack* stack);