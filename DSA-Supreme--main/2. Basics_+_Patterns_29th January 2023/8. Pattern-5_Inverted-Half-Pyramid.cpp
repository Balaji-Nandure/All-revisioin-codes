/*
Approach:
- Print an inverted half-pyramid of stars with n rows.
- For each row r (0-indexed), print (n - r) stars, then move to the next line.
- Two nested loops: outer for rows, inner for the number of stars.
*/

#include<iostream> // Include I/O facilities
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int n = 6; // Number of rows (height of the inverted half-pyramid)
    for(int row = 0; row < n; row = row + 1){ // Iterate rows from 0 to n-1
        for(int col = 0; col < n - row; col = col + 1){ // Print (n-row) stars in this row
            cout << "*"; // Print one star
        } // End inner loop (columns)
        cout << endl; // Move to the next line after finishing a row
    } // End outer loop (rows)
    return 0; // Successful execution
}

/*
Dry Run (n = 4):
row = 0 -> print 4 stars: **** then newline
row = 1 -> print 3 stars: *** then newline
row = 2 -> print 2 stars: ** then newline
row = 3 -> print 1 star : * then newline

Output:
****
***
**
*
*/