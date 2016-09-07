#include <stdio.h>
#include "p18.h"

#define NUM_ROWS 15

int getMaxPathSum(FILE* inputFile)
{
    return 0;
}

void readFile(FILE* inputFile, int array)
{

    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_ROWS; j++) {

            if (j <= i) {
                fscanf(inputFile, "%d", &array[i][j]);
            } else {
                array[i][j] = 0;
            }

        }
    }
}
