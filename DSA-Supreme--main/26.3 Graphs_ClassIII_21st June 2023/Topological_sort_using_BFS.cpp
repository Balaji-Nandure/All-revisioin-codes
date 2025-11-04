/*
    Approach Used: 
    ----------------
    This code implements Topological Sort using Kahn's Algorithm (BFS approach) for Directed Acyclic Graphs (DAGs).
    The main idea is to repeatedly remove nodes with indegree 0 and update the indegrees of their neighbors.

    Steps:
    1. Build the adjacency list for the graph.
    2. Calculate indegree (number of incoming edges) for each node.
    3. Push all nodes with indegree 0 into a queue.
    4. While the queue is not empty:
        a. Pop a node, add it to the result.
        b. Decrease indegree of its neighbors by 1.
        c. If any neighbor's indegree becomes 0, push it into the queue.
    5. The result is a valid topological ordering.

    Alternative Approach:
    ---------------------
    - Topological Sort using DFS:
        - Perform DFS traversal, and on returning from recursion, push the node to a stack.
        - At the end, pop all elements from the stack for the topological order.
        - This approach is more memory efficient for sparse graphs and can be implemented recursively.

    // DFS-based Topological Sort (Alternative)
    /*
    void dfs(int node, unordered_map<int, bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, st);
            }
        }
        st.push(node);
    }
    void topoSortDFS(int n, vector<int>& ans) {
        unordered_map<int, bool> visited;
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
    }
    */

    // Kahn's Algorithm is preferred for cycle detection and is iterative (no stack overflow risk).
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<vector>
using namespace std;

template<typename T>
class Graph{
    public:
        unordered_map<T, list<T>> adjList; // Adjacency list representation

        // Adds an edge to the graph
        void addEdge(T u, T v, bool direction){
            // direction = 0 -> undirected, direction = 1 -> directed
            adjList[u].push_back(v); // Always add edge from u to v
            if(direction == 0)
                adjList[v].push_back(u); // If undirected, add edge from v to u
        }

        // Prints the adjacency list of the graph
        void printAdjList(){
            for(auto node : adjList){
                cout << node.first << "-> ";
                for(auto neighbours : node.second){
                    cout << neighbours << ", ";
                }
                cout << endl;
            }
        }

        // Topological Sort using Kahn's Algorithm (BFS)
        void topoSort(int n, vector<int>& ans){
            queue<int> q; // Queue for BFS
            unordered_map<int, int> indegree; // Stores indegree of each node

            // Initialize indegree of all nodes to 0
            for(int i = 0; i < n; i++) {
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

            // BFS traversal
            while(!q.empty()){
                int frontNode = q.front();
                q.pop();
                ans.push_back(frontNode); // Add node to topological order

                // Decrease indegree of all neighbors
                for(auto nbr : adjList[frontNode]){
                    indegree[nbr]--;
                    // If indegree becomes 0, add to queue
                    if(indegree[nbr] == 0){
                        q.push(nbr);
                    }
                }
            }

            // If topological sort does not include all nodes, there is a cycle
            if(ans.size() != n) {
                cout << "\nCycle detected! Topological sort not possible.\n";
                ans.clear();
            }
        }
};

int main(){
    Graph<int> g;

    // Constructing the graph (Directed edges)
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    int n = 8; // Number of nodes (0 to 7)
    vector<int> ans; // To store topological order

    // Call topological sort
    g.topoSort(n, ans);

    // Print the result
    cout << "Topological Sort (Kahn's Algorithm): ";
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

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

    Step 1: Calculate indegree
    0: 0
    1: 1 (from 0)
    2: 1 (from 1)
    3: 1 (from 2)
    4: 1 (from 3)
    5: 1 (from 3)
    6: 2 (from 4,5)
    7: 1 (from 6)

    Step 2: Queue initialization
    Queue: [0]

    Step 3: BFS
    Pop 0 -> ans: [0], decrease indegree[1] to 0, push 1
    Pop 1 -> ans: [0,1], decrease indegree[2] to 0, push 2
    Pop 2 -> ans: [0,1,2], decrease indegree[3] to 0, push 3
    Pop 3 -> ans: [0,1,2,3], decrease indegree[4] to 0, push 4; indegree[5] to 0, push 5
    Pop 4 -> ans: [0,1,2,3,4], decrease indegree[6] to 1
    Pop 5 -> ans: [0,1,2,3,4,5], decrease indegree[6] to 0, push 6
    Pop 6 -> ans: [0,1,2,3,4,5,6], decrease indegree[7] to 0, push 7
    Pop 7 -> ans: [0,1,2,3,4,5,6,7]

    Final Topological Order: 0 1 2 3 4 5 6 7
    */
    return 0;
}