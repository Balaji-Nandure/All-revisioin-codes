/*
Approach:
To print a hollow rectangle (or square) pattern, we use two nested loops:
- The outer loop iterates over the number of rows (r).
- The inner loop iterates over the number of columns (c) in each row.
- For the first and last row, print stars in all columns.
- For the rows in between, print a star only in the first and last column, and print spaces in the rest.
- After printing all columns in a row, move to the next line.

This approach works for both hollow rectangles and hollow squares (just set r = c for square).
*/

#include<iostream> // Include the input-output stream library for using cout and endl
using namespace std; // Use the standard namespace

int main(){ // Main function starts here

    int r = 4; // Number of rows for the hollow shape (can be changed for different sizes)
    int c = 6; // Number of columns for the hollow shape (can be changed for different sizes)

    // Outer loop for rows (runs from 0 to r-1)
    for(int row = 0; row < r; row = row + 1){ // row starts from 0, runs while row < r, increments by 1 each time

        // Inner loop for columns (runs from 0 to c-1)
        for(int col = 0; col < c; col = col + 1){ // col starts from 0, runs while col < c, increments by 1 each time

            // If it's the first row or the last row, print star in all columns
            if(row == 0 || row == r - 1){ // Check if current row is first or last
                cout << "* "; // Print star followed by a space
            }
            else{ // For rows other than first and last
                // Print star only in the first and last column
                if(col == 0 || col == c - 1){ // Check if current column is first or last
                    cout << "* "; // Print star followed by a space
                }
                else{
                    cout << "  "; // Print two spaces for hollow part
                }
            }
        }

        cout << endl; // After printing all columns in a row, move to the next line
    }

    // Program ends, return 0 by default (optional in modern C++)
}

/*
Dry Run:
Let's dry run for r = 4, c = 6:

row = 0: (first row)
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    col = 3: print "* "
    col = 4: print "* "
    col = 5: print "* "
    (end inner loop) print endl

row = 1:
    col = 0: print "* "
    col = 1: print "  "
    col = 2: print "  "
    col = 3: print "  "
    col = 4: print "  "
    col = 5: print "* "
    (end inner loop) print endl

row = 2:
    col = 0: print "* "
    col = 1: print "  "
    col = 2: print "  "
    col = 3: print "  "
    col = 4: print "  "
    col = 5: print "* "
    (end inner loop) print endl

row = 3: (last row)
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    col = 3: print "* "
    col = 4: print "* "
    col = 5: print "* "
    (end inner loop) print endl

Output:
* * * * * * 
*         * 
*         * 
* * * * * * 
*/