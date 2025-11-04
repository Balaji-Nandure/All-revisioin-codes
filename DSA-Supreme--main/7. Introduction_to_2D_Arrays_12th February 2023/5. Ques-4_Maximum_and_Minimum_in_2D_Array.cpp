/*
Approach Used in This Code:
---------------------------
- The code finds the maximum and minimum elements in a 2D array (matrix).
- It does this by traversing every element of the matrix using nested loops.
- For maximum, it keeps updating the largest value found so far.
- For minimum, it keeps updating the smallest value found so far.

Logic/Comments for Important Lines:
-----------------------------------
- #include<limits.h>: To use INT_MIN and INT_MAX for initialization.
- int maximum(...): Function to find the maximum element in the 2D array.
- int minimum(...): Function to find the minimum element in the 2D array.
- Nested loops: Used to traverse each element of the matrix.
- if(arr[i][j] > maxi): Update maximum if current element is greater.
- if(arr[i][j] < mini): Update minimum if current element is smaller.
- main(): Initializes a 3x3 matrix and prints the maximum and minimum.

Better/Alternative Approaches:
-------------------------------
1. **Using Vectors for Dynamic Size:**
   ```
   #include <vector>
   int maximum(const vector<vector<int>>& arr) {
       int maxi = INT_MIN;
       for(const auto& row : arr)
           for(int val : row)
               if(val > maxi) maxi = val;
       return maxi;
   }
   int minimum(const vector<vector<int>>& arr) {
       int mini = INT_MAX;
       for(const auto& row : arr)
           for(int val : row)
               if(val < mini) mini = val;
       return mini;
   }
   ```
2. **Single Function for Both Max and Min:**
   ```
   void findMaxMin(int arr[][3], int rows, int cols, int &maxi, int &mini) {
       maxi = INT_MIN;
       mini = INT_MAX;
       for(int i=0; i<rows; i++)
           for(int j=0; j<cols; j++) {
               if(arr[i][j] > maxi) maxi = arr[i][j];
               if(arr[i][j] < mini) mini = arr[i][j];
           }
   }
   ```
3. **Using STL Algorithms (for 1D flattening):**
   ```
   #include <algorithm>
   int arr[3][3] = {...};
   int* begin = &arr[0][0];
   int* end = &arr[0][0] + 3*3;
   int maxi = *max_element(begin, end);
   int mini = *min_element(begin, end);
   ```

Dry Run:
--------
Given arr = { {1,2,3},
              {4,5,6},
              {7,8,9} }
- Initial maxi = INT_MIN, mini = INT_MAX
- Traverse all elements:
    - Compare each element with maxi and mini, update accordingly.
- After traversal:
    - maxi = 9 (largest element)
    - mini = 1 (smallest element)
- Output: Maxi = 9 and Mini = 1
*/

#include<iostream>
#include<limits.h> // For INT_MIN and INT_MAX
using namespace std;

// Function to find the maximum element in a 2D array
int maximum(int arr[][3], int rows, int cols){
    int maxi = INT_MIN; // Initialize maxi to the smallest integer
    for(int i = 0; i < rows; i++){ // Traverse each row
        for(int j = 0; j < cols; j++){ // Traverse each column in the current row
            if(arr[i][j] > maxi){ // If current element is greater than maxi
                maxi = arr[i][j]; // Update maxi
            }
        }
    }
    return maxi; // Return the maximum value found
}

// Function to find the minimum element in a 2D array
int minimum(int arr[][3], int rows, int cols){
    int mini = INT_MAX; // Initialize mini to the largest integer
    for(int i = 0; i < rows; i++){ // Traverse each row
        for(int j = 0; j < cols; j++){ // Traverse each column in the current row
            if(arr[i][j] < mini){ // If current element is less than mini
                mini = arr[i][j]; // Update mini
            }
        }
    }
    return mini; // Return the minimum value found
}

int main(){
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // Initialize a 3x3 matrix
    int rows = 3;      // Number of rows
    int columns = 3;   // Number of columns

    // Print the maximum and minimum values in the matrix
    cout << "Maxi = " << maximum(arr, rows, columns) 
         << " and  Mini = " << minimum(arr, rows, columns) << endl;

    return 0;
}

/*
Dry Run:
--------
arr = { {1,2,3},
        {4,5,6},
        {7,8,9} }
maximum:
- maxi = INT_MIN
- Compare: 1 > maxi? Yes -> maxi=1
- 2 > 1? Yes -> maxi=2
- 3 > 2? Yes -> maxi=3
- 4 > 3? Yes -> maxi=4
- 5 > 4? Yes -> maxi=5
- 6 > 5? Yes -> maxi=6
- 7 > 6? Yes -> maxi=7
- 8 > 7? Yes -> maxi=8
- 9 > 8? Yes -> maxi=9
Return 9

minimum:
- mini = INT_MAX
- Compare: 1 < mini? Yes -> mini=1
- 2 < 1? No
- 3 < 1? No
- 4 < 1? No
- ... (all others not less than 1)
Return 1

Output: Maxi = 9 and  Mini = 1
*/