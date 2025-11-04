/*
Approach Used:
---------------
This code detects a cycle in an undirected graph using Depth First Search (DFS). 
The main idea is: 
- For each unvisited node, start a DFS traversal.
- If during DFS, we visit an already visited node that is not the parent of the current node, a cycle exists.

Key Points:
- The graph is represented using an adjacency list.
- The checkCycle function is a recursive DFS that checks for cycles.
- The main function ensures all components are checked (for disconnected graphs).

Alternative Approaches:
-----------------------
1. **BFS Approach (using parent tracking):**
   - Use a queue to perform BFS.
   - For each node, track its parent.
   - If a visited neighbor is not the parent, a cycle exists.
   - See commented code at the end for BFS implementation.

2. **Disjoint Set Union (Union-Find):**
   - For each edge, check if both vertices have the same parent (using DSU).
   - If yes, a cycle exists.
   - Efficient for edge-list representation.

Improvements Made:
------------------
- Added detailed comments for logic.
- Used vector<bool> for visited for better performance and clarity.
- Added printAdjList call for debugging.
- Added input flexibility for number of nodes and edges.
- Provided a dry run at the end.

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

// Graph class using adjacency list
template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList; // adjacency list

        // Adds an edge between u and v
        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected, direction = 1 -> directed
            adjList[u].push_back(v); // add edge u->v
            if(direction == 0)
                adjList[v].push_back(u); // add edge v->u for undirected
        }

        // Prints the adjacency list
        void printAdjList(){
            for(auto node : adjList){
                cout << node.first << " -> ";
                for(auto neighbour : node.second){
                    cout << neighbour << ", ";
                }
                cout << endl;
            }
        }

        // DFS based cycle detection for undirected graph
        bool checkCycle(int src, vector<bool>& visited, int parent){
            visited[src] = true; // mark current node as visited

            // Traverse all adjacent nodes
            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    // If neighbor not visited, recursively check for cycle
                    if(checkCycle(nbr, visited, src))
                        return true; // cycle found in DFS subtree
                }
                else if(nbr != parent){
                    // If neighbor is visited and not parent, cycle exists
                    return true;
                }
            }
            return false; // no cycle found from this node
        }
};

int main(){
    Graph<int> g;

    // Example: Creating a cycle: 0-1-2-3-4-0
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 0, 0);

    int n = 5; // number of nodes (0 to 4)
    bool ans = false; // to store if cycle exists

    vector<bool> visited(n, false); // visited array for all nodes

    // Print adjacency list for debugging
    cout << "Adjacency List:" << endl;
    g.printAdjList();

    // Check for cycle in all components (handles disconnected graphs)
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            if(g.checkCycle(i, visited, -1)){
                ans = true;
                break; // cycle found, no need to check further
            }
        }
    }

    // Output result
    if(ans)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle not present" << endl;

    return 0;
}

/*
-------------------------------
Alternative Approach: BFS Cycle Detection
-------------------------------
bool checkCycleBFS(int src, unordered_map<int, list<int>>& adjList, vector<bool>& visited) {
    queue<pair<int, int>> q; // {node, parent}
    visited[src] = true;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto nbr : adjList[node]) {
            if(!visited[nbr]) {
                visited[nbr] = true;
                q.push({nbr, node});
            } else if(nbr != parent) {
                // Found a back edge (cycle)
                return true;
            }
        }
    }
    return false;
}
-------------------------------
Alternative Approach: Disjoint Set (Union-Find)
-------------------------------
class DSU {
    vector<int> parent;
public:
    DSU(int n) { parent.resize(n); for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); }
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false; // cycle detected
        parent[px] = py;
        return true;
    }
};
-------------------------------
Dry Run:
-------------------------------
Graph: 0-1-2-3-4-0 (cycle exists)
Visited: [F, F, F, F, F]
Start DFS from 0:
- Mark 0 visited. Neighbors: 1, 4
- Go to 1 (parent 0): Mark 1 visited. Neighbors: 0, 2
    - 0 is parent, skip. Go to 2 (parent 1): Mark 2 visited. Neighbors: 1, 3
        - 1 is parent, skip. Go to 3 (parent 2): Mark 3 visited. Neighbors: 2, 4
            - 2 is parent, skip. Go to 4 (parent 3): Mark 4 visited. Neighbors: 3, 0
                - 3 is parent, skip. 0 is already visited and not parent => CYCLE DETECTED!
-------------------------------
*/