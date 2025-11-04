// https://leetcode.com/problems/course-schedule/description/

/*
Approach Used:
---------------
- The problem is to determine if all courses can be finished given a list of prerequisite pairs.
- This is equivalent to checking if the directed graph formed by prerequisites is a Directed Acyclic Graph (DAG).
- We use **Kahn's Algorithm (BFS-based Topological Sort)** to detect cycles:
    - If a valid topological ordering exists (i.e., we can process all nodes), there is no cycle, and all courses can be finished.
    - If not all nodes are processed, a cycle exists, and it's impossible to finish all courses.

Key Steps:
----------
1. Build the adjacency list for the graph.
2. Compute the indegree (number of incoming edges) for each node.
3. Initialize a queue with all nodes having indegree 0 (no prerequisites).
4. Process nodes from the queue:
    - For each node, reduce the indegree of its neighbors.
    - If any neighbor's indegree becomes 0, add it to the queue.
5. If all nodes are processed, return true; else, return false.

Better Alternatives:
--------------------
1. **DFS Cycle Detection**:
    - Use DFS to detect cycles directly by marking nodes as 'visiting' and 'visited'.
    - If a node is revisited while 'visiting', a cycle exists.
    - See code below.

2. **Adjacency List Optimization**:
    - Use vector<vector<int>> instead of unordered_map for better cache locality if course numbers are 0..n-1.

3. **Space Optimization**:
    - Use vector<int> for indegree instead of unordered_map for O(1) access.

Alternative DFS-based Cycle Detection Code:
-------------------------------------------
/*
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& state) {
        state[node] = 1; // visiting
        for(int nbr : adj[node]) {
            if(state[nbr] == 1) return true; // cycle found
            if(state[nbr] == 0 && dfs(nbr, adj, state)) return true;
        }
        state[node] = 2; // visited
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> state(numCourses, 0); // 0=unvisited, 1=visiting, 2=visited
        for(int i=0; i<numCourses; ++i)
            if(state[i]==0 && dfs(i, adj, state)) return false;
        return true;
    }
};
*/

class Solution {
private:
    // Kahn's Algorithm for Topological Sort (BFS)
    bool topoSort(int n, unordered_map<int, list<int>>& adjList) {
        vector<int> result; // Stores the topological order
        queue<int> q; // Queue for BFS
        vector<int> indegree(n, 0); // Indegree of each node (using vector for O(1) access)

        // Calculate indegree for each node
        for (auto& [src, neighbors] : adjList) { // For each node and its neighbors
            for (int nbr : neighbors) {
                indegree[nbr]++; // Increment indegree for each neighbor
            }
        }

        // Push all nodes with indegree 0 (no prerequisites) into the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS: Process nodes with indegree 0
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            result.push_back(frontNode); // Add node to topological order

            // For all neighbors, reduce indegree (as frontNode is now processed)
            for (int nbr : adjList[frontNode]) {
                indegree[nbr]--;
                // If indegree becomes 0, add to queue
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If all nodes are processed, topological sort is valid (no cycle)
        return (result.size() == n);
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list: edge from v -> u means u depends on v
        unordered_map<int, list<int>> adjList;
        for (auto& task : prerequisites) {
            int u = task[0]; // course to take
            int v = task[1]; // prerequisite
            adjList[v].push_back(u); // v -> u
        }
        // Run Kahn's algorithm to check for cycle
        return topoSort(numCourses, adjList);
    }
};

/*
Dry Run Example:
----------------
Input: numCourses = 4, prerequisites = [[1,0],[2,1],[3,2]]
Graph: 0 -> 1 -> 2 -> 3

Step 1: Build adjList:
    0: [1]
    1: [2]
    2: [3]

Step 2: Compute indegree:
    indegree[1] = 1 (from 0)
    indegree[2] = 1 (from 1)
    indegree[3] = 1 (from 2)
    indegree[0] = 0

Step 3: Queue initialized with [0]

Step 4: Process queue:
    Pop 0: result = [0], indegree[1] = 0 -> push 1
    Pop 1: result = [0,1], indegree[2] = 0 -> push 2
    Pop 2: result = [0,1,2], indegree[3] = 0 -> push 3
    Pop 3: result = [0,1,2,3]

Step 5: result.size() == numCourses (4), so return true.

If there was a cycle (e.g., prerequisites = [[1,0],[0,1]]), result.size() < numCourses, so return false.
*/