#pragma once

typedef struct Stack Stack;

// Добавляет элемент в стек
Stack* push(Stack* stack, int element, int* errorCode);

// Удаляет элемент из стека
Stack* pop(Stack* stack, int* errorCode);

// Возвращает верхний элемент стека
int top(Stack* stack, int* errorCode);

// Удаляет стек
void deleteStack(Stack* stack);