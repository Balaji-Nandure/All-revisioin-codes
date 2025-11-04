/*
Approach:
This code demonstrates two popular algorithms to find Strongly Connected Components (SCCs) in a directed graph:
1. Kosaraju's Algorithm (uses two DFS traversals and graph reversal)
2. Tarjan's Algorithm (uses a single DFS traversal with low-link values)

Below are the implementations with detailed comments explaining the logic behind each important line.
Alternative approaches and dry run are also provided at the end.

-------------------------------
Kosaraju's Algorithm
-------------------------------
1. Do a DFS traversal and push nodes onto a stack in the order of their finishing times.
2. Reverse the graph.
3. Pop nodes from the stack and do DFS on the reversed graph to get SCCs.

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS and fill stack with vertices by finish time
void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true; // Mark node as visited
    for (int nbr : adj[node]) {
        if (!visited[nbr]) {
            dfs1(nbr, adj, visited, st); // Visit all unvisited neighbors
        }
    }
    st.push(node); // Push node to stack after visiting all neighbors
}

// Function to perform DFS on reversed graph and collect SCC
void dfs2(int node, vector<vector<int>>& revAdj, vector<bool>& visited, vector<int>& component) {
    visited[node] = true; // Mark node as visited
    component.push_back(node); // Add node to current SCC
    for (int nbr : revAdj[node]) {
        if (!visited[nbr]) {
            dfs2(nbr, revAdj, visited, component); // Visit all unvisited neighbors
        }
    }
}

// Kosaraju's main function
vector<vector<int>> kosarajuSCC(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    // Step 1: Fill stack with nodes in order of finishing times
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }

    // Step 2: Reverse the graph
    vector<vector<int>> revAdj(n);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            revAdj[v].push_back(u); // Reverse the edge
        }
    }

    // Step 3: Do DFS in order of stack to get SCCs
    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> sccs;
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, revAdj, visited, component);
            sccs.push_back(component); // Store the found SCC
        }
    }
    return sccs;
}

/*
-------------------------------
Tarjan's Algorithm
-------------------------------
1. Do a single DFS traversal.
2. Use discovery time and low-link values to identify SCC roots.
3. Use a stack to keep track of the current path.

*/

void tarjanDFS(int u, int& time, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack, vector<vector<int>>& sccs) {
    disc[u] = low[u] = time++; // Set discovery and low-link time
    st.push(u); // Push node to stack
    inStack[u] = true; // Mark node as in stack

    for (int v : adj[u]) {
        if (disc[v] == -1) { // If v is not visited
            tarjanDFS(v, time, adj, disc, low, st, inStack, sccs);
            low[u] = min(low[u], low[v]); // Update low-link value
        } else if (inStack[v]) {
            low[u] = min(low[u], disc[v]); // Update low-link for back edge
        }
    }

    // If u is root of SCC
    if (low[u] == disc[u]) {
        vector<int> component;
        while (st.top() != u) {
            component.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
        }
        component.push_back(u);
        inStack[u] = false;
        st.pop();
        sccs.push_back(component); // Store the found SCC
    }
}

vector<vector<int>> tarjanSCC(int n, vector<vector<int>>& adj) {
    vector<int> disc(n, -1), low(n, -1);
    vector<bool> inStack(n, false);
    stack<int> st;
    vector<vector<int>> sccs;
    int time = 0;

    for (int i = 0; i < n; ++i) {
        if (disc[i] == -1) {
            tarjanDFS(i, time, adj, disc, low, st, inStack, sccs);
        }
    }
    return sccs;
}

/*
-------------------------------
Alternative Approaches
-------------------------------
- Gabow's Algorithm: Another linear time algorithm for SCCs, less commonly used than Tarjan's.
- Path-based strong component algorithm: Also linear time, but more complex to implement.

-------------------------------
Dry Run Example
-------------------------------
Graph:
0 --> 1 --> 2
^     |     |
|     v     v
4 <-- 3 <-- 5

Adjacency List:
0: [1]
1: [2,3]
2: [5]
3: [4]
4: [0]
5: [3]

Kosaraju's Algorithm Dry Run:
1. DFS order: 0,1,2,5,3,4 (stack: 4,3,5,2,1,0)
2. Reverse graph:
   0: [4]
   1: [0]
   2: [1]
   3: [1,5]
   4: [3]
   5: [2]
3. Pop from stack and DFS:
   - Start at 0: 0,1,2,5,3,4 (all visited in one DFS) => SCC: [0,1,2,5,3,4]

Tarjan's Algorithm Dry Run:
- Start at 0, traverse 0->1->2->5->3->4->0 (cycle detected)
- All nodes in the cycle have the same low-link value, so SCC: [4,3,5,2,1,0]

Both algorithms find the same SCCs.

-------------------------------
Summary:
- Kosaraju's: Two DFS + graph reversal, easy to implement.
- Tarjan's: One DFS, more efficient in practice, uses low-link values.

*/
