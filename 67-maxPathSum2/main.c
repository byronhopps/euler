#include <stdio.h>
#include <time.h>
#include "p67.h"

#define NUM_ARGS 2

int main(int argc, char* argv[])
{

    // Too few arguments
    if (argc < NUM_ARGS) {
        puts("Not enough arguments");
        return -1;
    }

    // Too many arguments
    if (argc > NUM_ARGS) {
        puts("Too many arguments");
        return -1;
    }

    char filePath[128];
    sscanf(argv[1], "%127s", filePath);

    clock_t start, end;
    double cpuTimeUsed;

    FILE* inputFile = fopen(filePath, "r");
    start = clock();
    int result = getMaxPathSum(inputFile);
    end = clock();
    fclose(inputFile);

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("The maximum path sun is %i\n", result);
    printf("Program executed in %f seconds\n", cpuTimeUsed);

    return 0;
}
