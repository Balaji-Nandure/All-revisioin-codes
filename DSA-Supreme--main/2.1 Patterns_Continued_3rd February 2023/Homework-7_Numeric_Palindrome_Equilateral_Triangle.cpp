/*
Approach:
- Print a numeric palindrome equilateral triangle of height n.
- For each row i (from 0 to n-1):
    - Print (n-i) * 2 spaces to align the triangle centrally.
    - Print increasing numbers from 1 up to (i+1).
    - Then print decreasing numbers from i down to 1.
- Use nested loops: outer for rows, inner for spaces, and two for numbers (increasing and decreasing).
- Print a newline after each row.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 5; // Initialize the height of the triangle

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Calculate the number of spaces to print before the numbers for current row
        int space = n - i - 1; // Number of spaces for current row

        // Inner loop to print spaces for alignment
        for(; space >= 0; space = space - 1){ // Loop to print spaces
            cout << "  "; // Print two spaces for alignment
        }

        // Print the increasing numbers from 1 to (i+1)
        int num = 1; // Start number from 1
        for(int j = 0; j < i + 1; j = j + 1){ // Loop variable j for increasing numbers
            cout << num << " "; // Print the current number followed by a space
            num = num + 1; // Increment the number
        }

        // Print the decreasing numbers from i down to 1
        num = num - 2; // Set num to (i), as num was incremented one extra time in previous loop
        for(; num >= 1; num = num - 1){ // Loop to print decreasing numbers
            cout << num << " "; // Print the current number followed by a space
        }

        cout << endl; // Move to the next line after each row

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 5):

Row 0 (i=0):
    space = 4
    Print: "        1"
Row 1 (i=1):
    space = 3
    Print: "      1 2 1"
Row 2 (i=2):
    space = 2
    Print: "    1 2 3 2 1"
Row 3 (i=3):
    space = 1
    Print: "  1 2 3 4 3 2 1"
Row 4 (i=4):
    space = 0
    Print: "1 2 3 4 5 4 3 2 1"

Output:
        1 
      1 2 1 
    1 2 3 2 1 
  1 2 3 4 3 2 1 
1 2 3 4 5 4 3 2 1 

*/