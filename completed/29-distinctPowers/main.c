#include <stdio.h>
#include <time.h>
#include "p29.h"

#define NUM_ARGS 3

int main(int argc, char* argv[])
{

    // Too few arguments
    if (argc < NUM_ARGS) {
        puts("Not enougb arguments");
        return -1;
    }

    // Too many arguments
    if (argc > NUM_ARGS) {
        puts("Too many arguments");
        return -1;
    }

    char garbage[32];
    int minBound, maxBound;

    // Argument not only a number
    if (sscanf(argv[1], "%d%s", &minBound, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    if (sscanf(argv[2], "%d%s", &maxBound, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    // Argument a non-natural number
    if (minBound < 1 || maxBound < 1) {
        puts("Number must be greater than zero");
        return -1;
    }

    clock_t start, end;
    double cpuTimeUsed;

    start = clock();

    // Solve problem 29
    int result = countDistinctPowers(minBound, maxBound);

    end = clock();

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf result of program execution
    printf("Program executed in %f seconds, finding %d distinct terms\n",
            cpuTimeUsed, result);

    return 0;
}
