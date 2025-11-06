/*
Problem:
---------
Print the bottom view of a binary tree.
The bottom view contains all the nodes that would be visible if the tree were viewed from below.

Approach:
----------
Use Level Order Traversal (BFS) + Horizontal Distance (HD) Mapping:
1. Assign the root HD = 0.
2. For every node:
   - left child → HD = parent.HD - 1
   - right child → HD = parent.HD + 1
3. Use a map<int, int> to store the *last* node value at each HD.
4. Perform BFS — for every node at same HD, replace the previous one (to get the bottom-most).
5. Finally, output all values in order of HD.

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

vector<int> bottomView(Node* root) {
    vector<int> result;
    if (!root) return result;

    // map<HD, Node value>
    map<int, int> bottomNode;
    queue<pair<Node*, int>> q; // {node, horizontal distance}

    q.push({root, 0});

    while (!q.empty()) {
        auto [curr, hd] = q.front();
        q.pop();

        // For bottom view → always update (keep latest node for each HD)
        bottomNode[hd] = curr->val;

        if (curr->left)
            q.push({curr->left, hd - 1});
        if (curr->right)
            q.push({curr->right, hd + 1});
    }

    // collect results in HD order
    for (auto& p : bottomNode)
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

     Bottom view: [4, 2, 5, 7, 8]
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    vector<int> ans = bottomView(root);
    cout << "Bottom View: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
