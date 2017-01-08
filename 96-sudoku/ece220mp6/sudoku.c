#include "sudoku.h"

/*
 * sudoku.c
 * Byron Hopps
 * ECE220 MP6, Fall 2015
 * The file provides the logic for a sudoku solver. It is designed to work with main.c,
 *  which provides the overall control and I/O logic to make the program function.
 *
 * The is_val_in_* functions return true if the input value is in the 
 *  given row, and false if not.
 *
 * The function is_val_valid returns true if the input value is a valid solution for
 *  the input location and false otherwise.
 *
 * The function solve_sudoku is a recursive backtracking function which uses the
 *  aforementioned functions to solve an input sudoku puzzle.
 *
 * The parse_sudoku function reads an input file to fill the 9x9 array which
 *  contains the sudoku puzzle being worked on.
 *
 * Lastly, the print_sudoku function prints the input sudoku array to STDOUT.
 */


// Procedure: print_sudoku
void print_sudoku(int sudoku[9][9])
{
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      printf("%2d", sudoku[i][j]);
    }
    printf("\n");
  }
}

// Procedure: parse_sudoku
void parse_sudoku(const char fpath[], int sudoku[9][9]) {
  FILE *reader = fopen(fpath, "r");
  assert(reader != NULL);
  int i, j;
  for(i=0; i<9; i++) {
    for(j=0; j<9; j++) {
      fscanf(reader, "%d", &sudoku[i][j]);
    }
  }
  fclose(reader);
}

//-------------------------------------------------------------------------------------------------
// Start coding your MP here.
//-------------------------------------------------------------------------------------------------

// Function: is_val_in_row
// Return true if "val" already existed in ith row of array sudoku.
int is_val_in_row(const int val, const int i, const int sudoku[9][9]) {

    assert(i >= 0 && i < 9);

    // Loops through one row of the sudoku puzzle
    int j = 0;
    for(j = 0; j < 9; j++)
        // If there is a match, return 1
        if(sudoku[i][j] == val)
            return 1;

    // If no match was found, return 0
    return 0;
}

// Function: is_val_in_col
// Return true if "val" already existed in jth column of array sudoku.
int is_val_in_col(const int val, const int j, const int sudoku[9][9]) {

    assert(j >= 0 && j < 9);

    // Loops through one row of the sudoku puzzle
    int i = 0;
    for(i = 0; i < 9; i++)
        // If there is a match, return 1
        if(sudoku[i][j] == val)
            return 1;
  
    // If no match was found, return 0
    return 0;
}

// Function: is_val_in_3x3_zone
// Return true if val already existed in the 3x3 zone corresponding to (i, j)
int is_val_in_3x3_zone(const int val, const int i, const int j, const int sudoku[9][9]) {
   
    assert(i >= 0 && i < 9);
    
    // Determines which 3x3 box the current cell is in
    const int xzone = j/3, yzone = i/3;

    // Loops through the 3x3 box that (i,j) is in
    int x = 0, y = 0;
    for(y = 3*yzone; y < 3*yzone + 3; y++)
        for(x = 3*xzone; x < 3*xzone + 3; x++)
            // If there is a match, reutrn 1
            if(sudoku[y][x] == val)
                return 1;

    // If no match was found, return 0
    return 0;
}

// Function: is_val_in_diag
// Return true if val already exists in the diagonal corresponding to (i, j)
// Return false if there are no matches
int is_val_in_diag(const int value, const int i, const int j, const int sudoku[9][9]) {

    assert(i >= 0 && i < 9);

    int count = 0;

    // If the current location lies on the \ diagonal, search for a match
    if(i == j)
        for(count = 0; count < 9; count++)
            // If a match is found, return 1
            if(sudoku[count][count] == value)
                return 1;

    // If the current location lies on the / diagonal, search for a match
    if(-i + 8 == j)
        for(count = 0; count < 9; count++)
            // If a match is found, return 1
            if(sudoku[-count+8][count] == value)
                return 1;

    // If no match was found (or the location was not on a diagonal), return
    // 0 for no match found
    return 0;
}


// Function: is_val_valid
// Return true if the val is can be filled in the given entry.
int is_val_valid(const int val, const int i, const int j, const int sudoku[9][9]) {

    // If the value exists in the current row, column, box, or diagonal, return 0
    // Otherwise, return 1
    if(is_val_in_row(val, i, sudoku) || is_val_in_col(val, j, sudoku) ||
      is_val_in_3x3_zone(val, i, j, sudoku) || is_val_in_diag(val, i, j, sudoku))
        return 0;
    else
        return 1;
}

#define DEBUG

// Procedure: solve_sudoku
// Solve the given sudoku instance.
int solve_sudoku(int sudoku[9][9]) {

    int i = 0, j = 0;
    int value = -1;

    // Loops through the array until an unfilled cell is found (unfilled cells contain 0)
    // If a filled cell is found, i and j wil have the values of the location of
    //  the found cell, plus 1
    for(i = 0; i < 9 && value != 0; i++)
        for(j = 0; j < 9 && value != 0; j++)
            value = sudoku[i][j];

    // Compensates for the extra incrementation that the for loops will add
    i--; j--;

    // value != 0 means that there are no unfilled cells
    if(value != 0)
        return 1;

    // Iterates through each possible value for the chosen position
    for(value = 1; value <= 9; value++) {

        // If the chosen value is valid, use it for the current position and see if 
        //  it will solve the puzzle
        if(is_val_valid(value, i, j, sudoku)) {

            // Use the chosen value for the current location
            sudoku[i][j] = value;
            
#ifdef DEBUG
            printf("Location: (%d, %d), ", i, j);
            printf("Trying value %d ...\n", value);
#endif

            // If the chosen value solves the puzzle, return 1
            // Otherwise, the chosen value is incorrect, so replace it with
            //  an unfilled space and keep looking
            if(solve_sudoku(sudoku))
                return 1;
            else {
                sudoku[i][j] = 0;
#ifdef DEBUG
                printf("Guess %d at (%d, %d) invalid\n", value, i, j);
#endif
            }
        }
    }

    return 0;
}














