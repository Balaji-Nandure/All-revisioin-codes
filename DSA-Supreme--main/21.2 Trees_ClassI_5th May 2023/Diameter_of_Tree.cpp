/*
Problem:
---------
Find the diameter (length of the longest path between any two nodes) of a binary tree.

Approach:
----------
We use a post-order traversal (bottom-up):
1. For each node:
    - Compute height of left and right subtrees.
    - Diameter passing through that node = left_height + right_height.
2. Track the maximum such diameter across all nodes.
3. Return max diameter.

Time Complexity: O(n)
Space Complexity: O(h)   // h = height of tree
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
    int diameter = 0;

    int height(TreeNode* root) {
        if (!root) return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        diameter = max(diameter, lh + rh); // path through this node

        return 1 + max(lh, rh); // height of current node
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};

int main() {
    /*
         1
        / \
       2   3
      / \
     4   5

    Longest path: 4 → 2 → 5 or 4 → 2 → 1 → 3
    Diameter = 3 edges
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << "Diameter of Tree: " << sol.diameterOfBinaryTree(root) << "\n";
}
