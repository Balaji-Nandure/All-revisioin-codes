/*
Approach:
This code demonstrates the dry run of two famous shortest path algorithms for graphs with possible negative weights:
1. Bellman-Ford Algorithm: Computes shortest paths from a single source to all vertices, can handle negative weights, and detects negative cycles.
2. Floyd-Warshall Algorithm: Computes shortest paths between all pairs of vertices, can handle negative weights, and detects negative cycles.

Below are the dry runs and code snippets for both algorithms, with detailed comments explaining each step.

-------------------------------
Bellman-Ford Algorithm Dry Run
-------------------------------

// Example Graph:
// Vertices: 0, 1, 2, 3
// Edges: (0->1, 1), (0->2, 4), (1->2, -3), (2->3, 2), (3->1, 1)

int V = 4; // Number of vertices
vector<vector<int>> edges = {
    {0, 1, 1},
    {0, 2, 4},
    {1, 2, -3},
    {2, 3, 2},
    {3, 1, 1}
};

vector<int> dist(V, INT_MAX); // Distance from source to each vertex
int src = 0; // Source vertex
dist[src] = 0; // Distance to source is 0

// Relax all edges V-1 times
for(int i = 0; i < V-1; i++) {
    for(auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        // If the distance to u is not infinite and can be minimized
        if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
            dist[v] = dist[u] + wt; // Update distance to v
        }
    }
}

// Check for negative-weight cycles
for(auto &edge : edges) {
    int u = edge[0], v = edge[1], wt = edge[2];
    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
        // Negative cycle detected
        cout << "Negative weight cycle detected\n";
        break;
    }
}

/*
Dry Run:
Initialization: dist = [0, INF, INF, INF]
Iteration 1:
  Edge 0->1 (1): dist[1] = min(INF, 0+1) = 1
  Edge 0->2 (4): dist[2] = min(INF, 0+4) = 4
  Edge 1->2 (-3): dist[2] = min(4, 1-3) = -2
  Edge 2->3 (2): dist[3] = min(INF, -2+2) = 0
  Edge 3->1 (1): dist[1] = min(1, 0+1) = 1
After 1st iteration: [0, 1, -2, 0]
Iteration 2 and 3: No further updates
Final distances: [0, 1, -2, 0]
*/

-------------------------------
Floyd-Warshall Algorithm Dry Run
-------------------------------

// Example Graph (same as above)
int V = 4;
vector<vector<int>> dist(V, vector<int>(V, INT_MAX));

// Initialize distances
for(int i = 0; i < V; i++) dist[i][i] = 0;
dist[0][1] = 1;
dist[0][2] = 4;
dist[1][2] = -3;
dist[2][3] = 2;
dist[3][1] = 1;

// Main algorithm
for(int k = 0; k < V; k++) { // For each intermediate vertex
    for(int i = 0; i < V; i++) { // For each source
        for(int j = 0; j < V; j++) { // For each destination
            // If path i->k and k->j exists, and can minimize i->j
            if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}

/*
Dry Run:
Initial matrix:
[0, 1, 4, INF]
[INF, 0, -3, INF]
[INF, INF, 0, 2]
[INF, 1, INF, 0]

After k=0:
No changes

After k=1:
dist[0][2] = min(4, 1 + -3) = -2
dist[0][3] = min(INF, -2 + 2) = 0

After k=2:
dist[1][3] = min(INF, -3 + 2) = -1

After k=3:
dist[3][2] = min(INF, 1 + -3) = -2

Final matrix:
[0, 1, -2, 0]
[INF, 0, -3, -1]
[INF, 3, 0, 2]
[INF, 1, -2, 0]
*/

-------------------------------
Better Alternatives & Notes
-------------------------------
// - For graphs with only positive weights, Dijkstra's algorithm is more efficient than Bellman-Ford (O(E + V log V) with heap).
// - For all-pairs shortest path in sparse graphs, Johnson's algorithm (uses Bellman-Ford + Dijkstra) is more efficient than Floyd-Warshall (O(V^2 log V + VE)).
// - For dense graphs or when negative weights are present, Floyd-Warshall is simple and effective (O(V^3)).

-------------------------------
Summary
-------------------------------
// Bellman-Ford: Single source, negative weights, detects negative cycles, O(VE)
// Floyd-Warshall: All pairs, negative weights, detects negative cycles, O(V^3)
// Dijkstra: Single source, positive weights, O(E + V log V) with priority queue
// Johnson's: All pairs, negative weights (no negative cycles), O(V^2 log V + VE)

-------------------------------
End of Dry Run and Approach
-------------------------------
*/
