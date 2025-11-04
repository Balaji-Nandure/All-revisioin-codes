// https://leetcode.com/problems/critical-connections-in-a-network/description/

/*
Approach Used:
---------------
This code uses Tarjan's Algorithm to find all the critical connections (bridges) in an undirected graph.
A bridge is an edge whose removal increases the number of connected components in the graph.

Key Concepts:
- tin[]: Time of insertion (discovery time) for each node during DFS.
- low[]: The lowest discovery time reachable from the subtree rooted at that node (including back edges).
- If for an edge u-v, low[v] > tin[u], then u-v is a bridge.

Better Alternatives:
--------------------
- Use vector<vector<int>> for adjacency list instead of unordered_map<int, list<int>> for better cache locality and performance.
- Use vector<bool> for visited instead of unordered_map<int, bool> for O(1) access and less memory.
- Use a class member variable for timer to avoid passing by reference.
- Return bridges in sorted order (optional, for deterministic output).
- Handle disconnected graphs by running DFS from all unvisited nodes.

Alternative Efficient Implementation (in comments at the end).

Dry Run Example:
----------------
Suppose n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Graph:
    0
   / \
  1---2
  |
  3

DFS order: 0->1->2, back edge from 2->0, then 1->3
tin: [1,2,3,4]
low: [1,1,1,4]
Edge 1-3 is a bridge because low[3] > tin[1].

*/

class Solution {
public:
    // Helper function to perform DFS and find bridges
    void findBridges(
        int src,                // current node
        int parent,             // parent node in DFS tree
        int &timer,             // global timer for discovery time
        vector<int>& tin,       // discovery time of each node
        vector<int>& low,       // lowest discovery time reachable
        unordered_map<int, bool>& visited, // visited array
        vector<vector<int>>& ans,          // stores bridges
        unordered_map<int, list<int>>& adjList // adjacency list
    ) {
        timer++;                // increment timer for discovery time
        visited[src] = true;    // mark current node as visited
        tin[src] = timer;       // set discovery time
        low[src] = timer;       // initialize low time to discovery time

        // Traverse all adjacent nodes
        for (auto nbr : adjList[src]) {
            // If neighbor is parent, skip to avoid trivial cycle
            if (nbr == parent)
                continue;

            if (!visited[nbr]) {
                // If neighbor is not visited, do DFS
                findBridges(nbr, src, timer, tin, low, visited, ans, adjList);

                // After returning, update low time for src
                low[src] = min(low[src], low[nbr]);

                // If the lowest reachable time from nbr is greater than discovery time of src,
                // then edge src-nbr is a bridge
                if (low[nbr] > tin[src]) {
                    // Store the bridge (smaller node first for consistency)
                    if (src < nbr)
                        ans.push_back({src, nbr});
                    else
                        ans.push_back({nbr, src});
                }
            } else {
                // If neighbor is already visited and not parent, it's a back edge
                // Update low time for src
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build adjacency list
        unordered_map<int, list<int>> adjList;
        for (const auto& edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<vector<int>> ans;        // To store bridges
        int timer = 0;                  // Global timer for DFS
        vector<int> tin(n, -1);         // Discovery time for each node
        vector<int> low(n, -1);         // Lowest discovery time reachable
        unordered_map<int, bool> visited; // Visited array

        // Handle disconnected graphs by running DFS from all unvisited nodes
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                findBridges(i, -1, timer, tin, low, visited, ans, adjList);
            }
        }

        // Optional: sort the bridges for deterministic output
        for (auto& bridge : ans) {
            if (bridge[0] > bridge[1]) swap(bridge[0], bridge[1]);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};

/*
Alternative Efficient Implementation (using vector instead of unordered_map):

class Solution {
    int timer;
    void dfs(int u, int parent, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges, vector<bool>& vis) {
        vis[u] = true;
        tin[u] = low[u] = ++timer;
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!vis[v]) {
                dfs(v, u, adj, tin, low, bridges, vis);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) bridges.push_back({u, v});
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& e : connections) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<vector<int>> bridges;
        vector<int> tin(n, -1), low(n, -1);
        vector<bool> vis(n, false);
        timer = 0;
        for (int i = 0; i < n; ++i)
            if (!vis[i]) dfs(i, -1, adj, tin, low, bridges, vis);
        return bridges;
    }
};

*/

/*
Dry Run Example:
----------------
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]

Adjacency List:
0: 1,2
1: 0,2,3
2: 1,0
3: 1

DFS Traversal:
- Start at 0: tin[0]=1, low[0]=1
- Visit 1: tin[1]=2, low[1]=2
- Visit 2: tin[2]=3, low[2]=3
- 2 has neighbor 0 (already visited, not parent), update low[2]=min(3,1)=1
- Back to 1: low[1]=min(2,1)=1
- Visit 3: tin[3]=4, low[3]=4
- 3 has neighbor 1 (parent), skip
- Back to 1: low[1]=min(1,4)=1
- Since low[3] > tin[1], edge 1-3 is a bridge

Output: [[1,3]]
*/