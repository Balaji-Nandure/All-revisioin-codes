/*
Problem:
---------
Find the k-th ancestor of a given node in a binary tree.

Approach:
----------
- Use postorder traversal (Left → Right → Node)
- Recursively search for the target node.
- Once found, decrement k while returning up.
- When k == 0, current node is the k-th ancestor.
- Use reference variable for k to propagate decrements.

Time Complexity: O(n)
Space Complexity: O(h)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

Node* solve(Node* root, int& k, int node, int& ans) {
    if (!root) return nullptr;

    if (root->val == node) return root;

    Node* left = solve(root->left, k, node, ans);
    Node* right = solve(root->right, k, node, ans);

    if (left || right) {
        k--;
        if (k == 0) {
            ans = root->val;
            k = INT_MAX; // stop further changes
        }
        return root;
    }
    return nullptr;
}

int kthAncestor(Node* root, int k, int node) {
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}

int main() {
    /*
           1
          / \
         2   3
        / \
       4   5
      /
     7
    Example:  k = 2, node = 7 → 2 (ancestor sequence: 7 → 4 → 2)
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(7);

    int k = 2, node = 7;
    cout << "Kth ancestor of " << node << " is: " << kthAncestor(root, k, node) << endl;
}
