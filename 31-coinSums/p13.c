#include "p31.h"

int countCoins(int sum)
{
    static int coinSum = 0;
    static int coins[8] = {0};
    static int results[1024][8];

    // Increment count if new exact match found
    if (sum == 200 && notInResults(coins, results, coinSum)) {
        addToResults(coins, results, coinSum);
        coinSum += 1;
    }

    // Stop looking if over 200p
    if (sum >= 200)
        return -1;

    // Loop over each availible coin
    for (int curCoin = 1; curCoin > 0; curCoin = nextCoin(curCoin)) {

        // Add coin to coin count
        addCoin(coins, curCoin, 1);

        // Check all the possibilities with the current coin
        int status = countCoins(sum + curCoin);

        if (status == -1)
            break;
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
        case 1:
            return 2;

        case 2:
            return 5;

        case 5:
            return 10;

        case 10:
            return 20;

        case 20:
            return 50;

        case 50:
            return 100;

        case 100:
            return 200;

        case 200:
            return 0;

        default:
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
            return -1;
    }
}
