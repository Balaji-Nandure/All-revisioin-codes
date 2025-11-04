/*
Approach Used:
--------------
This code detects a cycle in a **directed graph** using **Kahn's Algorithm** (BFS-based Topological Sort).
- The main idea is: If the number of nodes in the topological order is less than the total number of nodes, then a cycle exists.
- Why? Because nodes involved in a cycle will never have indegree 0, so they can't be added to the topological order.

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

- All nodes can be sorted topologically (no cycle).
- If you add an edge 7 -> 3, a cycle is formed (3->4->6->7->3).

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

// Template class for generic graph
template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList; // Adjacency list

        // Function to add an edge to the graph
        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed
            adjList[u].push_back(v); // Add edge from u to v
            if(direction == 0)
                adjList[v].push_back(u); // If undirected, add edge from v to u
        }

        // Function to print the adjacency list (for debugging)
        void printAdjList(){
            for(auto node : adjList){
                cout << node.first << "-> ";
                for(auto neighbour : node.second){
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }

        // Kahn's Algorithm for Topological Sort (also detects cycle)
        void topoSort(int n, vector<int>& ans){
            queue<int> q; // Queue for BFS
            unordered_map<int, int> indegree; // Stores indegree of each node

            // Initialize indegree of all nodes to 0
            for(int i = 0; i < n; i++){
                indegree[i] = 0;
            }

            // Calculate indegree for each node
            for(auto i : adjList){
                int src = i.first;
                for(auto nbr : i.second){
                    indegree[nbr]++; // Increment indegree for each neighbor
                }
            }

            // Push all nodes with indegree 0 into the queue
            for(int i = 0; i < n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }

            // BFS logic for topological sort
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode); // Add node to topological order

                // For all neighbors, reduce indegree by 1
                for(auto nbr : adjList[frontNode]){
                    indegree[nbr]--;
                    // If indegree becomes 0, add to queue
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }
        }
};

int main(){
    Graph<int> g;

    // Add edges to the graph (directed)
    g.addEdge(0,1,1); // 0 -> 1
    g.addEdge(1,2,1); // 1 -> 2
    g.addEdge(2,3,1); // 2 -> 3
    g.addEdge(3,4,1); // 3 -> 4
    g.addEdge(3,5,1); // 3 -> 5
    g.addEdge(4,6,1); // 4 -> 6
    g.addEdge(5,6,1); // 5 -> 6
    g.addEdge(6,7,1); // 6 -> 7

    int n = 8; // Number of nodes (0 to 7)
    vector<int> ans; // Stores topological order

    // Run Kahn's Algorithm to get topological order
    g.topoSort(n, ans);

    // If topological order contains all nodes, no cycle exists
    if(ans.size() == n){
        cout << "No cycle present" << endl;
    }
    else{
        cout << "Cycle present" << endl;
    }

    // Optional: Print topological order
    cout << "Topological Order: ";
    for(int node : ans){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
Dry Run:
--------
Graph:
0 -> 1
1 -> 2
2 -> 3
3 -> 4, 5
4 -> 6
5 -> 6
6 -> 7

Step 1: Calculate indegree for all nodes:
0: 0
1: 1 (from 0)
2: 1 (from 1)
3: 1 (from 2)
4: 1 (from 3)
5: 1 (from 3)
6: 2 (from 4,5)
7: 1 (from 6)

Step 2: Queue starts with node 0 (indegree 0)
Process 0: ans = [0], queue = [1]
Process 1: ans = [0,1], queue = [2]
Process 2: ans = [0,1,2], queue = [3]
Process 3: ans = [0,1,2,3], queue = [4,5]
Process 4: ans = [0,1,2,3,4], queue = [5,6]
Process 5: ans = [0,1,2,3,4,5], queue = [6]
Process 6: ans = [0,1,2,3,4,5,6], queue = [7]
Process 7: ans = [0,1,2,3,4,5,6,7], queue = []

ans.size() == n (8), so No cycle present.

If you add an edge 7->3, indegree[3] becomes 2, and the process will not be able to process all nodes (cycle detected).
*/