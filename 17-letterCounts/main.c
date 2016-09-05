#include <stdio.h>
#include <time.h>
#include "p17.h"

#define NUM_ARGS 3

int main(int argc, char* argv[])
{

    // Too many arguments
    if (argc > NUM_ARGS) {
        puts("Too many arguments");
        return -1;
    }

    char garbage[32];
    int min, max;

    // Ensures that the arguments only contain a number
    if (sscanf(argv[1], "%i%s", &min, garbage) != 1) {
        puts("Argument 1 improperly formatted");
        return -1;

    } else if (argc > 2 && sscanf(argv[2], "%i%s", &max, garbage) != 1) {
        puts("Argument 2 improperly formatted");
        return -1;

    // Arguments must be greater than zero
    } else if (min < 1 || (argc > 2 && max < 1)) {
        puts("Bounds must be greater than zero");
        return -1;

    } else if (argc > 2 && min > max) {
        puts("Upper bound must be greater than lower bound");
        return -1;
    }

    clock_t start, end;
    double cpuTimeUsed;

    start = clock();
    int result = (argc == 3) ? getRangedCharCount(min, max) : \
        numCharCount(min);
    end = clock();

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (argc == 3) {
        printf("%i characters are needed to print out all numbers from "
                "%i to %i\n", result, min, max);
    } else {
        printf("%d has %d characters\n", min, result);
    }
    printf("Program executed in %f seconds\n", cpuTimeUsed);

    return 0;
}
