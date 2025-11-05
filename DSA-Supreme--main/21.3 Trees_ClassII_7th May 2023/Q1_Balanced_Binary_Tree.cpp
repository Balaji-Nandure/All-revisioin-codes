/*
Problem:
---------
Check if a binary tree is height-balanced.

Approach:
----------
1. If tree is empty → balanced
2. Recursively get height of left and right subtrees
3. If difference > 1 → not balanced
4. Also ensure left and right subtrees are balanced
*/

class Solution {
    public:
        // Function to get height of tree
        int height(TreeNode* root) {
            if (!root) return 0;
            return 1 + max(height(root->left), height(root->right));
        }
        
        bool isBalanced(TreeNode* root) {
            if (!root) return true;
            
            int lh = height(root->left);
            int rh = height(root->right);
            
            return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    };
    