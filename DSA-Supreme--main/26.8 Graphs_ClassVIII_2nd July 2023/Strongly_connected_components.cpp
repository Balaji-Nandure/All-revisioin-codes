/*
    Approach Used: Kosaraju's Algorithm for finding Strongly Connected Components (SCCs) in a directed graph.

    Steps:
    1. Do a DFS traversal of the original graph and push nodes onto a stack in the order of their finishing times (topological sort order).
    2. Reverse all the edges of the graph to get the transpose graph.
    3. Do DFS traversal of the transpose graph in the order defined by the stack. Each DFS traversal gives one SCC.

    Time Complexity: O(V + E)
    Space Complexity: O(V + E)

    Alternatives:
    - Tarjan's Algorithm: Finds SCCs in a single DFS traversal using low-link values. More efficient in practice, especially for online queries.
    - Kosaraju's is easier to implement and understand for most use-cases.

    See end of file for a dry run on the provided graph.

    Below, all important lines are commented for clarity.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
using namespace std;

class Graph{
public:
    unordered_map<int, list<int>> adjList; // Adjacency list representation

    // Adds an edge to the graph
    void addEdge(int u, int v, bool direction) {
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back(v);
        if (direction == 1) {
            adjList[v].push_back(u);
        }
    }

    // Utility function to print adjacency list (not used in SCC logic)
    void printAdjList() {
        for (auto i : adjList) {
            cout << i.first << "->";
            for (auto j : i.second) {
                cout << "(" << j << "," << j << "), ";
            }
            cout << endl;
        }
    }

    // First DFS: Fills stack with vertices in order of finishing times
    void dfs1(int src, stack<int>& s, unordered_map<int, bool>& vis) {
        vis[src] = true; // Mark current node as visited

        for (auto nbr : adjList[src]) {
            if (!vis[nbr]) {
                dfs1(nbr, s, vis); // Visit all unvisited neighbors
            }
        }
        s.push(src); // Push to stack after visiting all descendants (postorder)
    }

    // Second DFS: Traverses the reversed graph to collect SCC
    void dfs2(int src, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adjNew) {
        visited[src] = true; // Mark current node as visited
        cout << src << ", "; // Print node as part of current SCC

        for (auto nbr : adjNew[src]) {
            if (!visited[nbr]) {
                dfs2(nbr, visited, adjNew); // Visit all unvisited neighbors in reversed graph
            }
        }
    }

    // Main function to count and print all SCCs using Kosaraju's Algorithm
    int countSCC(int n) {
        stack<int> s; // Stack to store order of nodes by finishing time
        unordered_map<int, bool> visited;

        // 1. Perform DFS for all nodes to fill stack according to finishing times
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, s, visited);
            }
        }

        // 2. Reverse all edges to get the transpose graph
        unordered_map<int, list<int>> adjNew; // Transposed graph
        for (auto t : adjList) {
            for (auto nbr : t.second) {
                int u = t.first;
                int v = nbr;
                adjNew[v].push_back(u); // Reverse the edge
            }
        }

        // 3. Do DFS on transposed graph in order defined by stack
        int count = 0; // To count number of SCCs
        unordered_map<int, bool> visited2; // Visited map for second DFS

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            if (!visited2[node]) {
                cout << "Printing " << count + 1 << "th SCC: ";
                dfs2(node, visited2, adjNew); // Print all nodes in this SCC
                cout << endl;
                count++;
            }
        }
        return count;
    }
};

/*
    Alternative Approach: Tarjan's Algorithm (Single DFS, O(V+E))
    --------------------------------------------------------------
    // Uncomment and use this code for Tarjan's Algorithm

    // #include<vector>
    // class TarjanSCC {
    // public:
    //     vector<vector<int>> adj;
    //     vector<int> ids, low;
    //     vector<bool> onStack;
    //     stack<int> st;
    //     int id, sccCount;
    //     vector<vector<int>> sccs;
    //     TarjanSCC(int n) : adj(n), ids(n, -1), low(n, 0), onStack(n, false), id(0), sccCount(0) {}
    //     void addEdge(int u, int v) { adj[u].push_back(v); }
    //     void dfs(int at) {
    //         st.push(at);
    //         onStack[at] = true;
    //         ids[at] = low[at] = id++;
    //         for (int to : adj[at]) {
    //             if (ids[to] == -1) dfs(to);
    //             if (onStack[to]) low[at] = min(low[at], low[to]);
    //         }
    //         if (ids[at] == low[at]) {
    //             vector<int> scc;
    //             while (true) {
    //                 int node = st.top(); st.pop();
    //                 onStack[node] = false;
    //                 scc.push_back(node);
    //                 if (node == at) break;
    //             }
    //             sccs.push_back(scc);
    //             sccCount++;
    //         }
    //     }
    //     int getSCCs(int n) {
    //         for (int i = 0; i < n; i++) if (ids[i] == -1) dfs(i);
    //         return sccCount;
    //     }
    // };

    // Usage:
    // TarjanSCC t(8);
    // t.addEdge(0,1); t.addEdge(1,2); ... etc
    // cout << t.getSCCs(8);

    // Tarjan's is more efficient for online queries and doesn't require reversing the graph.

*/

int main() {
    Graph g;
    // Constructing the directed graph as per the example
    g.addEdge(0, 1, 0); // 0 -> 1
    g.addEdge(1, 2, 0); // 1 -> 2
    g.addEdge(2, 3, 0); // 2 -> 3
    g.addEdge(3, 0, 0); // 3 -> 0 (cycle: 0-1-2-3-0)
    g.addEdge(2, 4, 0); // 2 -> 4
    g.addEdge(4, 5, 0); // 4 -> 5
    g.addEdge(5, 6, 0); // 5 -> 6
    g.addEdge(6, 4, 0); // 6 -> 4 (cycle: 4-5-6-4)
    g.addEdge(6, 7, 0); // 6 -> 7

    cout << "Total SCCs: " << g.countSCC(8) << endl;
    return 0;
}

/*
    Dry Run for the given graph:
    ----------------------------
    Nodes: 0,1,2,3,4,5,6,7
    Edges: 0->1, 1->2, 2->3, 3->0, 2->4, 4->5, 5->6, 6->4, 6->7

    Step 1: DFS order (finishing times):
        Possible stack (top to bottom): 7,6,4,5,2,3,1,0

    Step 2: Reverse edges:
        1->0, 2->1, 3->2, 0->3, 4->2, 5->4, 6->5, 4->6, 7->6

    Step 3: DFS on reversed graph in stack order:
        - Start at 0: visits 0,3,2,1 (SCC 1: 0,3,2,1)
        - Next unvisited: 4: visits 4,6,5 (SCC 2: 4,6,5)
        - Next unvisited: 7 (SCC 3: 7)

    Output:
        Printing 1th SCC: 0, 3, 2, 1,
        Printing 2th SCC: 4, 6, 5,
        Printing 3th SCC: 7,
        Total SCCs: 3

    Thus, the code correctly finds all SCCs.
*/