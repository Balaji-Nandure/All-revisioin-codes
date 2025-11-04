// https://leetcode.com/problems/number-of-islands/description/

/*
Approach Used:
---------------
We use Breadth-First Search (BFS) to traverse the grid. Each time we find an unvisited land cell ('1'), we start a BFS from that cell, marking all connected land cells as visited. Each BFS traversal corresponds to one island, so we increment our island count. 

Key Points:
- We use a 2D vector<bool> for visited to optimize space and access time (instead of map).
- We traverse the grid, and for each unvisited '1', we perform BFS to mark the entire island.
- BFS explores all 4 directions (up, right, down, left) from each cell.

Better Alternatives:
--------------------
1. **DFS Approach**: Use recursion to mark all connected land cells.
2. **Union-Find (Disjoint Set Union)**: Treat each cell as a node and union adjacent lands, then count unique parents.
3. **In-place Marking**: Instead of a visited array, mark visited cells in the grid itself (e.g., change '1' to '0').

Below is the improved code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    // Helper function to perform BFS and mark all connected land cells as visited
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        int m = grid.size();        // number of rows
        int n = grid[0].size();     // number of columns
        queue<pair<int, int>> q;    // queue for BFS

        q.push({row, col});         // start BFS from the current cell
        visited[row][col] = true;   // mark the starting cell as visited

        // Directions: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Explore all 4 directions
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                // Check if new cell is within bounds, is land, and not visited
                if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
                    !visited[newX][newY] && grid[newX][newY] == '1') {
                    q.push({newX, newY});         // add cell to queue for BFS
                    visited[newX][newY] = true;   // mark as visited
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0; // edge case: empty grid

        int m = grid.size();
        int n = grid[0].size();
        int count = 0; // to count number of islands

        // 2D visited array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Traverse each cell in the grid
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                // If cell is land and not visited, it's a new island
                if (!visited[row][col] && grid[row][col] == '1') {
                    bfs(grid, visited, row, col); // mark all connected land
                    count++;                      // increment island count
                }
            }
        }
        return count; // return total number of islands
    }
};

/*
Alternative Approach 1: DFS (Recursive)
---------------------------------------
void dfs(vector<vector<char>>& grid, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1')
        return;
    grid[row][col] = '0'; // mark as visited
    dfs(grid, row-1, col);
    dfs(grid, row+1, col);
    dfs(grid, row, col-1);
    dfs(grid, row, col+1);
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++;
            }
    return count;
}

Alternative Approach 2: Union-Find (Disjoint Set)
-------------------------------------------------
(See Leetcode solutions for full implementation. This is more efficient for large grids.)

Dry Run Example:
----------------
Input:
grid = [
  ['1','1','0','0','0'],
  ['1','1','0','0','0'],
  ['0','0','1','0','0'],
  ['0','0','0','1','1']
]

Step-by-step:
- Start at (0,0): '1' and not visited -> BFS marks (0,0),(0,1),(1,0),(1,1) as visited. count = 1
- Next unvisited '1' at (2,2): BFS marks (2,2) as visited. count = 2
- Next unvisited '1' at (3,3): BFS marks (3,3),(3,4) as visited. count = 3
- All other cells are '0' or already visited.

Output: 3 islands

Time Complexity: O(m*n)
Space Complexity: O(m*n) for visited array (can be optimized by marking grid in-place)
*/