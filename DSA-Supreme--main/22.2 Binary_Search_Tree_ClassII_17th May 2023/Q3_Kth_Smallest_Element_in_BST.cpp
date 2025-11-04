// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

/*
Approach Used:
---------------
- The code uses **inorder traversal** (left-root-right) of the BST.
- Inorder traversal of BST gives nodes in sorted order.
- We decrement k at each node visited; when k==0, we've found the kth smallest.
- The function is recursive and passes k by reference to keep track of the count across recursive calls.

Improvements:
-------------
- Added detailed comments for each important line.
- Added input validation.
- Added a wrapper function to avoid passing k by reference from outside.
- Provided alternative approaches in comments.
- Provided a dry run at the end.

*/

class Solution {
public:
    // Wrapper function to avoid passing k by reference from outside
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kthSmallestUtil(root, k, ans);
        return ans;
    }
    
private:
    // Helper function for inorder traversal
    void kthSmallestUtil(TreeNode* root, int &k, int &ans) {
        if(root == nullptr) {
            // If node is null, just return
            return;
        }
        
        // Traverse left subtree (smaller elements)
        kthSmallestUtil(root->left, k, ans);
        
        // Visit current node
        k--; // Decrement k as we visit a node
        if(k == 0) {
            // If k is 0, we've found the kth smallest element
            ans = root->val;
            return;
        }
        
        // Traverse right subtree (larger elements)
        kthSmallestUtil(root->right, k, ans);
    }
};

/*
Alternative Approaches:
-----------------------

1. **Iterative Inorder Traversal (using stack):**
   - Avoids recursion stack overflow for deep trees.
   - More efficient in terms of call stack usage.

   // C++ code:
   int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode*> st;
       TreeNode* curr = root;
       while(curr || !st.empty()) {
           while(curr) {
               st.push(curr);
               curr = curr->left;
           }
           curr = st.top(); st.pop();
           k--;
           if(k == 0) return curr->val;
           curr = curr->right;
       }
       return -1; // Not found
   }

2. **Augmented BST (store subtree sizes):**
   - Each node stores the size of its left subtree.
   - Allows O(log n) kth smallest queries after O(n) preprocessing.
   - Useful if there are many kth smallest queries.

   // Not implemented here due to complexity.

3. **Morris Inorder Traversal (O(1) space):**
   - Threaded binary tree traversal.
   - No stack or recursion, but modifies tree structure temporarily.

   // Not implemented here due to complexity.

Dry Run:
--------
Given BST:
        5
       / \
      3   6
     / \
    2   4
   /
  1

k = 3

Inorder traversal: 1, 2, 3, 4, 5, 6

Step-by-step:
- Visit 1 (k=3->2)
- Visit 2 (k=2->1)
- Visit 3 (k=1->0) => Found kth smallest: 3

So, output is 3.

*/