/*
Approach Used in This Code:
---------------------------
- Demonstrates declaration, initialization, input, and output of 2D arrays (matrices) in C++.
- Shows both row-wise and column-wise access and input.
- Illustrates how to print a 2D array in row-wise and column-wise order.

Logic/Comments for Important Lines:
-----------------------------------
- int arr[3][3]; // Declares a 3x3 2D array (matrix) of integers. Total 9 elements.
- int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // Initializes a 3x3 matrix with values 1 to 9.
- cout<<brr[2][2]<<endl; // Accesses element at 3rd row, 3rd column (indexing from 0), prints 9.
- cout<<brr[1][1]<<endl; // Accesses element at 2nd row, 2nd column, prints 5.
- cout<<brr[0][2]<<endl; // Accesses element at 1st row, 3rd column, prints 3.
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cout<<brr[i][j]<<" "; // Prints matrix row-wise.
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cout<<brr[j][i]<<" "; // Prints matrix column-wise.
- int crr[3][3]; // Declares another 3x3 matrix for input.
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin>>crr[i][j]; // Takes row-wise input.
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cout<<crr[i][j]<<" "; // Prints crr row-wise.
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin>>crr[j][i]; // Takes column-wise input (fills columns one by one).
- for(int i=0; i<3; i++) for(int j=0; j<3; j++) cout<<crr[i][j]<<" "; // Prints crr row-wise after column-wise input.

Alternative Detailed Approaches:
-------------------------------
1. Using Vectors for Dynamic 2D Arrays:
   - Vectors allow dynamic sizing and are safer than raw arrays.
   Example:
   ```
   #include <vector>
   vector<vector<int>> mat(3, vector<int>(3, 0)); // 3x3 matrix initialized to 0
   // Row-wise input
   for(int i=0; i<3; i++)
       for(int j=0; j<3; j++)
           cin >> mat[i][j];
   // Row-wise output
   for(int i=0; i<3; i++) {
       for(int j=0; j<3; j++)
           cout << mat[i][j] << " ";
       cout << endl;
   }
   ```
2. Using Functions for Input/Output:
   - Encapsulate input/output logic in functions for reusability.
   Example:
   ```
   void input2D(int arr[][3], int n, int m) {
       for(int i=0; i<n; i++)
           for(int j=0; j<m; j++)
               cin >> arr[i][j];
   }
   void print2D(int arr[][3], int n, int m) {
       for(int i=0; i<n; i++) {
           for(int j=0; j<m; j++)
               cout << arr[i][j] << " ";
           cout << endl;
       }
   }
   ```

Dry Run:
--------
Initialization:
brr = [ [1,2,3],
        [4,5,6],
        [7,8,9] ]

cout<<brr[2][2]; // prints 9
cout<<brr[1][1]; // prints 5
cout<<brr[0][2]; // prints 3

Row-wise print:
1 2 3
4 5 6
7 8 9

Column-wise print:
1 4 7
2 5 8
3 6 9

Suppose user inputs for crr (row-wise): 10 11 12 13 14 15 16 17 18
crr after row-wise input:
10 11 12
13 14 15
16 17 18

Row-wise print:
10 11 12
13 14 15
16 17 18

Suppose user inputs for crr (column-wise): 21 22 23 24 25 26 27 28 29
crr after column-wise input:
21 24 27
22 25 28
23 26 29

Row-wise print:
21 24 27
22 25 28
23 26 29
*/

#include<iostream>
using namespace std;

int main(){
    int arr[3][3]; // Declares a 3x3 2D array (matrix) of integers. Total 9 elements.

    // Initialization of 2D array with values
    int brr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // 3x3 matrix initialized with 1-9

    // Accessing specific elements in 2D array
    cout << brr[2][2] << endl; // Access element at 3rd row, 3rd column (prints 9)
    cout << brr[1][1] << endl; // Access element at 2nd row, 2nd column (prints 5)
    cout << brr[0][2] << endl; // Access element at 1st row, 3rd column (prints 3)

    // Row-wise access and print
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << brr[i][j] << " "; // Print each element in the current row
        }
        cout << endl; // Move to next line after each row
    }

    // Column-wise access and print
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << brr[j][i] << " "; // Print each element in the current column
        }
        cout << endl; // Move to next line after each column
    }

    // Declaration of another 2D array for input
    int crr[3][3];

    // Row-wise input: user enters elements row by row
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> crr[i][j]; // Input element at row i, column j
        }
    }

    // Print crr row-wise after row-wise input
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << crr[i][j] << " "; // Print each element in the current row
        }
        cout << endl;
    }

    // Column-wise input: user enters elements column by column
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> crr[j][i]; // Input element at row j, column i (fills columns one by one)
        }
    }

    // Print crr row-wise after column-wise input
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << crr[i][j] << " "; // Print each element in the current row
        }
        cout << endl;
    }

    return 0;
}