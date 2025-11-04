
/*
Approach 1: Flood Fill without using visited map

Flood Fill is a classic DFS/BFS problem where you start from a given cell and "fill" all connected cells of the same color/value with a new color/value. 
Normally, a visited map is used to avoid revisiting cells, but we can avoid it by directly modifying the input grid (since the problem usually allows it).

Below is a sample implementation using DFS, without a visited map:
*/

// Function to perform flood fill
void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int oldColor = image[sr][sc]; // store the original color
    if (oldColor == newColor) return; // if the color is already the new color, nothing to do

    int n = image.size();
    int m = image[0].size();

    // Helper lambda for DFS
    function<void(int,int)> dfs = [&](int x, int y) {
        // Check for out of bounds or different color
        if (x < 0 || y < 0 || x >= n || y >= m || image[x][y] != oldColor)
            return;
        image[x][y] = newColor; // fill the color

        // recursively fill in all 4 directions
        dfs(x+1, y);
        dfs(x-1, y);
        dfs(x, y+1);
        dfs(x, y-1);
    };

    dfs(sr, sc);
}

/*
Better Alternative: BFS approach (iterative, avoids stack overflow for large grids)
*/
// void floodFillBFS(vector<vector<int>>& image, int sr, int sc, int newColor) {
//     int oldColor = image[sr][sc];
//     if (oldColor == newColor) return;
//     int n = image.size(), m = image[0].size();
//     queue<pair<int,int>> q;
//     q.push({sr, sc});
//     image[sr][sc] = newColor;
//     int dx[4] = {0, 0, 1, -1};
//     int dy[4] = {1, -1, 0, 0};
//     while (!q.empty()) {
//         auto [x, y] = q.front(); q.pop();
//         for (int d = 0; d < 4; ++d) {
//             int nx = x + dx[d], ny = y + dy[d];
//             if (nx >= 0 && ny >= 0 && nx < n && ny < m && image[nx][ny] == oldColor) {
//                 image[nx][ny] = newColor;
//                 q.push({nx, ny});
//             }
//         }
//     }
// }

/*
Dry Run:
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Step 1: oldColor = 1
Step 2: Start at (1,1), fill with 2
Step 3: Recursively fill (0,1), (2,1), (1,0), (1,2) if they are 1
Result: image = [[2,2,2],[2,2,0],[2,0,1]]
*/

/*
Approach 2: Rotten Oranges (Leetcode 994) - Handle -1 case without 2 for loops

Normally, after BFS, we use 2 for loops to check if any fresh orange (1) remains. 
Instead, we can maintain a count of fresh oranges and decrement it as we rot them. 
If at the end, fresh count > 0, return -1.

Below is the improved approach:
*/

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0; // count of fresh oranges

    // Initialize queue with all rotten oranges and count fresh oranges
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) q.push({i, j}); // rotten orange
            else if (grid[i][j] == 1) fresh++;   // fresh orange
        }
    }

    int time = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    // BFS to rot adjacent fresh oranges
    while (!q.empty() && fresh > 0) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                // If adjacent cell is fresh orange
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2; // rot it
                    fresh--; // decrement fresh count
                    q.push({nx, ny});
                }
            }
        }
        time++; // increment time after each level
    }

    // If fresh oranges remain, return -1, else return time
    return fresh == 0 ? time : -1;
}

/*
Better Alternative: 
- Use a single queue and count fresh oranges as above (already optimal).
- If you want to avoid even the initial 2 for loops, you can preprocess the grid as you read it (if input is streamed).

Dry Run:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Step 1: fresh = 6, queue = all rotten oranges
Step 2: BFS, rot adjacent fresh, decrement fresh
Step 3: After 4 rounds, fresh = 0, return 4

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Step 1: fresh = 5, queue = all rotten oranges
Step 2: BFS, some oranges can't be rotted, fresh > 0, return -1
*/
