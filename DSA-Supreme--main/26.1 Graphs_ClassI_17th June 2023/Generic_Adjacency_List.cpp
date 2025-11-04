/*
    Approach:
    -----------
    - We are implementing a generic Graph class using adjacency list representation.
    - The adjacency list is implemented using an unordered_map, where each key is a node and the value is a list of its neighbors.
    - The addEdge function allows us to add both directed and undirected edges.
    - The printAdjList function prints the adjacency list for all nodes.

    Alternatives:
    -------------
    1. Use vector<vector<T>> for dense graphs or when node values are small integers.
    2. Use map<T, set<T>> for sorted neighbors and to avoid duplicate edges.
    3. For weighted graphs, use unordered_map<T, list<pair<T, W>>>.
    4. For better memory locality, use vector<pair<T, T>> for edge list representation.

    Example alternative for weighted graph:
    // unordered_map<T, list<pair<T, int>>> adjList;
    // void addEdge(T u, T v, int weight, bool direction) {
    //     adjList[u].push_back({v, weight});
    //     if(direction == 0) adjList[v].push_back({u, weight});
    // }

    Dry Run:
    --------
    For directed edges: (1->2), (0->1), (0->2)
    Adjacency List Output:
    1-> 2,
    0-> 1, 2,
    2->

*/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Template class for generic graph
template<typename T>
class Graph{
    public:
        // Adjacency list: maps each node to a list of its neighbors
        unordered_map<T, list<T>> adjList;

        // Function to add an edge between node u and node v
        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected edge
            // direction = 1 -> directed edge

            // Add edge from u to v
            adjList[u].push_back(v);

            // If undirected, also add edge from v to u
            if(direction == 0)
                adjList[v].push_back(u);
        }

        // Function to print the adjacency list of the graph
        void printAdjList(){
            // Iterate over all nodes in the adjacency list
            for(const auto& node : adjList){
                cout << node.first << "-> ";
                // Print all neighbors of the current node
                for(const auto& neighbour : node.second){
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }
};

int main(){
    // Create a graph of type char (can be int, string, etc.)
    Graph<int> g; // Changed to int for consistency with edge values

    // Example for undirected graph (uncomment to test)
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);

    // Example for directed graph
    g.addEdge(1, 2, 1); // Add edge 1->2
    g.addEdge(0, 1, 1); // Add edge 0->1
    g.addEdge(0, 2, 1); // Add edge 0->2

    // Print the adjacency list
    g.printAdjList();

    return 0;
}

/*
Dry Run:
--------
g.addEdge(1, 2, 1); // 1->2
g.addEdge(0, 1, 1); // 0->1
g.addEdge(0, 2, 1); // 0->2

Adjacency List:
1-> 2,
0-> 1, 2,
2->

If undirected edges were used:
g.addEdge(0, 1, 0); // 0<->1
g.addEdge(1, 2, 0); // 1<->2
g.addEdge(0, 2, 0); // 0<->2

Adjacency List:
0-> 1, 2,
1-> 0, 2,
2-> 1, 0,
*/
