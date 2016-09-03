#include <stdio.h>
#include "p56.h"

// TODO: Change type from int to arbitrary precision
// This will require gmp or an equivalent

int main()
{

    int a, b, num, maxSum = 0;
    for (a = 1; a < 100; a++) {
        for (b = 1; b < 100; b++) {

            num = power(a, b);

            int sum = digitSum(num);
            maxSum = (sum > maxSum) ? sum : maxSum;
        }
    }

    printf("The maximum sum of digits is %i\n", maxSum);

    return 0;
}
