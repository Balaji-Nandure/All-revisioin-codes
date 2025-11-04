/*
Approach:
-----------
This code demonstrates how to check if a given undirected graph is bipartite using BFS (Breadth First Search).
A bipartite graph is a graph whose vertices can be divided into two disjoint sets such that every edge connects a vertex from one set to another.

Logic:
-------
- We use BFS to traverse the graph and try to color the graph using two colors (0 and 1).
- If we find a neighbor with the same color as the current node, the graph is not bipartite.

Better Alternatives:
---------------------
- DFS can also be used for bipartite checking.
- For disconnected graphs, we need to check each component.

Code:
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if the graph is bipartite using BFS
bool isBipartite(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1); // -1 means uncolored

    // Traverse all components (for disconnected graphs)
    for (int start = 0; start < n; ++start) {
        if (color[start] == -1) { // If not colored yet
            queue<int> q;
            q.push(start);
            color[start] = 0; // Assign first color

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                // Traverse all adjacent nodes
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        // Assign alternate color to neighbor
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        // If neighbor has same color, not bipartite
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

/*
Alternative Approach (DFS):
---------------------------
bool dfs(int node, int c, vector<int>& color, vector<vector<int>>& adj) {
    color[node] = c;
    for (int neighbor : adj[node]) {
        if (color[neighbor] == -1) {
            if (!dfs(neighbor, 1-c, color, adj)) return false;
        } else if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}
bool isBipartiteDFS(vector<vector<int>>& adj, int n) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!dfs(i, 0, color, adj)) return false;
        }
    }
    return true;
}
*/

// Example usage
int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> adj(n);
    // Example graph: 0-1, 1-2, 2-3, 3-0 (Even cycle, bipartite)
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(adj, n)) {
        cout << "Graph is Bipartite" << endl;
    } else {
        cout << "Graph is NOT Bipartite" << endl;
    }
    return 0;
}

/*
Dry Run:
---------
Graph: 0-1-2-3-0 (Even cycle)
- Start BFS from node 0, color 0.
- Node 0: color 0, neighbors 1 and 3.
    - Color 1 as 1, color 3 as 1.
- Node 1: color 1, neighbors 0 and 2.
    - 0 already colored with 0 (ok), color 2 as 0.
- Node 3: color 1, neighbors 2 and 0.
    - 2 already colored with 0 (ok), 0 already colored with 0 (ok).
- Node 2: color 0, neighbors 1 and 3.
    - Both already colored with 1 (ok).
No conflicts found, so graph is bipartite.

Time Complexity: O(V + E)
Space Complexity: O(V)
*/
