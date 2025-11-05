/*
Problem:
---------
Perform inorder traversal of a binary tree.

Definition:
------------
Inorder traversal: Visit Left subtree → Node → Right subtree.

Approach:
----------
1. Recursive approach:
   - Base case: if node == nullptr → return
   - Recursively visit left subtree
   - Process current node
   - Recursively visit right subtree

2. Iterative approach using stack:
   - Use a stack to simulate recursion
   - Traverse to the leftmost node, pushing nodes along the way
   - Pop from stack, process node, move to right subtree

Time Complexity: O(n)
Space Complexity: 
   - Recursive: O(h) for recursion stack
   - Iterative: O(h) for explicit stack (h = tree height)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive inorder traversal
void inorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    inorderRecursive(root->left, res);
    res.push_back(root->val);
    inorderRecursive(root->right, res);
}

// Iterative inorder traversal
vector<int> inorderIterative(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res;
    inorderRecursive(root, res);
    cout << "Recursive Inorder: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    vector<int> res2 = inorderIterative(root);
    cout << "Iterative Inorder: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";
}
