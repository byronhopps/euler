#include <stdlib.h>
#include <stdio.h>
#include "p29.h"

#define ARRAY_SIZE 100000

// Returns the number of distinct exponents from two numbers
// between minBound and maxBound
int countDistinctPowers(int minBound, int maxBound)
{
    // Declare array to hold distinct numbers
    unsigned long long int results[ARRAY_SIZE] = {0};

    for (int i = minBound; i <= maxBound; i++) {
        for (int j = minBound; j <= maxBound; j++) {
            insertItem(results, power(i, j));
        }
    }

    // Count items in array
    int termCount = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (results[i] != 0) {
            termCount++;
        } else {
            return termCount;
        }
    }

    fprintf(stderr, "Results array overflow\n");
    exit(-1);
    return -1;
}

// Returns an integer representing a^b
int power(int a, int b)
{
    int result = 1;

    while(b) {
        if (b & 1)
            result *= a;

        b >>= 1;
        a *= a;
    }

    return result;
}

void insertItem(unsigned long long int* array, int value)
{
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        if (array[idx] == (unsigned int)value) {
            return;
        } else if (array[idx] == 0) {
            array[idx] = value;
            return;
        }
    }
    fprintf(stderr, "Results array overflow\n");
    exit(-1);
    return;
}
