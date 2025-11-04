#include<iostream>
using namespace std;

/*
Approach:
-----------
- The code calculates the sum of each column in a 2D array and prints it.
- It iterates over each column, and for each column, it sums up all the elements in that column by traversing all rows.
- The function name 'rowWisePrint' is misleading; it actually prints column sums.

Logic:
-------
- Outer loop (i): Iterates over columns (from 0 to cols-1).
- Inner loop (j): Iterates over rows (from 0 to rows-1), accumulating the sum for the current column.
- After summing, print the sum for the current column.

Better Naming:
---------------
- The function should be named 'columnSumPrint' for clarity.

Detailed Comments and Alternatives:
-----------------------------------
*/

void columnSumPrint(int arr[][3], int rows, int cols) {
    // Loop over each column
    for(int i = 0; i < cols; i++) {
        int sum = 0; // Initialize sum for current column
        // Loop over each row for the current column
        for(int j = 0; j < rows; j++) {
            sum = sum + arr[j][i]; // Add element at row j, column i
        }
        // Print the sum of the current column
        cout << "Printing sum of column " << i << " " << sum << endl;
    }
}

int main() {
    // Initialize a 3x3 2D array
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;
    // Call function to print column sums
    columnSumPrint(arr, rows, columns);
    return 0;
}

/*
Alternative Approach 1: Using Vectors (for dynamic size)
---------------------------------------------------------
#include <vector>
void columnSumPrint(const vector<vector<int>>& arr) {
    int rows = arr.size();
    int cols = arr[0].size();
    for(int i = 0; i < cols; i++) {
        int sum = 0;
        for(int j = 0; j < rows; j++) {
            sum += arr[j][i];
        }
        cout << "Printing sum of column " << i << " " << sum << endl;
    }
}

Alternative Approach 2: Row-wise Sum (if needed)
-------------------------------------------------
void rowSumPrint(int arr[][3], int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        int sum = 0;
        for(int j = 0; j < cols; j++) {
            sum += arr[i][j];
        }
        cout << "Printing sum of row " << i << " " << sum << endl;
    }
}

Dry Run:
---------
Given arr:
1 2 3
4 5 6
7 8 9

For column 0: 1 + 4 + 7 = 12
For column 1: 2 + 5 + 8 = 15
For column 2: 3 + 6 + 9 = 18

Output:
Printing sum of column 0 12
Printing sum of column 1 15
Printing sum of column 2 18
*/
