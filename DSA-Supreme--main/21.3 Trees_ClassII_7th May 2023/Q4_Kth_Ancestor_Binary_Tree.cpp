/*
    Approach Used:
    ----------------
    - The code builds a binary tree from user input (using -1 as a marker for NULL/leaf).
    - It then finds the kth ancestor of a given node 'p' using a recursive function with backtracking.
    - The kthAncestor function traverses the tree to find node 'p', and then backtracks up the call stack, decrementing k at each ancestor. When k reaches 0, the current node is the kth ancestor.

    Better Alternatives:
    --------------------
    1. **Parent Mapping + Upward Traversal**:
        - Build a parent map (node -> parent) using BFS or DFS.
        - Once you find node 'p', move up k times using the parent map.
        - Time: O(N), Space: O(N)
        - See code in comments below.

    2. **Binary Lifting (for multiple queries, static tree)**:
        - Preprocess ancestors at powers of 2 for each node.
        - Answer kth ancestor queries in O(logN) time.
        - Useful for large trees and multiple queries.
        - See code in comments below.

    Dry Run Example at the end.
*/

// Include necessary headers
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for binary tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data; // Assign data to node
        left = NULL;       // Initialize left child as NULL
        right = NULL;      // Initialize right child as NULL
    }
};

// Function to build tree recursively from user input
Node *buildTree(int data)
{
    // Base Case: If data is -1, this is a NULL node (leaf)
    if (data == -1)
    {
        return NULL;
    }
    // Create the root node with given data
    Node *root = new Node(data);

    // Recursively build left subtree
    int leftData;
    cout << "Enter the data for left child of " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    // Recursively build right subtree
    int rightData;
    cout << "Enter the data for right child of " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    // Return the constructed subtree
    return root;
}

/*
    kthAncestor function:
    ---------------------
    - Finds the kth ancestor of node with value 'p' in the binary tree rooted at 'root'.
    - Uses recursion and backtracking.
    - k is passed by reference so it decrements as we backtrack.
    - When k == 0, we have found the kth ancestor.
    - Returns true if 'p' is found in the subtree, else false.
*/
bool kthAncestor(Node* root, int& k, int p) {
    if (root == NULL) {
        return false; // Base case: node not found
    }
    if (root->data == p) {
        return true; // Found the target node
    }

    // Search in left and right subtrees
    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // If found in either subtree, decrement k (backtracking step)
    if (leftAns || rightAns) {
        k--;
        // If k becomes 0, current node is the kth ancestor
        if (k == 0) {
            cout << "Ans = " << root->data << " ";
            k = -1; // To prevent further printing
        }
        return true; // Propagate true upwards
    }
    return false; // Not found in this path
}

int main()
{
    Node *root;
    int data;
    cout << "Enter data for root node" << endl;
    cin >> data;
    root = buildTree(data); // Build the binary tree

    int k, p;
    cout << "Enter value of k (which ancestor to find): ";
    cin >> k;
    cout << "Enter value of p (node to find ancestor for): ";
    cin >> p;

    bool found = kthAncestor(root, k, p);
    if (k > 0) {
        cout << "No such ancestor exists." << endl;
    }
    return 0;
}

/*
    -------------------------------
    Alternative 1: Parent Mapping
    -------------------------------
    // Build parent map using BFS
    unordered_map<Node*, Node*> parent;
    void buildParentMap(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        parent[root] = NULL;
        while (!q.empty()) {
            Node* curr = q.front(); q.pop();
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    // Find kth ancestor
    Node* kthAncestor(Node* root, int k, int p) {
        buildParentMap(root);
        // Find node with value p
        Node* target = findNode(root, p);
        while (k > 0 && target) {
            target = parent[target];
            k--;
        }
        return target;
    }

    -------------------------------
    Alternative 2: Binary Lifting
    -------------------------------
    // Preprocess ancestors at powers of 2 for each node
    // Useful for multiple queries, static tree
    // Not shown here due to complexity, but can be implemented using DP and parent table.

    -------------------------------
    Dry Run Example
    -------------------------------
    Input:
    Tree:      1
             /   \
            2     3
           / \   / \
          4   5 6   7
    k = 2, p = 4

    Steps:
    - Start at root (1), search for 4.
    - Go left to 2, then left to 4 (found).
    - Backtrack: at 2, k=2->1; at 1, k=1->0 (print 1).
    Output: Ans = 1

    -------------------------------
    Time Complexity:
    -------------------------------
    - O(N) in worst case (visit all nodes).
    - Space: O(H) for recursion stack (H = height of tree).
*/