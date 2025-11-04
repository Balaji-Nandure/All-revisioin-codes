// https://leetcode.com/problems/validate-binary-search-tree/

/*
Approach Used:
---------------
We use a recursive function to validate whether a binary tree is a Binary Search Tree (BST).
The function checks if every node's value lies within a valid range (lower bound, upper bound).
For the left child, the upper bound becomes the current node's value.
For the right child, the lower bound becomes the current node's value.
If all nodes satisfy the BST property, we return true; otherwise, false.

Time Complexity: O(N), where N is the number of nodes (each node is visited once).
Space Complexity: O(H), where H is the height of the tree (due to recursion stack).
*/

class Solution {
public:
    // Helper function to validate BST by checking value bounds
    bool solve(TreeNode* root, long long int lb, long long int ub) {
        // Base case: An empty tree is a valid BST
        if (root == nullptr) {
            return true;
        }
        // Check if current node's value is within the valid range
        if (root->val > lb && root->val < ub) {
            // Recursively check left subtree with updated upper bound
            bool leftAns = solve(root->left, lb, root->val);
            // Recursively check right subtree with updated lower bound
            bool rightAns = solve(root->right, root->val, ub);
            // Both left and right subtrees must be valid BSTs
            return leftAns && rightAns;
        } else {
            // Current node violates the BST property
            return false;
        }
    }

    bool isValidBST(TreeNode* root) {
        // Use long long min/max to avoid integer overflow for edge cases
        long long int lowerbound = LLONG_MIN; // Use standard limits for clarity
        long long int upperbound = LLONG_MAX;
        // Start recursion with the full range of valid values
        return solve(root, lowerbound, upperbound);
    }
};

/*
Alternative Approach 1: Inorder Traversal (Iterative or Recursive)
------------------------------------------------------------------
A valid BST's inorder traversal yields a strictly increasing sequence.
We can traverse the tree in inorder and check if each value is greater than the previous one.

Code Example:
-------------
bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;
    long long prev = LLONG_MIN;
    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top(); st.pop();
        if (curr->val <= prev) return false;
        prev = curr->val;
        curr = curr->right;
    }
    return true;
}

Pros:
- No need to manage explicit bounds.
- Simple and intuitive.

Cons:
- Requires extra space for stack (O(H)).

Alternative Approach 2: Morris Inorder Traversal (O(1) Space)
-------------------------------------------------------------
Same as above, but uses Morris Traversal to achieve O(1) space.

Dry Run Example:
----------------
Consider the tree:
      5
     / \
    1   7
       / \
      6   8

Initial call: solve(5, -inf, +inf)
- 5 in (-inf, +inf): true
    -> solve(1, -inf, 5)
        - 1 in (-inf, 5): true
            -> solve(NULL, -inf, 1): true
            -> solve(NULL, 1, 5): true
        - leftAns && rightAns = true
    -> solve(7, 5, +inf)
        - 7 in (5, +inf): true
            -> solve(6, 5, 7)
                - 6 in (5, 7): true
                    -> solve(NULL, 5, 6): true
                    -> solve(NULL, 6, 7): true
                - leftAns && rightAns = true
            -> solve(8, 7, +inf)
                - 8 in (7, +inf): true
                    -> solve(NULL, 7, 8): true
                    -> solve(NULL, 8, +inf): true
                - leftAns && rightAns = true
        - leftAns && rightAns = true
- leftAns && rightAns = true

Final result: true (valid BST)
*/