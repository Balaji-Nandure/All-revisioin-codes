/*
Approach:
- We want to print a hollow full pyramid of height n using stars ('*').
- For each row i (from 0 to n-1):
    - Print (n-i) spaces to align the pyramid centrally.
    - For each column j in the current row (from 0 to 2*i):
        - Print '*' at the first column (j==0), last column (j==2*i), and for the last row at every even column (j%2==0).
        - Print spaces elsewhere to keep the pyramid hollow.
- Use nested loops: outer for rows, inner for spaces, and another for stars/spaces.
*/

 // Homework - 4 Hollow full pyramid
#include<iostream> // Include standard input-output stream
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 6; // Initialize the height of the pyramid

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Print the spaces first to align the pyramid centrally
        int space = n - i - 1; // Calculate number of spaces for current row
        for(; space >= 0; space = space - 1){ // Loop to print spaces
            cout << " "; // Print a single space
        }

        // Print the stars and spaces for the current row
        for(int j = 0; j < 2 * i + 1; j = j + 1){ // Loop variable j for columns in current row

            // Check for border conditions to print stars
            if(j == 0 || j == 2 * i || (i == n - 1 && j % 2 == 0)){ 
                // j == 0: first column in the row
                // j == 2*i: last column in the row
                // i == n-1 && j%2==0: last row, print star at every even column
                cout << "*"; // Print star
            }
            else{
                cout << " "; // Print space for hollow part
            }
        }

        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 4):

Initialization:
n = 4

Row 0 (i=0):
    space = 3
    Print: "    *"
Row 1 (i=1):
    space = 2
    Print: "   * *"
Row 2 (i=2):
    space = 1
    Print: "  *   *"
Row 3 (i=3):
    space = 0
    Print: " * * * * *"

Output:
    *
   * *
  *   *
 * * * * *

*/