/*
Approach:
To print a solid square pattern, we use two nested loops:
- The outer loop iterates over the number of rows (n).
- The inner loop iterates over the number of columns (n) in each row.
- For each cell, we print a star followed by a space.
- After printing all columns in a row, we move to the next line.
*/

#include<iostream> // Include the input-output stream library for using cout and endl
using namespace std; // Use the standard namespace

int main(){ // Main function starts here

    int n = 8;  // Number of rows and columns for the solid square (side length of square)

    // Outer loop for rows (runs from 0 to n-1)
    for(int row = 0; row < n; row = row + 1){ // row starts from 0, runs while row < n, increments by 1 each time

        // Inner loop for columns (runs from 0 to n-1)
        for(int col = 0; col < n; col = col + 1){ // col starts from 0, runs while col < n, increments by 1 each time

            cout << "* "; // Print star followed by a space for each column in the current row
        }

        cout << endl; // After printing all columns in a row, move to the next line
    }

    // Program ends, return 0 by default (optional in modern C++)
}

/*
Dry Run:
Let's dry run for n = 3 (for simplicity):

row = 0:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    (end inner loop) print endl
row = 1:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    (end inner loop) print endl
row = 2:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    (end inner loop) print endl

Output:
* * * 
* * * 
* * * 
*/