#include<iostream>
using namespace std;

/*
Approach:
-----------
- The code calculates and prints the sum of each row in a 2D array.
- It iterates through each row, computes the sum of elements in that row, and prints the result.

Logic Explanation:
-------------------
1. The function `rowWisePrint` takes a 2D array and its dimensions as input.
2. For each row, it initializes a sum variable to 0.
3. It then iterates through all columns of the current row, adding each element to the sum.
4. After processing a row, it prints the sum for that row.

Better/Alternative Approaches:
-------------------------------
1. **Dynamic Column Size**: Instead of hardcoding column size in function parameter, use pointers or templates for more flexibility.
2. **Using Vectors**: Use `vector<vector<int>>` for dynamic 2D arrays.
3. **Row Sum Storage**: Store row sums in a separate array if needed for further processing.

Example of using vectors (Alternative Approach):
-------------------------------------------------
/*
#include <vector>
void rowWisePrint(const vector<vector<int>>& arr) {
    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for(int j = 0; j < arr[i].size(); j++) {
            sum += arr[i][j];
        }
        cout << "Printing sum of row " << i << " " << sum << endl;
    }
}
*/

void rowWisePrint(int arr[][3], int rows, int cols){
    // Loop through each row
    for(int i = 0; i < rows; i++){
        int sum = 0; // Initialize sum for current row
        // Loop through each column in the current row
        for(int j = 0; j < cols; j++){
            sum = sum + arr[i][j]; // Add current element to sum
        }
        // Print the sum of the current row
        cout << "Printing sum of row " << i << " " << sum << endl;
    }
}

int main(){
    // Initialize a 3x3 2D array
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;      // Number of rows
    int columns = 3;   // Number of columns
    rowWisePrint(arr, rows, columns); // Call function to print row sums
    return 0;
}

/*
Dry Run:
----------
arr = {{1,2,3},
       {4,5,6},
       {7,8,9}}

rows = 3, columns = 3

Iteration 1 (i=0):
    sum = 0
    sum += arr[0][0] => 0+1 = 1
    sum += arr[0][1] => 1+2 = 3
    sum += arr[0][2] => 3+3 = 6
    Output: Printing sum of row 0 6

Iteration 2 (i=1):
    sum = 0
    sum += arr[1][0] => 0+4 = 4
    sum += arr[1][1] => 4+5 = 9
    sum += arr[1][2] => 9+6 = 15
    Output: Printing sum of row 1 15

Iteration 3 (i=2):
    sum = 0
    sum += arr[2][0] => 0+7 = 7
    sum += arr[2][1] => 7+8 = 15
    sum += arr[2][2] => 15+9 = 24
    Output: Printing sum of row 2 24

Final Output:
Printing sum of row 0 6
Printing sum of row 1 15
Printing sum of row 2 24
*/
