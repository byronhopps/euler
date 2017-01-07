#include "p4.h"
#include <stdio.h>
#include <string.h>

int largestPalindrome(int numDigits)
{

    int maxResult = 0;

    // The upper bound (exclusive) is 10^numDigits
    int maxNum = power10(numDigits);

    // The lower bound (inclusive) is 10^(numDigits-1)
    int minNum = power10(numDigits-1);

    for (int i = minNum; i < maxNum; i++) {
        for (int j = i; j < maxNum; j++) {
            int result = i*j;

            if (isPalindrome(result) && (result > maxResult)) {
                maxResult = result;
            }
        }
    }

    return maxResult;
}

int isPalindrome(int num)
{
    char numStr[32] = {0};

    sprintf(numStr, "%d", num);

    int len = strlen(numStr);
    int idx = 0;

    while(idx <= len-idx-1) {
        if (numStr[idx] != numStr[len-idx-1]) {
            return 0;
        }

        idx++;
    }

    return 1;
}

int power10(int num)
{
    int result = 1;

    for (int i = 0; i < num; i++) {
        result *= 10;
    }

    return result;
}
