/*
Approach:
- The goal is to print a numeric hollow pyramid pattern for a given number of rows n.
- For each row i (from 0 to n-1):
    1. Print (n-i) spaces to center the numbers.
    2. For the first and last row, print numbers with a space in between.
    3. For the middle rows, print 1 at the start, (i+1) at the end, and spaces in between.
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    int n = 7; // Initialize the number of rows for the pyramid

    for(int i = 0; i < n; i++){ // Loop for each row from 0 to n-1

        int space = n - i - 1; // Calculate the number of leading spaces for the current row
        for(; space >= 0; space--){ // Print (n-i) spaces
            cout << " "; // Print a single space
        }

        int start = 1; // Numbering always starts from 1 in the pattern

        for(int j = 0; j < 2 * i + 1; j++){ // Loop to print numbers and spaces in the row

            if(i == 0 || i == n - 1){ // For the first and last row
                if(j % 2 == 0){ // Print number at even positions
                    cout << start << " "; // Print the number followed by a space
                    start = start + 1; // Increment the number
                }
            }
            else{ // For the middle rows
                if(j == 0){ // First position in the row
                    cout << 1; // Always print 1 at the start
                }
                else if(j == 2 * i){ // Last position in the row
                    cout << i + 1; // Print (i+1) at the end
                }
                else{ // All other positions
                    cout << " "; // Print space for hollow part
                }
            }
        }
        cout << endl; // Move to the next line after each row
    }

    return 0; // Indicate successful program termination
}

/*
Dry Run (n = 5):

Row 0 (i=0):
    space = 5-0-1 = 4
    Print: "     "
    Only one number: 1
    Output:      1 

Row 1 (i=1):
    space = 3
    Print: "    "
    j=0: 1
    j=1: space
    j=2: 2
    Output:     1 2 

Row 2 (i=2):
    space = 2
    Print: "   "
    j=0: 1
    j=1: space
    j=2: space
    j=3: space
    j=4: 3
    Output:    1   3

Row 3 (i=3):
    space = 1
    Print: "  "
    j=0: 1
    j=1: space
    j=2: space
    j=3: space
    j=4: space
    j=5: space
    j=6: 4
    Output:   1     4

Row 4 (i=4):
    space = 0
    Print: ""
    j=0: 1
    j=1: space
    j=2: 2
    j=3: space
    j=4: 3
    j=5: space
    j=6: 4
    j=7: space
    j=8: 5
    Output: 1 2 3 4 5 

Final Output for n=5:
     1 
    1 2 
   1   3
  1     4
 1 2 3 4 5 
*/