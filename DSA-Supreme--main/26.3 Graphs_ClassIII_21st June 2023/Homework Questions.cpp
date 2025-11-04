/*
Approach Used:
--------------
This code demonstrates how to perform Topological Sort and Cycle Detection in a Directed Graph using Kahn's Algorithm (BFS-based Topological Sort).

Key Steps:
----------
1. Build the adjacency list for the graph.
2. Compute the indegree for each node.
3. Use a queue to process all nodes with indegree 0 (i.e., nodes with no incoming edges).
4. For each node removed from the queue, reduce the indegree of its neighbors.
5. If a neighbor's indegree becomes 0, add it to the queue.
6. If the number of nodes processed equals the total number of nodes, there is **no cycle**. Otherwise, a **cycle exists**.

Better Alternatives:
--------------------
1. **DFS-based Cycle Detection (for Directed Graphs):**
   - Use two visited arrays/maps: `visited` (for all visited nodes) and `dfsVisited` (for nodes in the current DFS path).
   - If you revisit a node in the current DFS path, a cycle exists.
   - See code below:

   ```
   // DFS-based cycle detection for directed graph
   bool checkCycleDFS(int node, unordered_map<int,bool>& visited, unordered_map<int,bool>& dfsVisited, unordered_map<int,list<int>>& adjList) {
       visited[node] = true;
       dfsVisited[node] = true;
       for(auto nbr : adjList[node]) {
           if(!visited[nbr]) {
               if(checkCycleDFS(nbr, visited, dfsVisited, adjList))
                   return true;
           } else if(dfsVisited[nbr]) {
               // Found a back edge, cycle exists
               return true;
           }
       }
       dfsVisited[node] = false; // Backtrack
       return false;
   }
   ```

2. **Disjoint Set (Union-Find) for Undirected Graphs:**
   - Not suitable for directed graphs, but very efficient for undirected graphs.

3. **BFS/DFS for Undirected Graphs:**
   - Use parent tracking to avoid false positives.

Implementation:
---------------
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

// Graph class for generic data types
template<typename T>
class Graph {
public:
    unordered_map<T, list<T>> adjList; // Adjacency list

    // Function to add an edge to the graph
    void addEdge(T u, T v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed
        adjList[u].push_back(v); // Add edge from u to v
        if(direction == 0)
            adjList[v].push_back(u); // If undirected, add edge from v to u
    }

    // Function to print the adjacency list (for debugging)
    void printAdjList() {
        for(auto node : adjList) {
            cout << node.first << "-> ";
            for(auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // Kahn's Algorithm for Topological Sort (also detects cycle)
    bool topoSort(int n, vector<T>& ans) {
        queue<T> q; // Queue for BFS
        unordered_map<T, int> indegree; // Stores indegree of each node

        // Calculate indegree for each node
        for(auto i : adjList) {
            T src = i.first;
            for(auto nbr : i.second) {
                indegree[nbr]++;
            }
        }

        // Put nodes in queue having indegree = 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        // BFS logic for topological sort
        while(!q.empty()) {
            T frontNode = q.front();
            q.pop();
            ans.push_back(frontNode); // Add node to topological order

            // Reduce indegree of neighbors
            for(auto nbr : adjList[frontNode]) {
                indegree[nbr]--;
                // If indegree becomes 0, add to queue
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // If all nodes are in ans, no cycle; else, cycle exists
        return (ans.size() == n);
    }
};

int main() {
    int n = 8; // Number of nodes
    Graph<int> g;

    // Example edges (directed graph)
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    // Uncomment below to introduce a cycle:
    // g.addEdge(7, 3, 1);

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    vector<int> topoOrder;
    bool isAcyclic = g.topoSort(n, topoOrder);

    if(isAcyclic) {
        cout << "Topological Sort Order: ";
        for(int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
        cout << "No cycle detected in the graph." << endl;
    } else {
        cout << "Cycle detected in the graph. Topological sort not possible." << endl;
    }

    return 0;
}

/*
Dry Run Example:
----------------
Graph:
0 -> 1
1 -> 2
2 -> 3
3 -> 4, 5
4 -> 6
5 -> 6
6 -> 7

Step 1: Calculate indegree for each node:
0: 0
1: 1
2: 1
3: 1
4: 1
5: 1
6: 2
7: 1

Step 2: Queue starts with node 0 (indegree 0)
Process 0 -> 1 -> 2 -> 3 -> 4,5 -> 6 -> 7

All nodes processed, so no cycle.

If you add edge 7->3:
- 3's indegree increases, so it never reaches indegree 0.
- Not all nodes are processed, so a cycle is detected.
*/
