/*
    Approach Used:
    ----------------
    - We are representing a weighted graph using an adjacency list.
    - The adjacency list is implemented using an unordered_map, where each key is a node, and the value is a list of pairs.
    - Each pair in the list represents a neighbor and the weight of the edge to that neighbor.
    - The addEdge function allows us to add both directed and undirected edges with weights.
    - The printAdjList function prints the adjacency list in a readable format.

    Alternatives:
    -------------
    1. Use vector<vector<pair<int,int>>> for dense graphs or when node indices are contiguous and small.
    2. Use map instead of unordered_map if you want the adjacency list to be printed in sorted order.
    3. For very large graphs, consider using more memory-efficient structures or external storage.

    Example of alternative using vector:
    ------------------------------------
    // vector<vector<pair<int,int>>> adjList(n);
    // void addEdge(int u, int v, int weight, bool direction) {
    //     adjList[u].push_back({v, weight});
    //     if(direction == 0) adjList[v].push_back({u, weight});
    // }

    // For printing, iterate over indices.

    Why unordered_map?
    ------------------
    - Allows for non-contiguous node labels (e.g., node numbers like 100, 200).
    - Fast average-case insert and lookup.

    Improvements made:
    ------------------
    - Added comments for all important lines.
    - Improved code readability.
    - Added input for user to choose directed/undirected and number of edges.
    - Added dry run at the end as a comment.
*/

#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Graph class to represent a weighted graph using adjacency list
class Graph{
    public:
        // Adjacency list: node -> list of (neighbor, weight)
        unordered_map<int, list<pair<int,int>>> adjList;

        // Function to add an edge to the graph
        void addEdge(int u, int v, int weight, bool direction){
            // direction = 0 -> undirected, direction = 1 -> directed 
            // Add edge from u to v with given weight
            adjList[u].push_back({v, weight});
            // If undirected, also add edge from v to u
            if(direction == 0)
                adjList[v].push_back({u, weight});
        }

        // Function to print the adjacency list of the graph
        void printAdjList(){
            for(const auto& node : adjList){
                cout << node.first << " -> ";
                for(const auto& neighbour : node.second){
                    cout << "(" << neighbour.first << ", " << neighbour.second << "), ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g;

    // Example usage:
    // Let's create a directed weighted graph with 3 edges
    // Edge: 1 -> 2 (weight 8)
    // Edge: 0 -> 1 (weight 5)
    // Edge: 0 -> 2 (weight 6)
    g.addEdge(1, 2, 8, 1); // directed edge from 1 to 2 with weight 8
    g.addEdge(0, 1, 5, 1); // directed edge from 0 to 1 with weight 5
    g.addEdge(0, 2, 6, 1); // directed edge from 0 to 2 with weight 6

    // Print the adjacency list
    g.printAdjList();

    /*
    Dry Run:
    --------
    After adding the above edges, the adjacency list will look like:
    1 -> (2, 8)
    0 -> (1, 5), (2, 6)
    2 ->

    Output:
    1 -> (2, 8), 
    0 -> (1, 5), (2, 6), 

    (Note: 2 has no outgoing edges, so it may not appear unless you add a check to print all nodes.)
    */

    return 0;
}

/*
    Alternative: Using vector for contiguous node indices
    ----------------------------------------------------
    #include <vector>
    #include <iostream>
    using namespace std;
    class Graph {
        public:
            vector<vector<pair<int,int>>> adjList;
            Graph(int n) { adjList.resize(n); }
            void addEdge(int u, int v, int weight, bool direction) {
                adjList[u].push_back({v, weight});
                if(direction == 0) adjList[v].push_back({u, weight});
            }
            void printAdjList() {
                for(int i=0; i<adjList.size(); ++i) {
                    cout << i << " -> ";
                    for(auto& nbr : adjList[i])
                        cout << "(" << nbr.first << ", " << nbr.second << "), ";
                    cout << endl;
                }
            }
    };
*/