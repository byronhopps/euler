// Returns 1 if val exists in the ith row of the sudoku puzzle
// Returns 0 otherwise
int isValInRow(const int val, const int i, const int sudoku[9][9]);

// Returns 1 if val exists in the jth column of the sudoku puzzle
// Returns 0 otherwise
int isValInColumn(const int val, const int j, const int sudoku[9][9]);

// Returns 1 if val exists in the 3x3 square that contains (i,j)
// Returns 0 otherwise
int isValInSquare(const int val, const int i, const int j, const int sudoku[9][9]);

// Returns 1 is the current value is a valid move at the location (i,j)
// Returns 0 otherwise
int isValValid(const int val, const int i, const int j, const int sudoku[9][9]);

// Solves the given sudoku puzzle
// Returns 1 if the puzzle is solved
// Returns 0 if the puzzle is unsolvable
int solveSudoku(int sudoku[9][9]);

// Prints the given sudoku puzzle to stdout
void printSudoku(int sudoku[9][9]);

// Parses a sudoku puzzle from the given filepath
void parseSudoku(const char fpath[], int* sudoku[9][9]);
