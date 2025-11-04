/*
Approach:
- We want to print a numeric hollow inverted half pyramid of height n.
- For each row i (from 0 to n-1):
    - For each column j (from 0 to n-i-1):
        - If it's the first row (i==0), print numbers from 1 to n.
        - If it's the last row (i==n-1), print only n.
        - For other rows:
            - If it's the first column (j==0), print i+1.
            - If it's the last column in the row (j==n-i-1), print n.
            - Otherwise, print spaces to keep the pyramid hollow.
- Use nested loops: outer for rows, inner for columns.
- Print a newline after each row.
*/

#include<iostream> // Include the standard input-output stream library for cout and endl
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 5; // Initialize the height of the pyramid

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n; i = i + 1){ // Loop variable i represents the current row

        // Inner loop for each column in the current row (j from 0 to n-i-1)
        for(int j = 0; j < n - i; j = j + 1){ // Loop variable j represents the current column

            if(i == 0){ // If it's the first row
                cout << j + 1 << " "; // Print numbers from 1 to n with a space
            }
            else if(i == n - 1){ // If it's the last row
                cout << n; // Print only n
            }
            else{ // For all other rows (not first and not last)
                if(j == 0){ // If it's the first column in the row
                    cout << i + 1 << " "; // Print the row number + 1 followed by a space
                }
                else if(j == n - i - 1){ // If it's the last column in the row
                    cout << n; // Print n
                }
                else{ // For all columns in between
                    cout << "  "; // Print two spaces to keep the pyramid hollow
                }
            }
        } // End of inner loop (columns)

        cout << endl; // Move to the next line after each row

    } // End of outer loop (rows)

    return 0; // Indicate successful program termination

}

/*
Dry Run (n = 5):

Row 0 (i=0, j=0..4): Print 1 2 3 4 5
1 2 3 4 5 

Row 1 (i=1, j=0..3): First col (2), spaces, last col (5)
2     5 

Row 2 (i=2, j=0..2): First col (3), space, last col (5)
3   5 

Row 3 (i=3, j=0..1): First col (4), last col (5)
4 5 

Row 4 (i=4, j=0): Only n (5)
5

Output:
1 2 3 4 5 
2     5 
3   5 
4 5 
5
*/