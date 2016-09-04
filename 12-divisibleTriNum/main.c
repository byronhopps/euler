#include <stdio.h>
#include "p12.h"

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
    int intArg;

    // Argument not only a number
    if (sscanf(argv[1], "%i%s", &intArg, garbage) != 1) {
        puts("Argument improperly formatted");
        return -1;
    }

    // Argument a non-natural number
    if (intArg < 1) {
        puts("Number must be greater than zero");
        return -1;
    }

    // Put line of code here that calls funtion from problem
    int result = countDivisors(intArg);

    printf("%i has %i divisors\n", intArg, result);

    return 0;
}
