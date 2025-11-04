/*
Approach:
To print a solid rectangle pattern, we use two nested loops:
- The outer loop iterates over the number of rows.
- The inner loop iterates over the number of columns in each row.
- For each cell, we print a star followed by a space.
- After printing all columns in a row, we move to the next line.
*/

#include<iostream> // Include the input-output stream library for using cout and endl
using namespace std; // Use the standard namespace

int main(){ // Main function starts here

    // Outer loop for rows (total 3 rows)
    for(int row = 0; row < 3; row = row + 1){ // row starts from 0, runs while row < 3, increments by 1 each time

        // Inner loop for columns (total 5 columns)
        for(int col = 0; col < 5; col = col + 1){ // col starts from 0, runs while col < 5, increments by 1 each time

            cout << "* "; // Print star followed by a space for each column in the current row
        }

        cout << endl; // After printing all columns in a row, move to the next line
    }

    // Program ends, return 0 by default (optional in modern C++)
}

/*
Dry Run:
Let's dry run for 3 rows and 5 columns:

row = 0:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    col = 3: print "* "
    col = 4: print "* "
    (end inner loop) print endl
row = 1:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    col = 3: print "* "
    col = 4: print "* "
    (end inner loop) print endl
row = 2:
    col = 0: print "* "
    col = 1: print "* "
    col = 2: print "* "
    col = 3: print "* "
    col = 4: print "* "
    (end inner loop) print endl

Output:
* * * * * 
* * * * * 
* * * * * 
*/