/*
Problem:
---------
Given the root of a binary tree and an integer targetSum,
return true if there exists a root-to-leaf path such that 
the sum of the node values equals targetSum.

Approach:
----------
- Use simple recursion.
- Subtract current node’s value from targetSum.
- If it's a leaf node, check if remaining sum == 0.
- Recurse left and right for remaining targetSum.

Time Complexity: O(n)
Space Complexity: O(h)  // recursion depth
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Check if it's a leaf node
        if (!root->left && !root->right)
            return targetSum == root->val;

        // Recurse to left and right with updated sum
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    /*
           5
          / \
         4   8
        /   / \
       11  13  4
      /  \      \
     7    2      1
    */

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    Solution sol;
    int targetSum = 22;

    cout << (sol.hasPathSum(root, targetSum) ? "Path Exists" : "No Path") << endl;
}
