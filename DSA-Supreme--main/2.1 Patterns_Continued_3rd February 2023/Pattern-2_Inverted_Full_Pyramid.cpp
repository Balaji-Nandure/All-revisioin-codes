/*
Approach:
- The goal is to print a centered inverted full pyramid pattern of height n.
- For each row i (starting from 0 to n-1):
    - Print i+1 leading spaces to center the stars.
    - Then print (n-i) stars, each followed by a space.
    - Move to the next line after printing all stars in the current row.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    int n = 6; // Initialize the height of the inverted pyramid

    // Loop for each row from 0 to n-1
    for(int i = 0; i < n; i = i + 1){ // i represents the current row number
        int space = i; // Number of leading spaces for the current row increases with i

        // Print leading spaces for centering the stars
        for(; space >= 0; space--){ // Loop to print (i+1) spaces
            cout << " "; // Print a single space
        }

        // Print stars for the current row
        for(int j = 0; j < n - i; j = j + 1){ // Loop to print (n-i) stars
            cout << "* "; // Print a star followed by a space
        }

        cout << endl; // Move to the next line after printing all stars in the current row
    }

    return 0; // Return 0 to indicate successful execution
}

/*
Dry Run (n = 3):

Row 0 (i=0):
    space = 0
    Print 1 space: " "
    Print 3 stars: "* * * "
    Output: " * * * "

Row 1 (i=1):
    space = 1
    Print 2 spaces: "  "
    Print 2 stars: "* * "
    Output: "  * * "

Row 2 (i=2):
    space = 2
    Print 3 spaces: "   "
    Print 1 star: "* "
    Output: "   * "

Final Output for n=3:
 * * * 
  * * 
   * 
*/