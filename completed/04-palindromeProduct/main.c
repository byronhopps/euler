#include <stdio.h>
#include <time.h>
#include "p4.h"

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

    char garbage[32];
    int numDigits;

    // Argument not only a number
    if (sscanf(argv[1], "%i%s", &numDigits, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    // Argument a non-natural number
    if (numDigits < 1) {
        puts("Number must be greater than zero");
        return -1;
    }

    clock_t start, end;
    double cpuTimeUsed;

    start = clock();

    // Call function that solves problem
    int result = largestPalindrome(numDigits);

    end = clock();

    cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    // printf result of program execution
    printf("Largest palindrome product with %d digits is %d\n", numDigits, result);
    printf("Program executed in %f seconds\n", cpuTimeUsed);

    return 0;
}
