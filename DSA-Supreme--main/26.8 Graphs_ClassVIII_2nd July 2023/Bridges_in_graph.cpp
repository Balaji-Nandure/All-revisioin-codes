/*
    Approach Used:
    ----------------
    - The code implements Tarjan's Algorithm to find all bridges in an undirected graph.
    - A bridge is an edge whose removal increases the number of connected components in the graph.
    - The algorithm uses DFS traversal and maintains two arrays:
        - tin[]: Time of insertion (discovery time) for each node.
        - low[]: The lowest discovery time reachable from the subtree rooted at that node (including back edges).
    - If for an edge u-v, low[v] > tin[u], then u-v is a bridge.

    Better Alternatives:
    ---------------------
    - Use vector<vector<int>> instead of unordered_map<int, list<int>> for adjacency list if nodes are 0...n-1 for better cache locality and speed.
    - Use a single vector<bool> for visited instead of unordered_map for better performance.
    - Return bridges as a vector<pair<int,int>> instead of printing inside DFS for more flexibility.
    - Use iterative DFS for very large graphs to avoid stack overflow.
    - For multiple components, run DFS from all unvisited nodes.

    See detailed alternative code and dry run at the end.
*/

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>>adjList; // Adjacency list representation

    // Adds an edge to the graph
    void addEdge(int u,int v,bool direction){
        // direction = 1 -> undirected, direction = 0 -> directed
        adjList[u].push_back(v); // Add v to u's list
        if(direction == 1){
            adjList[v].push_back(u); // For undirected, add u to v's list
        }
    }

    // Prints the adjacency list of the graph
    void printAdjList(){
        for(auto i : adjList){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<"("<<j<<","<<j<<"), ";
            }
            cout<<endl;
        }
    }

    // Tarjan's Algorithm to find bridges in the graph
    void findBridges(int src,int parent,int &timer,vector<int>&tin,vector<int>&low,unordered_map<int,bool>&visited){
        timer++; // Increment timer for discovery time
        visited[src] = true; // Mark current node as visited
        tin[src] = timer;    // Set discovery time for src
        low[src] = timer;    // Initialize low time for src

        // Traverse all adjacent nodes
        for(auto nbr : adjList[src]){
            // If neighbor is parent, skip to avoid trivial cycle
            if(nbr == parent)
                continue;
            if(!visited[nbr]){
                // If neighbor not visited, do DFS
                findBridges(nbr,src,timer,tin,low,visited);

                // After returning, update low time for src
                low[src] = min(low[src],low[nbr]);

                // If the lowest reachable time from nbr is greater than discovery time of src, it's a bridge
                if(low[nbr] > tin[src])
                    cout<<src<<"--"<<nbr<<" is a bridge"<<endl;
            }
            else{
                // If neighbor is already visited and not parent, update low[src] (back edge)
                low[src] = min(low[src],tin[nbr]);
            }
        }
    }

    // Improved version: returns all bridges as vector of pairs
    void findAllBridges(int n, vector<pair<int,int>>& bridges) {
        vector<int> tin(n, -1), low(n, -1);
        vector<bool> visited(n, false);
        int timer = 0;
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                dfsBridge(i, -1, timer, tin, low, visited, bridges);
            }
        }
    }
    // Helper for improved version
    void dfsBridge(int src, int parent, int &timer, vector<int>& tin, vector<int>& low, vector<bool>& visited, vector<pair<int,int>>& bridges) {
        visited[src] = true;
        tin[src] = low[src] = timer++;
        for(int nbr : adjList[src]) {
            if(nbr == parent) continue;
            if(!visited[nbr]) {
                dfsBridge(nbr, src, timer, tin, low, visited, bridges);
                low[src] = min(low[src], low[nbr]);
                if(low[nbr] > tin[src]) {
                    bridges.push_back({src, nbr});
                }
            } else {
                low[src] = min(low[src], tin[nbr]);
            }
        }
    }
};

int main(){
    Graph g;
    // Constructing the graph
    g.addEdge(1,0,1); // Add edge 1-0 (undirected)
    g.addEdge(1,2,1); // Add edge 1-2 (undirected)
    g.addEdge(2,0,1); // Add edge 2-0 (undirected)
    g.addEdge(0,3,1); // Add edge 0-3 (undirected)
    g.addEdge(3,4,1); // Add edge 3-4 (undirected)

    int n = 5; // Number of nodes (0 to 4)
    int timer = 0; // Timer for discovery time
    vector<int>tin(n,-1); // Discovery time for each node
    vector<int>low(n,-1); // Lowest discovery time reachable from subtree
    unordered_map<int,bool>visited; // Visited map

    // Find and print all bridges using Tarjan's Algorithm
    g.findBridges(0,-1,timer,tin,low,visited);

    // Alternative: Get all bridges as a vector
    /*
    vector<pair<int,int>> bridges;
    g.findAllBridges(n, bridges);
    cout << "All bridges: ";
    for(auto &b : bridges) {
        cout << b.first << "--" << b.second << " ";
    }
    cout << endl;
    */

    return 0;
}

/*
    Dry Run:
    ---------
    Graph:
        0
       /|\
      1 2 3
            \
             4

    Edges: (1-0), (1-2), (2-0), (0-3), (3-4)

    DFS from 0:
    - Visit 0: tin[0]=1, low[0]=1
    - Visit 1: tin[1]=2, low[1]=2
        - 1->0 is parent, skip
        - Visit 2: tin[2]=3, low[2]=3
            - 2->1 is parent, skip
            - 2->0 already visited, update low[2]=min(3,1)=1
        - After 2, low[1]=min(2,1)=1
    - After 1, low[0]=min(1,1)=1
    - Visit 3: tin[3]=4, low[3]=4
        - 3->0 is parent, skip
        - Visit 4: tin[4]=5, low[4]=5
            - 4->3 is parent, skip
        - After 4, low[3]=min(4,5)=4
        - Since low[4]>tin[3] (5>4), 3--4 is a bridge
    - After 3, low[0]=min(1,4)=1
    - Since low[3]>tin[0] (4>1), 0--3 is a bridge

    Output:
    3--4 is a bridge
    0--3 is a bridge

    (Edges 0-3 and 3-4 are bridges. Removing either increases the number of connected components.)

    Alternative Approach (vector<vector<int>>):
    -------------------------------------------
    // For 0-based nodes and known n:
    class Graph {
        vector<vector<int>> adj;
    public:
        Graph(int n) : adj(n) {}
        void addEdge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        void findBridges() {
            int n = adj.size(), timer = 0;
            vector<int> tin(n, -1), low(n, -1);
            vector<bool> vis(n, false);
            vector<pair<int,int>> bridges;
            function<void(int,int)> dfs = [&](int u, int p) {
                vis[u]=true; tin[u]=low[u]=timer++;
                for(int v: adj[u]) {
                    if(v==p) continue;
                    if(!vis[v]) {
                        dfs(v,u);
                        low[u]=min(low[u],low[v]);
                        if(low[v]>tin[u]) bridges.push_back({u,v});
                    } else {
                        low[u]=min(low[u],tin[v]);
                    }
                }
            };
            for(int i=0;i<n;++i) if(!vis[i]) dfs(i,-1);
            for(auto& b: bridges) cout<<b.first<<"--"<<b.second<<" is a bridge\n";
        }
    };
*/