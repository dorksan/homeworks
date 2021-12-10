#pragma once

typedef struct Node Node;

// Создает дерево
Node* createTree(char* key, char* value);

// Добавляет элемент
Node* addElement(Node* node, char* key, char* value);

// Поиск элемента в дереве
Node* searchInTree(Node* node, char* key);

// Получение значение по заданному узлу
char* getValueInTree(Node* node);

// Удаляет элемент
Node* deleteElement(Node* node, char* key);

// Удаляет дерево
Node* deleteTree(Node* node);

// Подсчет количества элементов в дереве (используется в тестах)
int countElements(Node* node);