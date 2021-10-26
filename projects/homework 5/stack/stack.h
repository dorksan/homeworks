#pragma once

typedef struct Stack Stack;

// Создает стек
Stack* createStack(char element);

// Добавляет элемент в стек
void push(Stack** head, char element);

// Удаляет элемент из стека
void pop(Stack** head);

// Возвращает верхний элемент стека
void* peek(Stack* head);

 // Удаляет стек
void deleteStack(Stack** head);