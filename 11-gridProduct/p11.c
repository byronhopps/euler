#include <stdio.h>
#include "p11.h"

#define GRID_FILE_PATH "grid.txt"

int largestDiagProduct()
{

    // grid[i][j]
    // i is x-axis, j is y-axis
    int grid[20][20];

    importGrid(grid);

    int maxProduct = 0;
    int product;

    // Loop over all valid starting points
    // for a \ diagonal
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {

            // Check the \ diagonal
            product = 1;
            for (int k = 0; k < 4; k++) {
                product *= grid[i+k][j+k];
            }

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    // Loop over all valid starting points
    // for a / diagonal
    for (int i = 3; i < 20; i++) {
        for (int j = 0; j < 17; j++) {

            // Check the / diagonal
            product = 1;
            for (int k = 0; k < 4; k++) {
                product *= grid[i-k][j+k];
            }

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    // Loop over all valid starting points
    // for a horizontal
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 20; j++) {

            // Check the / diagonal
            product = 1;
            for (int k = 0; k < 4; k++) {
                product *= grid[i+k][j];
            }

            if (product > maxProduct)
                maxProduct = product;
        }
    }

    // Loop over all valid starting points
    // for a vertical
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 17; j++) {

            // Check the / diagonal
            product = 1;
            for (int k = 0; k < 4; k++) {
                product *= grid[i][j+k];
            }

            if (product > maxProduct)
                maxProduct = product;
        }
    }


    return maxProduct;
}

void importGrid(int grid[20][20])
{

    FILE* gridFile = fopen(GRID_FILE_PATH, "r");

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            fscanf(gridFile, "%i", &grid[i][j]);
        }
    }

    fclose(gridFile);

} 
