/*
================================================================================
Depth First Search (DFS) in Graphs - C++ Implementation
================================================================================

Approach:
---------
- We represent a graph using an adjacency list (unordered_map<T, list<T>>).
- DFS is a recursive algorithm that starts at a source node and explores as far as possible along each branch before backtracking.
- We use a visited map to keep track of visited nodes to avoid cycles and repeated work.
- The code supports both directed and undirected graphs.

Key Points:
-----------
- addEdge: Adds an edge to the graph. If undirected, adds both u->v and v->u.
- printAdjList: Prints the adjacency list for visualization.
- dfs: Recursively visits all nodes reachable from the source node.
- In main, we ensure all components are covered (for disconnected graphs).

Alternatives:
-------------
1. **Iterative DFS using stack** (avoids recursion stack overflow for very deep graphs):
   ```
   void dfsIterative(int src, unordered_map<int,bool>& visited) {
       stack<int> s;
       s.push(src);
       while(!s.empty()) {
           int node = s.top();
           s.pop();
           if(!visited[node]) {
               cout << node << " ";
               visited[node] = true;
               for(auto neighbour : adjList[node]) {
                   if(!visited[neighbour])
                       s.push(neighbour);
               }
           }
       }
   }
   ```
2. **Use vector<vector<int>> for dense graphs or contiguous node indices.**
3. **For weighted graphs, use list<pair<T, int>> in adjList.**

Dry Run Example:
----------------
Graph:
0--1--2
   |
   3
  / \
 5   7
    / \
   6   4

DFS starting from 0:
Visit 0 -> 1 -> 2 -> 3 -> 5 -> 7 -> 6 -> 4

================================================================================
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue> // Not used in DFS, but kept for possible BFS alternative
using namespace std;

// Template Graph class to support generic node types
template<typename T>
class Graph{
    public:
        unordered_map<T,list<T>>adjList;
        void addEdge(T u,T v,bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            // Create an edge from u to v
            adjList[u].push_back(v);
            // if undirected 
            if(direction == 0)
                adjList[v].push_back(u); // edge created from v to u    
        }
        void printAdjList(){
            for(auto node : adjList){
                cout<<node.first<<"-> ";
                for(auto neighbours : node.second){
                    cout<<neighbours<<", ";
                }
                cout<<endl;
            }
        }
        void dfs(int src,unordered_map<int,bool>&visited){
            cout<<src<<" ";
            visited[src] = true;
            for(auto neighbour : adjList[src]){
                if(!visited[neighbour]){
                    dfs(neighbour,visited);
                }
            }
        }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,5,0);
    g.addEdge(3,7,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);
    unordered_map<int,bool>visited;
    for(int i = 0;i<7;i++){
        if(!visited[i]){
            g.dfs(i,visited);
        }
    }
    return 0;
}