/*
Approach:
- We want to print a solid square pattern of size n x n using stars ('*').
- We'll use two nested loops:
    - The outer loop will iterate over each row (from 0 to n-1).
    - The inner loop will iterate over each column in the current row (from 0 to n-1).
    - For each cell, we print a star followed by a space.
    - After printing all columns in a row, we print a newline to move to the next row.
- This will result in a square of stars with n rows and n columns.
*/

// Homework - 1 Solid Square Pattern (Rows = Columns)
#include<iostream> // Include the input-output stream library for using cout and endl
using namespace std; // Use the standard namespace

int main(){ // Main function starts here

    int n = 4; // Initialize the side length of the square (number of rows and columns)

    // Outer loop for rows (runs from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Inner loop for columns (runs from 0 to n-1)
        for(int j = 0; j < n; j = j + 1){ // Loop variable j represents the current column

            cout << "* "; // Print a star followed by a space for each column in the current row

        } // End of inner loop (columns)

        cout << endl; // After printing all columns in a row, move to the next line

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 3):

Initialization:
n = 3

First iteration (i = 0):
    j = 0: print "* "
    j = 1: print "* "
    j = 2: print "* "
    (end inner loop) print newline

Second iteration (i = 1):
    j = 0: print "* "
    j = 1: print "* "
    j = 2: print "* "
    (end inner loop) print newline

Third iteration (i = 2):
    j = 0: print "* "
    j = 1: print "* "
    j = 2: print "* "
    (end inner loop) print newline

Output:
* * * 
* * * 
* * * 
*/