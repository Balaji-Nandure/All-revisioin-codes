/*
    Approach Used: 
    ----------------
    This code implements Topological Sort using Depth First Search (DFS) for a Directed Acyclic Graph (DAG).
    The main idea is to perform DFS traversal and, after visiting all descendants of a node, push the node onto a stack.
    At the end, popping from the stack gives the topological order.

    Key Points:
    - Only works for DAGs (Directed Acyclic Graphs).
    - Uses recursion and a stack to store the result.
    - Uses a visited map to avoid revisiting nodes.

    Better Alternative:
    -------------------
    Kahn's Algorithm (BFS based) is another popular approach for topological sorting.
    It uses in-degree of nodes and a queue, and is often preferred for its iterative nature and ability to detect cycles.
    (Kahn's Algorithm code is provided in comments at the end.)

    Dry Run:
    --------
    For the given graph:
    0 -> 1 -> 2 -> 3 -> 4 -> 6 -> 7
                        \-> 5 -> 6
    The topological order will be: 0 1 2 3 5 4 6 7

    Each node is pushed to the stack after all its descendants are visited.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

// Template Graph class to support generic node types
template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList; // Adjacency list representation

        // Function to add an edge to the graph
        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected
            // direction = 1 -> directed 
            adjList[u].push_back(v); // Always add edge from u to v
            if(direction == 0)
                adjList[v].push_back(u); // If undirected, add edge from v to u
        }

        // Utility function to print adjacency list (for debugging)
        void printAdjList(){
            for(auto node : adjList){
                cout << node.first << "-> ";
                for(auto neighbours : node.second){
                    cout << neighbours << ", ";
                }
                cout << endl;
            }
        }

        // Recursive function for DFS-based Topological Sort
        void topoSort(int src, unordered_map<int, bool>& visited, stack<int>& ans){
            visited[src] = true; // Mark current node as visited

            // Visit all unvisited neighbours (DFS)
            for(auto neighbour : adjList[src]){
                if(!visited[neighbour]){
                    topoSort(neighbour, visited, ans);
                }
            }
            // After visiting all descendants, push current node to stack
            ans.push(src);
        }
};

int main(){
    Graph<int> g;

    // Adding edges to the graph (Directed edges)
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);

    stack<int> ans; // Stack to store topological order
    unordered_map<int, bool> visited; // Map to keep track of visited nodes

    // Perform DFS-based Topological Sort for all nodes (handles disconnected graphs)
    for(int i = 0; i < 8; i++){
        if(!visited[i]){
            g.topoSort(i, visited, ans);
        }
    }

    // Print the topological sort (by popping from stack)
    cout << "Topological Sort (DFS): ";
    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    /*
    // Alternative: Kahn's Algorithm (BFS-based Topological Sort)
    // ----------------------------------------------------------
    // This approach is iterative and can also detect cycles.
    // Uncomment to use.

    // Kahn's Algorithm Implementation:
    unordered_map<int, int> indegree;
    // Calculate indegree of each node
    for(auto node : g.adjList){
        if(indegree.find(node.first) == indegree.end())
            indegree[node.first] = 0;
        for(auto neighbour : node.second){
            indegree[neighbour]++;
        }
    }
    queue<int> q;
    // Push all nodes with indegree 0
    for(int i = 0; i < 8; i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    vector<int> topoOrder;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        topoOrder.push_back(front);
        for(auto neighbour : g.adjList[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    cout << "Topological Sort (Kahn's Algorithm): ";
    for(auto node : topoOrder){
        cout << node << " ";
    }
    cout << endl;
    */

    /*
    Dry Run:
    --------
    Stack (after each push): [7], [6,7], [4,6,7], [5,4,6,7], [3,5,4,6,7], [2,3,5,4,6,7], [1,2,3,5,4,6,7], [0,1,2,3,5,4,6,7]
    Output: 0 1 2 3 5 4 6 7
    */

    return 0;
}