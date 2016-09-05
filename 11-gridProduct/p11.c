#include <stdio.h>
#include "p11.h"

#define GRID_FILE_PATH "grid.txt"

int largestDiagProduct()
{

    int grid[20][20];

    importGrid(grid);

    int result = 0;

    return result;
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
