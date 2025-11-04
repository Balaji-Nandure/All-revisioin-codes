/*
Approach Used:
---------------
This is a recursive approach to find the Lowest Common Ancestor (LCA) of two nodes in a binary tree (not necessarily a BST).
The idea is:
- If the current node is NULL, return NULL.
- If the current node matches either p or q, return that node.
- Recursively search for p and q in the left and right subtrees.
- If both left and right recursive calls return non-NULL, current node is the LCA.
- If only one side returns non-NULL, propagate that result up.

Time Complexity: O(N), where N is the number of nodes in the tree.
Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

Better/Alternative Approaches:
-----------------------------
1. **Parent Pointer + Hashing** (for multiple queries):
   - Traverse the tree and store parent pointers for each node.
   - For each query, store all ancestors of p in a set, then move up from q until you find a node in the set.
   - Useful for multiple LCA queries, but requires extra space.
   - Code Example:
     ```
     // Preprocessing
     unordered_map<TreeNode*, TreeNode*> parent;
     void dfs(TreeNode* node, TreeNode* par) {
         if (!node) return;
         parent[node] = par;
         dfs(node->left, node);
         dfs(node->right, node);
     }
     // Query
     unordered_set<TreeNode*> ancestors;
     while (p) { ancestors.insert(p); p = parent[p]; }
     while (q) {
         if (ancestors.count(q)) return q;
         q = parent[q];
     }
     ```

2. **Binary Lifting** (for static trees, many queries):
   - Preprocess tree with binary lifting to answer LCA in O(logN) per query.
   - More complex, used in competitive programming.

3. **Iterative Approach** (using stack):
   - Simulate recursion with stack, similar logic.

Below is the improved code with detailed comments and a dry run at the end.
*/

class Solution {
public:
    // Function to find the Lowest Common Ancestor of two nodes in a binary tree
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if current node is NULL, return NULL (no ancestor found in this path)
        if(root == NULL){
            return NULL;
        }

        // If current node matches p, we've found one of the nodes; return it up the call stack
        if(root == p){
            return p;
        }

        // If current node matches q, we've found one of the nodes; return it up the call stack
        if(root == q){
            return q;
        }

        // Recursively search for p and q in the left subtree
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);

        // Recursively search for p and q in the right subtree
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

        // If both left and right recursive calls return non-NULL,
        // it means p and q are found in different subtrees, so current node is their LCA
        if(leftAns != NULL && rightAns != NULL){
            return root;
        }

        // If only left subtree returns a non-NULL value, propagate it up (either p or q found in left subtree)
        if(leftAns != NULL){
            return leftAns;
        }

        // If only right subtree returns a non-NULL value, propagate it up (either p or q found in right subtree)
        if(rightAns != NULL){
            return rightAns;
        }

        // If neither subtree returns a non-NULL value, return NULL (neither p nor q found in this path)
        return NULL;
    }
};

/*
Dry Run Example:
----------------
Tree:
        3
       / \
      5   1
     / \ / \
    6  2 0  8
      / \
     7   4

p = 5, q = 1

Call Stack:
lowestCommonAncestor(3, 5, 1)
    - root != p or q
    - leftAns = lowestCommonAncestor(5, 5, 1) -> returns 5 (root == p)
    - rightAns = lowestCommonAncestor(1, 5, 1) -> returns 1 (root == q)
    - Both leftAns and rightAns are non-NULL, so return root (3)

Result: LCA is 3

Another Example:
p = 5, q = 4

lowestCommonAncestor(3, 5, 4)
    - leftAns = lowestCommonAncestor(5, 5, 4)
        - root == p, return 5
    - rightAns = lowestCommonAncestor(1, 5, 4)
        - search left/right, eventually finds 4 in left subtree of 2
    - leftAns = 5, rightAns = NULL, so return leftAns (5)

Result: LCA is 5
*/