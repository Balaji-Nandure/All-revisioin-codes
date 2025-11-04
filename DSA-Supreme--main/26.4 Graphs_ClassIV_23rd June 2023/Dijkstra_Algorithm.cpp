/*
Approach Used:
---------------
This code implements Dijkstra's Algorithm to find the shortest path from a source node to all other nodes in a weighted directed/undirected graph with non-negative weights.

Key Points:
- The graph is represented using an adjacency list (unordered_map<int, list<pair<int,int>>>).
- Dijkstra's algorithm is implemented using a set to efficiently fetch the node with the smallest tentative distance.
- The set stores pairs of (distance, node).
- For each node, we update the distances of its neighbors if a shorter path is found.

Better Alternative:
-------------------
- Instead of using a set (which has O(log n) insertion and deletion), a min-heap (priority_queue with custom comparator) can be used for better performance (O(log n) per operation, but no need to erase arbitrary elements).
- With a min-heap, we may push multiple entries for the same node, but we ignore outdated ones by checking the current distance.

Alternative Dijkstra Implementation (using min-heap):
-----------------------------------------------------
/*
void dijkstraAlgoHeap(int src, int n) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [nodeDistance, node] = pq.top();
        pq.pop();
        if(nodeDistance > dist[node]) continue; // Ignore outdated entry
        for(auto nbr : adjList[node]) {
            if(nodeDistance + nbr.second < dist[nbr.first]) {
                dist[nbr.first] = nodeDistance + nbr.second;
                pq.push({dist[nbr.first], nbr.first});
            }
        }
    }
    cout << "Printing array" << endl;
    for(int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
}
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>
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

    // Dijkstra's Algorithm using set (O(E log V))
    void dijkstraAlgo(int src, int n){
        // dist[i] will hold the shortest distance from src to i
        vector<int> dist(n, INT_MAX);

        // Set to get the node with the smallest distance efficiently
        set<pair<int,int>> st; // (distance, node)

        dist[src] = 0; // Distance to source is 0
        st.insert({0, src}); // Insert source node

        while(!st.empty()){
            // Fetch the node with the smallest distance
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int node = top.second;

            // Remove this node from the set
            st.erase(st.begin());

            // Traverse all neighbors of the current node
            for(auto nbr : adjList[node]){
                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                // If a shorter path to adjNode is found
                if(nodeDistance + edgeWeight < dist[adjNode]){
                    // If adjNode is already in set, remove the old entry
                    auto result = st.find({dist[adjNode], adjNode});
                    if(result != st.end()){
                        st.erase(result);
                    }
                    // Update distance and insert new entry in set
                    dist[adjNode] = nodeDistance + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        // Output the shortest distances from src to all nodes
        cout << "Printing array" << endl;
        for(int i = 0; i < n; i++){
            cout << dist[i] << " ";
        }
        cout << endl;
    }

    /*
    // Better alternative: Dijkstra's Algorithm using min-heap (priority_queue)
    void dijkstraAlgoHeap(int src, int n) {
        vector<int> dist(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        dist[src] = 0;
        pq.push({0, src});
        while(!pq.empty()) {
            auto [nodeDistance, node] = pq.top();
            pq.pop();
            if(nodeDistance > dist[node]) continue; // Ignore outdated entry
            for(auto nbr : adjList[node]) {
                if(nodeDistance + nbr.second < dist[nbr.first]) {
                    dist[nbr.first] = nodeDistance + nbr.second;
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }
        cout << "Printing array" << endl;
        for(int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    */
};

int main(){
    Graph g;
    // Adding edges: g.addEdge(u, v, weight, direction)
    g.addEdge(6,5,9,0);   // 6 -> 5 (weight 9), directed
    g.addEdge(6,3,2,0);   // 6 -> 3 (weight 2), directed
    g.addEdge(6,1,14,0);  // 6 -> 1 (weight 14), directed
    g.addEdge(3,1,9,0);   // 3 -> 1 (weight 9), directed
    g.addEdge(3,4,11,0);  // 3 -> 4 (weight 11), directed
    g.addEdge(3,2,10,0);  // 3 -> 2 (weight 10), directed
    g.addEdge(1,2,7,0);   // 1 -> 2 (weight 7), directed
    g.addEdge(2,4,15,0);  // 2 -> 4 (weight 15), directed
    g.addEdge(5,4,6,0);   // 5 -> 4 (weight 6), directed

    int n = 7;    // Number of nodes (0 to 6)
    int src = 6;  // Source node

    // Print adjacency list (optional for debugging)
    // g.printAdjList();

    // Run Dijkstra's algorithm from source node
    g.dijkstraAlgo(src, n);

    // To use the better alternative (min-heap), uncomment below:
    // g.dijkstraAlgoHeap(src, n);

    return 0;
}

/*
Dry Run:
--------
Graph:
6 -> 5 (9), 3 (2), 1 (14)
3 -> 1 (9), 4 (11), 2 (10)
1 -> 2 (7)
2 -> 4 (15)
5 -> 4 (6)

Source: 6

Step-by-step:
- dist = [INF, INF, INF, INF, INF, INF, 0] (src=6)
- Visit 6: update 5 (9), 3 (2), 1 (14)
    dist = [INF, 14, INF, 2, INF, 9, 0]
- Visit 3: update 1 (2+9=11 < 14), 4 (2+11=13), 2 (2+10=12)
    dist = [INF, 11, 12, 2, 13, 9, 0]
- Visit 5: update 4 (9+6=15 > 13, so no update)
- Visit 1: update 2 (11+7=18 > 12, so no update)
- Visit 2: update 4 (12+15=27 > 13, so no update)
- Visit 4: done

Final dist: [INF, 11, 12, 2, 13, 9, 0]
Output: 2147483647 11 12 2 13 9 0
(2147483647 = INT_MAX, means node 0 is unreachable from 6)
*/