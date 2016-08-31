#include <stdint.h>
#include <stdlib.h>

#include <stdio.h>

int getLongestChain(int maxTestValue)
{
    // Create Arrays
    int size = 5 * maxTestValue;
    uint32_t* nextValue = (uint32_t*)calloc(size, sizeof(uint32_t));
    uint16_t* lengthArray = (uint16_t*)calloc(size, sizeof(uint16_t));

    nextValue[0] = 1;
    nextValue[1] = 1;
    lengthArray[0] = 1;
    lengthArray[1] = 1;


    // Fill nextValue Array
    int i = 1;
    for (i = 1; i < maxTestValue; i++) {

        if (nextValue[i] != 0) {
            break;
        } else {
            nextValue[i] = collatz(i);
        }
    }

    // Fill lengthArray
    for (i = 1; i < maxTestValue; i++) {
        if (lengthArray[i] == 0)
            lengthArray[i] = chainLength(i, nextValue, lengthArray);
    }

    puts("");
    for (i = maxTestValue; i != 1; i = nextValue[i]) {
        printf("%i ",i);
    }
    printf("%i: L = %i\n", i, lengthArray[maxTestValue]);

    // Find Maximum
    int max = 0;
    for (i = 1; i < maxTestValue; i++) {
        if (lengthArray[i] > max)
            max = lengthArray[i];
    }

    return max;
}

int chainLength(int i, uint32_t* nextValue, uint16_t* lengthArray)
{
    if (lengthArray[i] != 0)
        return lengthArray[i];
    
    lengthArray[i] = 1 + chainLength(nextValue[i], nextValue, lengthArray);

    return lengthArray[i];
}

int collatz(int a)
{
    if (a % 2 == 0) {
        return a / 2;
    } else {
        return 3*a + 1;
    }
}

int getChainLength(int i)
{

    int size = 5 * i;
    uint32_t* nextValue = (uint32_t*)calloc(size, sizeof(uint32_t));
    uint16_t* lengthArray = (uint16_t*)calloc(size, sizeof(uint16_t));

    nextValue[1] = 1;
    lengthArray[1] = 1;

    int length = chainLength(i, nextValue, lengthArray);

    free(nextValue);
    free(lengthArray);

    return length;
}
