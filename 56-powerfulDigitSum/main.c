#include <math.h>
#include "p56.h"

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

    return 0;
}
