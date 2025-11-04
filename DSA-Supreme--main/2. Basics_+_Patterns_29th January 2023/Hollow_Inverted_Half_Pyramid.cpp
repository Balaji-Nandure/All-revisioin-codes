/*
Approach:
- Print a hollow inverted half-pyramid of height n using two nested loops.
- For each cell (i, j):
  - Print star on first row (i == 0), first column (j == 0), or diagonal boundary (j == n - 1 - i).
  - Otherwise print spaces to keep it hollow.
*/

#include<iostream> // Include standard I/O
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int n = 40; // Size parameter (height and base width)
    for(int i = 0; i < n; i = i + 1){ // Rows: 0..n-1
        for(int j = 0; j < n; j = j + 1){ // Cols: 0..n-1
            // i == 0: first row filled; j == 0: first column border; j == n - 1 - i: slanted border
            if(i == 0 || j == 0 || j == n - 1 - i){ // Border conditions
                cout << "* "; // Print star and a space
            }
            else{ // Hollow interior
                cout << "  "; // Two spaces to align with "* " width
            }
        } // End inner loop
        cout << endl; // Move to next line after finishing row i
    } // End outer loop
    return 0; // Successful execution
}

/*
Dry Run (n = 5):
Row 0: stars everywhere -> * * * * *
Row 1: first col and j==3 -> *     *
Row 2: first col and j==2 -> *   *
Row 3: first col and j==1 -> * *
Row 4: first col (j==0)    -> *

Output:
* * * * * 
*       * 
*     *   
*   *     
*         
*/