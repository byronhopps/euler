#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

// For all 50 puzzles:
    // Read puzzle to array
    // Solve puzzle
    // Add sum of the 3 numbers in the top left to accumulating sum 
int solveProblem96(char* filePath)
{
    // Define array containing pointers to the arrays of the sudoku puzzles
    typedef int sudoku_t[9][9];
    sudoku_t sudokuPuzzles[50];

    // Open input file
    FILE* inputFile = fopen(filePath, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Invalid input file\n");
        exit(-2);
    }

    // Read 50 puzzles from file
    for (int h = 0; h < 50; h++) {

        // Parse sudoku puzzle header
        int sudokuNum = -1;
        if (fscanf(inputFile, "Grid %2d", &sudokuNum) != 1 || sudokuNum != h+1) {
            fprintf(stderr, "Input grids out of order\n");
            exit(-2);
        }

        // Read sudoku puzzle
        for (int i = 0; i < 9; i++) {

            // Read line of sudoku puzzle
            for (int j = 0; j < 9; j++) {
                fscanf(inputFile, "%1d", &sudokuPuzzles[h][i][j]);
            }

            // Return error if more than 9 numbers on a line
            if (fgetc(inputFile) != '\n') {
                fprintf(stderr, "Input sudoku number %d has invalid formatting on line %d\n",
                        sudokuNum, i);
                exit(-2);
            }
        }
    }
    fclose(inputFile);

    // Solve all puzzles, returning an error if a puzzle is unsolvable
    for (int i = 0; i < 50; i++) {
        if (!solveSudoku(sudokuPuzzles[i])) {
            fprintf(stderr, "Sudoku puzzle number %d is unsolvable\n", i);
            exit(-1);
        }
    }

    // Add sum of the 3 numbers in the top left to accumulator
    int result;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 3; j++) {
            result += sudokuPuzzles[i][0][j];
        }
    }

    return result;
}
