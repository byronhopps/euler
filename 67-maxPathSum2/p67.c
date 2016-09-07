#include <stdio.h>
#include "p18.h"

int getMaxPathSum(FILE* inputFile)
{
    int triangle[NUM_ROWS][NUM_ROWS];
    int pathSum[NUM_ROWS][NUM_ROWS] = {{0}};

    readFile(inputFile, triangle);

    // Initial setup
    pathSum[0][0] = triangle[0][0];

    // Loop through the triangle
    for (int i = 1; i < NUM_ROWS; i++) {
        for (int j = 0; j <= i; j++) {

            // Assign the longest path total for each node
            if (j == 0 || pathSum[i-1][j] > pathSum[i-1][j-1]) {
                pathSum[i][j] = pathSum[i-1][j] + triangle[i][j];
            } else {
                pathSum[i][j] = pathSum[i-1][j-1] + triangle[i][j];
            }
        }
    }

    // Get the longest path sum
    int maxPathSum = 0;
    for (int j = 0; j < NUM_ROWS; j++) {
        if (pathSum[NUM_ROWS-1][j] > maxPathSum)
            maxPathSum = pathSum[NUM_ROWS-1][j];
    }

    return maxPathSum;
}

void readFile(FILE* inputFile, int array[NUM_ROWS][NUM_ROWS])
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
