// https://leetcode.com/problems/balanced-binary-tree/

/*
Approach Used in This Code:
---------------------------
- The code checks if a binary tree is height-balanced.
- A binary tree is balanced if for every node, the height difference between its left and right subtree is at most 1.
- The code uses a recursive approach:
    1. For each node, it calculates the height of its left and right subtrees.
    2. It checks if the difference in heights is <= 1.
    3. It recursively checks if the left and right subtrees are balanced.
    4. If all conditions are satisfied, the tree is balanced.

Drawback:
---------
- The current approach recalculates the height of subtrees multiple times, leading to O(N^2) time complexity in the worst case.

Better Alternative Approach (Optimal):
--------------------------------------
- Use a bottom-up approach: For each node, return both whether the subtree is balanced and its height in a single traversal.
- This reduces the time complexity to O(N).
- See the commented code at the end for the optimal approach.

Dry Run Example:
----------------
Consider the tree:
      1
     / \
    2   3
   /
  4

- For node 4: leftHeight=0, rightHeight=0, diff=0 (balanced)
- For node 2: leftHeight=1 (from 4), rightHeight=0, diff=1 (balanced)
- For node 3: leftHeight=0, rightHeight=0, diff=0 (balanced)
- For node 1: leftHeight=2 (from 2), rightHeight=1 (from 3), diff=1 (balanced)
- All nodes are balanced, so the tree is balanced.

*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Helper function to calculate height of a tree rooted at 'root'
    int height(TreeNode* root){
        // Base case: If the node is NULL, its height is 0
        if(root == NULL){
            return 0;
        }
        // Recursively calculate height of left subtree
        int lh = height(root->left);
        // Recursively calculate height of right subtree
        int rh = height(root->right);
        // Height of current node is 1 + max of left and right subtree heights
        int ans = 1 + max(lh, rh);
        return ans;
    }

    // Main function to check if the tree is balanced
    bool isBalanced(TreeNode* root) {
        // Base case: An empty tree is balanced
        if(root == NULL){
            return true;
        }
        // Calculate height of left subtree
        int leftHeight = height(root->left);
        // Calculate height of right subtree
        int rightHeight = height(root->right);
        // Find the absolute difference between left and right subtree heights
        int diff = abs(leftHeight - rightHeight);
        // Check if current node is balanced (difference <= 1)
        bool ans1 = (diff <= 1);
        // Recursively check if left subtree is balanced
        bool leftAns = isBalanced(root->left);
        // Recursively check if right subtree is balanced
        bool rightAns = isBalanced(root->right);
        // If current node and both subtrees are balanced, return true
        if(ans1 && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};

/*
Optimal Approach (O(N) Time, O(H) Space):
-----------------------------------------
- Instead of recalculating heights, return -1 if a subtree is unbalanced, else return its height.
- If any subtree is unbalanced, propagate -1 up the call stack.

class Solution {
public:
    // Returns height if balanced, else -1
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        int lh = checkHeight(root->left);
        if (lh == -1) return -1; // left subtree not balanced
        int rh = checkHeight(root->right);
        if (rh == -1) return -1; // right subtree not balanced
        if (abs(lh - rh) > 1) return -1; // current node not balanced
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

Dry Run for Optimal Approach:
-----------------------------
For the same tree:
      1
     / \
    2   3
   /
  4

- checkHeight(4): returns 1
- checkHeight(2): left=1, right=0, diff=1 -> returns 2
- checkHeight(3): returns 1
- checkHeight(1): left=2, right=1, diff=1 -> returns 3
- isBalanced returns true

*/