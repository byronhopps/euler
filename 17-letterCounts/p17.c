#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "p17.h"

int getRangedCharCount(int min, int max)
{

    int charCount = 0;
    for (int i = min; i <= max; i++) {
        charCount += numCharCount(i);
    }

    return charCount;
}

int numCharCount(int num)
{
    char numStr[16];

    sprintf(numStr, "%d", num);
    // assert(strlen(numStr) == 3);

    int charSum = 0;

    if (strlen(numStr) == 1) {
        charSum += digitCharCount(numStr[0]);
        return charSum;
    }

    if (strlen(numStr) == 2) {

        if (numStr[0] == '1') {
            // Deal with the 'teens
            charSum += teensDigitCharCount(numStr[0]);

        } else {
            charSum += tensDigitCharCount(numStr[0]);
            charSum += digitCharCount(numStr[1]);
        }    
    }

    if (strlen(numStr) == 3) {
        // <Hundreds digit> "Hundred and"
        charSum += digitCharCount(numStr[0]) + 10;

        if (numStr[1] == '1') {
            // Deal with the 'teens
            charSum += teensDigitCharCount(numStr[1]);

        } else {
            charSum += tensDigitCharCount(numStr[1]);
            charSum += digitCharCount(numStr[2]);
        }
    }

    return charSum;
}

int digitCharCount(char digit)
{
    switch (digit) {
        case '1': // One
        case '2': // Two
        case '6': // Six
            return 3;

        case '4': // Four
        case '5': // Five
        case '9': // Nine
            return 4;

        case '7': // Seven
        case '3': // Three
        case '8': // Eight
            return 5;

        case '0':
            return 0;

        default:
            assert(0);
            return 0;
    }
}

int tensDigitCharCount(char digit)
{

    switch (digit) {
        case '5': // Fifty
        case '6': // Sixty
            return 5;

        case '2': // Twenty
        case '3': // Thirty
        case '4': // Fourty
        case '8': // Eighty
        case '9': // Ninety
            return 6;

        case '7': // Seventy
            return 7;

        case '0':
            return 0;

        default:
            assert(0);
            return 0;

    }
}

int teensDigitCharCount(char digit)
{
    switch (digit) {
        case '0': // Ten
            return 3;

        case '1': // Eleven
        case '2': // Twelve
            return 6;

        case '5': // Fifteen
        case '6': // Sixteen
            return 7;

        case '3': // Thirteen
        case '4': // Fourteen
        case '8': // Eighteen
        case '9': // Nineteen
            return 8;

        case '7': // Seventeen
            return 9;

        default:
            assert(0);
            return 0;
    }
}
