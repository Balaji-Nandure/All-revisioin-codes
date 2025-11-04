/*
    Approach Used:
    ----------------
    The code implements Binary Search on a 2D matrix by treating the matrix as a virtual 1D sorted array.
    The matrix is assumed to be sorted in row-major order (each row and each column is sorted, and the first element of each row is greater than the last element of the previous row).
    The binary search is performed on the range [0, rows*cols - 1], and the 1D index is mapped to 2D indices using:
        rowIndex = mid / cols
        colIndex = mid % cols

    Better Alternatives (without code):
    -----------------------------------
    1. If the matrix is only row-wise and column-wise sorted (not strictly as above), a better approach is the "Staircase Search":
        - Start from the top-right or bottom-left corner.
        - Move left if the current element is greater than the target, move down if it is less.
        - Time Complexity: O(rows + cols)
    2. If the matrix is sorted as per the current assumption, the current approach is optimal: O(log(rows*cols))
    3. For very large matrices, consider memory-efficient approaches or external memory search.

    Code with detailed comments and improvements:
*/

#include<iostream>
using namespace std;

// Function to perform binary search on a 2D matrix
bool binarySearch(int arr[][4], int rows, int cols, int target) {
    int s = 0; // Start index of virtual 1D array
    int e = rows * cols - 1; // End index of virtual 1D array

    // Binary search loop
    while (s <= e) {
        int mid = s + (e - s) / 2; // Prevents integer overflow

        // Map 1D index to 2D indices
        int rowIndex = mid / cols; // Row number in 2D matrix
        int colIndex = mid % cols; // Column number in 2D matrix

        // Debug: Uncomment to see the current mid, rowIndex, colIndex, and value
        // cout << "Checking at (" << rowIndex << "," << colIndex << ") = " << arr[rowIndex][colIndex] << endl;

        // If target found, return true
        if (arr[rowIndex][colIndex] == target)
            return true;

        // If current element is less than target, search right half
        if (arr[rowIndex][colIndex] < target) {
            s = mid + 1;
        }
        // If current element is greater than target, search left half
        else {
            e = mid - 1;
        }
    }
    // Target not found
    return false;
}

int main() {
    // 2D matrix initialization (5 rows x 4 columns)
    int arr[5][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };
    int rows = 5;
    int cols = 4;
    int target = 29; // Target to search

    // Call binary search function
    bool ans = binarySearch(arr, rows, cols, target);

    // Output result
    if (ans) {
        cout << "Found" << endl;
    }
    else {
        cout << "Not found" << endl;
    }
    return 0;
}

/*
    Dry Run Example:
    ----------------
    Matrix:
    1   2   3   4
    5   6   7   8
    9  10  11  12
    13 14  15  16
    17 18  19  20

    Target: 29

    rows = 5, cols = 4
    s = 0, e = 19

    Iteration 1:
        mid = (0+19)/2 = 9
        rowIndex = 9/4 = 2, colIndex = 9%4 = 1
        arr[2][1] = 10 < 29 => s = 10

    Iteration 2:
        mid = (10+19)/2 = 14
        rowIndex = 14/4 = 3, colIndex = 14%4 = 2
        arr[3][2] = 15 < 29 => s = 15

    Iteration 3:
        mid = (15+19)/2 = 17
        rowIndex = 17/4 = 4, colIndex = 17%4 = 1
        arr[4][1] = 18 < 29 => s = 18

    Iteration 4:
        mid = (18+19)/2 = 18
        rowIndex = 18/4 = 4, colIndex = 18%4 = 2
        arr[4][2] = 19 < 29 => s = 19

    Iteration 5:
        mid = (19+19)/2 = 19
        rowIndex = 19/4 = 4, colIndex = 19%4 = 3
        arr[4][3] = 20 < 29 => s = 20

    Now, s > e (20 > 19), so loop ends. Target not found.

    Output: Not found

    Note: If you change target to 14, the function will return "Found".
*/