/*
Problem:
---------
Print the top view of a binary tree.
The top view contains all the nodes that are visible when the tree is viewed from the top.

Approach:
----------
Use Level Order Traversal (BFS) + Horizontal Distance (HD) Mapping:
1. Assign the root node a horizontal distance (HD) = 0.
2. For every node:
     - left child → HD = parent.HD - 1
     - right child → HD = parent.HD + 1
3. Use a map<int, int> to store the first node for each HD (smallest level node).
4. Perform BFS and record only the *first* occurrence of each HD.
5. Finally, print nodes in order of increasing HD.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

vector<int> topView(Node* root) {
    vector<int> result;
    if (!root) return result;

    // map<HD, Node value>
    map<int, int> topNode;
    queue<pair<Node*, int>> q; // pair(node, HD)
    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, hd] = q.front();
        q.pop();

        // store first node at each horizontal distance
        if (topNode.find(hd) == topNode.end())
            topNode[hd] = curr->val;

        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    // collect results in HD order
    for (auto& p : topNode)
        result.push_back(p.second);

    return result;
}

int main() {
    /*
             1
           /   \
          2     3
           \   / \
            4 5   6
                 / \
                7   8

     Top view: [2, 1, 3, 6, 8]
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = topView(root);
    cout << "Top View: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
