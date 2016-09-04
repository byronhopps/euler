#include <stdio.h>
#include <time.h>
#include "p11.h"

#define NUM_ARGS 1

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

    clock_t start, end;
    double cpuTimeUsed;

    start = clock();
    int result = largestDiagProduct();
    end = clock();

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The largest diagonal product is %i\n", result);
    printf("Program executed in %f seconds\n", cpuTimeUsed);

    return 0;
}
