/*
Approach:
- Print a numeric half-pyramid with n rows.
- Row r (0-indexed) contains the numbers 1..(r+1), separated by spaces.
- Use nested loops: outer for rows, inner for numbers within the row.
*/

#include<iostream> // Include I/O facilities
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int n = 5; // Height of the numeric half-pyramid
    for(int row = 0; row < n; row = row + 1){ // Iterate rows 0..n-1
        for(int col = 0; col < row + 1; col = col + 1){ // Print 1..(row+1)
            cout << col + 1 << " "; // Print current number with a trailing space
        } // End inner loop
        cout << endl; // Move to next line after each row
    } // End outer loop
    return 0; // Successful execution
}

/*
Dry Run (n = 4):
row = 0 -> print: 1
row = 1 -> print: 1 2
row = 2 -> print: 1 2 3
row = 3 -> print: 1 2 3 4

Output:
1
1 2
1 2 3
1 2 3 4
*/