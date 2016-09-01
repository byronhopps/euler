#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "p14.h"

struct resultsT getLongestChain(int maxTestValue)
{
    // Create head node
    struct nodeT* headNode = createNode();
    headNode->number = 1;
    headNode->length = 1;

    // Create end sentinal node
    struct nodeT* endNode = createNode();

    headNode->nextNode = endNode;
    endNode->nextNode = NULL;
    endNode->number = INT_MAX;
    endNode->length = 0;

    struct resultsT results;
    results.length = 0;
    results.startNumber = 0;

    // Find the longest sequence
    int i = 1;
    for(i = 1; i < maxTestValue + 1; i++) {

        struct nodeT* curNode = getNode(headNode, i);

        curNode->length = getLength(headNode, curNode);

        if (curNode->length > results.length) {
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

    int nextLocation = collatz(startNode->number);

    return 1 + getLength(headNode, getNode(headNode, nextLocation));
}

struct nodeT* getNode(struct nodeT* headNode, unsigned int location)
{
    struct nodeT* curNode = NULL;
    for(curNode = headNode; curNode->nextNode != NULL;
            curNode = curNode->nextNode) {

        if (location < curNode->nextNode->number &&
                location > curNode->number) {

            struct nodeT* newNode = createNode();
            newNode->number = location;
            newNode->length = 0;

            newNode->nextNode = curNode->nextNode;
            curNode->nextNode = newNode;

            return newNode;

        } else if (curNode->number == location) {

            return curNode;
        }
    }

    puts("This shouldn't happen");
    return NULL;
}
