/*
Problem:
---------
Find the height (maximum depth) of a binary tree.

Definition:
------------
Height of a tree = number of nodes on the longest path from root to a leaf.
OR
Depth of root node = 1, and height = max depth of all nodes.

Approach:
----------
Use recursion (post-order traversal):
1. Base case: if node == nullptr → return 0
2. Otherwise:
     leftHeight  = height(node->left)
     rightHeight = height(node->right)
3. Return 1 + max(leftHeight, rightHeight)

Time Complexity: O(n)
Space Complexity: O(h)   // h = tree height (recursion stack)
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0; // empty tree has height 0
        int leftHeight  = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
};

int main() {
    /*
          1
         / \
        2   3
       / \
      4   5
    Height = 3 (1 → 2 → 4 or 1 → 2 → 5)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Height of tree: " << sol.height(root) << "\n";
}
