/*
Problem:
---------
Perform postorder traversal of a binary tree.

Definition:
------------
Postorder traversal: Visit Left subtree → Right subtree → Node.

Approach:
----------
1. Recursive approach:
   - Base case: if node == nullptr → return
   - Recursively visit left subtree
   - Recursively visit right subtree
   - Process current node

2. Iterative approach (using two stacks or modified one stack):
   - More complex; usually recursive is simpler.

Time Complexity: O(n)
Space Complexity:
   - Recursive: O(h) for recursion stack
   - Iterative: O(n) for stacks
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive Postorder Traversal
void postorderRecursive(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorderRecursive(root->left, res);
    postorderRecursive(root->right, res);
    res.push_back(root->val);
}

// Iterative Postorder Traversal using two stacks
vector<int> postorderIterative(TreeNode* root) {
    vector<int> res;
    if (!root) return res;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* node = s1.top(); s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        res.push_back(s2.top()->val);
        s2.pop();
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
    Postorder: 4 5 2 3 1
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res;
    postorderRecursive(root, res);

    cout << "Recursive Postorder: ";
    for (int x : res) cout << x << " ";
    cout << "\n";

    vector<int> res2 = postorderIterative(root);
    cout << "Iterative Postorder: ";
    for (int x : res2) cout << x << " ";
    cout << "\n";
}
