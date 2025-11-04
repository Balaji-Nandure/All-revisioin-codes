/*
Approach Used:
---------------
- Dynamically allocate a 2D array (matrix) using heap memory in C++.
- Initialize all elements to 0.
- Print the 2D array.
- Deallocate all dynamically allocated memory to prevent memory leaks.

Key Points:
-----------
- Dynamic allocation allows for flexible array sizes at runtime.
- Each row is allocated separately, so memory is not contiguous.
- Proper deallocation is crucial to avoid memory leaks.

Better Alternatives:
--------------------
1. Use `std::vector<std::vector<int>>` for automatic memory management and contiguous storage.
2. Allocate a single contiguous block for the 2D array and use pointer arithmetic for access.
   (See detailed code for both alternatives in comments below.)

*/

// Include necessary header
#include<iostream>
using namespace std;

int main(){
    int row = 5; // Number of rows in the 2D array
    int col = 3; // Number of columns in the 2D array

    // Step 1: Dynamic allocation of array of pointers (each for a row)
    int **arr = new int*[row]; // arr is a pointer to an array of int pointers

    // Step 2: Allocate memory for each row
    for(int i = 0; i < row; i++){
        arr[i] = new int[col]; // Each row is a dynamic array of 'col' integers
    }

    // Step 3: Initialize all elements to 0
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = 0; // Set each element to 0
        }
    }

    // Step 4: Print the 2D array
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << arr[i][j] << " "; // Print each element
        }
        cout << endl; // Newline after each row
    }

    // Step 5: Deallocate memory to prevent memory leaks
    for(int i = 0; i < row; i++){ // Must use 'row', not 'col' here!
        delete [] arr[i]; // Delete each row
    }
    delete [] arr; // Delete the array of pointers

    return 0;
}

/*
-------------------------------
Better Alternatives (Recommended)
-------------------------------

1. Using std::vector (Best for C++):
-------------------------------------
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int row = 5, col = 3;
    vector<vector<int>> arr(row, vector<int>(col, 0)); // 2D vector initialized to 0
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // No need for manual deallocation!
    return 0;
}

2. Single Contiguous Block Allocation:
--------------------------------------
#include <iostream>
using namespace std;
int main() {
    int row = 5, col = 3;
    int* data = new int[row * col](); // Allocate and zero-initialize
    // Access: data[i * col + j]
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << data[i * col + j] << " ";
        }
        cout << endl;
    }
    delete[] data;
    return 0;
}

-------------------------------
Dry Run of the Main Code
-------------------------------
row = 5, col = 3
Step 1: arr = new int*[5]; // arr points to 5 int* (rows)
Step 2: For i = 0 to 4, arr[i] = new int[3]; // Each arr[i] points to 3 ints (columns)
Step 3: All arr[i][j] set to 0
Step 4: Print all arr[i][j] (all zeros, 5 rows, 3 columns)
Step 5: For i = 0 to 4, delete[] arr[i]; // Free each row
        delete[] arr; // Free array of pointers

Output:
0 0 0 
0 0 0 
0 0 0 
0 0 0 
0 0 0 

Note: In the original code, the deallocation loop was incorrect (used 'col' instead of 'row'). This is fixed above.
*/