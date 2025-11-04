/*
Approach:
- We want to print a numeric hollow half pyramid of height n.
- For each row i (from 0 to n-1):
    - For each column j (from 0 to i):
        - If it's the first row (i==0), print 1.
        - If it's the last row (i==n-1), print numbers from 1 to n (j+1).
        - For other rows:
            - If it's the first column (j==0), print 1.
            - If it's the last column in the row (j==i), print i+1.
            - Otherwise, print spaces to keep the pyramid hollow.
- Use nested loops: outer for rows, inner for columns.
- Print a newline after each row.
*/

#include<iostream> // Include the standard input-output stream library
using namespace std; // Use the standard namespace

int main(){ // Program entry point

    int n = 6; // Initialize the height of the pyramid

    // Outer loop for each row (i from 0 to n-1)
    for(int i = 0; i < n ; i++){ // Loop variable i represents the current row

        // Inner loop for each column in the current row (j from 0 to i)
        for(int j = 0; j < i + 1; j++){ // Loop variable j represents the current column

            if(i == 0){ // If it's the first row
                cout << 1; // Print 1 (only one element in the first row)
            }
            else if(i == n - 1){ // If it's the last row
                cout << j + 1 << " "; // Print numbers from 1 to n with a space
            }
            else{ // For all other rows (not first and not last)
                if(j == 0){ // If it's the first column in the row
                    cout << 1 << " "; // Print 1 followed by a space
                }
                else if(j == i){ // If it's the last column in the row
                    cout << i + 1 << " "; // Print the row number + 1 followed by a space
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
Dry Run (n = 6):

Row 0 (i=0): Only one element, print 1
1

Row 1 (i=1): First column (1), last column (2)
1 2 

Row 2 (i=2): First column (1), space, last column (3)
1   3 

Row 3 (i=3): First column (1), spaces, last column (4)
1     4 

Row 4 (i=4): First column (1), spaces, last column (5)
1       5 

Row 5 (i=5): Last row, print 1 2 3 4 5 6
1 2 3 4 5 6 

Output:
1
1 2 
1   3 
1     4 
1       5 
1 2 3 4 5 6 
*/