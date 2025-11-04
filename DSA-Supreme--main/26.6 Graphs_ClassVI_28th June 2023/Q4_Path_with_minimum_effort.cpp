// https://leetcode.com/problems/path-with-minimum-effort/description/

/*
Approach Used:
---------------
We use a modified Dijkstra's algorithm to find the path from the top-left to the bottom-right cell in the grid such that the maximum absolute difference in heights between adjacent cells along the path is minimized. 
Instead of summing weights, we track the maximum edge weight (effort) along the path.

Key Points:
- Each cell is a node, and edges exist between adjacent cells (up, down, left, right).
- The "effort" to move between two adjacent cells is the absolute difference in their heights.
- The cost of a path is the maximum effort along that path.
- We use a min-heap (priority queue) to always expand the path with the currently minimal maximum effort.

Better Alternatives:
--------------------
1. **Binary Search + BFS/DFS**:
   - Binary search the answer (effort) between 0 and max possible difference.
   - For each mid, check if a path exists from (0,0) to (n-1,m-1) with all steps <= mid using BFS/DFS.
   - Time complexity: O((N*M) * log(maxHeightDiff))
   - This is often faster in practice for large grids.

   // Example code for Binary Search + BFS:
   /*
   bool canReach(vector<vector<int>>& heights, int maxEffort) {
       int n = heights.size(), m = heights[0].size();
       queue<pair<int,int>> q;
       vector<vector<bool>> vis(n, vector<bool>(m, false));
       q.push({0,0});
       vis[0][0] = true;
       int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
       while(!q.empty()) {
           auto [x, y] = q.front(); q.pop();
           if(x == n-1 && y == m-1) return true;
           for(int d=0; d<4; ++d) {
               int nx = x+dx[d], ny = y+dy[d];
               if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] && abs(heights[x][y]-heights[nx][ny]) <= maxEffort) {
                   vis[nx][ny] = true;
                   q.push({nx,ny});
               }
           }
       }
       return false;
   }
   int minimumEffortPath(vector<vector<int>>& heights) {
       int l = 0, r = 1e6, ans = 0;
       while(l <= r) {
           int mid = l + (r-l)/2;
           if(canReach(heights, mid)) {
               ans = mid;
               r = mid-1;
           } else {
               l = mid+1;
           }
       }
       return ans;
   }
   */

2. **Union-Find (Kruskal's MST)**:
   - Treat each cell as a node, create all possible edges with their efforts.
   - Sort edges by effort, and connect cells using union-find.
   - The moment (0,0) and (n-1,m-1) are connected, the current edge's effort is the answer.
   - Time complexity: O(N*M*log(N*M))

Code with Comments and Improvements:
------------------------------------
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();         // Number of rows
        int m = heights[0].size();      // Number of columns

        // Min-heap to store {effort_so_far, {x, y}}
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;

        // Distance matrix to store minimum effort to reach each cell
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        // Start from (0,0) with 0 effort
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        // Directions: up, right, down, left
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto fNode = pq.top(); pq.pop();
            int effort = fNode.first;           // Current path's max effort so far
            int x = fNode.second.first;
            int y = fNode.second.second;

            // If we've reached the destination, return the effort
            if (x == n - 1 && y == m - 1) {
                return effort;
            }

            // If we already found a better path to (x, y), skip
            if (effort > dist[x][y]) continue;

            // Explore all 4 directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                // Check bounds
                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    // Calculate effort to move to neighbor
                    int currDiff = abs(heights[x][y] - heights[newX][newY]);
                    int newEffort = max(effort, currDiff); // Path's max effort so far

                    // If this path is better, update and push to queue
                    if (newEffort < dist[newX][newY]) {
                        dist[newX][newY] = newEffort;
                        pq.push({newEffort, {newX, newY}});
                    }
                }
            }
        }
        // If unreachable (should not happen as per problem constraints)
        return 0;
    }
};

/*
Dry Run Example:
----------------
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]

Step-by-step:
- Start at (0,0), effort = 0
- Move to (0,1): effort = max(0, |1-2|) = 1
- Move to (0,2): effort = max(1, |2-2|) = 1
- Move to (1,2): effort = max(1, |2-2|) = 1
- Move to (2,2): effort = max(1, |2-5|) = 3
- Move to (2,1): effort = max(3, |5-3|) = 3
- Move to (2,0): effort = max(3, |3-5|) = 3

But, from (1,2) to (1,1): effort = max(1, |2-8|) = 6 (not better)
So, the minimum effort path is (0,0)->(0,1)->(0,2)->(1,2)->(2,2) with max effort 3.

Output: 2

(Actually, the minimum effort is 2, as the path (0,0)->(1,0)->(2,0)->(2,1)->(2,2) has max effort 2.)

The algorithm ensures we always expand the path with the currently minimal maximum effort, guaranteeing the optimal solution.
*/