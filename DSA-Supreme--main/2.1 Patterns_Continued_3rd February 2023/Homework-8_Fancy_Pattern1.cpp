/*
Approach:
- The goal is to print a "fancy" pattern for a given n.
- For each row i (from 0 to n-1):
    - Print (n+3-i) stars on the left.
    - Print a sequence of numbers and stars in the middle: numbers at even positions (all the same, i+1), stars at odd positions, for a total of (2*i+1) characters.
    - Print (n+3-i) stars on the right.
    - Move to the next line.
- Use nested loops: outer for rows, inner for left stars, middle pattern, and right stars.
- Print a newline after each row.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 5; // Initialize the number of rows for the pattern

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // First print the stars on the left
        int stars = n + 3 - i; // Calculate number of stars for the current row
        for(; stars > 0; stars = stars - 1){ // Loop to print left stars
            cout << "*"; // Print a star
        }

        // Print the numbers and stars in the middle
        for(int j = 0; j < 2 * i + 1; j = j + 1){ // Loop for middle pattern
            if(j % 2 == 0){ // If position is even, print the number
                cout << i + 1; // Print the current row number + 1
            }
            else{ // If position is odd, print a star
                cout << "*"; // Print a star
            }
        }

        // Print the stars on the right
        stars = n + 3 - i; // Reset stars for the right side
        for(; stars > 0; stars = stars - 1){ // Loop to print right stars
            cout << "*"; // Print a star
        }

        cout << endl; // Move to the next line after each row

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 5):

Initialization:
n = 5

Row 0 (i=0):
    stars = 8
    Print: ********1********
Row 1 (i=1):
    stars = 7
    Print: *******2*2*******
Row 2 (i=2):
    stars = 6
    Print: ******3*3*3******
Row 3 (i=3):
    stars = 5
    Print: *****4*4*4*4*****
Row 4 (i=4):
    stars = 4
    Print: ****5*5*5*5*5****

Output:
********1********
*******2*2*******
******3*3*3******
*****4*4*4*4*****
****5*5*5*5*5****

*/