// https://leetcode.com/problems/number-of-provinces/description/

/*
Approach Used:
---------------
- The problem is to find the number of provinces (connected components) in an undirected graph represented by an adjacency matrix.
- We use Depth First Search (DFS) to traverse all nodes in a province, marking them as visited.
- For each unvisited node, we start a DFS, and increment the province count.

Betterments:
------------
- Use vector<bool> instead of unordered_map<int,bool> for visited for better cache locality and O(1) access.
- Add detailed comments for each important line.
- Provide alternative approaches (BFS, Union-Find) in comments.
- Add a dry run at the end.

*/

class Solution {
public:
    // Helper function to perform DFS traversal from a given node
    void dfs(vector<bool>& visited, int src, const vector<vector<int>>& isConnected) {
        visited[src] = true; // Mark current node as visited

        int n = isConnected.size(); // Number of nodes

        // Traverse all possible neighbours
        for (int col = 0; col < n; col++) {
            // If there is an edge and neighbour is not visited
            if (isConnected[src][col] == 1 && !visited[col]) {
                dfs(visited, col, isConnected); // Recursively visit neighbour
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of nodes (cities)
        vector<bool> visited(n, false); // Visited array to keep track of visited nodes
        int count = 0; // To count number of provinces

        // Iterate through all nodes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // If node is not visited, it's a new province
                dfs(visited, i, isConnected); // Visit all nodes in this province
                count++; // Increment province count
            }
        }
        return count; // Return total number of provinces
    }
};

/*
Alternative Approaches:
-----------------------

1. BFS Approach:
----------------
Instead of DFS, we can use BFS to traverse each component.

void bfs(vector<bool>& visited, int src, const vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int col = 0; col < n; col++) {
            if (isConnected[node][col] == 1 && !visited[col]) {
                visited[col] = true;
                q.push(col);
            }
        }
    }
}

2. Union-Find (Disjoint Set Union) Approach:
--------------------------------------------
- Each city is a node. Initially, each node is its own parent.
- For every edge (i, j), union their sets.
- The number of unique parents at the end is the number of provinces.

class DSU {
    vector<int> parent;
public:
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isConnected[i][j] == 1) dsu.unite(i, j);
        }
    }
    unordered_set<int> provinces;
    for (int i = 0; i < n; i++) provinces.insert(dsu.find(i));
    return provinces.size();
}

Time Complexity:
----------------
- DFS/BFS: O(N^2), where N is the number of cities (since we check all pairs).
- Union-Find: O(N^2 * α(N)), where α is the inverse Ackermann function (almost constant).

Dry Run Example:
----------------
Input:
isConnected = [
  [1,1,0],
  [1,1,0],
  [0,0,1]
]

Step-by-step:
- visited = [false, false, false], count = 0
- i=0: not visited, start DFS from 0
    - visited[0]=true, check neighbours: 1 is connected and not visited
        - DFS(1): visited[1]=true, check neighbours: 0 is connected (already visited), 1 is self, 2 is not connected
    - DFS for 0 done
- count = 1
- i=1: already visited
- i=2: not visited, start DFS from 2
    - visited[2]=true, check neighbours: none connected
- count = 2

Output: 2

*/