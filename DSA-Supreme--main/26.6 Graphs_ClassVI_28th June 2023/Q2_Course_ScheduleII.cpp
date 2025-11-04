// https://leetcode.com/problems/course-schedule-ii/description/

/*
Approach Used:
---------------
This code solves the Course Schedule II problem using **Kahn's Algorithm** (BFS-based Topological Sort).
- The idea is to build a directed graph from prerequisites, compute the indegree of each node (course), and process nodes with indegree 0.
- As we process nodes, we decrement the indegree of their neighbors. If a neighbor's indegree becomes 0, we add it to the queue.
- If we can process all nodes, a valid order exists; otherwise, a cycle exists and we return an empty array.

Key Points:
- Graph is represented as an adjacency list.
- Indegree array keeps track of prerequisites for each course.
- BFS ensures we always process courses whose prerequisites are already satisfied.

Alternative Approaches:
-----------------------
1. **DFS-based Topological Sort**:
   - Use DFS to detect cycles and build the order in postorder.
   - More code, but can be more memory efficient if the graph is sparse.
   - See commented code at the end for DFS approach.

2. **Using vector instead of unordered_map for indegree and adjList**:
   - If course numbers are 0 to n-1, using vector is more efficient.

3. **Cycle Detection**:
   - Both Kahn's and DFS approaches can detect cycles (if not all nodes are processed, or if a back edge is found).

Dry Run Example:
----------------
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Graph: 0 -> 1, 0 -> 2, 1 -> 3, 2 -> 3
Indegree: [0,1,1,2]
Queue: [0]
Order: [0,1,2,3] or [0,2,1,3] (both valid)

*/

class Solution {
public:
    // Helper function to perform Kahn's Algorithm (BFS Topological Sort)
    void topoSort(int n, unordered_map<int, list<int>>& adjList, vector<int>& ans) {
        queue<int> q; // Queue for BFS
        vector<int> indegree(n, 0); // Indegree array for all nodes, initialized to 0

        // Build indegree array
        for (auto& pair : adjList) { // For each node in the adjacency list
            int src = pair.first;
            for (int nbr : pair.second) { // For each neighbor
                indegree[nbr]++; // Increment indegree of neighbor
            }
        }

        // Push all nodes with indegree 0 into the queue (no prerequisites)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS traversal
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode); // Add node to result (order)

            // For all neighbors, reduce indegree by 1
            for (int nbr : adjList[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) { // If indegree becomes 0, add to queue
                    q.push(nbr);
                }
            }
        }

        // If not all nodes are processed, there is a cycle; return empty array
        if (ans.size() != n)
            ans.clear();
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans; // To store the topological order
        unordered_map<int, list<int>> adjList; // Adjacency list

        // Build the adjacency list from prerequisites
        // For each prerequisite pair [u, v], add edge v -> u (v must be done before u)
        for (auto& task : prerequisites) {
            int u = task[0];
            int v = task[1];
            adjList[v].push_back(u);
        }

        // Call the topological sort helper
        topoSort(numCourses, adjList, ans);

        return ans; // Return the order (or empty if not possible)
    }
};

/*
-------------------------------
Alternative: DFS-based Approach
-------------------------------
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ans) {
        visited[node] = 1; // Mark as visiting
        for (int nbr : adj[node]) {
            if (visited[nbr] == 1) return false; // Cycle detected
            if (visited[nbr] == 0) {
                if (!dfs(nbr, adj, visited, ans)) return false;
            }
        }
        visited[node] = 2; // Mark as visited
        ans.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> visited(numCourses, 0), ans;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, adj, visited, ans)) return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
*/

/*
-------------------------------
Dry Run Example
-------------------------------
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Adjacency List:
0: [1,2]
1: [3]
2: [3]
Indegree: [0,1,1,2]
Queue: [0]
Process 0: ans = [0], queue = [1,2]
Process 1: ans = [0,1], queue = [2,3]
Process 2: ans = [0,1,2], queue = [3]
Process 3: ans = [0,1,2,3], queue = []
All nodes processed, return [0,1,2,3] (or [0,2,1,3])
*/