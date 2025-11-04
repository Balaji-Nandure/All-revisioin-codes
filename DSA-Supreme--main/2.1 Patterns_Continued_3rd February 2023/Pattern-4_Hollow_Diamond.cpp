/*
Approach:
- The goal is to print a hollow diamond pattern of stars ('*') for a given size n.
- The pattern consists of two parts:
    1. The top half: a hollow full pyramid (upright).
    2. The bottom half: a hollow inverted full pyramid.
- For the top half (rows 0 to n-1):
    - Print (n - i) spaces to center the stars.
    - For each position in the row, print '*' at the first and last position, otherwise print space.
- For the bottom half (rows 0 to n-1):
    - Print (i + 1) spaces to center the stars.
    - For each position in the row, print '*' at the first and last position, otherwise print space.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input/output stream library for cout and endl
using namespace std; // Use the standard namespace to avoid prefixing std::

int main(){ // Main function: program execution starts here

    int n = 6; // Declare and initialize the size of the diamond

    // Print the top half of the hollow diamond (hollow full pyramid)
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the top half

        int space = n - i - 1; // Calculate the number of leading spaces for the current row
        for(int s = 0; s <= space; s = s + 1){ // Print (n - i) spaces to center the stars
            cout << " "; // Print a single space
        }

        // Print the hollow stars for the current row
        for(int j = 0; j < 2 * i + 1; j = j + 1){ // Loop through each position in the row
            if(j == 0 || j == 2 * i){ // If it's the first or last position, print star
                cout << "*"; // Print a star
            }
            else{
                cout << " "; // Print a space for hollow part
            }
        }
        cout << endl; // Move to the next line after printing each row
    }

    // Print the bottom half of the hollow diamond (hollow inverted full pyramid)
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the bottom half

        int space = i; // Calculate the number of leading spaces for the current row
        for(int s = 0; s <= space; s = s + 1){ // Print (i + 1) spaces to center the stars
            cout << " "; // Print a single space
        }

        // Print the hollow stars for the current row
        for(int j = 0; j < 2 * n - 2 * i - 1; j = j + 1){ // Loop through each position in the row
            if(j == 0 || j == 2 * n - 2 * i - 2){ // If it's the first or last position, print star
                cout << "*"; // Print a star
            }
            else{
                cout << " "; // Print a space for hollow part
            }
        }
        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 3):

Top half:
i = 0:
    space = 3 - 0 - 1 = 2
    Print 3 spaces: "   "
    j = 0 to 0: print '*'
    Output: "   *"

i = 1:
    space = 3 - 1 - 1 = 1
    Print 2 spaces: "  "
    j = 0: print '*'
    j = 1: print ' '
    j = 2: print '*'
    Output: "  * *"

i = 2:
    space = 3 - 2 - 1 = 0
    Print 1 space: " "
    j = 0: print '*'
    j = 1: print ' '
    j = 2: print ' '
    j = 3: print ' '
    j = 4: print '*'
    Output: " *   *"

Bottom half:
i = 0:
    space = 0
    Print 1 space: " "
    j = 0: print '*'
    j = 1: print ' '
    j = 2: print ' '
    j = 3: print ' '
    j = 4: print '*'
    Output: " *   *"

i = 1:
    space = 1
    Print 2 spaces: "  "
    j = 0: print '*'
    j = 1: print ' '
    j = 2: print '*'
    Output: "  * *"

i = 2:
    space = 2
    Print 3 spaces: "   "
    j = 0: print '*'
    Output: "   *"

Final Output for n = 3:
   *
  * *
 *   *
 *   *
  * *
   *
*/