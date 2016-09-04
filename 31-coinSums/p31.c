#include <stdio.h>
#include "p31.h"

int countCoins(int total)
{
    static int coinSum = 0;
    static int coins[8] = {0};
    static int results[4096][8];

    int sum = sumCoins(coins);
    if (sum == total && notInResults(coins, results, coinSum)) {
        addToResults(coins, results, coinSum);
        coinSum += 1;
    }

    if (sum >= total)
        return -1;

    // Loop over each availible coin
    for (int curCoin = 200; curCoin > 0; curCoin = nextCoin(curCoin)) {

        // Try with the current coin
        addCoin(coins, curCoin, 1);
        countCoins(total);
        addCoin(coins, curCoin, -1);
    }

    return coinSum;
}

void addCoin(int* coins, int curCoin, int amount)
{
    coins[idx(curCoin)] += amount;
}

int notInResults(int* coins, int results[][8], int size)
{
    int i, j;
    int match, zeroes;

    // Loop over each array entry
    for (j = 0; j < size + 1; j++) {

        // Assume that the entries match and are all zeroes
        match = 1;
        zeroes = 1;

        // Loop over each entry element
        for (i = 0; i < 8; i++) {

            // Mark if entry doesn't match
            if (results[j][i] != coins[i])
                match = 0;

            // Mark if entry is non zero
            if (results[j][i] != 0)
                zeroes = 0;

            // Go to next entry if non zero and not a match
            if (match == 0 && zeroes == 0)
                break;
        }

        // Stop searching if a fully zero entry has been found
        if (zeroes == 1)
            break;

        // If a match exists, return 0
        if (match == 1)
            return 0;
    }

    // No match found
    return 1;
}

void addToResults(int* coins, int results[][8], int idx)
{
    for (int i = 0; i < 8; i++) {
        results[idx][i] = coins[i];
    }
}

int nextCoin(int coin)
{
    switch (coin) {
        case 200:
            return 100;

        case 100:
            return 50;

        case 50:
            return 20;

        case 20:
            return 10;

        case 10:
            return 5;

        case 5:
            return 2;

        case 2:
            return 1;

        case 1:
            return 0;

        default:
            puts("Invalid coin in nextCoin");
            return -1;
    }
}

int idx(int coin)
{
    switch (coin) {
        case 1:
            return 0;

        case 2:
            return 1;

        case 5:
            return 2;

        case 10:
            return 3;

        case 20:
            return 4;

        case 50:
            return 5;

        case 100:
            return 6;

        case 200:
            return 7;

        default:
            puts("Invalid coin in coin idx()");
            return -1;
    }
}

int sumCoins(int* coins)
{
    int sum = 0;
    for (int i = 0; i < 8; i++) {
        sum += coins[i]*getValue(i);
    }

    return sum;
}

int getValue(int idx)
{
    int values[8] = {1, 2, 5, 10, 20, 50, 100, 200};
    return values[idx];
}
