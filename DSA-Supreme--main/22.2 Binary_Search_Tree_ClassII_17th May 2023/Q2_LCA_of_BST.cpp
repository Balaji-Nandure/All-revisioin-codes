// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/*
Approach Used:
---------------
This solution leverages the properties of a Binary Search Tree (BST):
- For any node, all values in the left subtree are less than the node's value.
- All values in the right subtree are greater than the node's value.

The algorithm recursively traverses the tree:
1. If both p and q are less than the current node, LCA must be in the left subtree.
2. If both p and q are greater than the current node, LCA must be in the right subtree.
3. Otherwise, the current node is the split point and thus the LCA.

Time Complexity: O(h), where h is the height of the tree.
Space Complexity: O(h) due to recursion stack.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL, there is no ancestor
        if(root == NULL)
            return NULL;

        // If both p and q are less than root, LCA lies in left subtree
        if(p->val < root->val && q->val < root->val){
            // Recursive call on left child
            return lowestCommonAncestor(root->left, p, q);
        }
        // If both p and q are greater than root, LCA lies in right subtree
        else if(p->val > root->val && q->val > root->val){
            // Recursive call on right child
            return lowestCommonAncestor(root->right, p, q);
        }
        // If p and q are on different sides or one is equal to root, root is LCA
        else {
            // This is the split point, so root is the LCA
            return root;
        }
    }
};

/*
Alternative Iterative Approach (Better in terms of space, avoids recursion stack):

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Loop until you find the split point
    while(root != NULL) {
        // If both p and q are less than root, move to left child
        if(p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both p and q are greater than root, move to right child
        else if(p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Found the split point, root is LCA
        else {
            return root;
        }
    }
    return NULL; // If not found
}

Time Complexity: O(h)
Space Complexity: O(1)
*/

/*
Dry Run Example:
----------------
Given BST:
        6
       / \
      2   8
     / \ / \
    0  4 7  9
      / \
     3   5

Let p = 2, q = 8

Step 1: root = 6
    p->val = 2, q->val = 8
    2 < 6 && 8 > 6 => falls into 'else' case, so root (6) is the LCA.

Let p = 2, q = 4

Step 1: root = 6
    2 < 6 && 4 < 6 => move to left child (root = 2)
Step 2: root = 2
    2 == 2 or 4 > 2 => falls into 'else' case, so root (2) is the LCA.
*/