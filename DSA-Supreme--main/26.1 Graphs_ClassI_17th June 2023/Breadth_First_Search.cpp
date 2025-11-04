/*
Approach:
----------
This code implements a Graph using an adjacency list and performs Breadth First Search (BFS) traversal. 
The graph can be either directed or undirected, as specified during edge addition. 
BFS is used to traverse all nodes in the graph, even if the graph is disconnected.

Key Points:
-----------
- Graph is represented using an unordered_map of lists (adjacency list).
- addEdge() adds an edge between two nodes, supporting both directed and undirected graphs.
- printAdjList() prints the adjacency list for debugging/visualization.
- bfs() performs BFS traversal from a given source node, marking nodes as visited.
- main() builds a sample graph and ensures all components are traversed (handles disconnected graphs).

Improvements:
-------------
- Added detailed comments for all important lines.
- Improved code formatting and output for clarity.
- Added printAdjList() call in main for visualization.
- Added space in BFS output for readability.
- Added a dry run at the end as a comment.
- Provided an alternative BFS approach using a vector for visited (commented).
- Provided an alternative using std::set for adjacency list (commented).

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Template class for Graph
template<typename T>
class Graph{
    public:
        // Adjacency list: maps each node to a list of its neighbors
        unordered_map<T, list<T>> adjList;

        // Function to add an edge to the graph
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
            cout << "Adjacency List:" << endl;
            for(auto node : adjList){
                cout << node.first << " -> ";
                for(auto neighbour : node.second){
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }

        // BFS traversal from a given source node
        void bfs(int src, unordered_map<int, bool>& visited){
            queue<int> q; // Queue for BFS

            // Push the source node and mark as visited
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                // Get the front node in the queue
                int frontNode = q.front();
                q.pop();

                // Print the node (with space for readability)
                cout << frontNode << " ";

                // Traverse all neighbors of the current node
                for(auto neighbour : adjList[frontNode]){
                    // If neighbor is not visited, add to queue and mark as visited
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
        }

        /*
        // Alternative BFS approach using vector<bool> for visited (if nodes are 0..N-1)
        void bfs_vector(int src, int n){
            vector<bool> visited(n, false);
            queue<int> q;
            q.push(src);
            visited[src] = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout << node << " ";
                for(auto neighbour : adjList[node]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }
        }
        */

        /*
        // Alternative: Use set instead of list for adjacency list to avoid duplicate edges and get sorted neighbors
        unordered_map<T, set<T>> adjSet;
        void addEdgeSet(T u, T v, bool direction){
            adjSet[u].insert(v);
            if(direction == 0)
                adjSet[v].insert(u);
        }
        */
};

int main(){
    // Create a graph of integers
    Graph<int> g;

    // Add edges to the graph (undirected, direction = 0)
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);

    // Print the adjacency list for visualization
    g.printAdjList();

    // Map to keep track of visited nodes
    unordered_map<int, bool> visited;

    // Traverse all nodes to handle disconnected graphs
    // (If a node is not visited, start BFS from that node)
    cout << "BFS Traversal: ";
    for(int i = 0; i <= 7; i++){
        if(!visited[i])
            g.bfs(i, visited);
    }
    cout << endl;

    return 0;
}

/*
Dry Run:
--------
Graph:
0: 1
1: 0, 2, 3
2: 1
3: 1, 5, 7
4: 7
5: 3
6: 7
7: 3, 6, 4

Adjacency List:
0 -> 1
1 -> 0, 2, 3
2 -> 1
3 -> 1, 5, 7
5 -> 3
7 -> 3, 6, 4
6 -> 7
4 -> 7

BFS Traversal (starting from 0):
- Start at 0: visit 0, queue = [0]
- Pop 0: visit 1, queue = [1]
- Pop 1: visit 2, 3, queue = [2, 3]
- Pop 2: (neighbor 1 already visited), queue = [3]
- Pop 3: visit 5, 7, queue = [5, 7]
- Pop 5: (neighbor 3 already visited), queue = [7]
- Pop 7: visit 6, 4, queue = [6, 4]
- Pop 6: (neighbor 7 already visited), queue = [4]
- Pop 4: (neighbor 7 already visited), queue = []

Output: 0 1 2 3 5 7 6 4

If there were disconnected components, the loop in main would ensure all are traversed.

Better Alternatives:
--------------------
- Use vector<bool> for visited if node indices are contiguous and known.
- Use set for adjacency list to avoid duplicate edges and get sorted neighbors.
- For weighted graphs, use unordered_map<T, list<pair<T, int>>> for adjList.
- For large graphs, consider using adjacency matrix if the graph is dense.

*/