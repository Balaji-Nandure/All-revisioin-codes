/*
Approach:
-----------
This code demonstrates how to represent a graph using an adjacency matrix. 
The adjacency matrix is a 2D vector where adj[i][j] = 1 indicates an edge from node i to node j, and 0 otherwise.
This approach is best suited for dense graphs or when you need to check edge existence in O(1) time.

Improvements made:
- Added comments explaining each important line and logic.
- Added input validation and user-friendly prompts.
- Added support for undirected graphs (optional, can be toggled).
- Provided a detailed alternative approach using adjacency list with code in comments.
- Added a dry run at the end of the code.
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n; // Input number of nodes

    // Initialize adjacency matrix with 0s (no edges)
    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges: ";
    cin >> e; // Input number of edges

    // Ask user if the graph is directed or undirected
    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    cout << "Enter each edge as a pair of nodes (u v) (0-based indexing):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v; // Input edge from u to v

        // Input validation
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid edge (" << u << ", " << v << "). Node indices must be between 0 and " << n-1 << ". Skipping this edge." << endl;
            continue;
        }

        // Mark the edge in the adjacency matrix
        adj[u][v] = 1;
        if (!isDirected) {
            // For undirected graph, also mark the reverse edge
            adj[v][u] = 1;
        }
    }

    // Printing the adjacency matrix
    cout << "\nAdjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Alternative Approach: Adjacency List
-------------------------------------
For sparse graphs, adjacency list is more space-efficient.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, e;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adjList(n);
    bool isDirected;
    cout << "Is the graph directed? (1 for Yes, 0 for No): ";
    cin >> isDirected;

    cout << "Enter each edge as a pair of nodes (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        if (!isDirected) {
            adjList[v].push_back(u);
        }
    }

    cout << "\nAdjacency List:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    return 0;
}
*/

/*
Dry Run Example:
-----------------
Input:
Enter the number of nodes: 3
Enter the number of edges: 2
Is the graph directed? (1 for Yes, 0 for No): 0
Enter each edge as a pair of nodes (u v) (0-based indexing):
0 1
1 2

Step-by-step:
- n = 3, e = 2, undirected graph
- adj initialized as 3x3 matrix of 0s
- First edge: 0 1
    adj[0][1] = 1, adj[1][0] = 1
- Second edge: 1 2
    adj[1][2] = 1, adj[2][1] = 1

Adjacency Matrix Output:
0 1 0
1 0 1
0 1 0
*/