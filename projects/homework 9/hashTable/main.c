#include "list.h"
#include <stdio.h>
#include <string.h>

#define MOD 1021
#define HASHTABLE_SIZE 10000

int hashFunction(const char* string)
{
    const int p = 67;
    const length = strlen(string);
    int hash = 0;
    for (int i = 0; i < length; i++)
    {
        hash = (hash * p + string[i]) % MOD;
    }
    return abs(hash);
}

typedef struct List
{
    char value;
    int count;
    int hash;
    List* next;
} List;

List* HashTable[HASHTABLE_SIZE];

void createHashTable(List** hashTable)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

void add(List** hashTable, const char* string)
{
    int index = hashFunction(string);
    List* node = calloc(1, sizeof(List));
    if (hashTable[index] == NULL)
    {
        if (node != NULL)
        {
            if (node->value == *string)
            {
                node->count++;
            }
            else
            {
                List* newNode = calloc(1, sizeof(List));
                newNode->value = _strdup(*string);
                newNode->next = node;
                newNode->count++;
                hashTable[index] = newNode;
            }
        }
    }
    else
    {
        node->value = _strdup(*string);
        node->next = NULL;
        node->count = 1;
        hashTable[index] = node;
    }
}

int main()
{
    printf("%d", hashFunction("фффф"));
}