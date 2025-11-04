/*
Approach:
- The goal is to print a centered full pyramid pattern of height n.
- For each row i (from 0 to n-1):
    - Print (n - i - 1) leading spaces to center the stars.
    - Then print (i + 1) stars, each followed by a space, to form the pyramid.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input/output stream library
using namespace std; // Use the standard namespace to avoid prefixing std::

int main(){ // Main function: program execution starts here

    int n = 6; // Declare and initialize the height of the pyramid

    // Loop through each row of the pyramid
    for(int i = 0; i < n; i = i + 1){ // i iterates from 0 to n-1 (rows)
        
        // Calculate the number of leading spaces for the current row
        int space = n - i - 1; // For row i, number of spaces = n - i - 1

        // Print the leading spaces to center the stars
        for(int s = 0; s < space; s = s + 1){ // s iterates from 0 to space-1
            cout << " "; // Print a single space for alignment
        }

        // Print the stars for the current row
        for(int j = 0; j < i + 1; j = j + 1){ // j iterates from 0 to i
            cout << "* "; // Print a star followed by a space
        }

        cout << endl; // Move to the next line after printing each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 3):

i = 0:
    space = 3 - 0 - 1 = 2
    Print 2 spaces: "  "
    Print 1 star: "* "
    Output: "  * "

i = 1:
    space = 3 - 1 - 1 = 1
    Print 1 space: " "
    Print 2 stars: "* * "
    Output: " * * "

i = 2:
    space = 3 - 2 - 1 = 0
    Print 0 spaces: ""
    Print 3 stars: "* * * "
    Output: "* * * "

Final Output for n = 3:
  * 
 * * 
* * * 
*/