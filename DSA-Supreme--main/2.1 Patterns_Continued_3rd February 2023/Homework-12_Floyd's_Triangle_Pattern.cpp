/*
Approach:
- The goal is to print Floyd's Triangle pattern for a given number of rows n.
- Floyd's Triangle is a right-angled triangular array of natural numbers, used to teach basic arithmetic.
- For each row i (from 0 to n-1), print (i+1) consecutive numbers, starting from 1 and incrementing by 1 each time.
- Use a variable 'num' to keep track of the current number to print.
- Use nested loops: the outer loop for rows, the inner loop for columns (numbers in each row).
- After printing each row, move to the next line.
*/

#include<iostream> // Include the standard input-output stream library for cout and endl
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int num = 1; // Initialize the starting number to print in the triangle
    int n = 4;   // Set the number of rows for Floyd's Triangle

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Inner loop for each number in the current row (j from 0 to i)
        for(int j = 0; j < i + 1; j = j + 1){ // Print (i+1) numbers in the current row
            cout << num << " "; // Print the current number followed by a space
            num = num + 1;      // Increment the number for the next print
        }

        cout << endl; // Move to the next line after each row is printed

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 4):

Initialization:
num = 1
n = 4

Row 0 (i=0):
    j=0: print 1 (num=1), num becomes 2
    Output: 1

Row 1 (i=1):
    j=0: print 2 (num=2), num becomes 3
    j=1: print 3 (num=3), num becomes 4
    Output: 2 3

Row 2 (i=2):
    j=0: print 4 (num=4), num becomes 5
    j=1: print 5 (num=5), num becomes 6
    j=2: print 6 (num=6), num becomes 7
    Output: 4 5 6

Row 3 (i=3):
    j=0: print 7 (num=7), num becomes 8
    j=1: print 8 (num=8), num becomes 9
    j=2: print 9 (num=9), num becomes 10
    j=3: print 10 (num=10), num becomes 11
    Output: 7 8 9 10

Final Output:
1 
2 3 
4 5 6 
7 8 9 10 

*/