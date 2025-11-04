#include<iostream>
using namespace std;

/*
Approach Used:
---------------
- The function columnWisePrint calculates the sum of each column in a 2D array.
- It does this by traversing the array column by column (i.e., for each column, it sums up all the elements in that column).
- The function then prints the sum for each column.

Detailed Logic:
---------------
- The outer loop (with variable 'i') iterates over columns.
- For each column, initialize sum to 0.
- The inner loop (with variable 'j') iterates over rows, adding the element at arr[j][i] to sum.
- After summing all elements in the current column, print the sum.

Note:
- The function assumes a fixed column size of 3 (as per arr[][3]), which is fine for this example but not flexible for other sizes.

*/

void columnWisePrint(int arr[][3], int rows, int cols) {
    // Traverse each column one by one
    for(int i = 0; i < cols; i++) { // 'i' is the column index
        int sum = 0; // Initialize sum for the current column
        for(int j = 0; j < rows; j++) { // 'j' is the row index
            sum = sum + arr[j][i]; // Add the element at row 'j' and column 'i' to sum
        }
        // Print the sum of the current column (i+1 for 1-based indexing in output)
        cout << "Sum of " << (i+1) << " column is " << sum << endl;
    }
}

/*
Better/Alternative Approaches:
-----------------------------
1. Make the function more generic by using variable column size:
   void columnWisePrint(int** arr, int rows, int cols) {
       for(int i = 0; i < cols; i++) {
           int sum = 0;
           for(int j = 0; j < rows; j++) {
               sum += arr[j][i];
           }
           cout << "Sum of " << (i+1) << " column is " << sum << endl;
       }
   }
   // But this requires dynamic memory allocation for arr.

2. Using Vectors for dynamic 2D arrays:
   #include <vector>
   void columnWisePrint(const vector<vector<int>>& arr) {
       int rows = arr.size();
       int cols = arr[0].size();
       for(int i = 0; i < cols; i++) {
           int sum = 0;
           for(int j = 0; j < rows; j++) {
               sum += arr[j][i];
           }
           cout << "Sum of " << (i+1) << " column is " << sum << endl;
       }
   }

3. If you want to return the sums instead of printing:
   vector<int> getColumnSums(const vector<vector<int>>& arr) {
       int rows = arr.size();
       int cols = arr[0].size();
       vector<int> sums(cols, 0);
       for(int i = 0; i < cols; i++) {
           for(int j = 0; j < rows; j++) {
               sums[i] += arr[j][i];
           }
       }
       return sums;
   }

*/

/*
Dry Run:
--------
Given arr[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}
rows = 3, cols = 3

For i = 0 (1st column):
    sum = arr[0][0] + arr[1][0] + arr[2][0] = 1 + 4 + 7 = 12
    Output: Sum of 1 column is 12

For i = 1 (2nd column):
    sum = arr[0][1] + arr[1][1] + arr[2][1] = 2 + 5 + 8 = 15
    Output: Sum of 2 column is 15

For i = 2 (3rd column):
    sum = arr[0][2] + arr[1][2] + arr[2][2] = 3 + 6 + 9 = 18
    Output: Sum of 3 column is 18
*/

int main() {
    // Declare and initialize a 3x3 2D array
    int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int rows = 3; // Number of rows in the array
    int cols = 3; // Number of columns in the array

    // Call the function to print column-wise sums
    columnWisePrint(arr, rows, cols);

    return 0; // Indicate successful program termination
}