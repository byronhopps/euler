#include "p56.h"
#include <stdio.h>

int digitSum(int num)
{

    char str[32];
    sprintf(str, "%i", num);

    int i, sum = 0;
    for (i = 0; i < 32 && str[i] != 0; i++) {
        sum += (int)str[i] - 48;
    }

    return sum;
}

int power(int a, int b)
{

    int power = 1;
    while (b-- > 0) {
        power *= a;
    }

    return power;
}
