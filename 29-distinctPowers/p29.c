#include <stdlib.h>
#include "p29.h"

// Returns the number of distinct exponents from two numbers
// between minBound and maxBound
int countDistinctPowers(int minBound, int maxBound)
{
    // Setup linked list
    struct listItem* listHead = NULL;
    listHead = (struct listItem*)malloc(sizeof(struct listItem));
    listHead->next = NULL;
    listHead->value = -1;

    for (int i = minBound; i <= maxBound; i++) {
        for (int j = minBound; j <= maxBound; j++) {
            insertItem(listHead, power(i, j));
        }
    }

    int nodeCount = 0;
    struct listItem* curNode = listHead;
    do {
        // Don't count sentinel nodes
        if (curNode->value > 0)
            nodeCount++;

        curNode = curNode->next;
    } while (curNode != NULL);

    return nodeCount;
}

// Returns an integer representing a^b
int power(int a, int b)
{
    int result = 1;

    while(b) {
        if (b & 1)
            result *= a;

        b >>= 1;
        a *= a;
    }

    return result;
}

// Inserts a value into a linked list
void insertItem(struct listItem* head, int value)
{
    struct listItem* curNode = head;
    do {

        // Do nothing if value already exists in list
        if (curNode->value == value) {
            return;

        // Insert after current node if value to insert falls after current
        // node and before next node (or next node doesn't exist)
        } else if ((curNode->next == NULL || curNode->next->value > value) &&
                (curNode->value < value)) {

            // Add node to linked list
            struct listItem* newNode = NULL;
            newNode = (struct listItem*)malloc(sizeof(struct listItem));
            newNode->next = curNode->next;
            curNode->next = newNode;
            newNode->value = value;
            return;
        }

        curNode = curNode->next;
    } while (curNode != NULL);

    return;
}
