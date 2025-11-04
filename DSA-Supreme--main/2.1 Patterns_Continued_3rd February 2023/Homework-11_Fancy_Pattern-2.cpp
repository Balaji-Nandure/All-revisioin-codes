/*
Approach:
This program prints two fancy patterns using numbers and asterisks.
- Pattern 1: For each row, it prints an increasing sequence of numbers separated by '*' in odd positions.
- Pattern 2: For each row, it prints a decreasing sequence of numbers (starting from 2*n-1) separated by '*' in odd positions.
Both patterns use nested loops and careful control of number increments.

Dry Run is provided at the end of the code.
*/

#include<iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function starts
    int n = 4; // Number of rows for the patterns
    int num = 1; // Initialize the starting number for Pattern 1

    // Pattern - 1
    // Outer loop for each row
    for(int i = 0; i < n; i++){ // Loop from 0 to n-1 (4 rows)
        // Inner loop for each element in the row
        for(int j = 0; j < 2*i + 1; j++){ // Each row has (2*i+1) elements
            if(j % 2 == 0){ // If position is even, print number
                cout << num << " "; // Print current number
                num++; // Increment number for next print
            }
            else{ // If position is odd, print '*'
                cout << "* "; // Print asterisk
            }
        }
        cout << endl; // Move to next line after each row
    }  

    // Pattern - 2
    int k = 2*n - 1; // Initialize starting number for Pattern 2

    // Outer loop for each row
    for(int i = 0; i < n; i++){ // Loop from 0 to n-1 (4 rows)
        int j = 0; // Initialize column index
        // Inner loop for each element in the row
        for(; j < 2*n - 2*i - 1; j++){ // Each row has (2*n-2*i-1) elements
            if(j % 2 == 0){ // If position is even, print number
                cout << k << " "; // Print current number
                k++; // Increment number for next print
            }
            else{ // If position is odd, print '*'
                cout << "* "; // Print asterisk
            }
        }
        k = k - j; // Reset k to the correct starting number for the next row
        cout << endl; // Move to next line after each row
    }
    return 0; // End of main function
}

/*
Dry Run:

n = 4

Pattern 1:
i=0: j=0 -> 1
      Output: 1
i=1: j=0 -> 2, j=1 -> *, j=2 -> 3
      Output: 2 * 3
i=2: j=0 -> 4, j=1 -> *, j=2 -> 5, j=3 -> *, j=4 -> 6
      Output: 4 * 5 * 6
i=3: j=0 -> 7, j=1 -> *, j=2 -> 8, j=3 -> *, j=4 -> 9, j=5 -> *, j=6 -> 10
      Output: 7 * 8 * 9 * 10

Pattern 2:
k starts at 7
i=0: j=0 -> 7, j=1 -> *, j=2 -> 8, j=3 -> *, j=4 -> 9, j=5 -> *, j=6 -> 10
      Output: 7 * 8 * 9 * 10
      k reset to 7
i=1: j=0 -> 7, j=1 -> *, j=2 -> 8, j=3 -> *, j=4 -> 9
      Output: 7 * 8 * 9
      k reset to 7
i=2: j=0 -> 7, j=1 -> *, j=2 -> 8
      Output: 7 * 8
      k reset to 7
i=3: j=0 -> 7
      Output: 7

Final Output:
1
2 * 3
4 * 5 * 6
7 * 8 * 9 * 10
7 * 8 * 9 * 10
7 * 8 * 9
7 * 8
7
*/