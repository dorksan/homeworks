#pragma once

typedef struct Node Node;

// Создает дерево
Node* createTree(int key, char* value);

// Подсчитывает высоту поддерева от заданного узла
int heightSearch(Node* node);

// Подсчитывает баланс для заданного узла
int balanceSearch(Node* node);

// Малый левый поворот
Node* rotateLeft(Node* node);

// Малый правый поворот
Node* rotateRight(Node* node);

// Большой левый поворот
Node* bigRotateLeft(Node* node);

// Большой правый поворот
Node* bigRotateRight(Node* node);

// Балансирует дерево
Node* balanceAllTree(Node* node, int key);

// Добавляет элемент
Node* addElement(Node* node, int key, char* value);

// Поиск элемента в дереве
Node* searchInTree(Node* node, int key);

// Получение значение по заданному узлу
char* getValueInTree(Node* node);

// Находит наименьший элемент в дереве
Node* leftmostChild(Node* node);

// Удаляет элемент
Node* deleteElement(Node* node, int key);

// Удаляет дерево
void deleteTree(Node* node);

// Подсчет количества элементов в дереве (используется в тестах)
int countElements(Node* node);