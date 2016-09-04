#include "p12.h"
#include <math.h>

// Returns the nth triangle number
unsigned int triNum(unsigned int n)
{
    return n * (n + 1) / 2;
}

// Returns the number of divisors n has
unsigned int countDivisors(unsigned int n)
{
    int factors = 0;

    for (int i = 1; i <= sqrtf((float)n); i++) {

        if (n % i != 0)
            continue;

        if (n == i*i)
            factors += 1;
        else
            factors += 2;
    }

    return factors;
}

// Returns the first triangular number with n divisors
unsigned int getTriNumByDivisors(unsigned int n)
{
    int i;

    for (i = 1; countDivisors(triNum(i)) <= n; i++);

    return triNum(i);
}
