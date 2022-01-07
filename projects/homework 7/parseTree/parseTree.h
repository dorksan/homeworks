#pragma once 

typedef struct Node Node;

// Создает узел дерева
Node* createNode();

// Создает дерево разбора
Node* createTree(const char* string);

// Подсчитывает результат выражения
int getResult(Node* node);

// Выводит дерево в строку
void getString(Node* node, char* string, int size);

// Рекурсивно удаляет дерево
void deleteTreeRecursive(Node* node);