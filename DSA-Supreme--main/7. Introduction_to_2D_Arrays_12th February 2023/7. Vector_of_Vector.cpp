/*
Approach:
- We are demonstrating how to use a vector of vectors (2D vector) in C++ to store and print a 2D array.
- We create three 1D vectors and push them into a 2D vector.
- Then, we print the 2D vector using nested loops.

Better Alternatives:
1. Use range-based for loops for better readability and to avoid index errors.
2. Dynamically take input for the 2D vector instead of hardcoding.
3. Use arr[i].size() instead of arr[0].size() in the inner loop to handle jagged arrays.

Alternative code using range-based for loop:
-------------------------------------------------
for(const auto& row : arr){
    for(const auto& elem : row){
        cout << elem << " ";
    }
    cout << endl;
}
-------------------------------------------------

Dry Run:
----------
arr = [
    [1,2,3],
    [2,4,6],
    [1,3,7]
]
Output:
1 2 3
2 4 6
1 3 7
*/

#include<iostream> // for input/output stream
#include<vector>   // for using vector container
using namespace std;

int main(){
    vector<vector<int>> arr; // Declare a 2D vector (vector of vectors) to store integer arrays

    vector<int> a{1,2,3};    // Create first row as a vector
    vector<int> b{2,4,6};    // Create second row as a vector
    vector<int> c{1,3,7};    // Create third row as a vector

    arr.push_back(a);        // Add first row to 2D vector
    arr.push_back(b);        // Add second row to 2D vector
    arr.push_back(c);        // Add third row to 2D vector

    // Print the 2D vector using nested loops
    // Outer loop iterates over each row
    for(int i = 0; i < arr.size(); i++){
        // Inner loop iterates over each element in the current row
        // Use arr[i].size() to handle rows of different sizes (jagged arrays)
        for(int j = 0; j < arr[i].size(); j++){
            cout << arr[i][j] << " "; // Print element at row i and column j
        }
        cout << endl; // Move to next line after printing each row
    }

    /*
    // Alternative: Using range-based for loops (recommended for readability)
    for(const auto& row : arr){
        for(const auto& elem : row){
            cout << elem << " ";
        }
        cout << endl;
    }
    */

    return 0; // Indicate successful program termination
}

/*
Dry Run:
---------
Step 1: arr = []
Step 2: a = [1,2,3], b = [2,4,6], c = [1,3,7]
Step 3: arr = [[1,2,3],[2,4,6],[1,3,7]]
Step 4: Print each row:
    i=0: 1 2 3
    i=1: 2 4 6
    i=2: 1 3 7
Output:
1 2 3
2 4 6
1 3 7
*/