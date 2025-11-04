/*
Approach:
- Print a hollow inverted half pyramid of height n.
- For each row i (from 0 to n-1):
    - Print (n-i-1) columns.
    - Print '*' at the first row (i==0), first column (j==0), and last column of the row (j==n-i-2).
    - Print spaces elsewhere to keep the pyramid hollow.
- Use nested loops: outer for rows, inner for columns.
*/

 // Homework - 3 Hollow inverted half pyramid
#include<iostream> // Include standard input-output stream
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 6; // Initialize the height of the pyramid

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Inner loop for each column in the current row (j from 0 to n-i-2)
        for(int j = 0; j < n - i - 1; j = j + 1){ // Loop variable j represents the current column

            // Check if it's the first row, first column, or last column in the current row
            if(i == 0 || j == 0 || j == n - i - 2){ // Border conditions for stars

                cout << "* "; // Print star followed by a space

            }
            else{ // For hollow part (not border)

                cout << "  "; // Print two spaces for alignment

            }
        } // End of inner loop (columns)

        cout << endl; // Move to the next line after each row

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 6):

Row 0 (i=0, j=0..4): All stars
* * * * * 

Row 1 (i=1, j=0..3): star, spaces, star
*     *

Row 2 (i=2, j=0..2): star, space, star
*   *

Row 3 (i=3, j=0..1): star, star
* *

Row 4 (i=4, j=0): star
*

Row 5 (i=5, j=0..-1): (no columns, so nothing printed)

Output:
* * * * * 
*     * 
*   * 
* * 
* 

*/