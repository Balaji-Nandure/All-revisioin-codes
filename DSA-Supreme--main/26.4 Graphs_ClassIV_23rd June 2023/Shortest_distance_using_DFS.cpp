/*
Approach Used:
---------------
This code finds the shortest path from a source node to all other nodes in a **Directed Acyclic Graph (DAG)** with weighted edges using **Topological Sort** and **Dynamic Programming**.

1. **Topological Sort** is performed using DFS to get the order of nodes such that for every directed edge u->v, u comes before v.
2. Using the topological order, we relax the edges in order, ensuring that when we process a node, all its dependencies have already been processed.
3. This approach works only for DAGs and is more efficient than Dijkstra's for such graphs (O(V+E) time).

Better Alternatives:
--------------------
- For graphs with cycles or undirected graphs, use **Dijkstra's Algorithm** (for non-negative weights) or **Bellman-Ford** (for negative weights).
- Dijkstra's Algorithm is more general but has higher time complexity (O(E log V) with min-heap).
- For unweighted graphs, use **BFS** for shortest path.

Dijkstra's Algorithm Example (for reference):
---------------------------------------------
/*
void dijkstra(int src, int n, unordered_map<int, list<pair<int,int>>>& adjList) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto nbr : adjList[node]) {
            if(d + nbr.second < dist[nbr.first]) {
                dist[nbr.first] = d + nbr.second;
                pq.push({dist[nbr.first], nbr.first});
            }
        }
    }
    for(int i=0; i<n; i++) cout << dist[i] << " ";
}
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

// Graph class to represent a weighted directed/undirected graph
class Graph{
    public:
    // Adjacency list: node -> list of (neighbour, weight)
    unordered_map<int, list<pair<int,int>>> adjList;

    // Adds an edge from u to v with weight wt. If direction==1, adds both u->v and v->u (undirected)
    void addEdge(int u, int v, int wt, bool direction){
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back({v, wt});
        if(direction == 1){
            adjList[v].push_back({u, wt});
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

    // Helper function for DFS-based Topological Sort
    void topoSort(int src, unordered_map<int, bool>& visited, stack<int>& ans){
        visited[src] = true; // Mark current node as visited
        for(auto neighbour : adjList[src]){
            if(!visited[neighbour.first]){
                topoSort(neighbour.first, visited, ans); // Visit all unvisited neighbours
            }
        }
        // After visiting all descendants, push current node to stack
        ans.push(src);
    }

    // Computes shortest path from source to all nodes using topological order
    void shortestPath(int src, int n){
        // Step 1: Get topological order of all nodes
        stack<int> topoOrder;
        unordered_map<int, bool> visited;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                topoSort(i, visited, topoOrder);
            }
        }

        // Step 2: Initialize distances to all nodes as infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; // Distance to source is 0

        // Step 3: Process nodes in topological order
        while(!topoOrder.empty()){
            int topElement = topoOrder.top();
            topoOrder.pop();
            // If the node has been reached before
            if(dist[topElement] != INT_MAX){
                // Relax all outgoing edges
                for(auto nbr : adjList[topElement]){
                    if(dist[topElement] + nbr.second < dist[nbr.first]){
                        dist[nbr.first] = dist[topElement] + nbr.second;
                    }
                }
            }
        }

        // Step 4: Print shortest distances from source to all nodes
        cout << "Shortest distances from node " << src << ": ";
        for(int i = 0; i < n; i++){
            if(dist[i] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Graph g;
    // Add edges: g.addEdge(u, v, weight, direction)
    g.addEdge(0, 1, 5, 0);   // 0 -> 1 (weight 5)
    g.addEdge(0, 2, 3, 0);   // 0 -> 2 (weight 3)
    g.addEdge(2, 1, 2, 0);   // 2 -> 1 (weight 2)
    g.addEdge(1, 3, 3, 0);   // 1 -> 3 (weight 3)
    g.addEdge(2, 4, 6, 0);   // 2 -> 4 (weight 6)
    g.addEdge(4, 3, 1, 0);   // 4 -> 3 (weight 1)
    g.addEdge(2, 3, 5, 0);   // 2 -> 3 (weight 5)
    int n = 5; // Number of nodes (0 to 4)

    // Print adjacency list for verification
    g.printAdjList();

    // Compute and print shortest paths from source node 0
    cout << "Printing shortest path" << endl;
    int src = 0;
    g.shortestPath(src, n);

    return 0;
}

/*
Dry Run:
--------
Graph:
0 -> (1,5), (2,3)
1 -> (3,3)
2 -> (1,2), (4,6), (3,5)
3 -> 
4 -> (3,1)

Topological Order (one possible): 0 2 4 1 3

Initialization:
dist = [0, INF, INF, INF, INF]

Processing 0:
  0->1 (5): dist[1] = 0+5 = 5
  0->2 (3): dist[2] = 0+3 = 3
dist = [0,5,3,INF,INF]

Processing 2:
  2->1 (2): dist[1] = min(5,3+2)=5 (no change)
  2->4 (6): dist[4] = 3+6=9
  2->3 (5): dist[3]=3+5=8
dist = [0,5,3,8,9]

Processing 4:
  4->3 (1): dist[3]=min(8,9+1)=8 (no change)
dist = [0,5,3,8,9]

Processing 1:
  1->3 (3): dist[3]=min(8,5+3)=8 (no change)
dist = [0,5,3,8,9]

Processing 3: no outgoing edges

Final Output:
Shortest distances from node 0: 0 5 3 8 9
*/