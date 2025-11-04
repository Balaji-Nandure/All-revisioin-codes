/*
    Approach Used in this Code (Wave Print / Column-wise Zigzag Traversal):
    ----------------------------------------------------------------------
    - The goal is to print the elements of a 2D matrix in a "wave" or "zigzag" order column-wise.
    - For each column:
        - If the column index is even, print from top to bottom.
        - If the column index is odd, print from bottom to top.
    - This creates a wave-like traversal of the matrix.

    Time Complexity: O(m * n), where m = number of rows, n = number of columns.
    Space Complexity: O(1) (prints in-place, no extra space used).

    Better Alternatives (with code in comments):
    --------------------------------------------
    1. **Row-wise Wave Print (if required):**
        - Instead of columns, traverse rows in a wave pattern.
        - For each row:
            - If row index is even, print left to right.
            - If row index is odd, print right to left.
        // Row-wise wave print
        void rowWavePrint(const vector<vector<int>>& v) {
            int m = v.size();
            int n = v[0].size();
            for(int i = 0; i < m; i++) {
                if(i % 2 == 0) {
                    for(int j = 0; j < n; j++)
                        cout << v[i][j] << " ";
                } else {
                    for(int j = n-1; j >= 0; j--)
                        cout << v[i][j] << " ";
                }
            }
        }

    2. **Store Result in a Vector (if you want to return instead of print):**
        // Store wave print in a vector
        vector<int> wavePrintVector(const vector<vector<int>>& v) {
            vector<int> res;
            int m = v.size(), n = v[0].size();
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                    for(int j = 0; j < m; j++)
                        res.push_back(v[j][i]);
                } else {
                    for(int j = m-1; j >= 0; j--)
                        res.push_back(v[j][i]);
                }
            }
            return res;
        }

    3. **Input Validation (Recommended for Robustness):**
        - Check if the matrix is empty before accessing v[0].size().

    Dry Run Example (for the given input):
    --------------------------------------
    Input Matrix:
    1   2   3   4
    5   6   7   8
    9  10  11  12

    Wave Print Output (column-wise):
    Column 0 (even): 1 5 9
    Column 1 (odd):  10 6 2
    Column 2 (even): 3 7 11
    Column 3 (odd):  12 8 4

    But as per the code, the output will be:
    1 5 9 10 6 2 3 7 11 12 8 4

    Step-by-step:
    i=0: 1 5 9
    i=1: 10 6 2
    i=2: 3 7 11
    i=3: 12 8 4

    Final Output: 1 5 9 10 6 2 3 7 11 12 8 4

*/

#include<iostream>
#include<vector>
using namespace std;

// Function to print the matrix in wave form (column-wise)
void wavePrint(const vector<vector<int>>& v) {
    // Check for empty matrix
    if(v.empty() || v[0].empty()) {
        cout << "Empty matrix!" << endl;
        return;
    }

    int m = v.size();      // Number of rows
    int n = v[0].size();   // Number of columns

    // Traverse each column
    for(int i = 0; i < n; i++) {
        // If column index is even, print from top to bottom
        if(i % 2 == 0) {
            for(int j = 0; j < m; j++) {
                cout << v[j][i] << " ";
            }
        }
        // If column index is odd, print from bottom to top
        else {
            for(int j = m - 1; j >= 0; j--) {
                cout << v[j][i] << " ";
            }
        }
    }
    cout << endl;
}

int main() {
    // Example matrix
    vector<vector<int>> v = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // Print the matrix in wave form
    wavePrint(v);

    /*
    Dry Run:
    Matrix:
    1  2  3  4
    5  6  7  8
    9 10 11 12

    Output:
    i=0 (even): 1 5 9
    i=1 (odd):  10 6 2
    i=2 (even): 3 7 11
    i=3 (odd):  12 8 4

    Final Output: 1 5 9 10 6 2 3 7 11 12 8 4
    */
    return 0;
}