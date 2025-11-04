/*
Approach:
To print a half pyramid pattern, we use two nested loops:
- The outer loop iterates over the number of rows (n).
- The inner loop iterates over the number of columns in each row.
- For each row, the number of stars to print is equal to the row index + 1.
- After printing all stars in a row, we move to the next line.
*/

#include<iostream> // Include the input-output stream library for using cout and endl
using namespace std; // Use the standard namespace

int main(){ // Main function starts here

    int n = 4; // Number of rows for the half pyramid

    // Outer loop for rows (runs from 0 to n-1)
    for(int row = 0; row < n; row = row + 1){ // row starts from 0, runs while row < n, increments by 1 each time

        // Inner loop for columns (number of stars in current row is row+1)
        for(int col = 0; col < row + 1; col = col + 1){ // col starts from 0, runs while col < row+1, increments by 1 each time

            cout << "*"; // Print star for each column in the current row
        }

        cout << endl; // After printing all stars in a row, move to the next line
    }

    // Program ends, return 0 by default (optional in modern C++)
}

/*
Dry Run:
Let's dry run for n = 4:

row = 0:
    col = 0: print "*"
    (end inner loop) print endl
row = 1:
    col = 0: print "*"
    col = 1: print "*"
    (end inner loop) print endl
row = 2:
    col = 0: print "*"
    col = 1: print "*"
    col = 2: print "*"
    (end inner loop) print endl
row = 3:
    col = 0: print "*"
    col = 1: print "*"
    col = 2: print "*"
    col = 3: print "*"
    (end inner loop) print endl

Output:
*
**
***
****
*/