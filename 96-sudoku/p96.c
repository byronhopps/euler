#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"

// For all 50 puzzles:
    // Read puzzle to array
    // Solve puzzle
    // Add sum of the 3 numbers in the top left to accumulating sum 
int solveProblem(char* filePath)
{
    // Define array containing pointers to the arrays of the sudoku puzzles
    int* (*)[9] sudokuPuzzles[50];

    // Input sudoku puzzles
    for (int i = 0; i < 50; i++) {
        sudokuPuzzles[i] = (int* (*)[9])malloc(sizeof(int* (*)[9]));

        // TODO: Add parser
    }

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


    // Free memory associated with sudoku puzzles
    for (int i = 0; i < 50; i++) {
        free(sudokuPuzzles[i]);
        sudokuPuzzles[i] = NULL;
    }

    return result;
}
