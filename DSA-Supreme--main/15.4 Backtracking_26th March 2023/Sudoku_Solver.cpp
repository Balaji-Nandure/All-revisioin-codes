/*
--------------------------------------------------------------------------------
Approach Used: Classic Backtracking for Sudoku Solver
--------------------------------------------------------------------------------
- The algorithm fills empty cells (represented by 0) in a 9x9 Sudoku board.
- For each empty cell, it tries all possible values from 1 to 9.
- For each value, it checks if placing it is valid (i.e., doesn't violate Sudoku rules for row, column, and 3x3 subgrid).
- If valid, it places the value and recursively attempts to solve the rest of the board.
- If a dead end is reached, it backtracks (removes the value) and tries the next possibility.
- The process continues until the board is completely filled with valid values.

--------------------------------------------------------------------------------
Better/Alternative Approaches:
--------------------------------------------------------------------------------
1. **Bitmasking for Fast Validity Checks:**
   - Use bitmasks to track used digits in rows, columns, and boxes for O(1) checks.
   - This reduces the time for checking if a digit can be placed.
   - Example (C++ code):
   ```
   // Use 3 arrays of 9 integers for rows, cols, boxes
   int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};
   // To set/check digit d at (i,j):
   int mask = 1 << (d-1);
   if (!(rows[i] & mask) && !(cols[j] & mask) && !(boxes[boxIndex] & mask)) {
       // Place digit
       rows[i] |= mask; cols[j] |= mask; boxes[boxIndex] |= mask;
       // ...recurse...
       // Backtrack: unset the bits after recursion
       rows[i] ^= mask; cols[j] ^= mask; boxes[boxIndex] ^= mask;
   }
   ```
2. **Constraint Propagation (with Dancing Links / Algorithm X):**
   - Advanced technique for very fast Sudoku solving.
   - Not shown here due to complexity.

--------------------------------------------------------------------------------
Code with Detailed Comments and Improvements
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing 'value' at (curr_row, curr_col) is valid
bool isSafe(int value, int board[9][9], int curr_row, int curr_col) {
    // Check if 'value' is already present in the current row
    for (int col = 0; col < 9; col++) {
        if (board[curr_row][col] == value) {
            return false; // Value already exists in row
        }
    }
    // Check if 'value' is already present in the current column
    for (int row = 0; row < 9; row++) {
        if (board[row][curr_col] == value) {
            return false; // Value already exists in column
        }
    }
    // Check if 'value' is already present in the 3x3 subgrid
    int startRow = 3 * (curr_row / 3);
    int startCol = 3 * (curr_col / 3);
    for (int i = 0; i < 3; i++) {           // Loop over 3 rows of subgrid
        for (int j = 0; j < 3; j++) {       // Loop over 3 columns of subgrid
            if (board[startRow + i][startCol + j] == value) {
                return false; // Value already exists in subgrid
            }
        }
    }
    // If all checks pass, it's safe to place the value
    return true;
}

// Recursive function to solve the Sudoku board using backtracking
bool solve(int board[9][9], int n) {
    // Traverse the board to find an empty cell (represented by 0)
    for (int i = 0; i < n; i++) {           // Loop over rows
        for (int j = 0; j < n; j++) {       // Loop over columns
            if (board[i][j] == 0) {         // Found an empty cell
                // Try all possible values from 1 to 9
                for (int value = 1; value <= 9; value++) {
                    // Check if placing 'value' is safe
                    if (isSafe(value, board, i, j)) {
                        board[i][j] = value;    // Place the value
                        // Recursively attempt to solve the rest of the board
                        if (solve(board, n)) {
                            return true;        // If solved, propagate success
                        }
                        // If not solved, backtrack: remove the value
                        board[i][j] = 0;
                    }
                }
                // If no value from 1 to 9 can be placed, trigger backtracking
                return false;
            }
        }
    }
    // If no empty cell is found, the board is solved
    return true;
}

int main() {
    // Initial Sudoku board (0 represents empty cells)
    int board[9][9] = {
        {4,5,0,0,0,0,0,0,0},
        {0,0,2,0,7,0,6,3,0},
        {0,0,0,0,0,0,0,2,8},
        {0,0,0,9,5,0,0,0,0},
        {0,8,6,0,0,0,2,0,0},
        {0,2,0,6,0,0,7,5,0},
        {0,0,0,0,0,0,4,7,6},
        {0,7,0,0,4,5,0,0,0},
        {0,0,8,0,0,9,0,0,0}
    };

    int n = 9; // Size of the board (9x9)
    bool solved = solve(board, n); // Attempt to solve the board

    if (solved) {
        cout << "Sudoku Solved Successfully:\n";
        // Print the solved board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists for the given Sudoku board.\n";
    }
    return 0;
}

/*
--------------------------------------------------------------------------------
Dry Run Example (First Few Steps)
--------------------------------------------------------------------------------
Initial Board (0 = empty):
4 5 0 0 0 0 0 0 0
0 0 2 0 7 0 6 3 0
0 0 0 0 0 0 0 2 8
...

Step 1: Find first empty cell at (0,2)
- Try value 1: isSafe(1,...) returns true
- Place 1 at (0,2)
- Recurse to next empty cell

Step 2: Next empty cell at (0,3)
- Try value 1: isSafe(1,...) returns false (already in row)
- Try value 2: isSafe(2,...) returns false (already in row)
- Try value 3: isSafe(3,...) returns true
- Place 3 at (0,3)
- Recurse...

If at any point no value fits, backtrack to previous cell and try next value.

Continue until all cells are filled or no solution is possible.

--------------------------------------------------------------------------------
*/