/*
Approach:
- The goal is to print a solid diamond pattern of stars ('*') for a given half-height n.
- The diamond is constructed by stacking a full pyramid (top half) and an inverted full pyramid (bottom half).
- For the top half (rows 0 to n-1):
    - Print (n - i) spaces to center the stars.
    - Print (i + 1) stars, each followed by a space.
- For the bottom half (rows 0 to n-1):
    - Print (i + 1) spaces to center the stars.
    - Print (n - i) stars, each followed by a space.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input/output stream library for cout and endl
using namespace std; // Use the standard namespace to avoid prefixing std::

int main(){ // Main function: program execution starts here

    int n = 6; // Declare and initialize the half-height of the diamond

    // Top half of the diamond (full pyramid)
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the top half

        int space = n - i; // Calculate the number of leading spaces for the current row
        for(int s = 0; s < space; s = s + 1){ // Print (n - i) spaces to center the stars
            cout << " "; // Print a single space
        }

        for(int j = 0; j < i + 1; j = j + 1){ // Print (i + 1) stars for the current row
            cout << "* "; // Print a star followed by a space
        }

        cout << endl; // Move to the next line after printing each row
    }

    // Bottom half of the diamond (inverted full pyramid)
    for(int i = 0; i < n; i = i + 1){ // Loop through rows 0 to n-1 for the bottom half

        int space = i + 1; // Calculate the number of leading spaces for the current row
        for(int s = 0; s < space; s = s + 1){ // Print (i + 1) spaces to center the stars
            cout << " "; // Print a single space
        }

        for(int j = 0; j < n - i; j = j + 1){ // Print (n - i) stars for the current row
            cout << "* "; // Print a star followed by a space
        }

        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 2):

Initialization:
n = 2

Top half:
i = 0:
    space = 2 - 0 = 2
    Print 2 spaces: "  "
    Print 1 star: "* "
    Output: "  * "

i = 1:
    space = 2 - 1 = 1
    Print 1 space: " "
    Print 2 stars: "* * "
    Output: " * * "

Bottom half:
i = 0:
    space = 0 + 1 = 1
    Print 1 space: " "
    Print 2 stars: "* * "
    Output: " * * "

i = 1:
    space = 1 + 1 = 2
    Print 2 spaces: "  "
    Print 1 star: "* "
    Output: "  * "

Final Output for n = 2:
  * 
 * * 
 * * 
  * 

Pattern forms a solid diamond shape.
*/