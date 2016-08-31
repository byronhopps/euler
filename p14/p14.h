#include <stdint.h>

// Returns the next number in the collatz sequence
int collatz(int a);

// Returns the length of the collatz sequence
int chainLength(int i, uint32_t* nextValue, uint16_t* lengthArray);
int getChainLength(int i);

// Returns the length of the longest collatz sequence
int getLongestChain(int maxTestValue);


