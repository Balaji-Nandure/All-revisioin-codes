/*
Problem:
---------
Find the Lowest Common Ancestor (LCA) of two nodes in a binary tree.

Definition:
------------
The LCA of two nodes p and q in a binary tree is the
lowest (deepest) node that has both p and q as descendants.
A node can be a descendant of itself.

Approach:
----------
Use recursion:
1. Base case:
   - If root == nullptr → return nullptr
   - If root == p or root == q → return root
2. Recurse left and right:
   - left = LCA(root->left, p, q)
   - right = LCA(root->right, p, q)
3. If both left and right are non-null → current node is LCA.
4. Else return whichever is non-null.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution { // Solution class for LCA problem // Encapsulates the LCA function logic
public: // Access specifier for member functions // Public so it can be accessed externally
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { // Function signature for LCA // Finds LCA of nodes p and q in tree rooted at root
        if (!root || root == p || root == q) // Check if root is null or matches p or q // Base case for recursion
            return root; // Return root if one of the base conditions met // root can be an ancestor

        TreeNode* left = lowestCommonAncestor(root->left, p, q); // Recursive call on left child // Looks for LCA in left subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q); // Recursive call on right child // Looks for LCA in right subtree

        if (left && right) return root; // If both left and right are non-null // p and q found in different subtrees, so root is LCA
        return left ? left : right; // If only one side is non-null, return that // Propagate the found node (if any) up the recursion
    }
};

int main() {
    /*
           3
          / \
         5   1
        / \ / \
       6  2 0  8
         / \
        7   4

    LCA(5, 1) = 3
    LCA(6, 4) = 5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, root->left, root->right);
    cout << "LCA(5, 1): " << lca->val << endl;

    lca = sol.lowestCommonAncestor(root, root->left->left, root->left->right->right);
    cout << "LCA(6, 4): " << lca->val << endl;
}
