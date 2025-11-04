/*
Approach:
-----------
We are representing a graph using an adjacency list. The adjacency list is implemented using an unordered_map, where each key is a node and the value is a list of its neighbors. The addEdge function allows us to add both directed and undirected edges. The printAdjList function prints the adjacency list for visualization.

Key Points:
-----------
- Adjacency list is memory efficient for sparse graphs.
- Using unordered_map allows us to handle any integer node labels (not just 0...N-1).
- addEdge supports both directed and undirected graphs.

Better Alternatives:
--------------------
1. If the number of nodes is known and small, a vector<vector<int>> can be used for faster access.
2. For weighted graphs, store pairs (neighbor, weight) instead of just neighbor.
3. For large graphs with string labels, unordered_map<string, list<string>> can be used.
4. To avoid duplicate edges in undirected graphs, check before inserting.

Alternative code for vector-based adjacency list:
-------------------------------------------------
    vector<vector<int>> adjList(n);
    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if(direction == 0)
            adjList[v].push_back(u);
    }

*/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Graph class using adjacency list representation
class Graph{
    public:
        // Adjacency list: key = node, value = list of neighbors
        unordered_map<int, list<int>> adjList;

        // Function to add an edge to the graph
        void addEdge(int u, int v, bool direction){
            // direction = 0 -> undirected edge
            // direction = 1 -> directed edge

            // Add edge from u to v
            adjList[u].push_back(v);

            // If undirected, also add edge from v to u
            if(direction == 0)
                adjList[v].push_back(u);
        }

        // Function to print the adjacency list
        void printAdjList(){
            // Iterate over all nodes in the adjacency list
            for(auto node : adjList){
                cout << node.first << " -> ";
                // Print all neighbors of the current node
                for(auto neighbour : node.second){
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g;

    // Example usage:
    // Uncomment below lines to create an undirected graph
    /*
    g.addEdge(0, 1, 0); // Add undirected edge between 0 and 1
    g.addEdge(1, 2, 0); // Add undirected edge between 1 and 2
    g.addEdge(0, 2, 0); // Add undirected edge between 0 and 2
    */

    // Creating a directed graph
    g.addEdge(1, 2, 1); // Add directed edge from 1 to 2
    g.addEdge(0, 1, 1); // Add directed edge from 0 to 1
    g.addEdge(0, 2, 1); // Add directed edge from 0 to 2

    // Print the adjacency list
    g.printAdjList();

    return 0;
}

/*
Dry Run:
---------
Directed graph edges added:
1 -> 2
0 -> 1
0 -> 2

Adjacency List after adding edges:
Node 1: 2
Node 0: 1, 2
Node 2: (no outgoing edges)

Output:
1 -> 2,
0 -> 1, 2,
*/

/*
Summary:
---------
- The code efficiently represents a graph using an adjacency list.
- It supports both directed and undirected graphs.
- For undirected graphs, edges are added in both directions.
- The printAdjList function displays the adjacency list for all nodes.
- For weighted graphs or other optimizations, see the alternative approaches above.
*/