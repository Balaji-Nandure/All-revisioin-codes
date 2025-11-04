// https://leetcode.com/problems/flood-fill/description/

/*
Approach:
- We use Depth First Search (DFS) to traverse the image grid starting from (sr, sc).
- For each cell, if it matches the original color, we change it to the new color and recursively process its 4 neighbors (up, right, down, left).
- We use a visited map to avoid revisiting the same cell.
- The function returns the modified image.

Better alternatives:
1. Use a vector<vector<bool>> for visited instead of map<pair<int,int>,bool> for better performance and less memory overhead.
2. Since we only need to check if a cell is already colored with the new color, we can avoid the visited structure entirely by checking the color directly.
3. BFS (queue-based) can also be used for iterative solution, which avoids stack overflow for large images.

Alternative code (without visited map, using only color check):
---------------------------------------------------------------
/*
void dfs(int x, int y, int oldColor, int newColor, vector<vector<int>>& ans) {
    if (x < 0 || x >= ans.size() || y < 0 || y >= ans[0].size()) return;
    if (ans[x][y] != oldColor || ans[x][y] == newColor) return;
    ans[x][y] = newColor;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        dfs(x + dx[i], y + dy[i], oldColor, newColor, ans);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int oldColor = image[sr][sc];
    if (oldColor == color) return image;
    vector<vector<int>> ans = image;
    dfs(sr, sc, oldColor, color, ans);
    return ans;
}
*/

class Solution {
public:
    // Helper function to perform DFS and fill the region
    void dfs(int x, int y, int oldColor, int newColor, map<pair<int,int>,bool>& visited, vector<vector<int>>& ans) {
        // Mark current cell as visited
        visited[{x, y}] = true;
        // Change the color of the current cell
        ans[x][y] = newColor;
        // Arrays to move in 4 directions: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        // Explore all 4 neighbors
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            // Check if new cell is within bounds, not visited, and has the old color
            if (newX >= 0 && newX < ans.size() && newY >= 0 && newY < ans[0].size() &&
                !visited[{newX, newY}] && ans[newX][newY] == oldColor) {
                dfs(newX, newY, oldColor, newColor, visited, ans);
            }
        }
    }

    // Main function to start flood fill
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc]; // Store the original color at starting cell
        map<pair<int,int>,bool> visited; // To keep track of visited cells
        vector<vector<int>> ans = image; // Copy of the original image to modify
        // If the old color is already the new color, no need to proceed
        if (oldColor == color) return ans;
        // Start DFS from the starting cell
        dfs(sr, sc, oldColor, color, visited, ans);
        return ans; // Return the modified image
    }
};

/*
Dry Run Example:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

Step 1: oldColor = 1, newColor = 2
Step 2: Start DFS at (1,1)
    - Change (1,1) to 2
    - Visit (0,1): change to 2
        - Visit (0,0): change to 2
            - Visit (1,0): change to 2
                - Visit (2,0): change to 2
    - Visit (1,0): already visited
    - Visit (1,2): color is 0, skip
    - Visit (2,1): color is 0, skip
Final Output:
[[2,2,2],
 [2,2,0],
 [2,0,1]]
*/

/*
Summary of improvements:
- Added comments for all important lines.
- Provided a better alternative approach (without visited map).
- Added a dry run for clarity.
- Added early return if oldColor == newColor to avoid unnecessary work.
*/