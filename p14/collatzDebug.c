#include <stdio.h>
#include "p14.h"

#define DEBUG

int main()
{
    int num;

    printf("Please enter a number: ");
    scanf("%i", &num);
    puts("");

    printf("Collatz chain length is %i terms\n", getChainLength(num));

    return 0;
}
