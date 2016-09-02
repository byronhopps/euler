#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "p14.h"

#define HASH_SIZE 100

struct resultsT getLongestChain(int maxTestValue)
{

    struct nodeT* headNode = initList();

    struct resultsT results;
    results.length = 0;
    results.startNumber = 0;

    // Find the longest sequence
    int i = 1;
    for(i = 1; i < maxTestValue + 1; i++) {

        struct nodeT* curNode = getNode(headNode, i);

        if (getLength(headNode, curNode) > results.length) {
            results.length = curNode->length;
            results.startNumber = curNode->number;
        }

    }

    return results;
}

int collatz(int a)
{
    if (a % 2 == 0) {
        return a / 2;
    } else {
        return 3*a + 1;
    }
}

struct nodeT* createNode()
{
    struct nodeT* newNode = (struct nodeT*)malloc(sizeof(struct nodeT));

    newNode->nextNode = NULL;
    newNode->number = 0;
    newNode->length = 0;

    if (newNode == NULL) {
        fprintf(stdout, "Failed to allocate memory for new node\n");
        exit(-1);
    }

    return newNode;
}

unsigned int getLength(struct nodeT* headNode, struct nodeT* startNode)
{

    if (startNode->length != 0)
        return startNode->length;

    struct nodeT* nextNode = getNode(headNode, collatz(startNode->number));
    int newLength = 1 + getLength(headNode, nextNode);

    startNode->length = newLength;

    return newLength;
}

struct nodeT* getNode(struct nodeT* headNode, unsigned int location)
{
    struct nodeT* curNode = NULL;
    struct nodeT* newNode = NULL;
    for(curNode = headNode; curNode->nextNode != NULL;
            curNode = curNode->nextNode) {

        if (location > curNode->nextNode->number &&
                location < curNode->number) {

            newNode = createNode();
            newNode->number = location;
            newNode->length = 0;

            newNode->nextNode = curNode->nextNode;
            curNode->nextNode = newNode;

            return newNode;

        } else if (curNode->number == location) {
            return curNode;
        }
    }

    // Edge case for last node in the list
    if (curNode->number == location)
        return curNode;

    // Insert node at end of list
    newNode = createNode();
    newNode->number = location;
    newNode->length = 0;

    newNode->nextNode = curNode->nextNode;
    curNode->nextNode = newNode;

    return newNode;
}

void freeAllNodes(struct nodeT* headNode)
{
    while (headNode != NULL) {
        struct nodeT* deadNode = headNode;
        headNode = headNode->nextNode;
        free(deadNode);
    }
}

struct nodeT* initList()
{
    // Create head node
    struct nodeT* headNode = createNode();
    headNode->number = INT_MAX;
    headNode->length = 0;

    // Create end node
    struct nodeT* endNode = createNode();
    endNode->number = 1;
    endNode->length = 1;

    headNode->nextNode = endNode;
    endNode->nextNode = NULL;

    return headNode;
}
