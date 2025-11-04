/*
Approach Used:
---------------
We are detecting a cycle in an undirected graph using Breadth-First Search (BFS). 
The main idea is: 
- For each unvisited node, we start a BFS traversal.
- For each node, we keep track of its parent (from where it was discovered).
- If we encounter a visited neighbor that is not the parent, a cycle exists.

Key Points:
-----------
- We use an adjacency list to represent the graph.
- We use a visited map to keep track of visited nodes.
- We use a parent map to avoid considering the immediate parent as a cycle.
- We check for cycles in all components (disconnected graphs).

Better Alternatives:
--------------------
1. **DFS Approach**: DFS can also be used for cycle detection in undirected graphs. 
   - It is often more concise and can be implemented recursively.
   - See code in comments below.

2. **Disjoint Set (Union-Find)**: For static graphs, Union-Find is efficient for cycle detection.
   - Especially useful for edge-list representation.
   - See code in comments below.

*/

// Include necessary headers
#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Graph class using adjacency list
template<typename T>
class Graph{
    public:
        unordered_map<T,list<T>>adjList; // Adjacency list to store graph

        // Function to add an edge to the graph
        void addEdge(T u,T v,bool direction){
            // direction = 0 -> undirected, direction = 1 -> directed 
            adjList[u].push_back(v); // Add edge from u to v
            if(direction == 0)
                adjList[v].push_back(u); // If undirected, add edge from v to u
        }

        // Function to print adjacency list (for debugging)
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }

        // Function to check for cycle in an undirected graph using BFS
        bool checkCycle(int src,unordered_map<int,bool>&visited){
            queue<int>q; // Queue for BFS
            unordered_map<int,int>parent; // To keep track of parent nodes

            q.push(src); // Start BFS from source node
            visited[src] = true; // Mark source as visited
            parent[src] = -1; // Source has no parent

            while(!q.empty()){
                int frontNode = q.front(); // Get the front node
                q.pop();

                // Traverse all adjacent nodes
                for(auto neighbour : adjList[frontNode]){
                    if(!visited[neighbour]){
                        // If neighbour is not visited, push to queue and set parent
                        q.push(neighbour);
                        visited[neighbour] = true;
                        parent[neighbour] = frontNode;
                    }
                    else{
                        // If already visited and not parent, cycle detected
                        if(neighbour != parent[frontNode]){
                            return true; // Cycle present
                        }
                    }
                }
            }
            return false; // No cycle found
        }
};

int main(){
    Graph<int>g;

    // Add edges to the graph (undirected)
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);

    int n = 5; // Number of nodes
    bool ans = false; // To store if cycle is present
    unordered_map<int,bool>visited; // To keep track of visited nodes

    // Check for cycle in all components (handles disconnected graphs)
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            ans = g.checkCycle(i,visited);
            if(ans == true)
                break; // If cycle found, break early
        }
    }

    // Output result
    if(ans == true)
        cout<<"Cycle is present";
    else    
        cout<<"Cycle not present";
    return 0;
}

/*
-------------------------------
Alternative 1: DFS Approach
-------------------------------
bool dfs(int node, int parent, unordered_map<int,bool>&visited, unordered_map<int,list<int>>&adjList) {
    visited[node] = true;
    for(auto neighbour : adjList[node]) {
        if(!visited[neighbour]) {
            if(dfs(neighbour, node, visited, adjList))
                return true;
        } else if(neighbour != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

-------------------------------
Alternative 2: Disjoint Set (Union-Find)
-------------------------------
class DisjointSet {
    vector<int> parent;
public:
    DisjointSet(int n) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x) {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    bool unionSet(int x, int y) {
        int px=find(x), py=find(y);
        if(px==py) return true; // Cycle detected
        parent[px]=py;
        return false;
    }
};
// Usage: For each edge (u,v), if unionSet(u,v) returns true, cycle exists.

-------------------------------
Dry Run (for given main):
-------------------------------
Graph:
0-1-2-3-4-0 (cycle)

Step-by-step:
- Start BFS from node 0.
- Visit 0, queue: [0], parent: -1
- Visit 1 from 0, queue: [1], parent: 0
- Visit 4 from 0, queue: [1,4], parent: 0
- Visit 2 from 1, queue: [4,2], parent: 1
- Visit 3 from 2, queue: [4,3], parent: 2
- Visit 4 from 3, already visited and not parent => cycle detected.

Output: "Cycle is present"
*/