#pragma once

typedef struct Node Node;

// Создает дерево
Node* createTree(int key, char* value);

// Добавляет элемент
Node* addElement(Node* node, int key, char* value);

// Поиск элемента в дереве
Node* searchInTree(Node* node, int key);

// Получение значение по заданному узлу
char* getValueInTree(Node* node);

// Находит наименьший элемент в дереве
Node* leftmostChild(Node* node);

// Удаляет элемент
void deleteElement(Node* node, int key);

// Удаляет дерево
void deleteTree(Node* node);

// Подсчет количества элементов в дереве (используется в тестах)
int countElements(Node* node);