/*
Problem:
---------
Print all nodes on the boundary of a binary tree in an anti-clockwise direction:
1. Left boundary (excluding leaf nodes)
2. All leaf nodes (left to right)
3. Right boundary (excluding leaf nodes, in reverse)

Approach:
----------
1. Print root node.
2. Print left boundary (top-down), excluding leaves.
3. Print all leaf nodes (using DFS).
4. Print right boundary (bottom-up), excluding leaves.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x): val(x), left(nullptr), right(nullptr) {}
};

// Print left boundary (excluding leaves)
void printLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (curr->left || curr->right) res.push_back(curr->val);
        if (curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

// Print leaf nodes
void printLeaves(Node* root, vector<int>& res) {
    if (!root) return;
    printLeaves(root->left, res);
    if (!root->left && !root->right) res.push_back(root->val);
    printLeaves(root->right, res);
}

// Print right boundary (excluding leaves) in reverse
void printRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (curr->left || curr->right) temp.push_back(curr->val);
        if (curr->right) curr = curr->right;
        else curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    res.insert(res.end(), temp.begin(), temp.end());
}

vector<int> boundaryTraversal(Node* root) {
    vector<int> res;
    if (!root) return res;
    res.push_back(root->val);

    printLeftBoundary(root, res);
    printLeaves(root, res);
    printRightBoundary(root, res);

    return res;
}

int main() {
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
           / \
          8   9

    Boundary traversal: 1 2 4 8 9 6 7 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);

    vector<int> ans = boundaryTraversal(root);
    cout << "Boundary Traversal: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
