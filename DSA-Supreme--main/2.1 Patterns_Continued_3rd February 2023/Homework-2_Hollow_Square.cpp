/*
Approach:
- Print a hollow n x n square: fill borders with stars, interior with spaces.
- Outer loop over rows; inner loop over columns; conditional to decide star vs spaces.
*/

// Homework - 2 Hollow Square Pattern 
#include<iostream> // Include standard I/O
using namespace std; // Use the standard namespace
int main(){ // Program entry
    int n = 4; // Side length of the square
    for(int i = 0; i < n; i = i + 1){ // Rows: 0..n-1
        for(int j = 0; j < n; j = j + 1){ // Cols: 0..n-1
            if(j == 0 || j == n - 1 || i == 0 || i == n - 1) // Border cells
                cout << "* "; // Print star and space on borders
            else    
                cout << "  "; // Print two spaces in the interior
        } // End inner loop
        cout << endl; // Next line after each row
    } // End outer loop
    return 0; // Successful execution
}

/*
Dry Run (n = 4):
Row 0: all stars -> * * * *
Row 1: star, spaces, star -> *     *
Row 2: star, spaces, star -> *     *
Row 3: all stars -> * * * *
*/