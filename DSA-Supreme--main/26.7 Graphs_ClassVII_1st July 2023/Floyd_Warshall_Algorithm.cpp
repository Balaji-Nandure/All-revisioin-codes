/*
    Floyd-Warshall Algorithm for All-Pairs Shortest Path

    Approach:
    -----------
    - The Floyd-Warshall algorithm is a dynamic programming algorithm to find shortest paths between all pairs of vertices in a weighted graph (with positive or negative edge weights, but no negative cycles).
    - The algorithm works by incrementally improving the solution by considering all vertices as intermediate points.
    - The main idea is: For each pair (i, j), check if a path from i to j through an intermediate vertex k is shorter than the direct path from i to j.

    Steps:
    1. Initialize a distance matrix with large values (infinity), and 0 for diagonal elements.
    2. For each edge (u, v, wt), set dist[u][v] = wt.
    3. For each vertex k (as intermediate), update all pairs (i, j): 
       dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    4. After all iterations, dist[i][j] contains the shortest distance from i to j.

    Alternatives:
    -------------
    - For single-source shortest path, Dijkstra's algorithm (for non-negative weights) or Bellman-Ford (for negative weights) is more efficient.
    - For sparse graphs, Johnson's algorithm can be used for all-pairs shortest path with better performance.
    - For dense graphs or when all-pairs are needed, Floyd-Warshall is simple and effective.

    Below is the improved code with detailed comments and a dry run at the end.
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits>
using namespace std;

class Graph
{
public:
    // Adjacency list: node -> list of (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adjList;

    // Adds an edge to the graph
    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back({v, wt}); // Add edge u->v
        if (direction == 1)
        {
            adjList[v].push_back({u, wt}); // Add edge v->u for undirected
        }
    }

    // Prints the adjacency list (for debugging)
    void printAdjList()
    {
        for (auto &i : adjList)
        {
            cout << i.first << "->";
            for (auto &j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    // Floyd-Warshall algorithm to compute all-pairs shortest paths
    void floydWarshall(int n)
    {
        // Use INT_MAX/2 to avoid integer overflow in addition
        int INF = numeric_limits<int>::max() / 2;

        // Step 1: Initialize distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0; // Distance to self is 0
        }

        // Step 2: Fill initial distances from adjacency list
        for (auto &t : adjList)
        {
            int u = t.first;
            for (auto &nbr : t.second)
            {
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = min(dist[u][v], wt); // In case of multiple edges, take minimum weight
            }
        }

        // Step 3: Main Floyd-Warshall DP
        for (int k = 0; k < n; k++) // For each intermediate node k
        {
            for (int i = 0; i < n; i++) // For each source node i
            {
                for (int j = 0; j < n; j++) // For each destination node j
                {
                    // If path i->k and k->j exists, try to update i->j
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Step 4: Detect negative cycles (optional, but good practice)
        bool hasNegativeCycle = false;
        for (int i = 0; i < n; i++)
        {
            if (dist[i][i] < 0)
            {
                hasNegativeCycle = true;
                break;
            }
        }

        // Output the result
        cout << "All-Pairs Shortest Path Matrix:" << endl;
        if (hasNegativeCycle)
        {
            cout << "Graph contains a negative weight cycle!" << endl;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/*
    Alternative Approach (Johnson's Algorithm):
    -------------------------------------------
    // Johnson's algorithm is more efficient for sparse graphs.
    // It uses Bellman-Ford to reweight edges, then runs Dijkstra from each node.
    // Complexity: O(V^2 log V + VE)
    // Not implemented here due to complexity, but recommended for large, sparse graphs.

    // For single-source shortest path:
    // - Use Dijkstra's algorithm for non-negative weights.
    // - Use Bellman-Ford for graphs with negative weights.
*/

int main()
{
    Graph g;
    // Add edges: g.addEdge(u, v, weight, direction)
    // direction = 0 for directed, 1 for undirected

    g.addEdge(0, 1, 3, 0); // Edge 0->1 with weight 3
    g.addEdge(0, 3, 5, 0); // Edge 0->3 with weight 5
    g.addEdge(1, 0, 2, 0); // Edge 1->0 with weight 2
    g.addEdge(1, 3, 4, 0); // Edge 1->3 with weight 4
    g.addEdge(2, 1, 1, 0); // Edge 2->1 with weight 1
    g.addEdge(3, 2, 2, 0); // Edge 3->2 with weight 2

    // Print adjacency list (optional)
    // g.printAdjList();

    g.floydWarshall(4); // Compute all-pairs shortest paths for 4 nodes

    return 0;
}

/*
    Dry Run:
    --------
    Nodes: 0, 1, 2, 3

    Edges:
    0->1 (3), 0->3 (5)
    1->0 (2), 1->3 (4)
    2->1 (1)
    3->2 (2)

    Initial dist matrix:
        0   3   INF 5
        2   0   INF 4
        INF 1   0   INF
        INF INF 2   0

    After Floyd-Warshall:
        0   3   7   5
        2   0   6   4
        3   1   0   5
        5   3   2   0

    Explanation:
    - Shortest path from 0 to 2: 0->3->2 = 5+2 = 7
    - Shortest path from 2 to 0: 2->1->0 = 1+2 = 3
    - All other shortest paths are similarly computed.
*/