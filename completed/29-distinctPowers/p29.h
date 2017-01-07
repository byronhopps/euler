#include <gmp.h>

// Returns the number of distinct exponents from two numbers
// between minBound and maxBound
int countDistinctPowers(int minBound, int maxBound);

// Appends value the the end of an array if it doesn't exist already
void insertItem(mpz_t* array, mpz_t value);
