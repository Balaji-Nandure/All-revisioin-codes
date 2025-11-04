// https://leetcode.com/problems/rotting-oranges/description/

/*
Approach Used:
---------------
- This problem is solved using **Multi-Source Breadth First Search (BFS)**.
- All initially rotten oranges (value 2) are enqueued with time 0.
- For each rotten orange, we try to rot its adjacent fresh oranges (value 1) in 4 directions.
- Each time a fresh orange is rotted, it is enqueued with incremented time.
- The process continues until no more oranges can be rotted.
- At the end, if any fresh orange remains, return -1. Otherwise, return the maximum time taken.

Why BFS?
---------
- BFS is ideal here because all rotten oranges rot their neighbors simultaneously in each minute (level-wise spread).
- Multi-source BFS allows us to start from all rotten oranges at once.

Better Alternatives:
--------------------
- The code can be optimized by:
    1. Using a single grid (no need to copy to 'ans').
    2. Counting fresh oranges at the start, and decrementing as we rot them, to avoid a final grid scan.
    3. Using a struct or tuple for queue elements for clarity.
    4. Using a queue of tuples (x, y, time) for better readability.

Alternative code (with fresh count optimization):
-------------------------------------------------
/*
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<tuple<int,int,int>> q;
    int fresh = 0, time = 0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(grid[i][j]==2) q.emplace(i,j,0);
            else if(grid[i][j]==1) fresh++;
    int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
    while(!q.empty()) {
        auto [x,y,t] = q.front(); q.pop();
        time = max(time, t);
        for(int d=0;d<4;d++) {
            int nx = x+dx[d], ny = y+dy[d];
            if(nx>=0 && nx<rows && ny>=0 && ny<cols && grid[nx][ny]==1) {
                grid[nx][ny]=2; fresh--;
                q.emplace(nx,ny,t+1);
            }
        }
    }
    return fresh==0 ? time : -1;
}
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // Queue to store coordinates and time: ((row, col), time)
        queue<pair<pair<int,int>,int>> q;
        // Copy of grid to mark rotting progress
        vector<vector<int>> ans = grid;
        int ansTime = 0; // To keep track of the maximum time taken

        // Step 1: Enqueue all initially rotten oranges with time 0
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[row].size(); col++) {
                if(grid[row][col] == 2) { // Rotten orange found
                    // Push its coordinates and time 0 into the queue
                    q.push({{row, col}, 0});
                }
            }
        }

        // Step 2: BFS to rot adjacent fresh oranges
        while(!q.empty()) {
            auto fNode = q.front(); // Get the front node from queue
            q.pop();
            int x = fNode.first.first;   // Row index
            int y = fNode.first.second;  // Column index
            int time = fNode.second;     // Time at which this orange rotted

            // Directions: up, right, down, left
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            // Check all 4 directions
            for(int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                // If new cell is within bounds and is a fresh orange
                if(newX >= 0 && newX < ans.size() && newY >= 0 && newY < ans[0].size() && ans[newX][newY] == 1) {
                    // Rot the fresh orange
                    ans[newX][newY] = 2;
                    // Update the time taken to rot this orange
                    ansTime = max(ansTime, time + 1);
                    // Push the new rotten orange into the queue with incremented time
                    q.push({{newX, newY}, time + 1});
                }
            }
        }

        // Step 3: Check if any fresh orange remains
        for(int i = 0; i < ans.size(); i++) {
            for(int j = 0; j < ans[i].size(); j++) {
                if(ans[i][j] == 1) { // Fresh orange found
                    return -1; // Impossible to rot all oranges
                }
            }
        }
        // Return the total time taken to rot all oranges
        return ansTime;
    }
};

/*
Dry Run Example:
----------------
Input:
grid = [
  [2,1,1],
  [1,1,0],
  [0,1,1]
]

Step 1: Enqueue all rotten oranges:
- (0,0) is rotten, enqueue ((0,0),0)

Step 2: BFS
Minute 0: (0,0) rots (0,1) and (1,0)
- Enqueue ((0,1),1), ((1,0),1)
Minute 1: (0,1) rots (0,2), (1,0) rots (1,1)
- Enqueue ((0,2),2), ((1,1),2)
Minute 2: (0,2) rots nothing, (1,1) rots (2,1)
- Enqueue ((2,1),3)
Minute 3: (2,1) rots (2,2)
- Enqueue ((2,2),4)
Minute 4: (2,2) rots nothing

All oranges are rotten at minute 4. Return 4.

If any fresh orange remains, return -1.
*/