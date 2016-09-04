#include <stdio.h>
#include "p14.h"

int main(int argc, char* argv[])
{

    // Too few arguments
    if (argc < 2) {
        puts("Please enter an upper bound");
        return -1;
    }

    // Too many arguments
    if (argc > 2) {
        puts("Too many arguments");
        return -1;
    }

    char garbage[32];
    int maxTestValue;

    // Argument not only a number
    if (sscanf(argv[1], "%i%s", &maxTestValue, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    // Argument a non-natural number
    if (maxTestValue < 1) {
        puts("Number must be greater than zero");
        return -1;
    }

    struct resultsT results = getLongestChain(maxTestValue);

    printf("Longest chain starts at %i, and has %i terms\n",
           results.startNumber, results.length);

    return 0;
}
