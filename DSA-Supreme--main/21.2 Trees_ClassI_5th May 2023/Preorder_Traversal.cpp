/*
Problem:
---------
Perform preorder traversal of a binary tree.

Definition:
------------
Preorder traversal: Visit Node → Left subtree → Right subtree.

Approach:
----------
1. Recursive approach:
   - Base case: if node == nullptr → return
   - Process current node
   - Recursively visit left subtree
   - Recursively visit right subtree

2. Iterative approach using stack:
   - Push root onto stack.
   - While stack is not empty:
       - Pop node, process it
       - Push right child, then left child (so left is processed first)

Time Complexity: O(n)
Space Complexity:
   - Recursive: O(h) for recursion stack
   - Iterative: O(n) for stack
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive Preorder Traversal
void preorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    res.push_back(root->val);
    preorderRecursive(root->left, res);
    preorderRecursive(root->right, res);
}

// Iterative Preorder Traversal
vector<int> preorderIterative(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        res.push_back(node->val);

        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }

    return res;
}

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    Preorder: 1 2 4 5 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res;
    preorderRecursive(root, res);
    cout << "Recursive Preorder: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    vector<int> res2 = preorderIterative(root);
    cout << "Iterative Preorder: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";
}