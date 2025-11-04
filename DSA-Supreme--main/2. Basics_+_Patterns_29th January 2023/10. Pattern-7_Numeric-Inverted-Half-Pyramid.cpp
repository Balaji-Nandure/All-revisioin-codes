/*
Approach:
- Print a numeric inverted half-pyramid with n rows.
- Each row r (0-indexed) prints numbers 1..(n-r) separated by spaces.
- Use nested loops: outer for rows, inner for the sequence in each row.
*/

#include<iostream> // Include I/O facilities
using namespace std; // Use the standard namespace

int main(){ // Program entry
    int n = 6; // Height/base width of the pyramid
    for(int row = 0; row < n; row = row + 1){ // Iterate rows 0..n-1
        for(int col = 0; col < n - row; col = col + 1){ // Print 1..(n-row)
            cout << col + 1 << " "; // Print current number and a space
        } // End inner loop
        cout << endl; // Move to next line
    } // End outer loop
    return 0; // Successful execution
}

/*
Dry Run (n = 4):
row = 0 -> print: 1 2 3 4
row = 1 -> print: 1 2 3
row = 2 -> print: 1 2
row = 3 -> print: 1

Output:
1 2 3 4
1 2 3
1 2
1
*/