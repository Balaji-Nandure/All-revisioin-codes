/*
    Bellman-Ford Algorithm Implementation

    Approach:
    1. The Bellman-Ford algorithm is used to find the shortest path from a single source to all other vertices in a weighted graph (can handle negative weights).
    2. It can also detect negative weight cycles in the graph.
    3. The algorithm works by relaxing all edges up to (V-1) times, where V is the number of vertices.
    4. After V-1 relaxations, if we can still relax any edge, then a negative cycle exists.

    Alternatives:
    - Dijkstra's Algorithm: Faster (O(E + V log V) with min-heap), but does NOT work with negative weights.
    - SPFA (Shortest Path Faster Algorithm): An improvement over Bellman-Ford in practice, but same worst-case time complexity.
    - Johnson's Algorithm: For all-pairs shortest paths with negative weights (but no negative cycles).

    Below is the improved and well-commented code for Bellman-Ford.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<climits>
using namespace std;

// Graph class using adjacency list representation
class Graph{
    public:
    // Adjacency list: node -> list of (neighbor, weight)
    unordered_map<int, list<pair<int,int>>> adjList;

    // Adds an edge to the graph
    void addEdge(int u, int v, int wt, bool direction){
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back({v, wt});
        if(direction == 1){
            adjList[v].push_back({u, wt});
        }
    }

    // Prints the adjacency list (for debugging)
    void printAdjList(){
        for(auto &i : adjList){
            cout << i.first << "->";
            for(auto &j : i.second){
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    // Bellman-Ford algorithm to detect negative weight cycle
    // Returns true if negative cycle is found, else false
    bool bellmanford(int n, int src){
        // n: number of vertices, src: source vertex

        // Step 1: Initialize distances from src to all other vertices as infinite
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; // Distance to source is 0

        // Step 2: Relax all edges (n-1) times
        for(int i = 1; i <= n-1; i++){
            // For each edge (u, v, wt)
            for(auto &t : adjList){
                int u = t.first;
                for(auto &nbr : t.second){
                    int v = nbr.first;
                    int wt = nbr.second;
                    // If u is reachable and can relax edge (u,v)
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Step 3: Check for negative-weight cycles by trying to relax once more
        for(auto &t : adjList){
            int u = t.first;
            for(auto &nbr : t.second){
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    // Negative cycle detected
                    return true;
                }
            }
        }

        // Optional: Print shortest distances
        cout << "Shortest distances from source " << src << ":\n";
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX)
                cout << "Node " << i << ": INF\n";
            else
                cout << "Node " << i << ": " << dist[i] << "\n";
        }

        return false; // No negative cycle found
    }

    /*
    // Alternative: SPFA (Shortest Path Faster Algorithm)
    // Faster in practice, but same worst-case as Bellman-Ford
    bool spfa(int n, int src) {
        vector<int> dist(n, INT_MAX);
        vector<int> inQueue(n, 0);
        vector<int> count(n, 0);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        inQueue[src] = 1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            inQueue[u] = 0;
            for(auto &nbr : adjList[u]) {
                int v = nbr.first;
                int wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                    if(!inQueue[v]) {
                        q.push(v);
                        inQueue[v] = 1;
                        count[v]++;
                        if(count[v] > n) // Negative cycle detected
                            return true;
                    }
                }
            }
        }
        return false;
    }
    */
};

int main(){
    Graph g;

    // Adding edges: g.addEdge(u, v, weight, direction)
    // direction = 0 for directed, 1 for undirected
    g.addEdge(0, 1, -1, 0); // Edge 0->1 with weight -1
    g.addEdge(0, 2, 4, 0);  // Edge 0->2 with weight 4
    g.addEdge(1, 2, 3, 0);  // Edge 1->2 with weight 3
    g.addEdge(1, 3, 2, 0);  // Edge 1->3 with weight 2
    g.addEdge(1, 4, 2, 0);  // Edge 1->4 with weight 2
    g.addEdge(3, 1, 1, 0);  // Edge 3->1 with weight 1
    g.addEdge(3, 2, 5, 0);  // Edge 3->2 with weight 5
    g.addEdge(4, 3, -3, 0); // Edge 4->3 with weight -3

    // Optional: Print adjacency list
    // g.printAdjList();

    // Run Bellman-Ford from source 0
    bool hasNegativeCycle = g.bellmanford(5, 0);

    if(hasNegativeCycle)
        cout << "Negative cycle found\n";
    else
        cout << "Negative cycle not found\n";

    return 0;
}

/*
Dry Run:
Graph:
0 -> 1(-1), 2(4)
1 -> 2(3), 3(2), 4(2)
2 -> 
3 -> 1(1), 2(5)
4 -> 3(-3)

Source: 0

Initialization:
dist = [0, INF, INF, INF, INF]

After 1st iteration:
0->1: dist[1] = min(INF, 0 + -1) = -1
0->2: dist[2] = min(INF, 0 + 4) = 4
1->2: dist[2] = min(4, -1 + 3) = 2
1->3: dist[3] = min(INF, -1 + 2) = 1
1->4: dist[4] = min(INF, -1 + 2) = 1
3->1: dist[1] = min(-1, 1 + 1) = -1
3->2: dist[2] = min(2, 1 + 5) = 2
4->3: dist[3] = min(1, 1 + -3) = -2

After 2nd iteration:
1->3: dist[3] = min(-2, -1 + 2) = -2
4->3: dist[3] = min(-2, 1 + -3) = -2
3->1: dist[1] = min(-1, -2 + 1) = -1
... (no further improvement for other edges)

After 3rd and 4th iterations:
No further improvements.

Check for negative cycle:
Try to relax all edges again. If any distance improves, negative cycle exists.
In this case, no further improvement, so "Negative cycle not found".

If you change edge 3->1 to weight -2, a negative cycle will be detected.

Time Complexity: O(V*E)
Space Complexity: O(V)
*/