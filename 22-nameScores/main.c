#include <stdio.h>
#include <time.h>
#include "p22.h"

#define NUM_ARGS 2

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

    char* filePath = argv[1];

    clock_t start, end;
    double cpuTimeUsed;

    start = clock();
    unsigned long long int result = getNameScores(filePath);
    end = clock();

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf result of program execution
    printf("Program executed in %f seconds\n", cpuTimeUsed);

    return 0;
}
