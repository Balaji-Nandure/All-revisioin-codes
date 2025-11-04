/*
1) Dry run the codes done in today's class

// Approach Used in Class:
// The codes in class were mainly about basic graph traversals (BFS, DFS), cycle detection, and shortest path algorithms.
// Let's take an example of BFS traversal for an undirected graph.

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal from a given source node
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q; // Queue for BFS
    q.push(start); // Push starting node
    visited[start] = true; // Mark as visited

    while(!q.empty()) {
        int node = q.front(); // Get the front node
        q.pop(); // Remove it from queue
        cout << node << " "; // Print the node (BFS order)

        // Traverse all adjacent nodes
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) { // If not visited
                q.push(neighbor); // Add to queue
                visited[neighbor] = true; // Mark as visited
            }
        }
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> adj(n); // Adjacency list

    // Example edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    vector<bool> visited(n, false); // Visited array

    cout << "BFS Traversal starting from node 0: ";
    bfs(0, adj, visited);
    cout << endl;

    return 0;
}

/*
Logic behind important lines:
- queue<int> q; : Used to store nodes for BFS traversal.
- q.push(start); : Start BFS from the given node.
- visited[start] = true; : Mark the starting node as visited to avoid revisiting.
- while(!q.empty()) : Continue until all reachable nodes are visited.
- int node = q.front(); : Get the current node to process.
- for(int neighbor : adj[node]) : Traverse all neighbors of the current node.
- if(!visited[neighbor]) : Only process unvisited neighbors.
- q.push(neighbor); visited[neighbor] = true; : Add neighbor to queue and mark as visited.

Better/Alternative Approaches:
1. For disconnected graphs, run BFS/DFS for all unvisited nodes to cover all components.
2. For shortest path in unweighted graphs, BFS is optimal. For weighted graphs, use Dijkstra's algorithm.

Example: Dijkstra's Algorithm for shortest path (weighted graph)
---------------------------------------------------------------
#include <queue>
#include <climits>
void dijkstra(int src, vector<vector<pair<int,int>>>& adj, vector<int>& dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto& edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if(dist[neighbor] > d + weight) {
                dist[neighbor] = d + weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
}

Dry Run of BFS Example:
-----------------------
adjacency list:
0: 1,2
1: 0,3
2: 0,4
3: 1
4: 2

Start BFS from node 0:
- Queue: [0], Visited: [1,0,0,0,0]
- Pop 0, print 0, push 1,2. Queue: [1,2], Visited: [1,1,1,0,0]
- Pop 1, print 1, push 3. Queue: [2,3], Visited: [1,1,1,1,0]
- Pop 2, print 2, push 4. Queue: [3,4], Visited: [1,1,1,1,1]
- Pop 3, print 3. Queue: [4]
- Pop 4, print 4. Queue: []
Output: 0 1 2 3 4

*/
