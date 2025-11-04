/*
Approach Used:
---------------
This code finds the shortest path between two nodes in an unweighted (or equally weighted) undirected/directed graph using Breadth-First Search (BFS). 
BFS is optimal for unweighted graphs as it explores all nodes at the present depth before moving to the next level, ensuring the shortest path is found.

Key Steps:
1. Build the adjacency list for the graph.
2. Use BFS to traverse the graph from the source node, keeping track of visited nodes and parent relationships.
3. After BFS, reconstruct the shortest path from destination to source using the parent map.

Better Alternatives:
--------------------
- For weighted graphs with different weights, Dijkstra's algorithm is preferred.
- For negative weights, Bellman-Ford or Floyd-Warshall algorithms are used.
- For just checking reachability, DFS can be used but won't guarantee the shortest path in unweighted graphs.

Dijkstra's Algorithm Example (for weighted graphs):
---------------------------------------------------
/*
void dijkstra(int src, int dest) {
    unordered_map<int, int> dist;
    unordered_map<int, int> parent;
    for (auto& node : adjList) {
        dist[node.first] = INT_MAX;
    }
    dist[src] = 0;
    parent[src] = -1;
    set<pair<int, int>> st; // {distance, node}
    st.insert({0, src});
    while (!st.empty()) {
        auto [d, node] = *st.begin();
        st.erase(st.begin());
        for (auto& nbr : adjList[node]) {
            int v = nbr.first;
            int wt = nbr.second;
            if (d + wt < dist[v]) {
                st.erase({dist[v], v});
                dist[v] = d + wt;
                parent[v] = node;
                st.insert({dist[v], v});
            }
        }
    }
    // Reconstruct path as in BFS
}
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    public:
    // Adjacency list: node -> list of (neighbor, weight)
    unordered_map<int, list<pair<int,int>>> adjList;

    // Adds an edge to the graph
    void addEdge(int u, int v, int wt, bool direction){
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back({v, wt}); // Add edge u->v
        if(direction == 1){
            adjList[v].push_back({u, wt}); // If undirected, add edge v->u
        }
    }

    // Prints the adjacency list of the graph
    void printAdjList(){
        for(auto i : adjList){
            cout << i.first << "->";
            for(auto j : i.second){
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
    }

    // Finds and prints the shortest path from src to dest using BFS
    void shortestPath(int src, int dest){
        queue<int> q; // Queue for BFS
        unordered_map<int, bool> visited; // Track visited nodes
        unordered_map<int, int> parent; // To reconstruct path

        // Initialize BFS
        q.push(src); // Start from source
        visited[src] = true; // Mark source as visited
        parent[src] = -1; // Source has no parent

        // BFS traversal
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            // Visit all neighbors of frontNode
            for(auto nbr : adjList[frontNode]){
                if(!visited[nbr.first]){
                    q.push(nbr.first); // Add neighbor to queue
                    visited[nbr.first] = true; // Mark as visited
                    parent[nbr.first] = frontNode; // Set parent for path reconstruction
                }
            }
        }

        // Reconstruct path from dest to src using parent map
        vector<int> ans;
        int node = dest;
        while(node != -1){
            ans.push_back(node);
            node = parent[node];
        }
        // Path is from dest to src, so reverse it
        reverse(ans.begin(), ans.end());

        // Print the shortest path
        cout << "Shortest path from " << src << " to " << dest << ": ";
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph g;
    // Constructing the graph
    g.addEdge(0,1,1,1); // 0-1
    g.addEdge(0,2,1,1); // 0-2
    g.addEdge(0,3,1,1); // 0-3
    g.addEdge(1,4,1,1); // 1-4
    g.addEdge(4,5,1,1); // 4-5
    g.addEdge(2,5,1,1); // 2-5
    g.addEdge(3,6,1,1); // 3-6
    g.addEdge(6,5,1,1); // 6-5

    g.printAdjList(); // Print adjacency list

    int src = 0;
    int dest = 5;
    cout << "Printing shortest path" << endl;
    g.shortestPath(src, dest); // Find and print shortest path

    return 0;
}

/*
Dry Run:
--------
Graph:
0: 1,2,3
1: 0,4
2: 0,5
3: 0,6
4: 1,5
5: 4,2,6
6: 3,5

Find shortest path from 0 to 5:
- Start BFS from 0.
- Visit 1,2,3 (neighbors of 0), parent[1]=0, parent[2]=0, parent[3]=0
- Visit 4 (neighbor of 1), parent[4]=1
- Visit 5 (neighbor of 2), parent[5]=2
- BFS stops as all nodes are visited.

Reconstruct path:
- parent[5]=2, parent[2]=0, parent[0]=-1
- Path: 5 -> 2 -> 0 (reverse: 0 2 5)

Output:
Shortest path from 0 to 5: 0 2 5
*/