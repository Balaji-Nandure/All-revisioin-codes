/*
Approach:
- The goal is to print a numeric full pyramid pattern for a given number of rows n.
- For each row i (from 0 to n-1):
    1. Print (n-i) spaces to center the numbers.
    2. Print increasing numbers starting from (i+1) up to (i+1)+(i).
    3. Then print decreasing numbers starting from (2*i) down to (i+1).
- Each row ends with a newline.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function: program execution starts here
    int n = 5; // Initialize the number of rows for the pyramid

    for(int i = 0 ; i < n; i++){ // Loop for each row from 0 to n-1

        // Print spaces to center the numbers
        int space = n - i - 1; // Calculate the number of leading spaces for the current row
        for(; space >= 0; space--){ // Print (n-i) spaces
            cout << " "; // Print a single space
        }

        // Print increasing numbers starting from (i+1)
        int start = i + 1; // Starting number for the increasing sequence
        for(int j = 0; j < i + 1; j++){ // Loop to print (i+1) numbers
            cout << start; // Print the current number
            start = start + 1; // Move to the next number
        }

        // Print decreasing numbers starting from (2*i)
        start = 2 * i; // Starting number for the decreasing sequence
        for(int j = 0; j < i; j++){ // Loop to print i numbers in decreasing order
            cout << start; // Print the current number
            start--; // Move to the previous number
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
    start = 1
    Print: 1
    (no reverse)
    Output:     1

Row 1 (i=1):
    space = 3
    Print: "    "
    start = 2
    Print: 2 3
    start = 2
    Print: 2
    Output:    232

Row 2 (i=2):
    space = 2
    Print: "   "
    start = 3
    Print: 3 4 5
    start = 4
    Print: 4 3
    Output:   34543

Row 3 (i=3):
    space = 1
    Print: "  "
    start = 4
    Print: 4 5 6 7
    start = 6
    Print: 6 5 4
    Output:  4567654

Row 4 (i=4):
    space = 0
    Print: ""
    start = 5
    Print: 5 6 7 8 9
    start = 8
    Print: 8 7 6 5
    Output: 567898765

Final Output:
     1
    232
   34543
  4567654
 567898765
*/