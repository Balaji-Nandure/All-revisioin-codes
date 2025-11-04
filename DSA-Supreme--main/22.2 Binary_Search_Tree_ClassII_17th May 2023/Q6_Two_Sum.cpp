// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

/*
Approach Used:
--------------
1. **Inorder Traversal + Two Pointer Technique**:
   - First, perform an inorder traversal of the BST to get a sorted array of all node values.
   - Then, use the two-pointer approach (like in the classic Two Sum in sorted array) to check if there exist two numbers that sum up to the target `k`.
   - This works because inorder traversal of BST gives a sorted sequence.

Time Complexity: O(N), where N is the number of nodes (O(N) for traversal + O(N) for two-pointer search).
Space Complexity: O(N), for storing the inorder traversal.

Improvements:
-------------
- Added detailed comments for each important line.
- Added input validation.
- Used more descriptive variable names.
- Provided better alternatives (see below).
- Provided a dry run at the end.

Better Alternatives:
--------------------
1. **HashSet Approach (O(N) time, O(N) space, no need to sort):**
   - Traverse the tree, for each node check if (k - node->val) exists in a hash set.
   - If yes, return true. Otherwise, insert node->val into the set and continue.
   - This avoids the need to store the entire inorder traversal.

   Example code:
   ```
   bool findTarget(TreeNode* root, int k) {
       unordered_set<int> seen;
       return dfs(root, k, seen);
   }
   bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
       if (!node) return false;
       if (seen.count(k - node->val)) return true;
       seen.insert(node->val);
       return dfs(node->left, k, seen) || dfs(node->right, k, seen);
   }
   ```

2. **O(1) Extra Space (Morris Traversal + BST Iterator):**
   - Use two iterators: one for the smallest value (inorder), one for the largest (reverse inorder).
   - Move the iterators towards each other, similar to two-pointer, but without storing all values.
   - This is more advanced and saves space, but is more complex to implement.

Dry Run Example:
----------------
Given BST:      5
              /   \
             3     6
            / \     \
           2   4     7
Target k = 9

Inorder Traversal: [2, 3, 4, 5, 6, 7]
Two pointers: s=0 (2), e=5 (7)
- 2+7=9 -> Found! Return true.

*/

class Solution {
public:
    // Helper function to perform inorder traversal and store node values in sorted order
    void storeInorder(TreeNode* root, vector<int>& inorder) {
        if (root == nullptr) { // Base case: empty node
            return;
        }
        storeInorder(root->left, inorder);   // Traverse left subtree
        inorder.push_back(root->val);        // Store current node's value
        storeInorder(root->right, inorder);  // Traverse right subtree
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false; // Edge case: empty tree

        vector<int> inorder;                 // To store sorted node values
        storeInorder(root, inorder);         // Step 1: Get sorted values via inorder traversal

        // Step 2: Two-pointer approach to find if any two numbers sum to k
        int left = 0;                        // Start pointer (smallest value)
        int right = inorder.size() - 1;      // End pointer (largest value)

        while (left < right) {               // While pointers do not cross
            int sum = inorder[left] + inorder[right]; // Current sum of two values
            if (sum == k) {                  // If sum matches target
                return true;                 // Found the pair
            } else if (sum < k) {            // If sum is less, move left pointer to increase sum
                left++;
            } else {                         // If sum is more, move right pointer to decrease sum
                right--;
            }
        }
        return false;                        // No such pair found
    }
};

/*
Dry Run:
--------
Input BST:      5
               / \
              3   6
             / \   \
            2   4   7
Target k = 9

Inorder Traversal: [2, 3, 4, 5, 6, 7]
left=0 (2), right=5 (7): 2+7=9 -> Found! Return true.

If k=28:
left=0 (2), right=5 (7): 2+7=9 < 28 -> left++
left=1 (3), right=5 (7): 3+7=10 < 28 -> left++
left=2 (4), right=5 (7): 4+7=11 < 28 -> left++
left=3 (5), right=5 (7): left==right, stop. Return false.
*/

/*
Alternative Approach (HashSet, O(N) time, O(N) space):

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> seen;
    return dfs(root, k, seen);
}
bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
    if (!node) return false;
    if (seen.count(k - node->val)) return true;
    seen.insert(node->val);
    return dfs(node->left, k, seen) || dfs(node->right, k, seen);
}
*/