/*
Approach Used:
---------------
This code performs an in-place transpose of a square matrix (3x3 in this case). 
The transpose of a matrix is obtained by swapping its rows with columns, i.e., element at (i, j) becomes (j, i).
For a square matrix, this can be done in-place by swapping elements above the main diagonal with those below it.

Key Steps:
1. Print the original matrix.
2. Transpose the matrix in-place by swapping arr[i][j] with arr[j][i] for all i > j.
3. Print the transposed matrix.

Alternative Approaches:
----------------------
1. For non-square matrices, you cannot transpose in-place. You need to create a new matrix of size [cols][rows].
   Example:
   ```
   void transpose(int arr[][3], int rows, int cols, int result[][3]) {
       for(int i = 0; i < rows; i++) {
           for(int j = 0; j < cols; j++) {
               result[j][i] = arr[i][j];
           }
       }
   }
   ```
2. For square matrices, you can also use STL vector for dynamic size.

Dry Run:
--------
Original Matrix:
1 2 3
4 5 6
7 8 9

After transpose (swap arr[i][j] with arr[j][i] for i > j):
- swap arr[1][0] with arr[0][1] => 2 <-> 4
- swap arr[2][0] with arr[0][2] => 3 <-> 7
- swap arr[2][1] with arr[1][2] => 6 <-> 8

Transposed Matrix:
1 4 7
2 5 8
3 6 9
*/

#include<iostream>
using namespace std;

// Function to transpose a square matrix in-place
void transpose(int arr[][3], int rows, int cols){
    // Loop through each row
    for(int i = 0; i < rows; i++){
        // Loop through each column before the diagonal (to avoid double swapping and diagonal elements)
        for(int j = 0; j < i; j++){
            // Swap element at (i, j) with element at (j, i)
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main(){
    // Initialize a 3x3 matrix
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;
    int columns = 3;

    // Print the original matrix
    cout << "Printing array first " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Taking transpose " << endl;

    // Transpose the matrix in-place
    transpose(arr, rows, columns);

    // Print the transposed matrix
    cout << "Printing transposed array " << endl;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
Alternative Approach for Non-Square Matrix (with code):

// Transpose for non-square matrix (rows x cols) to (cols x rows)
void transpose(int arr[][3], int rows, int cols, int result[][3]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = arr[i][j];
        }
    }
}

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};
    int result[3][2];
    transpose(arr, 2, 3, result);
    // Print result matrix
}

Dry Run Example:
----------------
Original:
1 2 3
4 5 6
7 8 9

i=1, j=0: swap arr[1][0] (4) with arr[0][1] (2)
Matrix:
1 4 3
2 5 6
7 8 9

i=2, j=0: swap arr[2][0] (7) with arr[0][2] (3)
Matrix:
1 4 7
2 5 6
3 8 9

i=2, j=1: swap arr[2][1] (8) with arr[1][2] (6)
Matrix:
1 4 7
2 5 8
3 6 9

Final Transposed Matrix:
1 4 7
2 5 8
3 6 9
*/
