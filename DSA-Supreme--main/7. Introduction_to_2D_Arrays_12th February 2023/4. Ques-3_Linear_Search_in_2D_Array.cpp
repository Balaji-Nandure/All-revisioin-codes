#include<iostream>
using namespace std;

/*
Approach Used:
---------------
- We are performing a simple linear search in a 2D array.
- The function 'findKey' iterates through each element of the 2D array using nested loops.
- If the key is found, it returns true immediately; otherwise, after checking all elements, it returns false.

Time Complexity: O(rows * cols)
Space Complexity: O(1)
*/

// Function to search for a key in a 2D array
bool findKey(int arr[][3], int rows, int cols, int key) {
    // Outer loop iterates over each row
    for(int i = 0; i < rows; i++) {
        // Inner loop iterates over each column in the current row
        for(int j = 0; j < cols; j++) {
            // Check if current element matches the key
            if(arr[i][j] == key) {
                // If found, return true immediately
                return true;
            }
        }
    }
    // If not found after checking all elements, return false
    return false;
}

int main() {
    // Initializing a 3x3 2D array
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; 
    int rows = 3;      // Number of rows
    int columns = 3;   // Number of columns
    int key = 10;      // Key to search for

    // Call the findKey function and print result
    if(findKey(arr, rows, columns, key)) {
        cout << "Found Element ";
    }
    else {
        cout << "Absent ";
    }
    
    return 0;
}

/*
-------------------------------
Better Alternative Approaches:
-------------------------------

1. If the 2D array is sorted row-wise and column-wise (like a matrix where each row and column is sorted in ascending order), 
   we can use a more efficient search (Staircase Search):

   // Time Complexity: O(rows + cols)
   bool searchSortedMatrix(int arr[][3], int rows, int cols, int key) {
       int i = 0, j = cols - 1; // Start from top-right corner
       while(i < rows && j >= 0) {
           if(arr[i][j] == key)
               return true;
           else if(arr[i][j] > key)
               j--; // Move left
           else
               i++; // Move down
       }
       return false;
   }

2. If the 2D array is flattened into a 1D sorted array, we can use binary search for O(log(n*m)) time.

   // Not applicable for general 2D arrays unless sorted and mapped accordingly.

-------------------------------
Dry Run of the Code:
-------------------------------

Given arr = {{1,2,3},{4,5,6},{7,8,9}}, key = 10

Step 1: i=0, j=0 -> arr[0][0]=1 != 10
Step 2: i=0, j=1 -> arr[0][1]=2 != 10
Step 3: i=0, j=2 -> arr[0][2]=3 != 10
Step 4: i=1, j=0 -> arr[1][0]=4 != 10
Step 5: i=1, j=1 -> arr[1][1]=5 != 10
Step 6: i=1, j=2 -> arr[1][2]=6 != 10
Step 7: i=2, j=0 -> arr[2][0]=7 != 10
Step 8: i=2, j=1 -> arr[2][1]=8 != 10
Step 9: i=2, j=2 -> arr[2][2]=9 != 10

All elements checked, key not found. Output: "Absent"
*/