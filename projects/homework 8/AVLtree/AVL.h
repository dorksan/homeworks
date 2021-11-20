#pragma once

typedef struct Node Node;

Node* createTree(int key, char* value);

int heightSearch(Node* node);

int balanceSearch(Node* node);

Node* rotateLeft(Node* node);

Node* rotateRight(Node* node);

Node* bigRotateLeft(Node* node);

Node* bigRotateRight(Node* node);

Node* balance(Node* node);

Node* balanceAllTree(Node* node, int key);

Node* addElement(Node* tree, int key, char* value);

Node* searchInTree(Node* tree, int key);

char* getValueInTree(Node* tree);

Node* leftmostChild(Node* tree);

Node* deleteElement(Node* tree, int key);

void deleteTree(Node* node);