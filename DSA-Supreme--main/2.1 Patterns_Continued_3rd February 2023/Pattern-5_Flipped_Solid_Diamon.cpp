/*
Approach:
- The goal is to print a "Flipped Solid Diamond" pattern for a given n.
- The pattern consists of two main parts:
    1. The upper part: For each row, print a decreasing number of stars, then increasing spaces, then the same number of stars again.
    2. The lower part: For each row, print an increasing number of stars, then decreasing spaces, then the same number of stars again.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input/output stream library for cout and endl
using namespace std; // Use the standard namespace to avoid prefixing std::

int main(){ // Main function: program execution starts here

    int n = 3; // Declare and initialize the size of the pattern

    // Upper part of the flipped solid diamond
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the upper part

        // First half pyramid pattern (decreasing stars)
        for(int j = 0; j < n - i; j = j + 1){ // Print (n - i) stars
            cout << "*"; // Print a star
        }

        // Print spaces between the two star patterns
        for(int j = 0; j < 2 * i + 1; j = j + 1){ // Print (2*i + 1) spaces
            cout << " "; // Print a space
        }

        // Second half pyramid pattern (decreasing stars)
        for(int j = 0; j < n - i; j = j + 1){ // Print (n - i) stars
            cout << "*"; // Print a star
        }

        cout << endl; // Move to the next line after printing each row
    }

    // Lower part of the flipped solid diamond
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the lower part

        // First half pyramid pattern (increasing stars)
        for(int j = 0; j < i + 1; j = j + 1){ // Print (i + 1) stars
            cout << "*"; // Print a star
        }

        // Print spaces between the two star patterns
        for(int j = 0; j < 2 * n - 2 * i - 1; j = j + 1){ // Print (2*n - 2*i - 1) spaces
            cout << " "; // Print a space
        }

        // Second half pyramid pattern (increasing stars)
        for(int j = 0; j < i + 1; j = j + 1){ // Print (i + 1) stars
            cout << "*"; // Print a star
        }

        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 3):

Upper part:
i = 0:
    Stars: n-i = 3-0 = 3 -> ***
    Spaces: 2*i+1 = 1 -> " "
    Stars: 3
    Output: "*** ***"

i = 1:
    Stars: 2
    Spaces: 3
    Stars: 2
    Output: "**   **"

i = 2:
    Stars: 1
    Spaces: 5
    Stars: 1
    Output: "*     *"

Lower part:
i = 0:
    Stars: i+1 = 1
    Spaces: 2*n-2*i-1 = 5
    Stars: 1
    Output: "*     *"

i = 1:
    Stars: 2
    Spaces: 3
    Stars: 2
    Output: "**   **"

i = 2:
    Stars: 3
    Spaces: 1
    Stars: 3
    Output: "*** ***"

Pattern:
*** ***
**   **
*     *
*     *
**   **
*** ***
*/