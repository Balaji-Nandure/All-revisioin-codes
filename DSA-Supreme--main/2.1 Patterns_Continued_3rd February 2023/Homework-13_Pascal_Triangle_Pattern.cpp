/*
Approach:
- The code prints Pascal's Triangle up to n rows.
- For each row, it calculates the binomial coefficients using the formula: C = C * (i-j)/j.
- Each coefficient is printed in its respective position.
- The triangle is built row by row, and each row starts with C=1.
*/

#include<iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Main function starts
    int n = 7; // Number of rows for Pascal's Triangle

    // Loop through each row from 1 to n
    for(int i = 1; i <= n; i++){
        int C = 1; // Initialize the first value in the row to 1 (nC0 = 1)

        // Loop through each element in the current row
        for(int j = 1; j <= i; j++){
            cout << C << " "; // Print the current binomial coefficient
            C = C * (i - j) / j; // Update C to the next binomial coefficient using the formula
        }
        cout << endl; // Move to the next line after printing all coefficients in the row
    }
    return 0; // Return 0 to indicate successful execution
}

/*
Dry Run:
n = 7

Row 1: i=1
    j=1: C=1 -> print 1
    Output: 1

Row 2: i=2
    j=1: C=1 -> print 1
    j=2: C = 1*(2-1)/2 = 0 -> print 1
    Output: 1 1

Row 3: i=3
    j=1: C=1 -> print 1
    j=2: C = 1*(3-1)/2 = 1 -> print 1
    j=3: C = 1*(3-2)/3 = 0 -> print 1
    Output: 1 2 1

Row 4: i=4
    j=1: C=1 -> print 1
    j=2: C = 1*(4-1)/2 = 1.5 -> int division = 1 -> print 1
    j=3: C = 1*(4-2)/3 = 0.666... -> int division = 0 -> print 1
    j=4: C = 0*(4-3)/4 = 0 -> print 1
    Output: 1 3 3 1

Row 5: i=5
    Output: 1 4 6 4 1

Row 6: i=6
    Output: 1 5 10 10 5 1

Row 7: i=7
    Output: 1 6 15 20 15 6 1

Final Output:
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1
*/