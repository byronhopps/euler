#include <stdio.h>
#include <limits.h>
#include "p14.h"

#define DEBUG

int main(int argc, char* argv[])
{

    // Too few arguments
    if (argc < 2) {
        puts("Please enter a starting number");
        return -1;
    }

    // Too many arguments
    if (argc > 2) {
        puts("Too many arguments");
        return -1;
    }

    char garbage[32];
    int testValue;

    // Argument not only a number
    if (sscanf(argv[1], "%i%s", &testValue, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    // Argument a non-natural number
    if (testValue < 1) {
        puts("Number must be greater than zero");
        return -1;
    }

    struct nodeT* = headNode = initList();
    int length = getLength(headNode, getNode(headNode, testValue));

    printf("Chain starting at %i has %i terms\n", testValue, length);

    freeAllNodes(headNode);

    return 0;
}
