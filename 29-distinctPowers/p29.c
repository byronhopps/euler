#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>
#include "p29.h"

#define ARRAY_SIZE 100000

// Returns the number of distinct exponents from two numbers
// between minBound and maxBound
int countDistinctPowers(int minBound, int maxBound)
{
    // Declare and initialize array to hold distinct numbers
    mpz_t results[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        mpz_init(results[i]);
    }

    // Declare and initialize current result
    mpz_t result;
    mpz_init(result);

    for (int i = minBound; i <= maxBound; i++) {
        for (int j = minBound; j <= maxBound; j++) {
            mpz_ui_pow_ui(result, (unsigned int)i, (unsigned int)j);
            insertItem(results, result);
        }
    }

    // Count items in array
    int termCount = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        // If the current spot in the array is non=zero
        if (mpz_sgn(results[i]) != 0) {
            termCount++;
        } else {
            return termCount;
        }
    }

    fprintf(stderr, "Results array overflow\n");
    exit(-1);
    return -1;
}

void insertItem(mpz_t* array, mpz_t value)
{
    for (int idx = 0; idx < ARRAY_SIZE; idx++) {
        // If the array value and the current value are the same
        if (mpz_cmp(array[idx], value) == 0) {
            return;
        } else if (mpz_sgn(array[idx]) == 0) {
            mpz_set(array[idx], value);
            return;
        }
    }
    fprintf(stderr, "Results array overflow\n");
    exit(1);
    return;
}
