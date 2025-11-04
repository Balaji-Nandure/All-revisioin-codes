/*
Approach:
- The goal is to print a solid half diamond pattern of stars ('*') of height n.
- The pattern consists of two parts:
    1. The upper half (including the middle row): For each row i (from 0 to n-1), print (i+1) stars.
    2. The lower half: For each row i (from 0 to n-2), print (n-i-1) stars.
- Use nested loops: outer for rows, inner for columns (stars).
- Print a newline after each row to move to the next line.
*/

 // Homework - 9 Solid half diamond 
#include<iostream> // Include the standard input-output stream library for cout and endl
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 6; // Initialize the height of the half diamond

    // Pattern - 1: Upper half of the diamond (including the middle row)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row (0 to n-1)
        for(int j = 0; j < i + 1; j = j + 1){ // Loop variable j for columns, print (i+1) stars
            cout << "* "; // Print a star followed by a space
        }
        cout << endl; // Move to the next line after each row
    }

    // Pattern - 2: Lower half of the diamond
    for(int i = 0; i < n - 1; i = i + 1){ // Loop variable i represents the current row (0 to n-2)
        for(int j = 0; j < n - i - 1; j = j + 1){ // Loop variable j for columns, print (n-i-1) stars
            cout << "* "; // Print a star followed by a space
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 6):

Initialization:
n = 6

Pattern - 1 (Upper half):
Row 0 (i=0): j=0..0 -> print 1 star
*
Row 1 (i=1): j=0..1 -> print 2 stars
* *
Row 2 (i=2): j=0..2 -> print 3 stars
* * *
Row 3 (i=3): j=0..3 -> print 4 stars
* * * *
Row 4 (i=4): j=0..4 -> print 5 stars
* * * * *
Row 5 (i=5): j=0..5 -> print 6 stars
* * * * * *

Pattern - 2 (Lower half):
Row 0 (i=0): j=0..4 -> print 5 stars
* * * * *
Row 1 (i=1): j=0..3 -> print 4 stars
* * * *
Row 2 (i=2): j=0..2 -> print 3 stars
* * *
Row 3 (i=3): j=0..1 -> print 2 stars
* *
Row 4 (i=4): j=0..0 -> print 1 star
*

Output:
* 
* * 
* * * 
* * * * 
* * * * * 
* * * * * * 
* * * * * 
* * * * 
* * * 
* * 
* 

*/