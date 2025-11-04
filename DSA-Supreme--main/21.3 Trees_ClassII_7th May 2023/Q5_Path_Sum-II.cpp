/*
Approach Used:
---------------
We use Depth First Search (DFS) with backtracking to find all root-to-leaf paths in a binary tree where the sum of the node values equals the given targetSum. At each node, we add its value to the current path and sum, and recursively explore its children. If we reach a leaf and the sum matches, we record the path. We backtrack after visiting each node to explore other paths.

Key Points:
- We use a reference to the current path vector to avoid unnecessary copies.
- We backtrack by popping the last node after visiting children.
- We only add the path to the answer if we are at a leaf and the sum matches.

Better Alternative Approach:
----------------------------
Instead of maintaining a running sum, we can pass the remaining sum (targetSum - current node's value) down the recursion. This avoids the need to track currSum and makes the code cleaner.

Alternative code (commented):
-----------------------------
/*
void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right && root->val == targetSum) {
        ans.push_back(path);
    } else {
        dfs(root->left, targetSum - root->val, path, ans);
        dfs(root->right, targetSum - root->val, path, ans);
    }
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    dfs(root, targetSum, path, ans);
    return ans;
}
*/

Dry Run Example:
----------------
Tree:      5
         /   \
        4     8
       /     / \
      11    13  4
     /  \        \
    7    2        1
targetSum = 22

Paths found: [5,4,11,2] and [5,8,4,5] (if 4's right child is 5)

Code with detailed comments:
*/

class Solution {
public:
    // Helper function to perform DFS and find all valid paths
    void solve(TreeNode* root, int targetSum, int currSum, vector<int>& path, vector<vector<int>>& ans) {
        // If current node is NULL, return (base case)
        if (root == NULL) {
            return;
        }

        // Add current node's value to path and currSum
        path.push_back(root->val); // include current node in path
        currSum += root->val;      // add current node's value to current sum

        // If current node is a leaf node (no left or right child)
        if (root->left == NULL && root->right == NULL) {
            // If the sum of the current path equals targetSum, add path to answer
            if (currSum == targetSum) {
                ans.push_back(path); // store a copy of the current path
            }
            // Backtrack: remove current node before returning
            path.pop_back();
            return;
        }

        // Recurse on left subtree
        solve(root->left, targetSum, currSum, path, ans);

        // Recurse on right subtree
        solve(root->right, targetSum, currSum, path, ans);

        // Backtrack: remove current node from path before returning to parent
        path.pop_back();
    }

    // Main function to be called
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans; // stores all valid paths
        vector<int> path;        // stores current path
        solve(root, targetSum, 0, path, ans); // start DFS with sum 0
        return ans;
    }
};

/*
Dry Run:
--------
Input: Tree as above, targetSum = 22

1. Start at root (5), path=[5], currSum=5
2. Go left to 4, path=[5,4], currSum=9
3. Go left to 11, path=[5,4,11], currSum=20
4. Go left to 7, path=[5,4,11,7], currSum=27 (not a valid path, backtrack)
5. Go right to 2, path=[5,4,11,2], currSum=22 (valid path, add to ans)
6. Backtrack to 4, then to 5
7. Go right to 8, path=[5,8], currSum=13
8. Go left to 13, path=[5,8,13], currSum=26 (not valid, backtrack)
9. Go right to 4, path=[5,8,4], currSum=17
10. Go right to 1, path=[5,8,4,1], currSum=18 (not valid, backtrack)
11. All paths explored, return ans = [[5,4,11,2]]

Alternative approach (passing remaining sum) is more concise and avoids currSum variable.
*/