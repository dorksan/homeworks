#pragma once 

typedef struct Node Node;

Node* createNode();

Node* createTree(const char* string);

int getResult(Node* node);

void getString(Node* node, char* string, int size);

void deleteTreeRecursive(Node* node);