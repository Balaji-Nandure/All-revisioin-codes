/*
Approach Used:
---------------
We are detecting a cycle in a directed graph using Depth First Search (DFS). 
The main idea is to use two hash maps:
    1. visited: to keep track of all nodes that have been visited in any DFS traversal.
    2. dfsVisited: to keep track of nodes in the current DFS path (recursion stack).
If we encounter a node that is already in the current DFS path (i.e., dfsVisited[node] == true), 
then there is a cycle.

Better Alternatives:
--------------------
1. Kahn's Algorithm (BFS based, Topological Sort):
   - If the number of nodes in the topological order is less than the total number of nodes, 
     then there is a cycle.
   - More suitable for large graphs and when you want to find topological order as well.
   - See commented code at the end for Kahn's Algorithm.

2. Using vector<bool> instead of unordered_map for better performance if node values are 0...n-1.

3. Using adjacency list as vector<vector<int>> for dense graphs.

Dry Run:
---------
Graph:
0 -> 1
1 -> 2
2 -> 3
3 -> 4
4 -> 2

DFS from 0: 0->1->2->3->4
At 4, neighbor 2 is already in the current DFS path (dfsVisited[2] == true), so cycle detected.

*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// Template Graph class for generic data types
template<typename T>
class Graph{
    public:
        unordered_map<T,list<T>>adjList; // Adjacency list representation

        // Function to add an edge to the graph
        void addEdge(T u,T v,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            adjList[u].push_back(v); // Always add edge from u to v
            if(direction == 0)
                adjList[v].push_back(u); // If undirected, add edge from v to u
        }

        // Utility function to print adjacency list
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }

        // DFS based function to check for cycle in directed graph
        bool checkCycle(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited){
            visited[src] = true;      // Mark current node as visited
            dfsVisited[src] = true;   // Mark current node as part of current DFS path

            // Traverse all neighbors
            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    // If neighbor not visited, recursively visit
                    bool checkAns = checkCycle(nbr,visited,dfsVisited);
                    if(checkAns == true)
                        return true; // If cycle found in recursion, propagate true
                }
                else{
                    // If neighbor is visited and also in current DFS path, cycle detected
                    if(dfsVisited[nbr] == true){
                        return true;
                    }
                }
            }
            // Backtracking: remove current node from current DFS path
            dfsVisited[src] = false;
            return false; // No cycle found from this node
        }
};

int main(){
    Graph<int>g;

    // Adding edges to the graph (directed)
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(4,2,1); // This edge creates a cycle: 2->3->4->2

    int n = 5; // Number of nodes
    bool ans = false; // To store if cycle is present

    unordered_map<int,bool>visited;    // To keep track of visited nodes
    unordered_map<int,bool>dfsVisited; // To keep track of nodes in current DFS path

    // Check for cycle in all components of the graph
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            ans = g.checkCycle(i,visited,dfsVisited);
            if(ans == true)
                break; // If cycle found, no need to check further
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
-----------------------------------
Alternative Approach: Kahn's Algorithm (BFS, Topological Sort)
-----------------------------------
#include <vector>
#include <queue>
bool isCyclicKahn(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for(int u=0; u<n; ++u)
        for(int v: adj[u])
            indegree[v]++;
    queue<int> q;
    for(int i=0; i<n; ++i)
        if(indegree[i]==0) q.push(i);
    int cnt = 0;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        cnt++;
        for(int v: adj[node]) {
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    return cnt != n; // If not all nodes processed, cycle exists
}
-----------------------------------

Dry Run:
---------
Graph:
0 -> 1
1 -> 2
2 -> 3
3 -> 4
4 -> 2

DFS Traversal:
Start at 0:
visited[0]=true, dfsVisited[0]=true
  0->1: visited[1]=false
    visited[1]=true, dfsVisited[1]=true
      1->2: visited[2]=false
        visited[2]=true, dfsVisited[2]=true
          2->3: visited[3]=false
            visited[3]=true, dfsVisited[3]=true
              3->4: visited[4]=false
                visited[4]=true, dfsVisited[4]=true
                  4->2: visited[2]=true, dfsVisited[2]=true => CYCLE DETECTED

Output: "Cycle is present"
*/