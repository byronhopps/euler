#include <stdio.h>
#include "sudoku.h"

// Returns 1 if val exists in the ith row of the sudoku puzzle
// Returns 0 otherwise
int isValInRow(const int val, const int i, const int sudoku[9][9])
{
    // Loop through current row
    for (int j = 0; j < 9; j++) {

        // Return 1 if a match was found
        if (sudoku[i][j] == val)
            return 1;
    }

    // Return 0 if no match was found
    return 0;
}

// Returns 1 if val exists in the jth column of the sudoku puzzle
// Returns 0 otherwise
int isValInColumn(const int val, const int j, const int sudoku[9][9])
{
    // Loop through current column
    for (int i = 0; i < 9; i++) {

        // Return 1 if match was found
        if (sudoku[i][j] == val)
            return 1;
    }

    // Return 0 if no match was found
    return 0;
}

// Returns 1 if val exists in the 3x3 square that contains (i,j)
// Returns 0 otherwise
int isValInSquare(const int val, const int i, const int j, const int sudoku[9][9])
{
    // Determine which square the current position is in
    const int xzone = j / 3;
    const int yzone = i / 3;

    // Loop through the current square
    for (int y = 3*yzone; y < 3*yzone + 3; y++) {
        for (int x = 3*xzone; x < 3*xzone + 3; x++) {

            // Return 1 if there is a match
            if (sudoku[y][x] == val)
                return 1;
        }
    }

    // Return 0 if no match was found
    return 0;
}

// Returns 1 is the current value is a valid move at the location (i,j)
// Returns 0 otherwise
int isValValid(const int val, const int i, const int j, const int sudoku[9][9])
{
    // Return 0 if the value is in the current row, column, or square
    if (isValInRow(val, i, sudoku) || isValInColumn(val, j, sudoku)
            || isValInSquare(val, i, j, sudoku))
        return 0;

    // Return 1 otherwise
    return 1;
}

// Solves the given sudoku puzzle
// Returns 1 if the puzzle is solved
// Returns 0 if the puzzle is unsolvable
int solveSudoku(int sudoku[9][9])
{
    // Variables that hold the current position and value being tried
    int i = 0, j = 0;
    int value = -1;

    // Loop through sudoku puzzle until empty cell is found
    for (i = 0; i < 9 && value != 0; i++)
        for (j = 0; j < 9 && value != 0; j++)
            value = sudoku[i][j];

    // Compensate for the extra incrementation the for loop will add
    i--; j--;

    // A nonzero value means that all cells are filled
    if (value != 0)
        return 1;

    // Loop through all possible values
    for (value = 1; value <= 9; value++) {
        // If the current value is valid, try to solve the puzzle with it
        if (isValValid(value, i, j, (const int (*)[9])sudoku)) {
            
            // Use the current value in the current location
            sudoku[i][j] = value;

            // Return 1 if the puzzle can be solve with the current value
            if (solveSudoku(sudoku)) {
                return 1;

            // Mark the location as unfilled if the puzzle can't be solved
            } else {
                sudoku[i][j] = 0;
            }
        } 
    }

    // Return 0 if all possible values and locations have been tested
    return 0;
}

// Prints the given sudoku puzzle to stdout
void printSudoku(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j ++ ) {
            printf("%2d", sudoku[i][j]);
        }

        // Print newline at the end of a row
        printf("\n");
    }
}
