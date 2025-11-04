// https://leetcode.com/problems/spiral-matrix/

/*
Approach Used:
---------------
We use four boundaries (startingRow, endingRow, startingCol, endingCol) to keep track of the current layer of the matrix that we are traversing in spiral order. 
We traverse the matrix in four directions: left to right (top row), top to bottom (right column), right to left (bottom row), and bottom to top (left column).
After traversing each direction, we move the corresponding boundary inward. We continue this process until all elements are traversed.

Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
Space Complexity: O(1) extra (excluding the output vector).

Better Alternatives:
--------------------
1. **Layer by Layer Approach**: Instead of using a count variable, we can use the boundaries directly and check if startingRow <= endingRow and startingCol <= endingCol.
2. **Visited Matrix**: For non-rectangular matrices, we can use a visited matrix to avoid revisiting elements, but for rectangular matrices, the boundary approach is optimal.
3. **Direction Array**: We can use direction arrays to generalize the movement, but for spiral order, explicit loops are more readable.

Alternative Code (Layer by Layer, without count):
-------------------------------------------------
/*
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size(), n = matrix[0].size();
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) ans.push_back(matrix[top][i]);
        ++top;
        for (int i = top; i <= bottom; ++i) ans.push_back(matrix[i][right]);
        --right;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) ans.push_back(matrix[bottom][i]);
            --bottom;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) ans.push_back(matrix[i][left]);
            ++left;
        }
    }
    return ans;
}
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // To store the spiral order traversal
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        int totalElements = m * n; // Total elements to traverse

        // Define the boundaries of the current layer
        int startingRow = 0; // Top boundary
        int endingRow = m - 1; // Bottom boundary
        int startingCol = 0; // Left boundary
        int endingCol = n - 1; // Right boundary

        int count = 0; // To keep track of how many elements have been added to ans

        // Loop until all elements are traversed
        while (count < totalElements) {
            // 1. Traverse from left to right on the topmost row
            for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++; // Move the top boundary down

            // 2. Traverse from top to bottom on the rightmost column
            for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--; // Move the right boundary left

            // 3. Traverse from right to left on the bottommost row
            for (int i = endingCol; i >= startingCol && count < totalElements; i--) {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--; // Move the bottom boundary up

            // 4. Traverse from bottom to top on the leftmost column
            for (int i = endingRow; i >= startingRow && count < totalElements; i--) {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++; // Move the left boundary right
        }
        return ans;
    }
};

/*
Dry Run Example:
----------------
Input:
matrix = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
]

Step-by-step:
- startingRow=0, endingRow=2, startingCol=0, endingCol=2, count=0
1. Top row: 1 2 3 (count=3)
2. Right col: 6 9 (count=5)
3. Bottom row: 8 7 (count=7)
4. Left col: 4 (count=8)
5. Next layer: Top row: 5 (count=9)
Done.

Output: [1,2,3,6,9,8,7,4,5]
*/